#include <iostream>
using namespace std;
int main(){
int a;
int b=0;
cout<<"Mời nhập vào số nguyên n :";
cin>>a;
for(int c=1;c<=a;c+=2){
   if(c==3)
    break;
   else 
{
b+=c;
cout<<c<<endl;
}
}
     cout<<"Tổng các số lẻ ngoại trừ 3 là:"<<b;
}