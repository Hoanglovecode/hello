//Cho 10 viên gồm 3 loại xanh, đỏ và vàng, các viên bi cùng màu không phân biệt
//
// Ví dụ dữ liệu đề bài:
// - Trường hợp n = 10 (Trùng khớp với đề bài gốc và phần chú thích minh họa ở cuối):
//   Input: n = 10 (Khai báo int n=10)
//   Output: Sinh ra 3^10 = 59049 cách sắp xếp. 5 cách cuối cùng:
//     Hoán vị thứ 59045 : VVVVVVVVDD
//     Hoán vị thứ 59046 : VVVVVVVVDV
//     Hoán vị thứ 59047 : VVVVVVVVVX
//     Hoán vị thứ 59048 : VVVVVVVVVD
//     Hoán vị thứ 59049 : VVVVVVVVVV
//     Tong cach sap xep la : 59049
// - Trường hợp n = 15 (Theo khai báo int n=15 mặc định trong code):
//   Input: n = 15
//   Output: Sinh ra 3^15 = 14348907 cách sắp xếp.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n=15,a[50];
ll landem=0;
void out(){
    landem++;
    cout<<"Hoan vi thu "<<landem<<" : ";
    for(int i=1;i<=n;i++){
        if(a[i]==1) cout<<"X";
        else if(a[i]==2) cout<<"D";
        else cout<<"V";
    }
    cout<<"\n";
}
void Try(int k){
    for(int i=1;i<=3;i++){
        a[k]=i;
        if(k==n) out();
        else Try(k+1);
    }
}
int main(){
    Try(1);
    cout<<"Tong cach sap xep la : "<<landem;
}
//# minh họa 5 lần đếm cuối cùng.

//Hoán vị thứ 59045 : VVVVVVVVDD
//Hoán vị thứ 59046 : VVVVVVVVDV
//Hoán vị thứ 59047 : VVVVVVVVVX
//Hoán vị thứ 59048 : VVVVVVVVVD
//Hoán vị thứ 59049 : VVVVVVVVVV

// #Trả lời chi tiết thuật toán
// Ý tưởng và cơ chế hoạt động của thuật toán:
// 1. Thuật toán sử dụng kỹ thuật Quay lui (Backtracking) thông qua hàm đệ quy `Try(k)` để sinh tất cả các chỉnh hợp lặp chập n của 3 phần tử (1 đại diện cho màu Xanh - X, 2 đại diện cho màu Đỏ - D, 3 đại diện cho màu Vàng - V).
// 2. Tại mỗi bước k (vị trí thứ k trong hàng bi từ 1 đến n):
//    - Thử gán giá trị cho viên bi a[k] lần lượt bằng 1, 2, và 3.
//    - Nếu đã gán xong cho tất cả n vị trí (k == n): Gọi hàm `out()` để ghi nhận cấu hình hợp lệ, chuyển đổi các số 1, 2, 3 thành ký tự tương ứng ('X', 'D', 'V') để in ra, đồng thời tăng biến đếm cấu hình `landem`.
//    - Nếu chưa đạt đến vị trí cuối cùng (k < n): Gọi đệ quy `Try(k + 1)` để tiếp tục chọn màu cho vị trí tiếp theo. Sau khi nhánh đệ quy kết thúc, vòng lặp tự động chuyển sang màu khác (quá trình quay lui tự nhiên).
// Độ phức tạp:
// - Thời gian: O(3^N) vì tại mỗi vị trí trong số N vị trí, ta có 3 sự lựa chọn. Với N = 10, tổng số cách sắp xếp là 3^10 = 59,049. Với N = 15, tổng số cách sắp xếp là 3^15 = 14,348,907.
// - Không gian: O(N) tương ứng với chiều sâu lớn nhất của cây đệ quy (ngăn xếp hệ thống) và độ dài mảng lưu cấu hình.