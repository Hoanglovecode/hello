#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
char a[100];
fgets(a,100,stdin);
int dem=0;
for(int i=0;i<strlen(a);i++){
    if(a[i]==' ') dem++;
}
printf("%d",dem);
}