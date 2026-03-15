#include <iostream>
#include <cmath>
using namespace std;
int main() {
double a,b,c,d;
//viết lệnh giải phương trình bậc 2 ax^2+bx+c=0
cout<<"Giải phương trình bậc 2: ax^2+bx+c=0"<<endl;
cout<<"Nhập vào hệ số a: ";
cin>>a;
cout<<"Nhập vào hệ số b: ";
cin>>b;
cout<<"Nhập vào hệ số c: ";
cin>>c;
d=pow(b,2)-4*a*c;
if (d<0)
cout<<"Phương trình vô nghiệm";
if (d==0)
cout<<"Phương trình có nghiệm kép là x1=x2="<<-b/(2*a);
if (d>0){
    cout <<"Phương trình có 2 nghiệm phân biệt:"<<endl;
    cout<<"x1="<<(-b+sqrt(d))/(2*a)<<" và x2="<<(-b-sqrt(d))/(2*a);
 
}
return 0;
}