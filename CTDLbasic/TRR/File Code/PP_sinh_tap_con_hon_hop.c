/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ TẤT CẢ TẬP CON CỦA TẬP HỖN HỢP CHỮ VÀ SỐ N PHẦN TỬ (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các tập con của tập hợp X gồm n phần tử hỗn hợp chữ và số {a, 1, b, 2, c, 3} 
 *   bằng phương pháp sinh.
 *   Chương trình sẽ lặp qua k từ 1 đến n để in các tập con có k phần tử, 
 *   sau đó in thêm tập rỗng.
 *   (Lưu ý: Mặc định trong code gán cứng n = 6).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Không yêu cầu (cố định n = 6).
 *   - Output: 
 *     + Danh sách các tập con có kích thước từ 1 đến 6 (gồm các phần tử {a, 1, b, 2, c, 3}) 
 *       và tập rỗng. Các tập con được đánh số thứ tự từ 1 đến 64.
 *     + Dòng cuối cùng in tổng số tập con (kể cả tập rỗng), bằng 2^n = 64.
 * 
 * Ví dụ kết quả chạy (một phần):
 *   Tap con 1 phan tu tu X co 6 phan tu la:
 *   1: a 
 *   2: 1 
 *   ...
 *   64: Tap rong
 *   Vay co tat ca 64 tap con (bao gom ca tap rong)
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

int count = 0;
// Tập X chứa hỗn hợp chữ cái và chữ số
char X[] = {'a', '1', 'b', '2', 'c', '3'};

void init(int b[], int k){
    for (int i = 1; i <= k; i++) b[i] = i;
}

bool last(int b[], int n, int k) {
    for (int i = 1; i <= k; i++){
        if (b[i] != n - k + i) return true;
    }
    return false;
}

void out(int b[], int k){
    count += 1;
    printf("%d: ", count);
    for (int i = 1; i <= k; i++){
        printf("%c ", X[b[i] - 1]);
    }
    printf("\n");
}

void next_gen(int b[], int n, int k){
    int j = k;
    while (j > 0 && b[j] == n - k + j) j -= 1;
    b[j]++;
    for (int i = j + 1; i <= k; i++) b[i] = b[i - 1] + 1;
}

void pp_sinh(int b[], int n, int k){
    init(b, k);
    out(b, k);
    while (last(b, n, k)){
        next_gen(b, n, k);
        out(b, k);
    }
}

int main(){
    int n = 6;
    // Khai báo mảng b có kích thước n + 1 để tránh lỗi tràn chỉ số (truy cập b[n] khi k = n)
    int b[n + 1]; 
    printf("Liet ke tap con cua tap hop hon hop: \n\n");

    for (int k = 1; k <= n; k++){
        printf("Tap con %d phan tu tu X co %d phan tu la:\n", k, n);
        pp_sinh(b, n, k); // k phần tử
    }
    
    count += 1;
    printf("%d: Tap rong\n\n", count);

    printf("Vay co tat ca %d tap con (bao gom ca tap rong)", count);
    return 0;
}
/*
-Số xâu có độ dài n trong tập X là:12n
-Th1:Xâu có độ dài n nhưng không chứa chữ số nào:Ta có 6n  xâu
-Th2:Xâu có độ dài n chứa duy nhất 1 chữ số:
+Chọn 1 trong n vị trí để chèn số đó vào xâu có C(1¦n)  cách
+Chọn 1 trong 6 số có :6 cách
+n-1 vị trí còn lại mỗi vị trí có 6 cách chọn chữ cái
=>Tổng cộng có C(1¦n).6.6n-1cách
-Th3:Xâu có độ dài n chứ duy nhất 2 chữ số:
+Chọn 2 trong n vị trí chèn số đó vào xâu có C(2¦n) cách
+Mỗi vị trí điền số có đều có 6 cách
+n-2 vị trí còn lại mỗi vị trí có 6 cách chọn chữ cái
=>Tổng cộng có C(2¦n)  .62 .6n-2
Áp dụng nguyên lý bù trừ
Vậy số xâu thõa mãn yêu cầu đề bài là 12n - C(1¦n).6.6n-1 - C(2¦n)  .62 .6n-2
*/
