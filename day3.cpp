#include <iostream>
using namespace std;
int main ()
{
//1.khai bao hằng
const int nhietdosoi=100;
const int nhietdodongdac=0;
cout<<"nhiệt độ sôi của nước là: "<<nhietdosoi<<endl;
cout<<"nhiệt độ đông đặc của nước là: "<<nhietdodongdac<<endl;
// 2.type promotion
int a =8;
float b =2.4f;
cout<<"a+b= "<<a+b<<endl;
//khia baso biến kết quả để nhận kết quả là tổng 
int kq;
kq=a+b;
cout <<"kết quả của a+b là: "<<kq<<endl;
}