#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int dem;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
         dem++;
    }
    cout<<dem;
}