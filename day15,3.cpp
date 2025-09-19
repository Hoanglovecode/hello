//BT tính tổng các số chẵn/lẻ từ 0 đến số được nhập
#include <iostream>
using namespace std;
int main(){
int a;
int b=0;
cout<<"Mời nhập vào số nguyên a:";
cin>>a;
if(a%2==0)
{   
    for(int c=0;c<=a;c+=2){
     b+=c;    
    }
    cout<<"Tổng các số chẵn từ 0 đến "<<a<<" là:"<<b;
}
else 
{
    for(int c=1;c<=a;c+=2){
     b+=c;   
    }
    cout<<"Tổng các số lẻ từ 0 đến "<<a<<" là:"<<b;
}
}
