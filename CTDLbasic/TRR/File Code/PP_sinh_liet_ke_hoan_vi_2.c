/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ CÁC HOÁN VỊ KẾ TIẾP TỪ CẤU HÌNH CHO TRƯỚC (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Nhập vào một cấu hình hoán vị bất kỳ của tập hợp {1, 2, ..., n}, sinh và liệt kê 
 *   lần lượt tất cả các cấu hình hoán vị tiếp theo theo thứ tự từ điển cho đến khi 
 *   gặp cấu hình cuối cùng (được sắp xếp giảm dần n, n-1, ..., 1).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số nguyên dương N.
 *     + Nhập các phần tử của hoán vị hiện tại (cách nhau bởi dấu cách).
 *   - Output:
 *     + Danh sách các cấu hình hoán vị kế tiếp (từ hoán vị sau hoán vị nhập vào cho 
 *       đến cấu hình cuối cùng) kèm số thứ tự.
 * 
 * Ví dụ:
 *   - Input:
 *     Nhập n: 3
 *     Nhập các phần tử: 1 3 2
 *   - Output:
 *     1: 2 1 3 
 *     2: 2 3 1 
 *     3: 3 1 2 
 *     4: 3 2 1 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int n, stop, count = 0;

void out(int a[]){
    count++;
    printf("\n%d: ", count);
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
    while( last(a) ){
        next_gen(a);
        out(a); 
    }
    
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
 * # TRẢ LỜI: Giải thích phương pháp sinh hoán vị kế tiếp từ cấu hình cho trước:
 * - Nguyên lý: Khác với việc sinh từ đầu (từ dãy tăng dần), chương trình này nhận vào một cấu hình hoán vị bất kỳ, sau đó liên tục sinh ra các cấu hình lớn hơn tiếp theo cho đến khi đạt cấu hình cuối cùng (dãy giảm dần).
 * - Các bước tìm hoán vị kế tiếp tại mỗi vòng lặp:
 *   1. Tìm từ phải sang trái vị trí i đầu tiên thỏa mãn `a[i] < a[i+1]`.
 *   2. Tìm tiếp từ cuối dãy ngược lại vị trí j đầu tiên thỏa mãn `a[j] > a[i]`.
 *   3. Tráo đổi (swap) a[i] và a[j].
 *   4. Lật ngược đoạn con từ vị trí `i + 1` đến cuối dãy để đưa đoạn này về tăng dần (nhỏ nhất).
 */