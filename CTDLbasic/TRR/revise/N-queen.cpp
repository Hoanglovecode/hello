#include <stdio.h>
int n,k;
int x[100];
void INP(){
    for(int i=1;i<=n;i++)printf("%d ",x[i]);
    printf("\n");
}
void quaylui(int i,int tong){
    if(i==n){
        x[i]=k-tong;
        if(x[i]>=0)INP();
        return;
    }
    for(int j=0;j<=k-tong;j++){
        x[i]=j;
        quaylui(i+1,tong+j);
    }
}
int main(){
    printf("Nhap n ja k:");
    scanf("%d %d",&n,&k);
    quaylui(1,0);
    return 0;
}