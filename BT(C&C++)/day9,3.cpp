#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double a,b;
  cout<<"Nhập vào chiều cao(m):";
    cin>>a;
    cout<<"Nhập vào cân nặng(kg):";
    cin>>b;
    double BMI=b/pow(a,2);
    cout<<"Chỉ số BMI của bạn là: "<<BMI<<endl;
    cout<<"Phân loại cơ thể của bạn là: \n";
    if(BMI<15)
    {
        cout<<"Bạn bị suy dinh dưỡng độ 3\n";
    }
    else if(BMI>=15 && BMI<16)
    {
        cout<<"Bạn bị suy dinh dưỡng độ 2\n";
    }
    else if(BMI>=16 && BMI<18.5)
    {
        cout<<"Bạn bị suy dinh dưỡng độ 1\n";
    }
    else if(BMI>=18.5 && BMI<25)
    {
        cout<<"Bạn bình thường\n";
    }
    else if(BMI>=25 && BMI<30)
    {
        cout<<"Bạn thừa cân\n";
    }
    else
    {
        cout<<"Bạn béo phì\n";
    }       

}