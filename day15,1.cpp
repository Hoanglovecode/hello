//Bài tập tính giai thừa số bất kì nhập từ bàn phím 
#include <iostream>
using namespace std;
int main(){
//1.cách for
int b=1;
int c;
cout<<"Mời nhập vào số n:";
cin>>c;
for(int a=1;a<=c;a++){
cout<<"a="<<a<<endl;
b*=a;
}
cout<<c<<"!="<<b<<endl;
//2.cách while dùng do
int x,y,z=1;
cout<<"Nhập vào số n:";
cin>>x;
do{
   y++;
   z*=y; 
}while (y<=x);
{
 cout<<x<<"!="<<z<<endl;
}
//3.while không dùng do
int e,f=1,g=1;
cout<<"Nhập vào đây số n:";
cin>>e;
while(g<=e)
{
f*=g;
g++; 
}
cout<<"Kết quả: "<<e<<"!="<<f<<endl;
}