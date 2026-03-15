#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<*min_element(v.begin(),v.end())<<' ';//min value array
    cout<<*max_element(v.begin(),v.end())<<' ';//max value array
    cout<<accumulate(v.begin(),v.end(),0);
    

}