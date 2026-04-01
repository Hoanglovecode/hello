#include <bits/stdc++.h>
using namespace std;
int n,k,x[1000];
int used1[1000];
int used2[1000];
//backtrack sâu nhị phân
void inkq1(){
    for(int i=1;i<=n;i++)cout<<x[i];
    cout<<endl;
}
void try1(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n) inkq1();
        else try1(i+1);
    }
}
//backtrack tổ hợp(combination) C(k,n)
void inkq2(){
    for(int i=1;i<=k;i++)cout<<x[i];
    cout<<endl;
}
void try2(int i){
    x[0]=0;
    for(int j=x[i-1]+1;j<=n-k+1;j++){
        x[i]=j;
        if(i==k) inkq2();
        else try2(i+1);
    }
}
//backtrack chỉnh hợp(permuation) A(k,n)
void inkq3(){
    for(int i=1;i<=k;i++)cout<<x[i];
    cout<<endl;
}
void try3(int i){
    for(int j=1;j<=n;j++){
        if(used1[j]==0){
            used1[j]=1;
            x[i]=j;
            if(i==k)inkq3();
            else try3(i+1);
            used1[j]=0;
        }
    }
}
//backtrach hoán vị(chỉ khác chỉnh hợp ở chỗ là thay k=n)
void inkq4(){
    for(int i=1;i<=n;i++)cout<<x[i];
    cout<<endl;
}
void try4(int i){
    for(int j=1;j<=n;j++){
        if(used2[j]==0){
            used2[j]=1;
            x[i]=j;
            if(i==n)inkq4();
            else try4(i+1);
            used2[j]=0;
        }
    }
}       
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>n>>k;
   cout<<"Backtrack sâu nhị phân"<<endl;
   try1(1);
   cout<<"Backtrack tổ hợp(combination) C(k,n)"<<endl;
   try2(1);
   cout<<"Backtrack chỉnh hợp(permuation) A(k,n)"<<endl;
   try3(1);
   cout<<"Backtrach hoán vị(chỉ khác chỉnh hợp ở chỗ là thay k=n)"<<endl;
   try4(1);
}