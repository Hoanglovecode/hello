#include <bits/stdc++.h>
using namespace std;
int n=9,x[100],cnt[4],dem=0;
void out(){
    for(int i=1;i<=n;i++){
        if(x[i]==1)cout<<"X ";
        else if(x[i]==2)cout<<"D ";
        else cout<<"V ";
    }
    cout<<endl;
}
void Try(int i=1){
    for(int j=1;j<=3;j++){
        if(cnt[j]<3){
            if(i==1 || x[i-1]!=j){
                x[i]=j;
                cnt[j]++;
                if(i==n){
                    out();
                    dem++;
                }
                else Try(i+1);
                cnt[j]--;
            }
        }
    }
}
int main(){
   freopen("output.txt","w",stdout);
   Try(1);
   cout<<"Tổng số cách = "<<dem;
}