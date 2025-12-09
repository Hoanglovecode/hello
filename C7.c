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
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
  }
  int dem=0;
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1])dem++;
  }
  printf("%d",n-dem);
  printf("\n%d",a[0]);
  for(int i=1;i<n;i++){
    if(a[i]!=a[i-1])printf("\n%d",a[i]);
  }
}