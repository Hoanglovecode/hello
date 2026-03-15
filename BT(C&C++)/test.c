#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
    ll n,q,k;
    char s[10];
    scanf("%lld %lld %lld",&n,&q,&k);
    scanf("%s",&s);
    if (s[0] == 'c'){
        ll sopheptinh=n*q;
        ll ML=n*k;
        ll TL=sopheptinh*2+ML*5;
        if(TL>5*pow(10,8)){
            printf("TL");
            if(ML>2*pow(10,7)) printf(" and ML");
        }
        else{
            if(ML>2*pow(10,7)) printf("ML");
            else printf("OK");
        }
    }
    else if(s[0]=='j'){
        ll sopheptinh=n*q;
        ll ML=n*k;
        ll TL=sopheptinh*2+ML*5;
        if(TL>pow(10,8)){
            printf("TL");
            if(ML>2*pow(10,7)) printf(" and ML");
        }
        else{
            if(ML>2*pow(10,7)) printf("ML");
            else printf("OK");
        }
    }
    else if(s[0]=='p'){
        ll sopheptinh=n*q;
        ll ML=n*k;
        ll TL=sopheptinh*2+ML*5;
        if(TL>2*pow(10,7)){
            printf("TL");
            if(ML>2*pow(10,7)) printf(" and ML");
        }
        else{
            if(ML>2*pow(10,7)) printf("ML");
            else printf("OK");
        }
    }
}