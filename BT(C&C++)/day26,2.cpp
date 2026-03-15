#include <bits/stdc++.h>
using namespace std;
int main(){
   //Tính S=1-2+3-4+....+n
   int tong=0;
   int  n;
   cout<<"Mời nhập n:";
   cin>>n;
   for(int i =0;i<=n;i++){
    if(i%2==0)
     tong-=i;
    else
     tong+=i;
   }
   cout<<"Tính S=1-2+3-4+....+"<<n<<"="<<tong;
}