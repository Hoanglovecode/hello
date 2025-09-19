#include <iostream>
using namespace std;
/*
BT:Viết hàm (funtion) hoán vị 2 số thực a và b bằng cách sử dụng con trỏ
*/
void hoanvi(double*a,double*b){
double c=*a;
*a=*b;
*b=c;
}
int main(){
    double a,b;
    cout<<"Mời nhập số a:";
    cin>>a;
    cout<<"Mời nhập số b:";
    cin>>b;
    hoanvi(&a,&b);
    cout<<"a sau hoán đổi:"<<a<<endl;
    cout<<"b sau hoán đổi:"<<b<<endl;
     
}