/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ TẬP CON K PHẦN TỬ CỦA TẬP N PHẦN TỬ (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các tập con gồm k phần tử từ tập hợp ban đầu gồm n 
 *   phần tử {a, b, c, d, ...} (với n phần tử tương ứng ký tự 'a' đến 'a'+n-1) 
 *   theo phương pháp sinh (Generation Algorithm).
 *   (Lưu ý: Mặc định trong code gán cứng n = 6 và k = 3).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Không yêu cầu (cố định n = 6, k = 3).
 *   - Output: Danh sách các tập con 3 phần tử (được biểu diễn dưới dạng chữ cái) 
 *             sinh ra từ tập {a, b, c, d, e, f} được đánh số thứ tự từ 1 đến 20.
 * 
 * Ví dụ kết quả chạy:
 *   Liet ke tap con k phan tu tu n phan tu: 
 * 
 *   1: a b c 
 *   2: a b d 
 *   ...
 *   20: d e f 
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int count = 0;

void init(int b[], int k){
    for (int i = 1; i <= k; i++) b[i] = i;
}

bool last(int b[], int n, int k) {
    for (int i = 1; i <= k; i++){
        if (b[i] != n - k + i) return true;
    }
    return false;
}

void out(int b[], int k){
    count +=1;
    printf("%d: ", count);
    for (int i = 1; i <= k; i++){
        char c = 'a' + b[i] - 1;
        printf("%c ", c);
    }
    printf("\n");
}

void next_gen(int b[], int n, int k){
    int j = k;
    while (j > 0 && b[j] == n - k + j) j-=1;
    b[j]++;
    for (int i = j + 1; i <= k; i++) b[i] = b[i - 1] + 1;
}

void pp_sinh(int b[], int n, int k){
    init(b, k);
    out(b, k);
    while ( last(b, n, k) ){
        next_gen(b, n, k);
        out(b, k);
    }
}

int main(){
    int n = 6, k = 3;
    int b[n];
    printf("Liet ke tap con k phan tu tu n phan tu: \n\n");

    pp_sinh(b, n, k); //k phần tử
}

/*
 * # TRẢ LỜI: Giải thích phương pháp sinh tổ hợp chập k của n (trong code đặt tên là tập chỉnh hợp):
 * - Ý tưởng: Biểu diễn tập con dưới dạng dãy số tăng dần b[1] < b[2] < ... < b[k]. Do tăng dần nên giá trị cực đại của phần tử ở vị trí i là `n - k + i`.
 * - Cơ chế sinh kế tiếp:
 *   + Duyệt từ phải qua trái để tìm phần tử b[j] đầu tiên chưa đạt giới hạn cực đại (`b[j] != n - k + j`).
 *   + Tăng b[j] lên 1 đơn vị (`b[j]++`), sau đó điền các phần tử phía sau tăng dần liên tiếp từ b[j] (`b[i] = b[i-1] + 1` với i chạy từ j+1 đến k).
 * - Điểm dừng: Khi mọi phần tử đều đạt giới hạn cực đại (b[i] == n - k + i với mọi i).
 */

