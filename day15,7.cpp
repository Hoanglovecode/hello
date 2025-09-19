#include <iostream>
using namespace std;
int main(){
for(int i=1;i<=1000;i++){
int n=i;
int b=0;
for(int a=1;a<n;a++){
if(n%a==0)
b+=a;
}
if(b==n)
    cout << n << " là số hoàn hảo"<<endl;
       else
    cout << n << " không phải là số hoàn hảo"<<endl;
    
}
}