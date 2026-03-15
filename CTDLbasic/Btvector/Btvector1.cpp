#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   vector<int>v;
   int q;cin>>q;
   while(q--){
    int tt;cin>>tt;
    if(tt==1){
        int k;cin>>k;
        v.push_back(k);
    }
    else if(tt==2){
        cout<<v.size()<<endl;
    }
    else if(tt==3){
        if(v.size()){
            cout<<"EMPTY"<<endl;
        }
    }
    else if(tt==4){
        if(v.size()!=0){
            cout<<v.back()<<endl;
        }
    }
    else if(tt==5){
        auto it=v.begin();
        cout<<*it<<endl;
    }
    else{
        if(v.size()!=0)v.pop_back();
    }
   }
   if(v.empty())cout<<"EMPTY";
   else 
       for(int x:v)cout<<x<<endl;
}