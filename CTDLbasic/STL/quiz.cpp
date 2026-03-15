#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int a[7]={1,2,3,5,4,7,6};
   set<int>se(a,a+7);//se={1,2,3,4,5,6,7}
   auto it=se.find(7);
   it--;
   cout<<*it<<endl;//6
   cout<<*se.begin()<<endl;//1
   cout<<*se.rbegin()<<endl;//7
   for(int x:se)cout<<x<<" ";//1 2 3 4 5 6 7
   auto x=se.end();x--;
   cout<<"\n"<<*x<<endl;
}