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
    int tt;cin>>tt;
    if(tt==1){
        int i,x;cin>>i>>x;
        if(i<=v.size())
            v.insert(v.begin()+i,x);
        else cout<<"Khong hop le"<<endl; 
    }
    else if(tt==2){
        int i;cin>>i;
        if(i<v.size() && v.size()!=0)
            v.erase(v.begin()+i);
        else cout<<"Khong hop le"<<endl;
    }
    else if(tt==3){
        int l,r;cin>>l>>r;
        if(r<v.size() && v.size()!=0){
            v.erase(v.begin()+l,v.begin()+r+1);
        }
        else cout<<"Khong hop le"<<endl;
    }
    else{
        if(v.size()!=0)
            cout<<v[v.size()-1]<<endl;
        else cout<<"Khong hop le"<<endl;
    }
   }
   if(v.empty())cout<<"Empty";
   else{
    for(int x:v)cout<<x<<' ';
   }

}