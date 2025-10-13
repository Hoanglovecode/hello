#include <bits/stdc++.h>
using namespace std;
int main()
{
    float a, b, c, d;
    cin >> a >> b >> c;
    d = 0.2 * (a + b) + 0.6 * c;
    if (d >= 8.5 && d <= 10)
        cout << "A";
    else if (d >= 7 && d < 8.5)
        cout << "B";
    else if (d >= 5.5 && d < 7)
        cout << "C";
    else if (d >= 4 && d < 5.5)
        cout << "D";
    else
        cout << "F";
}