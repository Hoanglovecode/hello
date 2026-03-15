/*
Bài 78. Viết chương trình có sử dụng hàm để nhập ma trận A cấp nxn (với n nhập từ
bàn phím):
a. Xuất ma trận A ra màn hình
b. Tìm ma trận nghịch đảo của ma trận A 
*/
#include <stdio.h>
#define N 10   // Kích thước tối đa cho ma trận (n <= N)
// Hàm nhập ma trận A kích thước n x n
void nhap(double a[N][N], int n) {
    // Thông báo kích thước ma trận cho người dùng
    printf("Nhap ma tran A (%dx%d):\n", n, n);
    // Duyệt từng phần tử và đọc từ bàn phím
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]); // %lf để đọc double
}


// Hàm in ma trận a (n x n) theo định dạng cố định
void in(double a[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            // %8.4lf: rộng 8 ký tự, 4 chữ số thập phân — đẹp khi in ma trận
            printf("%8.4lf ", a[i][j]);
        printf("\n");
    }
}


/*
 Hàm nghichdao:
   - input:  a (ma trận A, kích thước n x n)
   - output: inverse (ma trận nghịch đảo A^{-1}, nếu khả nghịch)
   - trả về: 1 nếu thành công (có nghịch đảo), 0 nếu ma trận không khả nghịch
*/
int nghichdao(double a[N][N], double inverse[N][N], int n) {
    // Tạo ma trận mở rộng aug có kích thước n x (2n):
    // phần trái (0..n-1) chứa A, phần phải (n..2n-1) chứa ma trận đơn vị I
    double aug[N][2*N];


    // Khởi tạo ma trận mở rộng [A | I]
    for (int i = 0; i < n; i++) {
        // copy phần A vào bên trái
        for (int j = 0; j < n; j++)
            aug[i][j] = a[i][j];
        // tạo ma trận đơn vị bên phải
        // nếu j-n == i thì phần tử = 1 (điểm chéo của I), ngược lại = 0
        for (int j = n; j < 2*n; j++)
            aug[i][j] = (i == j - n) ? 1 : 0;
    }


    // Bắt đầu bước Gauss–Jordan: biến phần trái thành ma trận đơn vị
    for (int i = 0; i < n; i++) {
        // --- 1. Kiểm tra pivot (phần tử chéo aug[i][i]) ---
        // Nếu pivot = 0, cần đổi với một hàng phía dưới có phần tử khác 0
        if (aug[i][i] == 0) {
            int k;
            // Tìm hàng k > i sao cho aug[k][i] != 0
            for (k = i+1; k < n; k++)
                if (aug[k][i] != 0)
                    break;
            // Nếu không tìm được hàng nào có giá trị khác 0 ở cột i ⇒ ma trận không khả nghịch
            if (k == n)
                return 0; // trả về 0 báo không nghịch đảo

            // Hoán vị 2 hàng i và k (đổi vị để có pivot ≠ 0)
            for (int j = 0; j < 2*n; j++) {
                double tmp = aug[i][j];
                aug[i][j] = aug[k][j];
                aug[k][j] = tmp;
            }
        }


        // --- 2. Chuẩn hóa hàng i: chia cả hàng cho giá trị pivot để pivot = 1 ---
        double diag = aug[i][i]; // giá trị phần tử chéo (sau khi đổi nếu cần)
        // Lưu ý: nếu diag == 0 ở đây thì có lỗi logic (nhưng code trên đã tránh bằng đổi hàng)
        for (int j = 0; j < 2*n; j++)
            aug[i][j] /= diag; // bây giờ aug[i][i] = 1

        // --- 3. Khử các hàng khác ở cùng cột i ---
        // Mục tiêu: biến tất cả aug[k][i] (k != i) thành 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aug[k][i]; // hệ số cần khử
                // trừ factor * hàng i khỏi hàng k
                for (int j = 0; j < 2*n; j++)
                    aug[k][j] -= factor * aug[i][j];
                // Sau vòng này, aug[k][i] sẽ trở thành 0
            }
        }
        // Kết thúc bước cho cột i — tiếp tục với cột i+1
    }
    // Sau khi hoàn thành Gauss–Jordan, phần trái aug[..][0..n-1] là I
    // Phần phải aug[..][n..2n-1] là ma trận nghịch đảo A^{-1}
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = aug[i][j + n]; // copy phần phải sang kết quả
    return 1; // thành công
}
int main() {
    int n;
    double a[N][N], inv[N][N];
    // Nhập kích thước ma trận (n)
    printf("Nhap cap ma tran n: ");
    scanf("%d", &n);
    // Ghi chú: không kiểm tra n > N hoặc n <= 0 ở đây — có thể thêm kiểm tra để an toàn
    nhap(a, n); // gọi hàm nhập
    // Tính nghịch đảo
    if (nghichdao(a, inv, n)) {
        printf("\nMa tran nghich dao:\n");
        in(inv, n); // in ma trận nghịch đảo
    } else {
        printf("\nMa tran khong kha nghich (det(A)=0)\n");
    }
    return 0;
}
