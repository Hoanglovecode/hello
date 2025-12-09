#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
ll check(ll n, ll k)
{
    int f = 0;
    for (ll i = 1;; i++)
    {
        if (i % n != 0)
            f++;
        if (f == k)
            return i;
    }
}
int main()
{
    ll n;
    ll k;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%lld %lld", &n, &k);
        if (n >= 2 && k >= 1 && q >= 1 && n <= pow(10, 9) && k <= pow(10, 9) && q <= 1000)
            printf("\n%lld", check(n, k));
    }
}