#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  int x;
  scanf("%d",&x);
  int b[x];
  for(int i=0;i<x;i++)scanf("%d",&b[i]);
  for(int i=0;i<x;i++){// cho b[0]=7
    int best=-1;
    for(int j=0;j<n;j++){
      if(a[j]<=b[i]) best=a[j];
      else break;
    }
    printf("%d",best);
    printf("\n");
  }
}