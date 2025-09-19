#include <iostream>
using namespace std;
int main()
{
//xuất các số chẵn từ 1 đến 100
//cách 1
int a=2;
while(true)
{
cout<<"a="<<a<<endl;
a+=2;
if (a>100)
break;
}
//cách 2
//  for(khởi tạo;điều kiện;bước lặp){
//     câu lệnh;
//  }
for(int b=2;b<=100;b+=2){
cout<<"b="<<b<<endl;
}
}

