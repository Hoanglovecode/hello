#include <bits/stdc++.h>
using namespace std;
void init(int b[],int n){
    for(int i=1;i<=n;i++)b[i]=0;
}
void out(int b[],int n){
    for(int i=1;i<=n;i++)cout<<b[i]<<endl;
}
void method(int b[],int n){
    int(b,n);
    out(b,n);
    int stop=islast(b,n);
    while(stop==0){
        out(b,n);
        stop=islast(b,n);
    }
}
int islast(int b[],int n){
    for(int i=1;i<=n;i++){
        if(b[i]==0)return 0;
    }
    return 1;
}
void gen(int b[],int n){
    int i=n;
    while(b[i]==1){
        i--;
    }
    b[i]=1;
    for(int  j=i+1;j<n;j++){
        b[j]=0;
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   int b[20];
   init(b,n);
   method(b,n);
}