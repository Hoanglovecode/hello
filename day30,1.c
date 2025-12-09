//Kiểm tra 2 xâu nhập từ bàn phím có giống nhau 2 không
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s", s);
    char x[100];
    scanf("%s", x);
    //cách 1 sài for
    int a = 0;
    if (strlen(s) == strlen(x))
    {
        for (int i = 0; i < strlen(s); i++){
                if (s[i] == x[i]) a++;
        }
        if (a == strlen(s)) printf("two people having the same name");
        else printf("two people don't have the same name");
    }
    else  printf("two people don't have the same name");
    /*
    cách 2 strcmp.Trả về 0 nếu 2 xâu giống nhau.
    if(strcmp(s,x)==0) printf("two people having the same name");
    else  printf("two people don't have the same name");
    */
}