//Câu 2 (4,0 điểm) Bn là số xâu bit độ dài n.
//Liệt kê số cách sắp xếp số xâu bit để không có 3 bít 1 kề nhau bằng phương pháp sinh
//
// Ví dụ dữ liệu đề bài:
// - Input: Nhập từ bàn phím một số nguyên dương n (ví dụ: n = 4)
// - Output: In ra các cấu hình xâu bit hợp lệ kèm theo số thứ tự cách.
//   Ví dụ với n = 4:
//   Cách 1 :0000
//   Cách 2 :0001
//   Cách 3 :0010
//   Cách 4 :0011
//   Cách 5 :0100
//   Cách 6 :0101
//   Cách 7 :0110
//   Cách 8 :1000
//   Cách 9 :1001
//   Cách 10 :1010
//   Cách 11 :1011
//   Cách 12 :1100
//   Cách 13 :1101

#include <bits/stdc++.h>
using namespace std;
int ok=1,cnt=1;
void init(int a[],int n){
    for(int i=1;i<=n;i++)a[i]=0;
}
void out(int a[],int n){
    cout<<"Cách "<<cnt<<" :";
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}
int check(int a[],int n){
    for(int i=1;i<=n-2;i++)if(a[i]==1 && a[i+1]==1 && a[i+2]==1)return 0;
    return 1;
}
void gen(int a[],int n){
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
void method(int a[],int n){
    init(a,n);
    while(ok){
        if(check(a,n)){
            out(a,n);
            cnt++;
        }
        gen(a,n);
    }
}
int main(){
   int n;cin>>n;
   int a[n+1];
   method(a,n);
}

// #Trả lời chi tiết thuật toán
// 1. Ý tưởng thuật toán sinh cấu hình trong code:
//    - Thuật toán sinh tất cả các xâu nhị phân có độ dài n bằng phương pháp sinh kế tiếp (hàm gen). 
//    - Hàm `init` khởi tạo xâu nhị phân đầu tiên là 00...0.
//    - Hàm `gen` tìm bit 0 đầu tiên từ phải qua trái, chuyển nó thành 1 và chuyển toàn bộ các bit đứng sau nó thành 0. Nếu không còn bit 0 nào (tức là cấu hình toàn 1), ta đặt ok = 0 để kết thúc quá trình sinh.
//    - Với mỗi xâu nhị phân được sinh ra, hàm `check` sẽ kiểm tra xem có chứa 3 bit 1 kề nhau hay không (duyệt từ i = 1 đến n-2, kiểm tra a[i] == 1 && a[i+1] == 1 && a[i+2] == 1). Nếu không chứa thì in cấu hình đó ra.
//
// 2. Hệ thức truy hồi tìm số xâu nhị phân độ dài n không chứa 3 bit 1 liên tiếp (Bn):
//    Một xâu hợp lệ độ dài n có thể được tạo ra bằng cách thêm vào cuối các xâu hợp lệ ngắn hơn:
//    - Nếu xâu kết thúc bằng bit 0: Phần trước đó là một xâu hợp lệ độ dài n-1. Số cách là B(n-1).
//    - Nếu xâu kết thúc bằng cụm 01: Phần trước đó là một xâu hợp lệ độ dài n-2. Số cách là B(n-2).
//    - Nếu xâu kết thúc bằng cụm 011: Phần trước đó là một xâu hợp lệ độ dài n-3. Số cách là B(n-3).
//    Do đó, hệ thức truy hồi là:
//      Bn = B(n-1) + B(n-2) + B(n-3) với n >= 3.
//    Các giá trị cơ bản (Base cases):
//      B(0) = 1 (xâu rỗng)
//      B(1) = 2 (0, 1)
//      B(2) = 4 (00, 01, 10, 11)
//      B(3) = 7 (loại bỏ cấu hình duy nhất là 111)
//      B(4) = B(3) + B(2) + B(1) = 7 + 4 + 2 = 13 (khớp với kết quả chạy thử của chương trình).
//    Độ phức tạp:
//    - Thời gian: O(2^n * n) để sinh toàn bộ cấu hình nhị phân và kiểm tra điều kiện.
//    - Không gian: O(n) để lưu trữ mảng nhị phân kích thước n.
//    (Nếu chỉ tính số lượng cấu hình Bn, ta có thể dùng Quy hoạch động để đạt độ phức tạp thời gian O(n) và không gian O(1)).
