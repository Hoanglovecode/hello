//Tìm Fn nhập từ bàn phím trong dãy fibonaci cách 2(ĐỆ QUY)
#include <iostream>
using namespace std;
int f(double n)
{
   if (n == 0)
      return 0;
   if (n <= 2)
      return 1;
   return f(n - 1) + f(n - 2);
}
int main()
{
   double n;
   cout << "Tính Fn được nhập từ bàn phím:";
   cin >> n;
   double kq = f(n);
   cout << "kết quả=" << kq << endl;
}