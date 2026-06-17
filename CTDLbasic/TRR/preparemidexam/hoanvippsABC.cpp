// Ví dụ dữ liệu đề bài:
// - Input: Đọc từ file input.txt một số nguyên dương n (ví dụ: n = 3)
// - Output: Ghi vào file output.txt các hoán vị độ dài n của các chữ cái tương ứng trong mảng x[].
//   Ví dụ với n = 3:
//   ABC
//   ACB
//   BAC
//   BCA
//   CAB
//   CBA

#include <bits/stdc++.h>
using namespace std;
int ok=1;
char x[]={'A','B','C','D','E','F'};
void init(int a[],int n){
    for(int i=1;i<=n;i++)a[i]=i;
}
void out(int a[],int n){
    for(int i=1;i<=n;i++)cout<<x[a[i]-1];
    cout<<endl;
}
void gen(int a[],int n){
    int i=n-1;
    while(i>=1 && a[i]>a[i+1])i--;
    if(i==0)ok=0;
    else{
        int j=n;
        while(a[i]>a[j])j--;
        swap(a[i],a[j]);
        int l=i+1,r=n;
        while(l<r){
            swap(a[l],a[r]);
            l++;r--;
        }
    }
}
void method(int a[],int n){
    init(a,n);
    while(ok){
        out(a,n);
        gen(a,n);
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   int a[n+1];
   method(a,n);
   
}

// #Trả lời chi tiết thuật toán
// Chương trình sinh toàn bộ các hoán vị có độ dài n từ các ký tự đầu tiên của tập ký tự x = {'A', 'B', 'C', 'D', 'E', 'F'}.
// Thuật toán sinh hoán vị kế tiếp (Next Permutation) hoạt động như sau:
// 1. Khởi tạo: Hàm `init` gán hoán vị ban đầu dưới dạng các số tăng dần: a = [1, 2, ..., n].
// 2. In kết quả: Hàm `out` in các ký tự tương ứng với cấu hình số hiện tại, ánh xạ số a[i] thành ký tự x[a[i]-1].
// 3. Hàm sinh cấu hình tiếp theo `gen`:
//    - Duyệt ngược từ cuối mảng (i = n-1 về 1) tìm chỉ số i đầu tiên thỏa mãn a[i] < a[i+1].
//    - Nếu không tìm thấy (i == 0), tức là toàn bộ mảng đã giảm dần (là hoán vị cuối cùng), ta gán ok = 0 để dừng vòng lặp.
//    - Nếu tìm thấy i, duyệt ngược từ cuối mảng (j = n về i+1) tìm phần tử đầu tiên a[j] lớn hơn a[i].
//    - Đổi chỗ a[i] và a[j].
//    - Đảo ngược thứ tự phân đoạn từ vị trí i+1 đến n để làm cho đoạn phía sau tăng dần (nhỏ nhất).
// 4. Lặp lại bước 2 và 3 cho đến khi ok = 0.
// Độ phức tạp thuật toán:
// - Thời gian: O(N! * N) với N là số lượng phần tử cần hoán vị, vì có N! hoán vị và mỗi hoán vị mất O(N) để in và sinh tiếp theo.
// - Không gian: O(N) để lưu trữ mảng hoán vị.