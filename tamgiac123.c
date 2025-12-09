#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
  int a=1;
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    for(int j=1;j<=i;j++){
        printf("%d",a);
        a++;
        if(j<i)printf(" ");
        if(a==4)a=1;
    }
    printf("\n");
  }
}