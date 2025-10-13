#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if (a == "B" && b == "K")
        cout << "WIN";
    else if (a == "B" && b == "G")
        cout << "LOSE";
    else if (a == "K" && b == "G")
        cout << "WIN";
    else if (a == "K" && b == "B")
        cout << "LOSE";
    else if (a == "G" && b == "K")
        cout << "LOSE";
    else if (a == "G" && b == "B")
        cout << "WIN";
    else if (a == "G" && b == "G")
        cout << "DRAW";
    else if (a == "B" && b == "B")
        cout << "DRAW";
    else if (a == "K" && b == "K")
        cout << "DRAW";
}