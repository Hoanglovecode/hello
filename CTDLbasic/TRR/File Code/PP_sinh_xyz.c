/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * TÌM NGHIỆM NGUYÊN KHÔNG ÂM CỦA PHƯƠNG TRÌNH X1 + X2 + ... + XM = N (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Tìm tất cả các nghiệm nguyên không âm (xi >= 0 với mọi i = 1..m) 
 *   của phương trình tổng:
 *     x1 + x2 + ... + xm = n
 *   sử dụng phương pháp sinh (sinh các bộ có giá trị từ 0 đến n trong hệ cơ số n+1 
 *   và lọc ra những bộ có tổng bằng n).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: 
 *     + Nhập tổng n (ví dụ: 3).
 *     + Nhập số nghiệm m (ví dụ: 2).
 *   - Output: 
 *     + Liệt kê các bộ nghiệm nguyên không âm thỏa mãn cùng số thứ tự.
 * 
 * Ví dụ (n = 3, m = 2):
 *   - Input:
 *     Nhap tong n: 3
 *     Nhap so nghiem: 2
 *   - Output:
 *     1: 0 3 
 *     2: 1 2 
 *     3: 2 1 
 *     4: 3 0 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>
int n, m;
long count = 1;
void init(int a[]) {
    for (int i = 1; i <= m; i++) a[i] = 0;
}
void out(int a[]) {
    int sum = 0;
    for (int i = 1; i <= m; i++) sum += a[i];
    if (sum != n) return;
    printf("\n%d: ", count);
    for (int i = 1; i <= m; i++) printf("%d ", a[i]);
    count++;
}
void next_gen(int a[]) {
    int j = m;
    while (j >= 1 && a[j] == n) j--;
    if (j == 0) return;
    a[j] += 1;
    for (int i = j + 1; i <= m; i++) a[i] = 0;
}
bool last(int a[]) {
    for (int i = 1; i <= m; i++)
        if (a[i] != n) return true; 
    return false;
}
void gen(int a[]) {
    init(a);  
    out(a); 
    while (last(a)) {
        next_gen(a);
        out(a); // In ra 
    }
}
int main() {
    printf("Nhap tong n: ");
    scanf("%d", &n);
    printf("Nhap so nghiem: ");
    scanf("%d", &m);
    int a[m + 1];
    gen(a);
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh tìm nghiệm nguyên không âm x1 + ... + xm = n:
 * - Nguyên lý: Vì mỗi biến nhận giá trị từ 0 đến n, ta sinh tất cả các bộ số m phần tử trong hệ cơ số n+1 theo thứ tự từ điển, bắt đầu từ bộ toàn 0 và kết thúc ở bộ toàn n.
 * - Cơ chế sinh kế tiếp:
 *   + Duyệt từ phải sang trái tìm vị trí j đầu tiên chưa đạt giá trị cực đại n (`a[j] != n`).
 *   + Tăng `a[j]` thêm 1 đơn vị, đồng thời reset toàn bộ các vị trí phía sau (từ j+1 đến m) về lại 0.
 * - Lọc điều kiện: Mỗi cấu hình sinh ra sẽ được tính tổng. Nếu tổng đúng bằng n, ta tăng biến đếm và in bộ nghiệm ra.
 */

