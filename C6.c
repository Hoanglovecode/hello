#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
int n;
int a[1000],b[1000];
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        int temp;
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        int temp2;
        if(b[i]<b[j]){
            temp2=b[i];
            b[i]=b[j];
            b[j]=temp2;
        }
    }
}
int tong=0;
for(int i=0;i<n;i++){
   tong+=a[i]*b[i];
}
printf("%d",tong);
}