/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ CHỈNH HỢP KHÔNG LẶP CHẬP K CỦA N PHẦN TỬ (QUAY LUI)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các chỉnh hợp không lặp chập k của tập hợp N phần tử 
 *   {1, 2, ..., n} theo phương pháp quay lui (Backtracking). Các phần tử trong 
 *   mỗi cấu hình là phân biệt và thứ tự sắp xếp có ý nghĩa.
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập 2 số nguyên dương n và k (nhập n trước, k sau, với 1 <= k <= n <= 20).
 *   - Output: In ra các chỉnh hợp không lặp chập k của n phần tử trên từng dòng.
 * 
 * Ví dụ (n = 3, k = 2):
 *   - Input: 3 2
 *   - Output:
 *     1 2 
 *     1 3 
 *     2 1 
 *     2 3 
 *     3 1 
 *     3 2 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n,k;
int a[21];

void cal(int pos){
    if (pos>k){
        for (int i=1; i<=k; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1; i<=n; i++){
        int check=0;
        if (pos>1){
            for (int h=1;  h<= pos-1; h++){  //Kiem tra xem so do da xuat hien chua
                if (a[h]==i){
                    check=1;
                    break;
                }
            }
        }
        if (check==1) continue;
        a[pos]=i;
        cal(pos+1);
    }
}

int main(){
    printf("Nhap to hop k chap n (nhap n roi k): ");
    scanf("%d%d", &n, &k);
    cal(1);
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui sinh chỉnh hợp không lặp chập k của n:
 * - Ý tưởng: Điền lần lượt các số từ vị trí 1 đến k. Vì là chỉnh hợp nên thứ tự quan trọng (ví dụ 1 2 khác 2 1), nhưng không được trùng số đã chọn.
 * - Cơ chế đệ quy:
 *   + Tại vị trí pos, thử gán a[pos] = i chạy từ 1 đến n.
 *   + Kiểm tra trùng lặp: Duyệt qua các vị trí đứng trước (từ 1 đến pos-1), nếu thấy i đã được dùng (check == 1) thì bỏ qua (continue).
 *   + Nếu chưa dùng, gán a[pos] = i và gọi đệ quy cal(pos + 1).
 *   + Khi pos > k, ta có cấu hình hoàn chỉnh, in kết quả và quay lui.
 */