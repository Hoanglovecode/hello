#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
if(n>=2 && n<=3){
    int a[3];
    for (int i = 0; i <n; i++)
    {  
        scanf("%d",&a[i]); 
    }
    int max=a[0];
    for (int i = 0; i <n; i++)
    { 
        if(max<=a[i])
            max=a[i];
    }
    for(int j=1;j<=max;j++)
    {
        if(n=2){
            if(a[0]%j==0 && a[1]%j==0){
              printf("\n%d",j);
            }
        }
        else{
            if(a[0]%j==0 && a[1]%j==0 && a[2]%j==0){
              printf("\n%d",j);
            }
        }
    }
}
}