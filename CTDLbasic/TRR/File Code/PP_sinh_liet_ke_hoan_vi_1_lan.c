/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * TÌM CẤU HÌNH HOÁN VỊ KẾ TIẾP (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Nhập vào một hoán vị bất kỳ của tập hợp {1, 2, ..., n}, in ra hoán vị kế tiếp 
 *   theo thứ tự từ điển của hoán vị đó (chỉ sinh và in 1 cấu hình tiếp theo).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số nguyên dương N.
 *     + Nhập các phần tử của hoán vị hiện tại (cách nhau bởi dấu cách).
 *   - Output:
 *     + In ra cấu hình nhập vào và cấu hình hoán vị kế tiếp.
 *     + Nếu cấu hình nhập vào đã là cấu hình cuối cùng, chương trình 
 *       sẽ thông báo: "Đây đã là cấu hình cuối cùng".
 * 
 * Ví dụ 1:
 *   - Input:
 *     Nhập n: 3
 *     Nhập các phần tử: 1 3 2
 *   - Output:
 *     Cấu hình nhập vào: 1 3 2 
 *     Cấu hình tiếp theo: 2 1 3 
 * 
 * Ví dụ 2:
 *   - Input:
 *     Nhập n: 3
 *     Nhập các phần tử: 3 2 1
 *   - Output:
 *     Cấu hình nhập vào: 3 2 1 
 *     Cấu hình tiếp theo: Đây đã là cấu hình cuối cùng
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int n, stop;

void out(int a[]){
    int i;
    for(i=1; i<=n; i++) printf("%d ", a[i]);
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void next_gen(int a[]){

    int i = n-1;
    while(a[i] > a[i+1] ) i-=1;

    if(i==0) return;
    int j=n;

    while (a[j] < a[i]) j--;

    swap(&a[i] , &a[j]);

    int l = i+1, r=n;
    while(l<r){
        swap(&a[l], &a[r]);
        l++;
        r--;
    }
}

bool last(int a[]){
    int i, temp=0;
    for(int i=n; i>=1; i--){ temp +=1; if(a[i] != temp) return true;}
    return false;
}

void gen(int a[]){
    printf("Cấu hình nhập vào: ");
    out(a);

    printf("\nCấu hình tiếp theo: ");
    next_gen(a);
    if( last(a) ) printf("Đây đã là cấu hình cuối cùng");
    else out(a); 
    
}

int main(){
    printf("Nhập n: ");
    scanf("%d", &n);
    int a[n+1];
    printf("Nhập các phần tử: ");
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    gen(a);
    
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh hoán vị kế tiếp của cấu hình hiện tại:
 * - Nguyên lý: Từ cấu hình nhập vào, ta sinh ra duy nhất một cấu hình kế tiếp lớn hơn nó kề trước theo thứ tự từ điển.
 * - Các bước tìm hoán vị kế tiếp:
 *   1. Tìm từ phải sang trái vị trí i đầu tiên thỏa mãn `a[i] < a[i+1]`.
 *   2. Tìm tiếp từ cuối dãy ngược lại vị trí j đầu tiên thỏa mãn `a[j] > a[i]`.
 *   3. Tráo đổi (swap) a[i] và a[j].
 *   4. Lật ngược đoạn con từ vị trí `i + 1` đến cuối dãy để đưa đoạn này về tăng dần (cấu hình nhỏ nhất của đoạn đó).
 * - Trường hợp đặc biệt: Nếu dãy ban đầu đã là dãy giảm dần toàn bộ (i = 0), thì đây chính là cấu hình cuối cùng.
 */