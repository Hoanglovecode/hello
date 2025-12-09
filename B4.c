//ktlt2599_t1
#include <stdio.h>
int main()
{
    int n;
    int tong = 0;
    scanf("%d", &n);
    if (n >= 1 && n <= 1000)
    {
        for (int i = 1; i <= n * n; i++)
        {
            if (i % 2 == 0 || i % 3 == 0)
            {
                tong++;
            }
        }
        printf("%d", tong);
    }
}