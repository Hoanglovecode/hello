#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    long long m, n;
    double a;
    scanf("%lld %lld", &n, &m);
    if (n >= 1 && m >= 1 && m <= pow(10, 9) && n <=50)
    {

        if (n == 1 || n == 2)
            printf("1");
        else
        {
            a = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
            long long b=(long long)a;
            long long c  =b % m;
            printf("%lld", c);
        }
    }
}