#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
int main()
{
    int dem1=0,dem2=0,dem3=0,dem4=0;
    int i,n,c=0;
    int a[20];
    unsigned ll b;
    scanf("%llu",&b);
    while(b){
        c=b%10;
        a[i]=c;
        i++;n++;
        b/=10;
    }
    for(int i=0;i<=n;i++){
        if (a[i] == 2)dem1++;
        else if (a[i] == 3)dem2++;      
        else if (a[i] == 5)dem3++;
        else if (a[i] == 7)dem4++;
    }
    printf("%d\n",dem1);
    printf("%d\n",dem2);
    printf("%d\n",dem3);
    printf("%d\n",dem4);
}