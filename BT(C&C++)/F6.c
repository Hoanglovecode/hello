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
for(int i=0;i<strlen(a);i++){
    if(a[i]>='A' && a[i]<='Z'){
        a[i]+=32;
    }
    else if(a[i]>='a' && a[i]<='z'){
        a[i]-=32;
    }
}
printf("%s",a);
}