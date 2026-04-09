//Câu 2 (4,0 điểm) Bn là số xâu bit độ dài n.
//Liệt kê số cách sắp xếp số xâu bit để không có 2 bít 0 kề nhau bằng phương pháp sinh
#include <bits/stdc++.h>
using namespace std;
int ok=1,cnt=1;
void init(int a[],int n){
    for(int i=1;i<=n;i++)a[i]=0;
}
void out(int a[],int n){
    cout<<"Cách "<<cnt<<" :";
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}
int check(int a[],int n){
    for(int i=1;i<n;i++)if(a[i]==0 && a[i+1]==0)return 0;
    return 1;
}
void gen(int a[],int n){
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
void method(int a[],int n){
    init(a,n);
    while(ok){
        if(check(a,n)){
            out(a,n);
            cnt++;
        }
        gen(a,n);
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   int a[n+1];
   method(a,n);
}