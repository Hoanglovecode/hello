#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
int main()
{
 int a=12;
 cout<<(a>10 && a<13)<<endl;//kiểm tra a lớn hơn 10 và nhỏ hơn 13 hay không
 cout<<!(a>10 && a<13)<<endl;//đảo ngược kết quả của biểu thức thêm ! phía trước
 cout<<(a>10 || a<-13)<<endl;// dấu "||"là phép hoặc còn "&&"là phép và
 cout<<!(a>10 || a<-13)<<endl;

a++;
 cout<<"a="<<a<<endl;
 int b=15;
 --b;
 cout<<"b="<<b<<endl;
 //trường hợp biểu thức phức  tạp lun theo quy tắc
 // prefix:thực hiện trước khi dùng biến mẫu ++a
 //postfix :thực hiện sau khi dùng biến mẫu a--
 int x=1;
 int y=2;
 int z= x++-++y+3;
 cout<<z<<endl;;//kết quả z bằng 1
 cout <<x<<endl;//kết quã bằng 2 nhưng trong z x vẫn là 1 vì nó là postfix
 double p=M_PI;
double r;
cout << "Mời nhập và bán kính hình tròn: ";
cin>>r;
cout << "Diện tích hình tròn là: " << p * pow(r, 2) << "\n"; // diện tích hình tròn
cout << "Chu vi hình tròn là: " << 2 * p * r << "\n";        // chu vi hình tròn
}