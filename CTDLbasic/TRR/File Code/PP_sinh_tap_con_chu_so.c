/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ TẤT CẢ TẬP CON CỦA TẬP CHỮ SỐ N PHẦN TỬ (PHƯƠNG PHÁP SINH)
 * 
 * Mô tả bài toán:
 *   Sinh và liệt kê tất cả các tập con của tập hợp X gồm n phần tử chữ số {1, 2, 3, 4, 5, 6} 
 *   bằng phương pháp sinh.
 *   Chương trình sẽ lặp qua k từ 1 đến n để in các tập con có k phần tử, 
 *   sau đó in thêm tập rỗng.
 *   (Lưu ý: Mặc định trong code gán cứng n = 6).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Không yêu cầu (cố định n = 6).
 *   - Output: 
 *     + Danh sách các tập con có kích thước từ 1 đến 6 (gồm các chữ số {1, 2, 3, 4, 5, 6}) 
 *       và tập rỗng. Các tập con được đánh số thứ tự từ 1 đến 64.
 *     + Dòng cuối cùng in tổng số tập con (kể cả tập rỗng), bằng 2^n = 64.
 * 
 * Ví dụ kết quả chạy (một phần):
 *   Tap con 1 phan tu tu X co 6 phan tu la:
 *   1: 1 
 *   2: 2 
 *   ...
 *   64: Tap rong
 *   Vay co tat ca 64 tap con (bao gom ca tap rong)
 * ----------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

int count = 0;
// Tập X chứa các chữ số
char X[] = {'1', '2', '3', '4', '5', '6'};

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
    count += 1;
    printf("%d: ", count);
    for (int i = 1; i <= k; i++){
        printf("%c ", X[b[i] - 1]);
    }
    printf("\n");
}

void next_gen(int b[], int n, int k){
    int j = k;
    while (j > 0 && b[j] == n - k + j) j -= 1;
    b[j]++;
    for (int i = j + 1; i <= k; i++) b[i] = b[i - 1] + 1;
}

void pp_sinh(int b[], int n, int k){
    init(b, k);
    out(b, k);
    while (last(b, n, k)){
        next_gen(b, n, k);
        out(b, k);
    }
}

int main(){
    int n = 6;
    // Khai báo mảng b có kích thước n + 1 để tránh lỗi tràn chỉ số (truy cập b[n] khi k = n)
    int b[n + 1]; 
    printf("Liet ke tap con cua tap hop chu so: \n\n");

    for (int k = 1; k <= n; k++){
        printf("Tap con %d phan tu tu X co %d phan tu la:\n", k, n);
        pp_sinh(b, n, k); // k phần tử
    }
    
    count += 1;
    printf("%d: Tap rong\n\n", count);

    printf("Vay co tat ca %d tap con (bao gom ca tap rong)", count);
    return 0;
}
