//Câu 2 (4,0 điểm) Bn là số xâu bit độ dài n.
//Liệt kê số cách sắp xếp số xâu bit để không có 2 bít 0 kề nhau bằng phương pháp sinh
#include <bits/stdc++.h>
using namespace std;
int n,a[100],ok;
void ktao(){
    for(int i=1;i<=n;i++)a[i]=0;
}
bool check(){
    for(int i=1;i<n;i++)if(a[i]==0 && a[i+1]==0)return false;
    return true;
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
    if(check()){
        for(int i=1;i<=n;i++)cout<<a[i];
        cout<<endl;
    }
    sinh();
   }
}