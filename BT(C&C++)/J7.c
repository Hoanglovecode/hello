#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
  double n,m;
  scanf("%lf %lf",&n,&m);
  double a=m*n;
  if(a<=0) printf("Yes");
  else  printf("No");
}