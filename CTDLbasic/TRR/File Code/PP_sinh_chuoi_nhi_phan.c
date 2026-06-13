/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ CHUỖI NHỊ PHÂN ĐỘ DÀI N (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các chuỗi nhị phân độ dài N theo thứ tự từ điển 
 *   sử dụng phương pháp sinh (Generation Algorithm).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương N.
 *   - Output: Danh sách các chuỗi nhị phân từ cấu hình đầu tiên (toàn '0') 
 *             đến cấu hình cuối cùng (toàn '1') kèm số thứ tự.
 * 
 * Ví dụ (n = 3):
 *   - Input: 3
 *   - Output:
 *     1: 000
 *     2: 001
 *     3: 010
 *     4: 011
 *     5: 100
 *     6: 101
 *     7: 110
 *     8: 111
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int n, stop, count=1;

void init(char a[]){
    int i;
    for(i=1; i<=n; i++) a[i] = '0';
}

void out(char a[]){
    printf("\n%d: ", count);
    int i;
    for(i=1; i<=n; i++) printf("%c", a[i]);
}

void next_gen(char a[]){
    int i=n; 
    while( i>=1 && a[i] == '1'){
        a[i] = '0';
        i-=1;
    }
    a[i] = '1';
}

bool last(char a[]){
    int i, temp=0;
    for(int i=1; i<=n; i++){if(a[i] != '1') return true;}
    return false;
}

void gen(char a[]){
    init(a); //Khởi tạo
    out(a); //In ra chuỗi đầu tiên tức chuỗi khởi tạo

    while(last(a)){ //Kiểm tra xem đã có phải là dãy cuối cùng chưa
        count+=1;
        next_gen(a);
        out(a); //In ra 
    }
}

int main(){
    printf("Nhap n: ");
    scanf("%d", &n);
    char a[n+1];
    gen(a);
    
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh chuỗi nhị phân:
 * - Cấu hình đầu tiên: Chuỗi toàn '0'. Cấu hình cuối cùng: Chuỗi toàn '1'.
 * - Thuật toán sinh kế tiếp:
 *   + Duyệt từ cuối chuỗi (i = n) về đầu. Nếu gặp '1' thì chuyển thành '0' và lùi tiếp sang trái.
 *   + Khi gặp ký tự '0' đầu tiên, chuyển nó thành '1' rồi dừng.
 * - Điều kiện dừng: Khi chuỗi đã đạt trạng thái toàn '1' (hàm last trả về false).
 */