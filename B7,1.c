#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
void nhap(int a[],int n){
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
}
int binarysearch(int a[],int n,int x){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]<=x){
            ans=a[m];
            l=m+1;
        }
        else r=m-1;
    }
    return ans;
}
int main(){
    int n,x;
    scanf("%d",&n);
    int a[n];
    nhap(a,n);
    scanf("%d",&x);
    int b[x];
    nhap(b,x);
    for(int i=0;i<x;i++){
        int kq=binarysearch(a,n,b[i]);
        printf("%d\n",kq);
    }
}