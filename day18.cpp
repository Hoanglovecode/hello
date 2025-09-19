// Dãy fibonaci từ U0 đến Un nhập từ bàn phím
#include <iostream>
using namespace std;
int main()
{
    int u0 = 0;
    int u1 = 1;
    int n;
    cout << "Dãy fibonaci từ U0 đến Un nhập từ bàn phím :";
    cin >> n;
    cout << u0 << " " << u1;
    for (int i = 2; i <= n; i++)
    {
        int u = u0 + u1;
        cout << " " << u;
        u0 = u1;
        u1 = u;
    }
}