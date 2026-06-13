/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * TÌM NGHIỆM NGUYÊN DƯƠNG CỦA PHƯƠNG TRÌNH X1 + X2 + ... + XM = N (QUAY LUI)
 * 
 * Mô tả bài toán:
 *   Tìm tất cả các nghiệm nguyên dương (xi >= 1 với mọi i = 1..m) 
 *   của phương trình tổng:
 *     x1 + x2 + ... + xm = n
 *   sử dụng phương pháp quay lui (Backtracking).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: 
 *     + Nhập tổng n (ví dụ: 5).
 *     + Nhập số nghiệm m (ví dụ: 3).
 *   - Output: 
 *     + Liệt kê các bộ nghiệm nguyên dương thỏa mãn cùng số thứ tự.
 * 
 * Ví dụ (n = 5, m = 3):
 *   - Input:
 *     Nhap tong n: 5
 *     Nhap so nghiem: 3
 *   - Output:
 *     1: 1 1 3 
 *     2: 1 2 2 
 *     3: 1 3 1 
 *     4: 2 1 2 
 *     5: 2 2 1 
 *     6: 3 1 1 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int count =0;

void pb( int a[], int pos, int n, int m){
    if( pos == m + 1 ){
        int sum = 0;
        for( int i=1; i<=m; i++) sum+=a[i];
        if( sum == n){
            count +=1;
            printf("%d: ", count);
            for( int i=1; i<=m; i++) printf("%d ", a[i]);
            printf("\n");
        }
        return;
    }

    for( int i=1; i<=n; i++){
        a[pos] = i;
        pb( a, pos+1, n, m);
    }
}

int main() {
    int n,m;
    printf("Nhap tong n: ");
    scanf("%d", &n);
    printf("Nhap so nghiem: ");
    scanf("%d", &m);
    
    int a[m + 1];
    pb(a,1,n,m);
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui tìm nghiệm nguyên dương x1 + ... + xm = n:
 * - Ý tưởng: Thử từng giá trị cho m nghiệm a[1] đến a[m]. Vì là nghiệm nguyên dương nên mỗi a[pos] có thể nhận giá trị từ 1 đến n.
 * - Cơ chế đệ quy:
 *   + Tại vị trí pos, chạy vòng lặp i từ 1 đến n, gán a[pos] = i rồi đệ quy gọi pb(a, pos + 1, n, m).
 *   + Khi gán xong cả m nghiệm (pos == m + 1), tính tổng các phần tử đã chọn.
 *   + Nếu tổng đúng bằng n, in bộ nghiệm ra màn hình và tăng biến đếm.
 *   + Nhánh đệ quy tự động quay lui sau khi return để tìm cấu hình khác.
 */
