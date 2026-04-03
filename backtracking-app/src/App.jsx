import React, { useState, useEffect, useRef } from 'react';
import { Play, Pause, SkipForward, SkipBack, RotateCcw, AlertCircle, CheckCircle2 } from 'lucide-react';

export default function App() {
  // Trạng thái cho đầu vào
  const [inputText, setInputText] = useState("4 8\n2 4 6 8");
  const [errorMsg, setErrorMsg] = useState("");

  // Trạng thái cho thuật toán và mô phỏng
  const [arrayA, setArrayA] = useState([]);
  const [targetX, setTargetX] = useState(0);
  const [steps, setSteps] = useState([]);
  const [currentStepIndex, setCurrentStepIndex] = useState(0);
  
  // Trạng thái cho player (chạy tự động)
  const [isPlaying, setIsPlaying] = useState(false);
  const [speed, setSpeed] = useState(500); // ms per step
  
  const timerRef = useRef(null);
  const codeContainerRef = useRef(null); // Ref để auto-scroll code tracker

  // Hàm sinh các bước mô phỏng (Backtracking)
  const generateSteps = (originalA, targetX) => {
    // Đảm bảo mảng A có các số dương phân biệt và được sắp xếp
    const A = Array.from(new Set(originalA.filter(x => x > 0))).sort((a, b) => a - b);
    let simulationSteps = [];
    let validCombos = [];
    let stopSimulation = false; // Cờ an toàn chống crash

    const backtrack = (i_depth, start, currentSum, currentCombo) => {
      if (stopSimulation) return;
      
      // Giới hạn an toàn chống tràn trình duyệt (10,000 bước)
      if (simulationSteps.length > 10000) {
        stopSimulation = true;
        simulationSteps.push({
          action: 'EXCEED',
          combo: [...currentCombo], sum: currentSum, index: -1, valid: [...validCombos], activeLines: [],
          msg: `CẢNH BÁO: Đạt giới hạn 10,000 bước mô phỏng. Dừng sớm để tránh treo trình duyệt!`
        });
        return;
      }

      for (let j = start; j < A.length; j++) {
        currentCombo.push(A[j]); // X[i] = a[j]
        let nextSum = currentSum + A[j]; // sum += a[j]

        simulationSteps.push({
          action: 'TRY',
          combo: [...currentCombo],
          sum: nextSum,
          index: j,
          valid: [...validCombos],
          activeLines: [2, 3, 4],
          msg: `Vòng lặp j=${j}: Gán X[${i_depth}] = a[${j}] (${A[j]}), sum = ${nextSum}`
        });

        if (nextSum === targetX) {
          validCombos.push([...currentCombo]);
          simulationSteps.push({
            action: 'SUCCESS',
            combo: [...currentCombo],
            sum: nextSum,
            index: j,
            valid: [...validCombos],
            activeLines: [5, 6, 7, 8, 9],
            msg: `sum == S (${targetX}). In cấu hình hợp lệ!`
          });
        } else if (nextSum < targetX) {
          simulationSteps.push({
            action: 'RECURSE',
            combo: [...currentCombo],
            sum: nextSum,
            index: j,
            valid: [...validCombos],
            activeLines: [11, 12],
            msg: `sum < S (${nextSum} < ${targetX}). Gọi đệ quy Try(i+1, j, sum).`
          });
          backtrack(i_depth + 1, j, nextSum, currentCombo);
        } else {
          simulationSteps.push({
            action: 'EXCEED',
            combo: [...currentCombo],
            sum: nextSum,
            index: j,
            valid: [...validCombos],
            activeLines: [5, 11], 
            msg: `sum > S (${nextSum} > ${targetX}). Cả 2 điều kiện đều sai, không đệ quy.`
          });
        }

        if (stopSimulation) return;

        const removed = currentCombo.pop();
        simulationSteps.push({
          action: 'BACKTRACK',
          combo: [...currentCombo],
          sum: currentSum,
          index: j,
          valid: [...validCombos],
          activeLines: [14],
          msg: `Quay lui: sum -= a[${j}]. Loại bỏ ${removed} khỏi cấu hình.`
        });
      }
    };

    simulationSteps.push({
      action: 'START',
      combo: [], sum: 0, index: -1, valid: [], activeLines: [1],
      msg: `Bắt đầu gọi thuật toán: Try(1, 0, 0)`
    });

    backtrack(1, 0, 0, []);

    if (!stopSimulation) {
      simulationSteps.push({
        action: 'DONE',
        combo: [], sum: 0, index: -1, valid: [...validCombos], activeLines: [16],
        msg: `Hoàn tất vòng lặp, kết thúc thuật toán!`
      });
    }

    return { simulationSteps, A };
  };

  // Hàm xử lý parse input và khởi tạo
  const handleParseInput = () => {
    try {
      setErrorMsg("");
      const lines = inputText.trim().split('\n').map(line => line.trim()).filter(line => line);
      
      if (lines.length < 2) {
        throw new Error("Vui lòng nhập đủ 2 dòng: Dòng 1 (N X) và Dòng 2 (Mảng A).");
      }

      const firstLine = lines[0].split(/\s+/).map(Number);
      if (firstLine.length !== 2 || isNaN(firstLine[0]) || isNaN(firstLine[1])) {
        throw new Error("Dòng 1 phải chứa đúng 2 số nguyên N và X.");
      }
      
      const N = firstLine[0];
      const X = firstLine[1];

      // Đọc toàn bộ các dòng còn lại thành 1 mảng (để phòng trường hợp user paste array bị rớt dòng)
      const arrayTokens = lines.slice(1).join(' ').split(/\s+/).filter(x => x !== '');
      
      if (arrayTokens.length < N) {
        throw new Error(`Cần nhập đủ ${N} số cho mảng A[]. Hiện tại mới có ${arrayTokens.length} số.`);
      }

      const parsedA = arrayTokens.slice(0, N).map(Number);
      
      if (parsedA.some(isNaN) || parsedA.some(num => num <= 0)) {
        throw new Error("Mảng A[] phải chứa các số nguyên dương.");
      }
      
      if (X <= 0) {
        throw new Error("X (Tổng mục tiêu) phải là số nguyên dương.");
      }

      const { simulationSteps, A } = generateSteps(parsedA, X);
      
      setArrayA(A);
      setTargetX(X);
      setSteps(simulationSteps);
      setCurrentStepIndex(0);
      setIsPlaying(false);

    } catch (err) {
      setErrorMsg(err.message);
    }
  };

  // Xử lý auto play
  useEffect(() => {
    if (isPlaying && steps.length > 0) {
      timerRef.current = setInterval(() => {
        setCurrentStepIndex(prev => {
          if (prev < steps.length - 1) {
            return prev + 1;
          } else {
            setIsPlaying(false);
            return prev;
          }
        });
      }, speed);
    } else {
      clearInterval(timerRef.current);
    }
    return () => clearInterval(timerRef.current);
  }, [isPlaying, speed, steps.length]);

  // Khởi chạy mặc định lần đầu
  useEffect(() => {
    handleParseInput();
    // eslint-disable-next-line
  }, []);

  const currentStep = steps[currentStepIndex] || null;

  // Auto-scroll Code Tracker khi bước (step) thay đổi
  useEffect(() => {
    if (currentStep && currentStep.activeLines && currentStep.activeLines.length > 0 && codeContainerRef.current) {
      const firstActiveLine = currentStep.activeLines[0];
      const lineElement = codeContainerRef.current.querySelector(`[data-line="${firstActiveLine}"]`);
      if (lineElement) {
        lineElement.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
      }
    }
  }, [currentStepIndex, currentStep]);

  // Lấy màu trạng thái
  const getStatusColor = (action) => {
    switch (action) {
      case 'SUCCESS': return 'bg-green-100 border-green-500 text-green-800';
      case 'EXCEED': return 'bg-red-100 border-red-500 text-red-800';
      case 'TRY': return 'bg-blue-100 border-blue-500 text-blue-800';
      case 'RECURSE': return 'bg-purple-100 border-purple-500 text-purple-800';
      case 'BACKTRACK': return 'bg-orange-100 border-orange-500 text-orange-800';
      case 'DONE': return 'bg-gray-200 border-gray-500 text-gray-800';
      default: return 'bg-gray-100 border-gray-400 text-gray-800';
    }
  };

  const cppCode = [
    "void Try(int i, int start, int sum){",
    "    for(int j = start; j < n; j++){",
    "        X[i] = a[j];",
    "        sum += a[j];",
    "        if(sum == S){",
    "            for(int idx = 1; idx <= i; idx++){",
    "                cout << X[idx] << ' ';",
    "            }",
    "            cout << endl;",
    "        }",
    "        else if(sum < S){",
    "            Try(i + 1, j, sum);",
    "        }",
    "        sum -= a[j];",
    "    }",
    "}"
  ];

  // Regex đã được tối ưu để nhận diện thêm biến và số
  const renderCodeLine = (line) => {
    const parts = line.split(/(\b(?:void|int|for|if|else)\b|\b(?:cout|endl|Try|X|a|n|S)\b|' '|==|\+=|-=|<|<=|\b\d+\b)/);
    return parts.map((part, i) => {
      if (['void', 'int', 'for', 'if', 'else'].includes(part)) return <span key={i} className="text-[#c586c0]">{part}</span>;
      if (['cout', 'endl', 'Try'].includes(part)) return <span key={i} className="text-[#dcdcaa]">{part}</span>;
      if (['X', 'a', 'n', 'S'].includes(part)) return <span key={i} className="text-[#9cdcfe]">{part}</span>;
      if (!isNaN(part) && part.trim() !== '') return <span key={i} className="text-[#b5cea8]">{part}</span>;
      if (part === "' '") return <span key={i} className="text-[#ce9178]">{part}</span>;
      if (['==', '+=', '-=', '<', '<='].includes(part)) return <span key={i} className="text-[#569cd6]">{part}</span>;
      return <span key={i} className="text-[#d4d4d4]">{part}</span>;
    });
  };

  return (
    // Đã thay đổi background từ bg-slate-50 sang lớp custom bg-animate và relative overflow-hidden
    <div className="min-h-screen bg-animate font-sans text-slate-800 p-4 md:p-8 flex flex-col items-center relative overflow-hidden">
      
      {/* KHỐI NỀN ĐỘNG (FLOATING PARTICLES) */}
      <ul className="circles">
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
      </ul>

      {/* Main Container - Cần thêm relative và z-10 để nổi lên trên nền động */}
      <div className="max-w-6xl w-full bg-white/90 backdrop-blur-sm shadow-2xl rounded-2xl overflow-hidden border border-slate-200/50 flex flex-col md:flex-row relative z-10">
        
        {/* PANEL TRÁI: Đầu vào & Điều khiển */}
        <div className="w-full md:w-1/3 bg-slate-100/80 p-6 border-r border-slate-200/50 flex flex-col gap-6">
          <div>
            <h2 className="text-xl font-bold text-slate-800 mb-2 flex items-center gap-2">
              <RotateCcw className="w-5 h-5" /> Đầu vào (Input)
            </h2>
            <p className="text-sm text-slate-600 mb-2">
              Dòng 1: N và X (Số phần tử & Tổng mục tiêu)<br />
              Dòng 2: N số nguyên dương của mảng A[]
            </p>
            <textarea
              className="w-full h-24 p-3 border border-slate-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:outline-none font-mono text-sm"
              value={inputText}
              onChange={(e) => setInputText(e.target.value)}
              placeholder="4 8&#10;2 4 6 8"
            />
            {errorMsg && (
              <div className="mt-2 text-sm text-red-600 flex items-center gap-1">
                <AlertCircle className="w-4 h-4" /> {errorMsg}
              </div>
            )}
            <button
              onClick={handleParseInput}
              className="mt-3 w-full bg-blue-600 hover:bg-blue-700 text-white font-semibold py-2 px-4 rounded-lg transition-colors shadow-sm"
            >
              Cập nhật & Bắt đầu
            </button>
          </div>

          <div className="flex-1">
            <h2 className="text-xl font-bold text-slate-800 mb-4">Điều khiển Mô phỏng</h2>
            
            <div className="grid grid-cols-4 gap-2 mb-4">
              <button
                onClick={() => { setIsPlaying(false); setCurrentStepIndex(0); }}
                className="col-span-1 flex justify-center items-center p-2 bg-slate-200 hover:bg-slate-300 rounded-lg transition"
                title="Làm lại"
              >
                <RotateCcw className="w-5 h-5" />
              </button>
              <button
                onClick={() => { setIsPlaying(false); setCurrentStepIndex(p => Math.max(0, p - 1)); }}
                className="col-span-1 flex justify-center items-center p-2 bg-slate-200 hover:bg-slate-300 rounded-lg transition"
                title="Bước trước"
                disabled={currentStepIndex === 0}
              >
                <SkipBack className="w-5 h-5" />
              </button>
              <button
                onClick={() => setIsPlaying(!isPlaying)}
                className={`col-span-1 flex justify-center items-center p-2 rounded-lg transition shadow-sm text-white ${isPlaying ? 'bg-orange-500 hover:bg-orange-600' : 'bg-green-600 hover:bg-green-700'}`}
                title={isPlaying ? "Tạm dừng" : "Tự động chạy"}
              >
                {isPlaying ? <Pause className="w-5 h-5" /> : <Play className="w-5 h-5 ml-1" />}
              </button>
              <button
                onClick={() => { setIsPlaying(false); setCurrentStepIndex(p => Math.min(steps.length - 1, p + 1)); }}
                className="col-span-1 flex justify-center items-center p-2 bg-slate-200 hover:bg-slate-300 rounded-lg transition"
                title="Bước tiếp theo"
                disabled={steps.length === 0 || currentStepIndex === steps.length - 1}
              >
                <SkipForward className="w-5 h-5" />
              </button>
            </div>

            <div className="mb-2">
              <label className="text-sm font-semibold text-slate-700 flex justify-between">
                <span>Tốc độ: {speed}ms</span>
                <span>Tiến trình: {steps.length > 0 ? `${currentStepIndex + 1} / ${steps.length}` : '0/0'}</span>
              </label>
              <input
                type="range"
                min="100"
                max="2000"
                step="100"
                value={speed}
                onChange={(e) => setSpeed(Number(e.target.value))}
                className="w-full h-2 bg-slate-300 rounded-lg appearance-none cursor-pointer mt-2 accent-blue-600"
                style={{ direction: 'rtl' }} // Ngược lại: ms thấp = chạy nhanh
              />
              <div className="flex justify-between text-xs text-slate-500 mt-1">
                <span>Chậm</span>
                <span>Nhanh</span>
              </div>
            </div>
            
            <div className="mt-4 p-4 bg-white rounded-lg border border-slate-200 shadow-sm">
               <div className="text-sm font-semibold text-slate-500 mb-1">Thống kê hiện tại</div>
               <div className="text-2xl font-bold text-slate-800">
                  {currentStep ? currentStep.valid.length : 0} <span className="text-sm font-normal text-slate-500">tổ hợp được tìm thấy</span>
               </div>
            </div>
          </div>
        </div>

        {/* PANEL PHẢI: Giao diện Trực quan */}
        <div className="w-full md:w-2/3 p-6 flex flex-col gap-6 relative bg-white/80">
          
          {/* Status Bar */}
          <div className="h-16">
            {currentStep && (
              <div className={`p-3 rounded-lg border-l-4 shadow-sm transition-all duration-300 flex items-center gap-3 ${getStatusColor(currentStep.action)}`}>
                {currentStep.action === 'SUCCESS' && <CheckCircle2 className="w-6 h-6 flex-shrink-0" />}
                {currentStep.action === 'EXCEED' && <AlertCircle className="w-6 h-6 flex-shrink-0" />}
                <p className="font-semibold text-sm md:text-base leading-tight">{currentStep.msg}</p>
              </div>
            )}
          </div>

          <div className="flex-1 flex flex-col gap-6">
            <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
              {/* Cột hiển thị Thuật toán (Mảng & Tổ hợp) */}
              <div className="flex flex-col gap-6">
                
                {/* Mảng A */}
                <div className="bg-white border border-slate-200 rounded-xl p-4 shadow-sm">
                  <h3 className="text-sm font-bold text-slate-500 uppercase tracking-wider mb-3">Mảng a[] (đã sắp xếp)</h3>
                  <div className="flex flex-wrap gap-2">
                    {arrayA.map((num, idx) => {
                      const isConsidering = currentStep?.index === idx && currentStep?.action !== 'DONE' && currentStep?.action !== 'START';
                      return (
                        <div
                          key={idx}
                          className={`w-12 h-12 flex items-center justify-center rounded-lg text-lg font-bold border-2 transition-all duration-300 ${
                            isConsidering 
                              ? 'bg-blue-100 border-blue-500 text-blue-700 scale-110 shadow-md' 
                              : 'bg-slate-50 border-slate-200 text-slate-600'
                          }`}
                        >
                          {num}
                        </div>
                      )
                    })}
                  </div>
                </div>

                {/* Tổ hợp đang xét */}
                <div className="bg-white border border-slate-200 rounded-xl p-4 shadow-sm flex-1">
                  <h3 className="text-sm font-bold text-slate-500 uppercase tracking-wider mb-3 flex justify-between">
                    <span>Mảng X[] (Cấu hình)</span>
                    <span className="text-blue-600">sum: {currentStep ? currentStep.sum : 0} / S: {targetX}</span>
                  </h3>
                  
                  <div className="min-h-[100px] flex items-center flex-wrap gap-2 bg-slate-50 rounded-lg p-4 border border-slate-100 border-dashed">
                    {currentStep && currentStep.combo.length > 0 ? (
                      currentStep.combo.map((num, idx) => (
                        <div key={idx} className="flex items-center">
                          <div className={`w-10 h-10 flex items-center justify-center rounded-full text-white font-bold shadow-sm transition-all animate-bounce-in
                            ${idx === currentStep.combo.length - 1 && currentStep.action === 'TRY' ? 'bg-orange-500 scale-110' : 
                              currentStep.action === 'SUCCESS' ? 'bg-green-500' :
                              currentStep.action === 'EXCEED' && idx === currentStep.combo.length - 1 ? 'bg-red-500' : 'bg-blue-500'}`
                          }>
                            {num}
                          </div>
                          {idx < currentStep.combo.length - 1 && <span className="mx-1 text-slate-400 font-bold">+</span>}
                        </div>
                      ))
                    ) : (
                      <span className="text-slate-400 italic">Cấu hình rỗng [ ]</span>
                    )}
                    
                    {currentStep && currentStep.combo.length > 0 && (
                      <div className="ml-2 flex items-center text-lg font-bold">
                        <span className="text-slate-400 mx-2">=</span>
                        <span className={`${
                          currentStep.sum === targetX ? 'text-green-600' :
                          currentStep.sum > targetX ? 'text-red-600' : 'text-blue-600'
                        }`}>
                          {currentStep.sum}
                        </span>
                      </div>
                    )}
                  </div>

                  {/* Thanh Progress so sánh với X */}
                  <div className="mt-4">
                    <div className="w-full h-3 bg-slate-200 rounded-full overflow-hidden flex">
                      {currentStep && targetX > 0 && (
                        <div 
                          className={`h-full transition-all duration-300 ease-out ${
                            currentStep.sum === targetX ? 'bg-green-500' : 
                            currentStep.sum > targetX ? 'bg-red-500' : 'bg-blue-500'
                          }`}
                          style={{ width: `${Math.min(100, (currentStep.sum / targetX) * 100)}%` }}
                        />
                      )}
                    </div>
                  </div>
                </div>
              </div>

              {/* Cột theo dõi Code C++ */}
              <div className="bg-[#1e1e1e] border border-slate-800 rounded-xl shadow-lg flex flex-col relative overflow-hidden h-full min-h-[350px]">
                 <h3 className="text-xs font-bold text-slate-400 uppercase tracking-wider p-3 border-b border-[#333] bg-[#2d2d2d] flex justify-between">
                    Trình theo dõi mã C++
                    {currentStep && currentStep.activeLines && currentStep.activeLines.length > 0 && (
                      <span className="text-blue-400 font-normal normal-case">Dòng: {currentStep.activeLines.join(', ')}</span>
                    )}
                 </h3>
                 <div ref={codeContainerRef} className="p-4 font-mono text-sm overflow-auto text-[#d4d4d4] flex-1 leading-relaxed custom-scrollbar">
                    {cppCode.map((line, idx) => {
                      const lineNum = idx + 1;
                      const isActive = currentStep?.activeLines?.includes(lineNum);
                      return (
                        <div key={idx} data-line={lineNum} className={`flex rounded transition-colors duration-200 ${isActive ? 'bg-[#062f4a] border-l-2 border-blue-500' : 'border-l-2 border-transparent'}`}>
                           <div className="w-8 flex-shrink-0 text-slate-600 text-right pr-3 select-none">{lineNum}</div>
                           <div className="flex-1 whitespace-pre">
                             {renderCodeLine(line)}
                           </div>
                           {isActive && <div className="pr-2 text-blue-500 animate-pulse">◀</div>}
                        </div>
                      )
                    })}
                 </div>
              </div>
            </div>

            {/* Cột hiển thị Kết quả (Dưới cùng) */}
            <div className="bg-white border border-slate-200 rounded-xl p-4 shadow-sm flex flex-col min-h-[160px]">
               <h3 className="text-sm font-bold text-slate-500 uppercase tracking-wider mb-3 flex items-center gap-2">
                 Kết quả hợp lệ (sum == {targetX})
               </h3>
               <div className="flex-1 overflow-y-auto bg-slate-50 rounded-lg p-3 border border-slate-100">
                  {currentStep && currentStep.valid.length > 0 ? (
                    <div className="flex flex-wrap gap-2">
                      {currentStep.valid.map((combo, idx) => (
                        <div key={idx} className="bg-white px-4 py-2 rounded-md shadow-sm border border-green-200 flex text-slate-700 font-mono items-center gap-2 animate-bounce-in">
                          <span className="text-green-500 font-bold">#{idx + 1}</span>
                          <span>{"{"} {combo.join(", ")} {"}"}</span>
                        </div>
                      ))}
                    </div>
                  ) : (
                    <div className="h-full flex items-center justify-center text-slate-400 italic text-sm">
                      Chưa tìm thấy cấu hình nào...
                    </div>
                  )}
               </div>
            </div>
          </div>
        </div>

      </div>
      
      {/* Footer Info */}
      <div className="mt-8 text-center text-slate-600 text-sm max-w-2xl relative z-10 font-medium">
        <p>Minh họa thuật toán Quay lui (Backtracking). Số liệu được xử lý bằng cách lọc số dương và sắp xếp tăng dần để dễ dàng loại bỏ trùng lặp và in ra mảng theo thứ tự không giảm.</p>
      </div>

      <style dangerouslySetInnerHTML={{__html: `
        /* Các style cũ */
        @keyframes bounce-in {
          0% { transform: scale(0.3); opacity: 0; }
          50% { transform: scale(1.05); opacity: 1; }
          100% { transform: scale(1); opacity: 1; }
        }
        .animate-bounce-in {
          animation: bounce-in 0.3s cubic-bezier(0.175, 0.885, 0.32, 1.275) forwards;
        }
        .custom-scrollbar::-webkit-scrollbar {
          width: 8px; height: 8px;
        }
        .custom-scrollbar::-webkit-scrollbar-track {
          background: #1e1e1e; 
        }
        .custom-scrollbar::-webkit-scrollbar-thumb {
          background: #4b5563; border-radius: 4px;
        }
        .custom-scrollbar::-webkit-scrollbar-thumb:hover {
          background: #6b7280; 
        }
        
        /* STYLE MỚI: Hiệu ứng Nền Động (Dynamic Background) */
        .bg-animate {
          background: linear-gradient(-45deg, #f8fafc, #f1f5f9, #e0f2fe, #dbeafe);
          background-size: 400% 400%;
          animation: gradientBG 15s ease infinite;
        }
        @keyframes gradientBG {
          0% { background-position: 0% 50%; }
          50% { background-position: 100% 50%; }
          100% { background-position: 0% 50%; }
        }
        
        /* STYLE MỚI: Floating Particles (Các hạt bay lơ lửng) */
        .circles {
          position: absolute;
          top: 0; left: 0; width: 100%; height: 100%;
          overflow: hidden; pointer-events: none; z-index: 0;
          margin: 0; padding: 0;
        }
        .circles li {
          position: absolute; display: block; list-style: none;
          width: 20px; height: 20px; background: rgba(59, 130, 246, 0.15); /* Màu xanh blue-500 trong suốt */
          animation: animate-up 25s linear infinite; bottom: -150px;
        }
        .circles li:nth-child(1) { left: 25%; width: 80px; height: 80px; animation-delay: 0s; }
        .circles li:nth-child(2) { left: 10%; width: 20px; height: 20px; animation-delay: 2s; animation-duration: 12s; }
        .circles li:nth-child(3) { left: 70%; width: 20px; height: 20px; animation-delay: 4s; }
        .circles li:nth-child(4) { left: 40%; width: 60px; height: 60px; animation-delay: 0s; animation-duration: 18s; }
        .circles li:nth-child(5) { left: 65%; width: 20px; height: 20px; animation-delay: 0s; }
        .circles li:nth-child(6) { left: 75%; width: 110px; height: 110px; animation-delay: 3s; }
        .circles li:nth-child(7) { left: 35%; width: 150px; height: 150px; animation-delay: 7s; }
        .circles li:nth-child(8) { left: 50%; width: 25px; height: 25px; animation-delay: 15s; animation-duration: 45s; }
        .circles li:nth-child(9) { left: 20%; width: 15px; height: 15px; animation-delay: 2s; animation-duration: 35s; }
        .circles li:nth-child(10) { left: 85%; width: 150px; height: 150px; animation-delay: 0s; animation-duration: 11s; }
        
        @keyframes animate-up {
          0% { transform: translateY(0) rotate(0deg); opacity: 1; border-radius: 0; }
          100% { transform: translateY(-1000px) rotate(720deg); opacity: 0; border-radius: 50%; }
        }
      `}} />
    </div>
  );
}