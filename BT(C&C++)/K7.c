#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int binarysearch(int a[],int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x) return 1;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return 0;
}
int main(){
  int n,x;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  scanf("%d",&x);
  if(binarysearch(a,n,x)) printf("Yes");
  else printf("No");
}