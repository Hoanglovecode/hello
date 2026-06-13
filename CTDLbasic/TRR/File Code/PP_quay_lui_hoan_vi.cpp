/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ CÁC HOÁN VỊ CỦA TẬP N PHẦN TỬ (QUAY LUI)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các cấu hình hoán vị của tập hợp gồm N phần tử {1, 2, ..., n} 
 *   sử dụng phương pháp quay lui (Backtracking). 
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương N từ bàn phím.
 *   - Output: 
 *     + Liệt kê các hoán vị được đánh số thứ tự từ 1 đến N! (N giai thừa).
 *     + Dòng cuối cùng in tổng số hoán vị tìm được.
 * 
 * Ví dụ (n = 3):
 *   - Input: 3
 *   - Output:
 *     Liệt kê các hoán vị bằng phương pháp quay lui:
 *     1: 1 2 3 
 *     2: 1 3 2 
 *     3: 2 1 3 
 *     4: 2 3 1 
 *     5: 3 1 2 
 *     6: 3 2 1 
 *     Tổng số hoán vị: 6
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int x[105];
bool used[105];
int cnt = 0;

void out() {
    cnt++;
    cout << cnt << ": ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void try_hoanvi(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = true;
            if (i == n) {
                out();
            } else {
                try_hoanvi(i + 1);
            }
            used[j] = false;
        }
    }
}

int main() {
    cout << "Nhập n: ";
    if (!(cin >> n)) return 0;
    memset(used, false, sizeof(used));
    cout << "Liệt kê các hoán vị bằng phương pháp quay lui:\n";
    try_hoanvi(1);
    cout << "Tổng số hoán vị: " << cnt << endl;
    return 0;
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui sinh hoán vị:
 * - Ý tưởng: Điền lần lượt các số từ vị trí 1 đến n sao cho mỗi số từ 1 đến n chỉ xuất hiện đúng một lần.
 * - Cơ chế dùng mảng đánh dấu:
 *   + Dùng mảng boolean `used[]` toàn cục để biết số nào đã được chọn ở các bước trước.
 *   + Tại vị trí thứ i, thử gán x[i] = j (với j từ 1 đến n). Nếu `!used[j]` (chưa dùng j), gán x[i] = j và đánh dấu `used[j] = true`.
 *   + Đệ quy: Nếu i == n thì in kết quả ra, ngược lại gọi đệ quy try_hoanvi(i + 1).
 *   + Quay lui: Sau khi đệ quy xong, trả lại trạng thái `used[j] = false` để nhánh khác có thể dùng lại số j.
 */
