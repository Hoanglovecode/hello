#include <bits/stdc++.h>
#define int long long
using namespace std;
int main()
{
  int a, b, m;
  cin >> a >> b >> m;
  int ans = 1;
  while (b>0)
  {
    if(b%2!=0)//if(b%2==0):false
     ans = ans * a % m;
    a = a * a % m;
    b = b / 2;
  }
  cout << ans;
}