#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n > 0)
    {
        if (n % 2 == 0)
            printf("YES");
        else
            printf("NO");
    }
}