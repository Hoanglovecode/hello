#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
char a[100];
scanf("%s",&a);
int len=strlen(a);
for(int i=0;i<len-1;i++){
    if(a[i]==a[i+1]){
        printf("NO");
        return 0;
    }
}
printf("YES");
return 0;
}