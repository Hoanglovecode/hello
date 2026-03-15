#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    int n;
    scanf("%lf", &x);
    scanf("%d", &n);
    double tong = 1;
    double s = 1;
    if (x < 100 && x>-100 && n < 20 && n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            s *= i;
            tong = tong + pow(x, i) / s;
        }
        printf("%.2lf", tong);
    }
}