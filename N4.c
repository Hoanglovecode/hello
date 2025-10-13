#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(){
int a;
int dem=0;
scanf("%d",&a);
if(a>=1 && a<=pow(10,9)){
    for(int i=1;i<=a;i++){
        if(a%i==0){
            dem++;
        }
    }
    printf("%d",dem);
}
}