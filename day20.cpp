//Đệ quy tính giai thừa số n nhập từ bàn phím
#include <iostream>
using namespace std;
int giaithua(double n){
    if(n<=1)
      return 1;
    return n*giaithua(n-1);
}
int main(){
double n;
cout<<"Tính giai thừa số n nhập từ bàn phím:";
cin>>n;
double kq=giaithua(n);
cout<<n<<"!="<<kq;
}
