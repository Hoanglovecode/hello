#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
  int h,m,s,x;
  scanf("%d %d %d %d",&h,&m,&s,&x);
  for(int i=1;i<=x;i++){
    s++;
    if(s==60){
      m++;
      s=0;
    }
    if(m==60){
      h++;
      m=0;
    }
    if(h==13){
      h=1;
      m=0;
      s=0;
    }
  }
  printf("%d %d %d",h,m,s);
}