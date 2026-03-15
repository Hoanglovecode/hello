#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a;
  cin >> a;
  if (a >= 0 && a <= pow(10, 5))
  {
    if (a == 0)
    {
      cout << 0;
    }
    else
    {
      string s = "";
      // CÁCH 1 DÙNG WHILE
      while(a>0){
        s=char(a%2+'0')+s;
        a=a/2;
      }
      // CÁCH 2 DÙNG FOR
      // for (int b = a; b > 0; b /= 2)
      // {
      //   s = char(a % 2 + '0') + s;
      // }
      cout << s;
    }
  }
}