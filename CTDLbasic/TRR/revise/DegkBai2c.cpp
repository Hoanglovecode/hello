//Câu 2( 4 điểm) Cho tập X = {a, b, c, d, e ,f }.
//c) Viết chương trình liệt kê tất cả các tập con của X 
#include <bits/stdc++.h>
using namespace std;
int n,a[100],ok;
char x[]={'a','b','c','d','e','f'};
void ktao(){
    for(int i=1;i<=n;i++)a[i]=0;
}
void sinh(){
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>n;
   ok=1;
   ktao();
   while(ok){
    cout<<"{";
    for(int i=n;i>=1;i--){
        if(a[i]==1) cout<<x[i-1];
    }
    cout<<"}"<<endl;
    sinh();
   }
}
/*
fedba
fedc
fedca
fedcb
fedcba
*/