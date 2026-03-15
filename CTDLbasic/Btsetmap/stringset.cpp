#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   set<string>s;
   cin.ignore();
   for(int i=0;i<n;i++){
    string str;
    getline(cin,str);
    s.insert(str);
   }
   cout<<s.size()<<endl;
   for(string x:s)cout<<x<<endl;
}