#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<__gcd(a,b)<<endl;
  cout<<abs(a*b)/(__gcd(a,b))<<endl;
}