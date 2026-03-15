#include <stdio.h>
#include <math.h>
float f(float x){
    float a=cbrt(4*x+7);
    return(a);
}
int main(){
    int i,n;
    float x,x0;
    float f(float);
    printf("Enter so lan lap n=");
    scanf("%d",&n);
    printf("Enter value x0=");
    scanf("%f",&x0);
    x=x0;
    for(i=1;i<=n;i++){
        x=f(x);
    }
    printf("Nghiem cua phuong trinh la: %4f",x);
}

