#include <stdio.h>
#include <math.h>
int main()
{

    int a;
    int s[10000];
    int dem = 0;
    int tong = 0;
    scanf("%d", &a);
    int b=a;
    while (a > 0)
    {
        s[dem] = a % 10;
        dem++;
        a /= 10;
    }
    for (int i = dem - 1; i >= 0; i--)
    {
        tong += pow(s[i], dem);
    }
    
    if (tong == b)
        printf("\nYES");
    else
        printf("\nNO");
}
