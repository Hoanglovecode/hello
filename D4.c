#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 0 && n <= pow(10, 5))
    {
        if (n == 0)
            printf("0");
        else
        {
            char s[32];
            int i = 0;
            while (n > 0)
            {
                s[i] = n % 2 + '0';
                n = n / 2;
                i++;
            }
            for(int j=i-1;j>=0;j--){
                printf("%c",s[j]);
            }
        }
    }
}