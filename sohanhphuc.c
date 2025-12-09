#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main(){
    char c[1000];
    scanf("%s",c);
    if(strlen(c)%2!=0){
        printf("NO");
        return 0;
    }
    long long l=0;
    long long r=strlen(c)-1;
    long long tong1=0;
    long long tong2=0;
    while(l<r){
        tong1+=c[l]-'0';
        tong2+=c[r]-'0';
        ++l,--r;
    }
    if(tong1==tong2){
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}