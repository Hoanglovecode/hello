#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   pair<int,int>p{1,2};
   cout<<p.first<<' '<<p.second<<' '<<endl;
   pair<int,int>v={3,4};
   cout<<v.first<<' '<<v.second<<' '<<endl;
   pair<int,long long>q=make_pair(10,100);
   cout<<q.first<<' '<<q.second<<' ';
   int n;cin>>n;
   pair<int,int>a[n];
   for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
   }
   pair<int,pair<int,int>>c;
   c.first=1000;
   c.second.first=2000;
   c.second.second=3000;//c={1000,{2000,3000}}
   vector<pair<int,int>>c;
   pair<int,vector<int>>b;
}