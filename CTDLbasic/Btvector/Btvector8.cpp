#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+1;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n,m;cin>>n>>m;
   vector<vector<int>>v(n,vector<int>(m));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>v[i][j];
   }
   for(int i=0;i<n;i++){
    int _min=mod,_max=-mod;
    for(int j=0;j<m;j++){
        /*có thể sài hàm min_element và max_element
        EX: cout<<*min_element(v.begin(),v.end())<<' '<<*max_element(v.begin(),v.end());
        */
       _min=min(_min,v[i][j]);
       _max=max(_max,v[i][j]);
    }
    cout<<_min<<' '<<_max<<endl;
   }
}