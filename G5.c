#include <stdio.h>
#include <math.h>
int check(int n)
{
    int dem = 0;
    for (int i = 1; i <= pow(n, 2); i++)
    {
        if (i % 2 == 0 || i % 3 == 0)
        {
            dem++;
        }
    }
    return dem;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 1000)
    {
        printf("%d", check(n));
    }
}