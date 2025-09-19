#include <iostream>
using namespace std;
int main(){
int a;
int b=1;
int c=0;
cout<<"Mời nhập vào số nguyên a:";
cin>>a;
c+=2; 
b+=c;
if(a%2==0 && c<=a){
cout<<"Tổng các số chẵn từ 0 đến "<<a<<" là:";
cout<<b;
}
}