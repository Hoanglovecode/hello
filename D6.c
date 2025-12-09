#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
char a[1000],b[1000];
gets(a);
gets(b);
int lena=strlen(a);
int lenb=strlen(b);
printf("%d",abs(lena-lenb));
}