#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tt;cin>>tt;
        if(tt==1){
            int x;cin>>x;
            v.push_back(x);
        }
        else{
            if(!v.empty()) v.pop_back();
        }
    }
    if(v.empty())cout<<"EMPTY";
    else{
        for(auto x:v) cout<<x<<" "; 
    }
}