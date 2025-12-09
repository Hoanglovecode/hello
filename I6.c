#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
//Chuyển dãy mã ASII về kí tự
//Nhập số
char a[1000];
scanf("%s",&a);
int len=strlen(a);
for(int i=0;i<len;i++){
    printf("%c",a[i]);
}
//duyệt từng số từ đầu đến cuối.Nếu bắt gặp từ 6 đến 9 
//thì lấy 2 số liên tiếp
//Nếu số từ 
}