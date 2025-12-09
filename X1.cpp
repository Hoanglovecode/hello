#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n >= 1 && n <= 100)
    {
        string s[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i].size() > 10)
            {
                cout << s[i][0] << (s[i].size() - 2) <<s[i][s[i].size()-1]<<endl;
            }
            else
             cout <<s[i]<<endl;
        }
    }
}