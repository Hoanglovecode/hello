/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * SINH CHUỖI NHỊ PHÂN HẠN CHẾ (KHÔNG CHỨA 3 BIT 1 LIÊN TIẾP)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các chuỗi nhị phân độ dài N sao cho 
 *   không có bất kỳ 3 bit 1 nào nằm cạnh nhau (kề nhau liên tiếp) 
 *   bằng phương pháp sinh (Generation Algorithm).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương N từ bàn phím.
 *   - Output: 
 *     + Liệt kê các chuỗi nhị phân thỏa mãn điều kiện theo thứ tự từ điển kèm số thứ tự.
 *     + Dòng cuối cùng in ra tổng số chuỗi nhị phân tìm được.
 * 
 * Ví dụ (n = 4):
 *   - Input: 4
 *   - Output:
 *     Các chuỗi nhị phân không chứa 3 bit 1 liên tiếp:
 *     1: 0000
 *     2: 0001
 *     3: 0010
 *     4: 0011
 *     5: 0100
 *     6: 0101
 *     7: 0110
 *     8: 1000
 *     9: 1001
 *     10: 1010
 *     11: 1011
 *     12: 1100
 *     13: 1101
 *     Tổng số cách xếp: 13
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int ok = 1;
int cnt = 0;

void init() {
    for (int i = 1; i <= n; i++) a[i] = 0;
}

void out() {
    cnt++;
    cout << cnt << ": ";
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}

// Kiểm tra không có 3 bit 1 kề nhau
bool check() {
    for (int i = 1; i <= n - 2; i++) {
        if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 1) return false;
    }
    return true;
}

void next_gen() {
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0) ok = 0;
    else a[i] = 1;
}

int main() {
    cout << "Nhập độ dài chuỗi nhị phân n: ";
    if (!(cin >> n)) return 0;
    
    init();
    cout << "Các chuỗi nhị phân không chứa 3 bit 1 liên tiếp:\n";
    while (ok) {
        if (check()) {
            out();
        }
        next_gen();
    }
    cout << "Tổng số cách xếp: " << cnt << endl;
    return 0;
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh chuỗi nhị phân không chứa 3 bit 1 liên tiếp:
 * - Nguyên lý: Ta sinh tất cả các chuỗi nhị phân độ dài n (từ toàn 0 đến toàn 1) bằng thuật toán sinh kế tiếp thông thường.
 * - Lọc điều kiện: Với mỗi cấu hình sinh ra, hàm `check()` sẽ duyệt chuỗi để kiểm tra xem có 3 ô liên tiếp nào cùng bằng 1 không (`a[i] == 1 && a[i+1] == 1 && a[i+2] == 1`). Nếu có thì bỏ qua, nếu không thì in ra.
 * - Điểm lưu ý: Vòng lặp kiểm tra chỉ chạy đến `n - 2` để tránh vượt quá giới hạn mảng khi truy cập `a[i+2]`.
 */

