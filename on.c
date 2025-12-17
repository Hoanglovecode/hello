#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int ucln(int a,int b){
    if(b==0) return a;
    return ucln(b,a%b);
}
int bcnn(int a,int b){
    return a*b/ucln(a,b);
}
int main(){
  
}