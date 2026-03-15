#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   int a[n];
   set<int>s;
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++){
    s.insert(a[i]);
   }
   cout<<s.size()<<endl;
   for(int x:s)cout<<x<<' ';
   cout<<endl;
   if(s.find(4)==s.end())cout<<"NOT FOUND"<<endl;
   else cout<<"FOUND"<<endl;
}