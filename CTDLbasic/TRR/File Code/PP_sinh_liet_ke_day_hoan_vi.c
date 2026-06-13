/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ TẤT CẢ HOÁN VỊ CỦA DÃY SỐ (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các hoán vị của tập hợp gồm N phần tử {1, 2, ..., n}
 *   theo thứ tự từ điển tăng dần bằng phương pháp sinh (Generation Algorithm).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương N.
 *   - Output: Danh sách các hoán vị từ cấu hình đầu tiên (1 2 ... n) 
 *             đến cấu hình cuối cùng (n n-1 ... 1) kèm số thứ tự.
 * 
 * Ví dụ (n = 3):
 *   - Input: 3
 *   - Output:
 *     1: 1 2 3 
 *     2: 1 3 2 
 *     3: 2 1 3 
 *     4: 2 3 1 
 *     5: 3 1 2 
 *     6: 3 2 1 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int n, stop, count=1;

void init(int a[]){
    int i;
    for(i=1; i<=n; i++) a[i] = i;
}

void out(int a[]){
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
    init(a);
    out(a);

    while(last(a)){
        count+=1;
        next_gen(a);
        out(a); 
    }
}

int main(){
    printf("Nhap n: ");
    scanf("%d", &n);
    int a[n+1];
    gen(a);
    
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh hoán vị kế tiếp:
 * - Nguyên lý: Bắt đầu từ cấu hình tăng dần {1, 2, ..., n} và sinh dần đến cấu hình giảm dần {n, n-1, ..., 1}.
 * - Các bước tìm hoán vị kế tiếp:
 *   1. Tìm từ phải qua trái phần tử a[i] đầu tiên nhỏ hơn phần tử đứng sau nó: `a[i] < a[i+1]`.
 *   2. Tìm từ cuối dãy ngược lại phần tử a[j] đầu tiên lớn hơn a[i]: `a[j] > a[i]`.
 *   3. Tráo đổi (swap) a[i] và a[j].
 *   4. Lật ngược thứ tự đoạn từ vị trí `i + 1` đến cuối dãy để đưa đoạn này về tăng dần (cấu hình nhỏ nhất có thể).
 */