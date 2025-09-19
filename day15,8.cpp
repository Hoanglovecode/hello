#include <iostream>
using namespace std;
int main(){
cout<<"Các số hoàn hảo từ 1-1000 là: ";
for(int i=1;i<=1000;i++){
int n=i;
int b=0;
for(int a=1;a<n;a++){
if(n%a==0)
b+=a;
}
if(b==n)
       cout << n << "      ";
}
}