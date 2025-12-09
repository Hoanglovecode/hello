//Hàm
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ld long double
//(n-k+1)(n-k+2)...n
ld giaithua1(int k,int n)
{
    ld p = 1;
    for (int i =(n-k+1); i <= n; i++)
    {
        p *= i;
    }
    return p;
}
//k!
ld giaithua2(int n)
{
    ld p = 1;
    for (int i = 1; i <= n; i++)
    {
        p *= i;
    }
    return p;
}
int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    if (k >= 0 && k <= n && n <= 60)
    {
        ld s;
        s=giaithua1(k,n)/giaithua2(k);
        printf("%.0Lf", s);
    }
}