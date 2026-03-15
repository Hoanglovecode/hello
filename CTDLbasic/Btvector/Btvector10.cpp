#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   vector<pair<int,pair<int,int>>>v;
   for(int i=0;i<n;i++){
    int x,y,z;cin>>x>>y>>z;
    v.push_back({x,{y,z}});
   }
   sort(v.begin(),v.end());
   for(auto x:v)
    cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<endl;
   
}