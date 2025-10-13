#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c,d;
    cin >> a >> b >> c>>d;
    if (a <= b && a <= c)
        cout << a;
    else if (c <= b && c <= a)
        cout << c;
    else
        cout << b;
}