#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];
   int q;cin>>q;
   while(q--){
    int tt,l,r;cin>>tt>>l>>r;
    if(tt==1){
        reverse(v.begin()+l,v.begin()+r+1);
    }
    else{
        swap(v[l],v[r]);//exchange element not iterator
    }
   }
   for(int x:v)cout<<x<<' ';
}