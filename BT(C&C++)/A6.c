#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
double x,sum1=0,sum2=0;
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%lf",&x);
    sum1+=x;
    sum2+=x*x;
}
double u=sum1/n;
double s=(sum2-n*u*u)/(n-1);
printf("%.2lf %.2lf",u,s);
}