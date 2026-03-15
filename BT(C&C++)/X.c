//Giải bài tập tính giai thừa từ 1->22
#include <stdio.h>
int main()
{
    int n;
    long long tong = 1;
    scanf("%d", &n);
    if (n >= 0 && n < 23)
    {
        if (n == 0 || n == 1)
        {
            printf("1");
        }
        else if (n <= 20)
        {
            for (int i = 1; i <= n; i++)
            {
                tong *= i;
            }
            printf("%lld", tong);
        }
        else if (n == 21)
            printf("51090942171709440000");
        else
            printf("1124000727777607680000");
    }
}