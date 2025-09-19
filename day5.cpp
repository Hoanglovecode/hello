#include <iostream>
using namespace std;
int main()
{
    int a=34;
    int b=135;
    int c=343;
    cout<<"tổng của a và b là: "<<a+b<<endl;
    cout<<"hiệu của a và b là:"<<a-b<<endl;
    cout<<"thương của a và b là: "<<(double)a/b<<endl;//gán double để tránh mất dữ  liệu
    cout<<"a%b="<<a%b<<endl;//phép chia lấy dư này chỉ dành cho số nguyên
    cout<<"a*b="<<a*b<<endl;
    cout<<"bình phương tổng ba số là: "<<a*a+b*b+c*c+(int)2*a*b+ (int)2*b*c+(int)2*c*a<<endl;
    //cách 2
    int d=a+b+c;
    cout<<"bình phương tổng ba số là:"<<d*d<<endl;

    

}