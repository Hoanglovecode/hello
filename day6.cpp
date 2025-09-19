#include <iostream>
using namespace std;
int main()
{
 //gán nhân
 int a=13;
 a*=2;
 cout<<"a="<<a<<endl;
 //gán chia
 double b=13;
 b/=2;
 cout<<"b="<<b<<endl;
 //gán chia lấy dư
 int c=13;
 c%=2;
 cout<<"c="<<c<<endl;
 //phép so sánh
 int x=123;
 int y=321;
 cout<<(x==y)<<endl;
 cout<<(x<=y)<<endl;
 cout<<(x>=y)<<endl;
 cout<<(x!=y)<<endl;
 cout<<(x<y)<<endl;
 cout<<(x>y)<<endl;
 //bài tập
 int a2=6;
 a+=3;
 cout<<"a2="<<a2<<endl;
 int b2=2;
 cout<<"a-(b+7)="<<a2-(b2+=7)<<endl;//trường hợp này ta có thể bỏ đi dấu bằng 

}