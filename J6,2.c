#include <stdio.h>
#include <string.h>
int main(){
    char n[10005];
    scanf("%s",&n);
    int dem=0;
    int a[10]={0};
    for(int i=0;i<strlen(n);i++){
        int x=n[i]-'0';
        a[x]++;
        dem+=x;
    }
    if((a[0]>0 || a[5]>0) && dem%9==0){
        char last;
        if(a[0]>0){
            last='0';
            a[0]--;
        }
        else{
            last='5';
            a[5]--;
        }
        for(int i=9;i>=0;i--){
            while(a[i]>0){
                putchar('0'+i);
                a[i]--;
            }
        }
        putchar(last);
    }
    else printf("-1");
}