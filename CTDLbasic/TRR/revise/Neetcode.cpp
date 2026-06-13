//Combination Sum 
/*
Input:
nums = [3,4,5]
target = 16
Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]
*/
#include <bits/stdc++.h>
using namespace std;
int n,a[100],S;
vector<int>v;
void input(){
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
}
void tryy(int start,int sum){
   for(int j=start;j<n;j++){
      if(sum+a[j]>S)break;
      v.push_back(a[j]);
      if(sum+a[j]==S){
         for(int x:v)cout<<x<<" ";
         cout<<endl;
      }
      else{
         tryy(j,sum+a[j]);
      }
      v.pop_back();
   }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>n>>S;
   input();
   tryy(0,0);
}