#include <bits/stdc++.h>
using namespace std;
int main()
{
    float x;
    int n;
    cin >> x >> n;
    float tong = 1;
    float a = 1;
    if (abs(x) < 100 && n < 20)
    {
        for (int j = 1; j <= n; j++)
        {
            a = a * j;
            tong = tong + pow(x, j) / a;
        }
        cout << tong;
    }
}