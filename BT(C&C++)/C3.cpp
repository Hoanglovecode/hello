#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    double tong = 0;
    if (n <= 100)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                tong += a[i];
        }
        cout << tong;
    }
}