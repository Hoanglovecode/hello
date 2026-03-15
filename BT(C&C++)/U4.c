#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    long double m, n;
    long double a;
    scanf("%Lf %Lf", &n, &m);
    if (n >= 1 && m >= 1 && m <= pow(10, 9) && n <= pow(10, 9))
    {

        if (n == 1 || n == 2)
            printf("1");
        else
        {
            a = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
            printf("%.0Lf", fmodl(a, m));
        }
    }
}