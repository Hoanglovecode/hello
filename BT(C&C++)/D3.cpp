#include <bits/stdc++.h>
using namespace std;
int main(){
    //Cách 1
        int a[100000];
    double dem=0;
    for(int i=0;i<=100000;i++){
        cin>>a[i];
        if(a[i]%2 !=0)
         dem+=1;
        if(a[i]==0)
        break;
    }
    cout<<dem;
    //Cách 2
    long long x;
    int dem2=0;
    while(true){
        cin>>x;
        if(x%2!=0)
         dem2+=1;
        if(x==0)
        break;
    }
    cout<<dem2;
}