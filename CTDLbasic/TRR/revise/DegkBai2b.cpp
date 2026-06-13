//Câu 2 ( 4 điểm) Cho tập X = {a, b, c, d, e ,f }.
//b) Viết chương trình liệt kê tập con k phần tử từ X sử dụng phương pháp sinh
#include <bits/stdc++.h>
using namespace std;
int n,a[100],ok,k;
char x[]={'a','b','c','d','e','f'};
void ktao(){
    for(int i=1;i<=k;i++)a[i]=i;
}
void sinh(){
    int i=k;
    while(i>=1 && a[i]==n-k+i)i--;
    if(i==0)ok=0;
    else{
        a[i]++;
        for(int j=i+1;j<=n;j++)a[j]=a[j-1]+1;
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>n>>k;
   ok=1;
   ktao();
   while(ok){
    for(int i=1;i<=k;i++)cout<<x[a[i]-1];
    cout<<endl;
    sinh();
   }
}