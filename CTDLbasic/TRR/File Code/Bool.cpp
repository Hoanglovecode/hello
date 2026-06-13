/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LẬP BẢNG CHÂN TRỊ BIỂU THỨC BOOLE (TRUTH TABLE GENERATOR)
 * 
 * Mô tả bài toán:
 *   Nhập vào một số lượng biến n (ví dụ n = 3 ứng với các biến x, y, z)
 *   và một biểu thức Boole. Chương trình sẽ sinh bảng chân trị hoàn chỉnh
 *   của biểu thức đó.
 * 
 * Ký hiệu toán tử trong biểu thức Boole:
 *   - Phép HOẶC (OR): '+' (ví dụ: x + y)
 *   - Phép VÀ (AND): '*' hoặc viết liền (ví dụ: x*y hoặc xy)
 *   - Phép PHỦ ĐỊNH (NOT): '-' đi liền sau biến hoặc biểu thức (ví dụ: x- là NOT x, (x+y)- là NOT (x OR y))
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số lượng biến (1-10)
 *     + Nhập biểu thức Boole (ví dụ: (x+y)-z )
 *   - Output:
 *     + Bảng chân trị hiển thị tất cả tổ hợp giá trị của các biến và kết quả F.
 * 
 * Ví dụ:
 *   - Nhập số lượng biến (1-10): 3
 *   - Nhập biểu thức Boole: (x+y)-z
 *   - Kết quả bảng chân trị:
 *     +-------+-------+-------+-------+
 *     |   x   |   y   |   z   |   F   |
 *     +-------+-------+-------+-------+
 *     |   0   |   0   |   0   |   0   |
 *     |   0   |   0   |   1   |   0   |
 *     |   0   |   1   |   0   |   0   |
 *     |   0   |   1   |   1   |   1   |
 *     |   1   |   0   |   0   |   0   |
 *     |   1   |   0   |   1   |   1   |
 *     |   1   |   1   |   0   |   0   |
 *     |   1   |   1   |   1   |   1   |
 *     +-------+-------+-------+-------+
 * 
 * Ví dụ biểu thức khác:
 *   x*y*z- + x*y-*x- + x-*y*z + x-*y-*z-
 * ----------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra một ký tự có phải là biến không (a-z)
bool isVariable(char c) {
    return islower(c);
}

// Hàm lấy độ ưu tiên của toán tử
int getPrecedence(char op) {
    switch (op) {
        case '-': return 3; // NOT (phủ định)
        case '*': return 2; // AND (và)
        case '+': return 1; // OR (hoặc)
    }
    return 0;
}

// Hàm thêm toán tử AND (*) vào những chỗ bị thiếu (xy -> x*y)
string addImplicitAnd(const string& expr) {
    string result = "";
    if (expr.empty()) return result;

    result += expr[0];
    for (size_t i = 1; i < expr.length(); ++i) {
        // Thêm '*' nếu:
        // 1. Ký tự trước là biến và ký tự hiện tại là biến (vd: xy)
        // 2. Ký tự trước là biến và ký tự hiện tại là '(' (vd: x(y+z))
        // 3. Ký tự trước là ')' và ký tự hiện tại là biến (vd: (x+y)z)
        // 4. Ký tự trước là '-' và ký tự hiện tại là '(' (vd: -(x+y))
        // 5. Ký tự trước là ')' và ký tự hiện tại là '('
        if ((isVariable(expr[i-1]) && isVariable(expr[i])) ||
            (isVariable(expr[i-1]) && expr[i] == '(') ||
            (expr[i-1] == ')' && isVariable(expr[i])) ||
            (expr[i-1] == ')' && expr[i] == '(') ) {
            result += '*';
        }
        result += expr[i];
    }
    return result;
}

// Thuật toán Shunting-yard: Chuyển biểu thức trung tố sang hậu tố (postfix)
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";

    for (char token : infix) {
        if (isVariable(token)) {
            postfix += token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else { // Toán tử
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

// Hàm tính giá trị của biểu thức hậu tố
int evaluatePostfix(const string& postfix, const map<char, int>& var_values) {
    stack<int> values;

    for (char token : postfix) {
        if (isVariable(token)) {
            values.push(var_values.at(token));
        } else {
            if (token == '-') { // Toán tử 1 ngôi (NOT)
                if (values.empty()) throw runtime_error("Error! Thieu toan hang cho toan tu NOT.");
                int val = values.top();
                values.pop();
                values.push(!val); // Phủ định
            } else { // Toán tử 2 ngôi (AND, OR)
                if (values.size() < 2) throw runtime_error("Error! Thieu toan hang.");
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                if (token == '+') {
                    values.push(val1 || val2); // OR
                } else if (token == '*') {
                    values.push(val1 && val2); // AND
                }
            }
        }
    }
    if (values.size() != 1) throw runtime_error("Error! Bieu thuc khong hop le");
    return values.top();
}


int main() {
    int num_vars;
    cout << "Nhập số lượng biến (1-10) (vd: 3 cho x,y,z): ";
    cin >> num_vars;
    cin.ignore(); // Xóa bộ đệm

    if (num_vars <= 0 || num_vars > 10) {
        cout << "Số lượng biến không hợp lệ" << endl;
        return 1;
    }

    string expression;
    cout << "Nhap bieu thuc Boole (vd: (x+y)-z ): ";
    getline(cin, expression);

    // Xóa các khoảng trắng
    expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

    vector<char> vars;
    for (int i = 0; i < num_vars; ++i) {
        vars.push_back('x' + i);
    }

    try {
        string processed_expr = addImplicitAnd(expression);
        string postfix_expr = infixToPostfix(processed_expr);

        // In tiêu đề bảng
        cout << "\n+";
        for (int i = 0; i < num_vars; ++i) cout << "-------+";
        cout << "-------+\n|";
        for (char v : vars) cout << "   " << v << "   |";
        cout << "   F   |\n+";
        for (int i = 0; i < num_vars; ++i) cout << "-------+";
        cout << "-------+\n";

        int num_rows = 1 << num_vars; // 2^n
        for (int i = 0; i < num_rows; ++i) {
            map<char, int> current_values;
            cout << "|";
            for (int j = 0; j < num_vars; ++j) {
                // Tạo các tổ hợp 0 và 1
                int val = (i >> (num_vars - 1 - j)) & 1;
                current_values[vars[j]] = val;
                cout << "   " << val << "   |";
            }

            int result = evaluatePostfix(postfix_expr, current_values);
            cout << "   " << result << "   |\n";
        }

        cout << "+";
        for (int i = 0; i < num_vars; ++i) cout << "-------+";
        cout << "-------+\n";

    } catch (const runtime_error& e) {
        cout << "Loi: " << e.what() << endl;
        return 1;
    }

    return 0;
}