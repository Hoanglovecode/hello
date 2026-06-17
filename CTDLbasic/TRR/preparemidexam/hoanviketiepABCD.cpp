//Câu 2 ( 4 điểm) Cho tập X = {a, b, c, d, e ,f }.
//a) Tìm hoán vị tiếp theo của hoán vị S = afedcb. bằng phương pháp sinh
//
// Ví dụ dữ liệu đề bài:
// - Trường hợp 1 (Dữ liệu chạy thử trong main):
//   Input: s = "CDBFEA"
//   Output: Hoan vi ke tiep :CDEABF
// - Trường hợp 2 (Đề bài gốc):
//   Input: s = "afedcb"
//   Output: Khong co hoan vi ke tiep. Day la hoan vi cuoi cung. (hoặc Da dat den cau hinh cuoi cung)

#include <bits/stdc++.h>
using namespace std;
bool nextpermutation(string &s){
    int n=s.length();
    int i=n-2;
    while(i>=0 && s[i]>=s[i+1]) i--;
    if(i<0)return false;
    else{
        int j=n-1;
        while(s[j]<s[i]) j--;
        swap(s[j],s[i]);
        int l=i+1,r=n-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;r--;
        }
    }
    return true;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   string s="CDBFEA";
   if(nextpermutation(s)) cout<<"Hoan vi ke tiep :"<<s<<endl;
   else cout<<"Da dat den cau hinh cuoi cung"<<endl;
}








// #include <bits/stdc++.h>
// using namespace std;
// bool nextPermutation(string &s)
// {
//     int n = s.length();
//     int i = n - 2;
//     while (i >= 0 && s[i] >= s[i + 1])
//     {
//         i--;
//     }
//     if (i < 0)
//         return false;
//     int j = n - 1;
//     while (s[j] <= s[i])
//     {
//         j--;
//     }
//     swap(s[i], s[j]);
//     reverse(s.begin() + i + 1, s.end());
//     return true;
// }
// int main()
// {
//     string s = "afedcb";
//     if (nextPermutation(s))
//     {
//         cout << "Hoan vi ke tiep: " << s << endl;
//     }
//     else
//     {
//         cout << "Khong co hoan vi ke tiep. Day la hoan vi cuoi cung.\n";
//     }
//     return 0;
// }

// #Trả lời chi tiết thuật toán
// Thuật toán sinh hoán vị kế tiếp (Next Permutation) hoạt động như sau:
// 1. Tìm chỉ số i lớn nhất (từ phải sang trái) sao cho s[i] < s[i+1].
//    - Nếu không tìm thấy chỉ số i nào thỏa mãn (i < 0), tức là toàn bộ chuỗi đã được sắp xếp giảm dần. Đây là cấu hình hoán vị lớn nhất (cuối cùng), thuật toán dừng lại và trả về false.
// 2. Nếu tìm thấy i, tìm chỉ số j lớn nhất bắt đầu từ cuối chuỗi về phía i sao cho s[j] > s[i].
// 3. Đổi chỗ hai ký tự s[i] và s[j] cho nhau.
// 4. Đảo ngược thứ tự các ký tự trong đoạn từ chỉ số i+1 đến hết chuỗi (cuối chuỗi) để thu được phần đuôi có thứ tự tăng dần (nhỏ nhất), giúp tạo ra hoán vị kế tiếp ngay sau hoán vị hiện tại.
// Độ phức tạp thuật toán:
// - Thời gian: O(N) với N là độ dài của chuỗi.
// - Không gian: O(1) do chỉ thao tác biến đổi trực tiếp trên chuỗi đầu vào.
