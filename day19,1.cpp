//Parameter mặc định giá trị
#include <iostream>
using namespace std;
int tong(int a,int b=4){
    return a+b;
}
int main(){
int kq=tong(4);//cho ra a=4 và mặc định b=4
cout<<"kq="<<kq<<endl;
int kq2=tong(3,5);//a=3 và bỏ qua giá trị mặc định nên b=5
cout<<"kq2="<<kq2;
}