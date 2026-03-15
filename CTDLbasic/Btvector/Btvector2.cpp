#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++){
    int k;cin>>k;
    v.push_back(k);
   }
   int q;cin>>q;
   while(q--){
    int tt;cin>>tt;
    if(tt==1){
        int x;cin>>x;
        v.push_back(x);
    }
    else if(tt==2){
        if(v.empty())cout<<"No front"<<endl;
        else{
            cout<<v.front()<<endl;
        }
    }
    else if(tt==3){
        if(v.empty())cout<<"No back"<<endl;
        else{
            cout<<v.back()<<endl;
        }
    }
   }
   if(v.empty())cout<<"EMPTY"<<endl;
    else 
         for(int x:v)cout<<x<<' ';
}