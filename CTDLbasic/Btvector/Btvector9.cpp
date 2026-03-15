#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   vector<float>b(n);
   pair<int,int>a[n];
   for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
   }
   for(int i=0;i<n;i++){
    float x=sqrt(a[i].first*a[i].first+a[i].second*a[i].second);
    b[i]=x;
   }
   sort(b.begin(),b.end());
   for(float x:b)cout<<fixed<<setprecision(2)<<x<<" ";
}