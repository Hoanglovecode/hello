//Liệt kê và tính Tổng 1!+2!+3!+...+10!
#include <iostream>
using namespace std;
int main(){
int b=1;
int c=0;
for(int a=1;a<=10;a++){
    b*=a;
    cout<<b<<endl;
    c+=b;
}
cout<<"Tổng 1!+2!+3!+...+10!="<<c;
}