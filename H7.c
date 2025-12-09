#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
  return *(int*)a-*(int*)b;
}
int tiemkiem(int a[],int n,int x){
  int l=0,r=n-1;
  while(l<=r){
    int m=(l+r)/2;
    if(a[m]==x) return 1;
    if(a[m]>=x) r=m-1;
    else l=m+1;
  }
  return 0;
}
int main(){
  int n,q;
  scanf("%d %d",&n,&q);
  int a[n],b[q];
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  for(int i=0;i<q;i++) scanf("%d",&b[i]);
  qsort(a,n,sizeof(int),cmp);
  for(int i=0;i<q;i++){
    if(tiemkiem(a,n,b[i]))printf("YES\n");
    else printf("NO\n");
  }
}

