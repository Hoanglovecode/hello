#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];
   for(auto it=v.begin();it!=v.end();it++)
        cout<<*it<<' ';
    cout<<endl;
   for(auto it=v.rbegin();it!=v.rend();it++)
        cout<<*it<<' ';
}