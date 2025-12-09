#include <stdio.h>
#include <string.h>
int main(){
    char a[105];
    scanf("%s",&a);
    int len=strlen(a);
    if(a[len-1]=='0')printf("YES");
    else printf("NO");
}