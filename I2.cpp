#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c)
    {
        cout << a<<" ";
        if (b <= c)
        {
            cout << b<<" ";
            cout << c<<" ";
        }
        else
        {
            cout << c<<" ";
            cout << b<<" ";
        }
    }
    else if (b <= c && b <= a)
    {
        cout << b<<" ";
        if (a <= c)
        {
            cout << a<<" ";
            cout << c<<" ";
        }
        else
        {
            cout << c<<" ";
            cout << a<<" ";
        }
    }
    else if (c <= b && c <= a)
    {
        cout << c<<" ";
        if (b <= a)
        {
            cout << b<<" ";
            cout << a<<" ";
        }
        else
        {
            cout << a<<" ";
            cout << b<<" ";
        }
    }
}