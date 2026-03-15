#include <bits/stdc++.h>
using namespace std;
int k=0;
int mod=-1e9;
int a[10000],b[10000]={0};
double _max;
double can(int n,int a[],int b[]){
    if(a[0]>0){
        for(int i=0;i<n;i++){
            if(a[i]<0){
                b[k]=abs(a[i]);
                k++;
            }
        }
        for(int i=0;i<k;i++) _max=max(mod,b[i]);
    }
    else if(a[0]<0){
        for(int i=0;i<n;i++)a[i]*=-1;
        for(int i=0;i<n;i++){
            if(a[i]<0){
                b[k]=abs(a[i]);
                k++;
            }
        }
        for(int i=0;i<k;i++)_max=max(mod,b[i]);
    }
    else return 0;
    double q=1+pow(_max/a[0],1/k);
    return q;
}
int main(){
   freopen("input2.txt","r",stdin);
   freopen("output2.txt","w",stdout);
   int n;cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   cout<<can(n,a,b);
}