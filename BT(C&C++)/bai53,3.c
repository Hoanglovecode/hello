#include <stdio.h>
#include <string.h>
int main(){
    int len=1;
    int a[10000];
    a[0]=1;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int carry=0;
        for(int j=0;j<len;j++){
            int mul=a[j]*2+carry;
            a[j]=mul%10;
            carry=mul/10;
        }
        while(carry>0){
            a[len]=carry%10;
            carry/=10;
            len++;
        }
    }
    for(int i=len-1;i>=0;i--)printf("%d",a[i]);
}