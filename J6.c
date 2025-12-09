#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *a=(int*)malloc(n*sizeof(int));
    int j = 0;
    while (n > 0)
    {
        a[j] = n % 10;//Cho từng con số vào trong mảng 
        n /= 10;
        j++;
    }
    int tong = 0,dem0=0,dem5=0;
    for (int i = j - 1; i >= 0; i--){
        tong += a[i];
        if(a[i]==0) dem0++;
        else if (a[i]%5==0) dem5++;
    }
    if (tong % 9 == 0)
    {
        if (dem0 >= 1)
        {   //Kiểm tra nếu có số 0 dãy dãy thì thay thế nó xuống hàng đơn vị
            for (int i = j - 1; i >= 0; i--)
            {
                if (a[i] == 0)
                {
                    int temp = a[0];
                    a[0] = a[i];
                    a[i] = temp;
                    break;
                }
            }
            for (int i = 1; i <= j - 1; i++)
            {//Bắt đầu sắp xếp tăng dần từ hàng chục->hàng trăm->...
                for (int k = i + 1; k <= j; k++)
                {   if(k==j) break;
                    if (a[i] > a[k])
                    {
                        int temp = a[i];
                        a[i] = a[k];
                        a[k] = temp;
                    }
                }
            }
            for (int i = j - 1; i >= 0; i--)
                printf("%d", a[i]);
        }
        else if (dem5 >= 1 && dem0 == 0)
        {   //Kiểm tra nếu có số 5 dãy dãy thì thay thế nó xuống hàng đơn vị
            for (int i = j - 1; i >= 0; i--)
            {
                if (a[i] == 5)
                {
                    int temp = a[0];
                    a[0] = a[i];
                    a[i] = temp;
                    break;
                }
            }
            for (int i = 1; i <= j - 1; i++)
            {//Bắt đầu sắp xếp tăng dần từ hàng chục->hàng trăm->...
                for (int k = i + 1; k <= j; k++)
                {   if(k==j) break;
                    if (a[i] > a[k])
                    {
                        int temp = a[i];
                        a[i] = a[k];
                        a[k] = temp;
                    }
                }
            }
            for (int i = j - 1; i >= 0; i--)
                printf("%d", a[i]);
        }
    }
    else
        printf("-1");
    free(a);
}

#include <stdio.h>
#include <string.h>
int main() {
    char n[10005];
    scanf("%s", n);

    int a[10] = {0};
    int dem = 0;
    for (int i = 0; i < strlen(n); i++) {
        int x = n[i] - '0';
        a[x]++;
        dem += x;
    }
    if ((a[0] > 0 || a[5] > 0) && dem % 9 == 0) {
        char last;
        if (a[0] > 0) {
            last = '0';
            a[0]--;
        } else {
            last = '5';
            a[5]--;
        }
        for (int i = 9; i >= 0; i--) {
            while (a[i] > 0) {
                putchar('0' + i);
                a[i]--;
            }
        }
        putchar(last);
    }
    else {
        printf("-1");
    }
    return 0;
}