/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * TÌM NGHIỆM NGUYÊN CỦA PHƯƠNG TRÌNH X1 + X2 + ... + XM = K (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Tìm tất cả các nghiệm nguyên không âm hoặc nguyên dương 
 *   của phương trình tổng:
 *     x1 + x2 + ... + xm = k
 *   sử dụng phương pháp sinh trực tiếp các cấu hình kế tiếp theo thứ tự từ điển.
 * 
 * Áp dụng giải quyết câu C của đề bài:
 *   Tìm tập S = {(x1, x2, x3, x4) | x1 + x2 + x3 + x4 = 12, xi > 0, i = 1..4}
 *   Đây là bài toán tìm nghiệm nguyên dương (xi >= 1) với m = 4, k = 12.
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: 
 *     + Nhập tổng k (ví dụ: 12).
 *     + Nhập số biến m (ví dụ: 4).
 *     + Chọn loại nghiệm: 1 (nguyên dương, xi >= 1) hoặc 2 (nguyên không âm, xi >= 0).
 *   - Output: 
 *     + Liệt kê các bộ nghiệm nguyên thỏa mãn cùng số thứ tự.
 * 
 * Ví dụ (k = 12, m = 4, nghiệm nguyên dương):
 *   - Input:
 *     Nhap tong k: 12
 *     Nhap so bien m: 4
 *     Chon loai nghiem (1: nguyen duong, 2: nguyen khong am): 1
 *   - Output:
 *     1: (1, 1, 1, 9)
 *     2: (1, 1, 2, 8)
 *     ...
 *     165: (9, 1, 1, 1)
 * ----------------------------------------------------
- Giả sử xi là túi đựng số i,tổng 4 cái túi bên trong đó chứa những viên bi không phân biệt,đồng chất thỏa mãn tổng số bi cả 4 túi là 12.
Ta áp dụng phia pháp chia kẹo euler,đặt 3 vách ngăn vào khe , giữa 12 viên bi tạo thành 11 vách ngăn do đó t chọn 3 vách ngăn từ 11 vách ngăn đó có C(3¦11) cách.
Do đó số nghiệm nguyên dương là C(3¦11) = 165 nghiệm

 */
#include <stdio.h>
#include <stdbool.h>
int k, m, min_val = 1;
long count = 1;
void init(int a[]) {
    for (int i = 1; i < m; i++) {
        a[i] = min_val;
    }
    a[m] = k - (m - 1) * min_val;
}
void out(int a[]) {
    printf("%ld: (", count++);
    for (int i = 1; i <= m; i++) {
        printf("%d", a[i]);
        if (i < m) printf(", ");
    }
    printf(")\n");
}
bool next_gen(int a[]) {
    int suffix_sum = a[m];
    int j = m - 1;   
    while (j >= 1) {
        if (suffix_sum - 1 >= (m - j) * min_val) {
            break;
        }
        suffix_sum += a[j];
        j--;
    }
    if (j == 0) return false;
    a[j]++;
    for (int i = j + 1; i < m; i++) {
        a[i] = min_val;
    }
    int used_sum = 0;
    for (int i = 1; i < m; i++) {
        used_sum += a[i];
    }
    a[m] = k - used_sum;
    return true;
}
int main() {
    printf("Nhap tong: ");
    if (scanf("%d", &k) != 1) return 1;
    printf("Nhap so bien: ");
    if (scanf("%d", &m) != 1) return 1;
    if (k < m * min_val) {
        printf("Khong co nghiem nguyen duong nao thoa man dieu kien!\n");
        return 0;
    }
    int a[m + 1];
    printf("\nCac nghiem tim duoc:\n");
    init(a);
    out(a);
    while (next_gen(a)) {
        out(a);
    }
    printf("\nTong so nghiem: %ld\n", count - 1);
    return 0;
}

/*
 * # TRẢ LỜI: Trình bày phương pháp sinh toàn bộ số phần tử của S (x1 + x2 + x3 + x4 = 12, xi > 0, i = 1..4):
 * - Nguyên lý: Sử dụng phương pháp sinh trực tiếp các cấu hình kế tiếp theo thứ tự từ điển (không cần duyệt qua toàn bộ rồi lọc, tối ưu hóa bộ nhớ và thời gian).
 * - Cấu hình bắt đầu: (1, 1, 1, 9) (Bộ nghiệm nguyên dương có thứ tự từ điển nhỏ nhất).
 * - Cấu hình kết thúc: (9, 1, 1, 1) (Bộ nghiệm nguyên dương có thứ tự từ điển lớn nhất).
 * - Thuật toán sinh cấu hình kế tiếp từ cấu hình hiện tại a = (a1, a2, a3, a4):
 *   1. Tìm vị trí j phải nhất (chạy từ j = 3 xuống 1) sao cho tổng các phần tử phía sau j trừ đi 1 vẫn lớn hơn hoặc bằng số lượng phần tử phía sau j.
 *      Công thức: (a[j+1] + ... + a[4]) - 1 >= 4 - j (hoặc đơn giản là tổng các phần tử phía sau > 4 - j).
 *   2. Nếu j == 0: Kết thúc thuật toán (đã đạt cấu hình cuối cùng).
 *   3. Nếu tìm thấy j thỏa mãn:
 *      * Tăng a[j] lên 1 đơn vị: a[j] = a[j] + 1.
 *      * Reset tất cả các phần tử từ j + 1 đến 3 về giá trị tối thiểu là 1: a[i] = 1 (với i = j + 1 -> 3).
 *      * Tính giá trị cho phần tử cuối cùng a[4] bằng phần tổng còn lại: a[4] = 12 - (a[1] + a[2] + a[3]).
 */
/*
 * # TRẢ LỜI: Câu b) Cho nghiệm (3, 4, 1, 4). Hãy xác định nghiệm kế tiếp theo thứ tự từ điển:
 * - Nghiệm hiện tại: a = (3, 4, 1, 4) với k = 12 và m = 4.
 * - Quy trình xác định nghiệm kế tiếp bằng phương pháp sinh:
 *   1. Xét từ phải qua trái (từ vị trí cuối cùng), ta tìm vị trí j đầu tiên thỏa mãn:
 *      Tổng các phần tử phía sau j trừ đi 1 vẫn lớn hơn hoặc bằng số lượng phần tử phía sau j.
 *      - Xét j = 3 (phần tử a[3] = 1): Phần tử phía sau nó là a[4] = 4.
 *        Tổng phía sau là 4, lớn hơn số lượng phần tử phía sau (4 - 3 = 1). Vậy chọn j = 3.
 *   2. Tăng a[j] lên 1 đơn vị: a[3] = a[3] + 1 = 1 + 1 = 2.
 *   3. Reset các phần tử phía sau từ j + 1 đến m - 1 về giá trị cực tiểu là 1 (không có phần tử nào vì j + 1 = 4).
 *   4. Gán phần giá trị còn lại cho phần tử cuối cùng a[4]:
 *      a[4] = 12 - (a[1] + a[2] + a[3]) = 12 - (3 + 4 + 2) = 3.
 *   => Kết quả nghiệm kế tiếp theo thứ tự từ điển là: (3, 4, 2, 3).
 */
