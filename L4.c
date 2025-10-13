#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    int n;
    int dem = 0;
    scanf("%d", &n);
    if (n >= 2 && n <= pow(10, 9))
    {
        for (int i = 2; i <= n; i++)
        {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                while (n % i == 0)
                {
                    dem++;
                    n = n / i;
                }
            }
        }
        printf("%d", dem);
    }
}
/*
#include <stdio.h>
#include <math.h>
int main()
{
    int dem=0;
    long long n;
    scanf("%lld", &n);
    if (n >= 2 && n <= 1000000000)
    {
        for (long long i = 2; i*i <= n; i++)
        {
            while(n % i == 0)
            {
                    dem++;
                    n = n / i;
            }
        }
        if(n>1)
         dem++;
        printf("%d",dem);
    }
}
*/