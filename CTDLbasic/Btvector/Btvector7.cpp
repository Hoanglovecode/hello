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
   sort(v.begin(),v.end());//sort() là hàm sx tăng dần 
   for(int x:v)cout<<x<<' ';
   cout<<endl;
   sort(v.rbegin(),v.rend());//sx giảm dần
   for(int x:v)cout<<x<<' ';
}