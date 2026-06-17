//a)Đếm số cách xếp 9 viên bi trên thành hàng ngang để ko có các viên bị cùng màu xếp kề nhau.
//
// Ví dụ dữ liệu đề bài:
// - Input: Dữ liệu được xác định sẵn trong code: n = 9 viên bi chia đều cho 3 màu (Xanh, Đỏ, Vàng), mỗi màu có đúng 3 viên bi.
// - Output: Ghi toàn bộ các cấu hình xếp bi hợp lệ vào file output.txt và in ra tổng số cách.
//   Một số cấu hình hợp lệ cuối cùng trong file output.txt:
//     V D V X D X D X V 
//     V D V X D X D V X 
//     V D V X D X V X D 
//     V D V X D X V D X 
//     V D V X D V X D X 
//     V D V X V X D X D 
//     V D V X V D X D X 
//     V D V D X D X V X 
//     V D V D X V X D X 
//     Tổng số cách = 174

#include <bits/stdc++.h>
using namespace std;
int n=9,x[100],cnt[4],dem=0;
void out(){
    for(int i=1;i<=n;i++){
        if(x[i]==1)cout<<"X ";
        else if(x[i]==2)cout<<"D ";
        else cout<<"V ";
    }
    cout<<endl;
}
void Try(int i=1){
    for(int j=1;j<=3;j++){
        if(cnt[j]<3){
            if(i==1 || x[i-1]!=j){
                x[i]=j;
                cnt[j]++;
                if(i==n){
                    out();
                    dem++;
                }
                else Try(i+1);
                cnt[j]--;
            }
        }
    }
}
int main(){
   freopen("output.txt","w",stdout);
   Try(1);
   cout<<"Tổng số cách = "<<dem;
}
/*
Trường hợp 1 (0 lỗi-xen kẽ hoàn toàn):
xdxdxdxd
dxdxdxdx
->có 2 cấu hình=>số cách=2.7C3=70 cách
Trường hợp 2 (1 lỗi-có 1 cặp kề nhau):
3.x-dd-x-d-x
4.x-d-x-dd-x
5.d-xx-d-x-d
6.d-x-d-xx-d
->có 4 cấu hình=>số cách=4.6C2=60 cách
Trường hợp 3 (2 lỗi-có 2 cặp kề nhau):
7.xx-dd-x-d
8.xx-d-x-dd
9.x-dd-xx-d
10.x-d-xx-dd
11.dd-xx-d-x
12.dd-x-d-xx
13.d-xx-dd-x
14.d-x-dd-xx
->có 8 cấu hình=>số cách=8.5C1=40 cách
Trường hợp 4 (3 lỗi-có 3 cặp kề nhau):
15.xx-ddd-x
16.x-ddd-xx
17.dd-xxx-d
18.d-xxx-dd
->có 4 cấu hình=>số cách=4.4C0=4 cách
Trường hợp 5 (4 lỗi-dồn cục):
Sinh ra 0 cách(do có 4 lỗi nhưng chỉ có 3 bi Vàng,không đủ để chèn vách ngăn)
19.xxx-ddd
20.ddd-xxx
*/

// #Trả lời chi tiết thuật toán
// Ý tưởng và cơ chế hoạt động của thuật toán:
// 1. Thuật toán giải quyết bài toán đếm số cách sắp xếp 9 viên bi (gồm 3 loại màu: Xanh - 1, Đỏ - 2, Vàng - 3; mỗi màu có đúng 3 viên bi) sao cho không có 2 viên bi nào cùng màu đứng cạnh nhau.
// 2. Thuật toán sử dụng phương pháp Quay lui (Backtracking) thông qua hàm đệ quy `Try(i)` để gán màu cho viên bi tại vị trí thứ i (từ 1 đến 9):
//    - Với mỗi vị trí i, ta duyệt qua các màu j từ 1 đến 3.
//    - Kiểm tra xem màu j đã được dùng dưới 3 lần chưa (`cnt[j] < 3`).
//    - Kiểm tra điều kiện không kề nhau: màu đang thử j phải khác với màu của viên bi đứng liền trước nó (`i == 1 || x[i-1] != j`).
//    - Nếu thỏa mãn cả 2 điều kiện, gán màu: `x[i] = j`, tăng số lần sử dụng của màu đó `cnt[j]++`.
//    - Nếu đã gán xong cho tất cả 9 vị trí (i == 9): Gọi hàm `out()` để in cấu hình ra file output.txt dưới dạng các chữ cái màu (X, D, V) và tăng biến đếm tổng số cấu hình hợp lệ `dem`.
//    - Nếu chưa đạt đến vị trí cuối cùng, tiếp tục đệ quy `Try(i+1)`.
//    - Sau khi hoàn thành nhánh đệ quy, thực hiện quay lui (backtrack) bằng cách giảm số lượng sử dụng của màu j (`cnt[j]--`) để thử màu tiếp theo cho vị trí i.
// 3. Phần chú thích ở cuối file là cách phân tích bằng toán học tổ hợp: Chia bài toán thành các trường hợp lỗi (số cặp bi cùng màu xếp kề nhau) và sử dụng nguyên lý bù trừ để tính ra kết quả thủ công là:
//    Tổng = 70 (0 lỗi) + 60 (1 lỗi) + 40 (2 lỗi) + 4 (3 lỗi) = 174 cách. Kết quả này trùng khớp hoàn hảo với 174 cấu hình sinh ra bởi chương trình.
// Độ phức tạp thuật toán:
// - Thời gian: Nhỏ hơn O(3^N) vì nhờ các điều kiện cắt tỉa (mỗi màu chỉ dùng tối đa 3 lần và không kề nhau) nên số lượng trạng thái thực tế cần duyệt qua là rất nhỏ.
// - Không gian: O(N) với N = 9, tương ứng với chiều sâu lớn nhất của ngăn xếp đệ quy.