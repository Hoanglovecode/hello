//Hãy liệt kê các số chia hết cho 5 và tính tổng của nó giới hạn đến 400 bằng 2 cách
#include <iostream>
using namespace std;
int main()
{
//cách 1 dùng lệnh do while
int a=0;
int tong=0;
do{
tong+=a;
a+=5;
cout<<"a="<<a<<endl;
} while(a<=400);
{
    cout<<"Tổng cách 1 là:"<<tong<<endl;}
// cách 2 dùng lệnh for
int b=0;
for (int c=5;c<=400;c+=5){
b+=c;
cout<<"c="<<c<<endl;
}
cout<<"Tổng cách 2 là:"<<b<<endl;
}