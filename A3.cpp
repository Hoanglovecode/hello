//Vòng lặp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int s = 1;
    if (n < 23 && n >= 0)
    {
        for (int i = 1; i <= n; i++)
        {
            s = s * i;
        }
        cout << s;
    }
}