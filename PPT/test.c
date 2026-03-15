#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
float cos1(float x, float eps){
    int k=0;
    float q=0.0,t=1;
    while(abs(t)>=eps){
        q+=t;
        k+=2;
        t=-t*x*x/(k*(k-1));
    }
    return q;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    float x,eps;scanf("%f %f",&x,&eps);
    printf("%f",cos1(x,eps));
}