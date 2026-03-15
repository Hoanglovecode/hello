#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n >= 2 && n <= 1000)
    {
        for (int i = 2; i <= n; i++)
        {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0){
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && n % i == 0)
                cout << i << " ";
        }
    }
}