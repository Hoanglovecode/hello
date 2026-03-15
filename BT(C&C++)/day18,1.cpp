// Tìm Fn nhập từ bàn phím trong dãy fibonaci cách 1(if-else)
#include <iostream>
using namespace std;
int main()
{
   int f0 = 0;
   int f1 = 1;
   int n;
   cout << "Fn nhập từ bàn phím trong dãy: ";
   cin >> n;
   int f;
   if (n == 0)
      f = f0;
   else if (n == 1)
      f = f1;
   else
   {
      for (int i = 2; i <= n; i++)
      {
         f = f0 + f1;
         f0 = f1;
         f1 = f;
      }
   }
   cout << "f" << n << "=" << f;
}