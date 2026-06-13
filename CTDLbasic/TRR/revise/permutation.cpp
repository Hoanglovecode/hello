#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;
   cin>>n;
   int a[n];
   cout<<"function next_permutation((a,a+n) (sinh hoan vi)"<<endl;
   for(int i=0;i<n;i++)a[i]=i+1;
   do{
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
   }while(next_permutation(a,a+n));
   cout<<"function prev_permutation((a,a+n) (sinh hoan vi nguoc)"<<endl;
   for(int i=0;i<n;i++)a[i]=n-i;
   do{
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
   }while(prev_permutation(a,a+n));
   //hoan vi string 
   vector<string> s1={"do","vang","xanh","tim"};
   do{
    for(auto str : s1) cout<<str<<' ';
    cout<<endl;
   }while(next_permutation(s1.begin(),s1.end()));
}