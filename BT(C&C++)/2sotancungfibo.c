//Fibo lũy thừa ma trận 
#include <stdio.h>
#define ll long long
void nhan(int a[2][2],int b[2][2],int c[2][2]){
    //Nhân 2 ma trận a và b và lưu vào ma trận c
    c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%100;
    c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%100;
    c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%100;
    c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%100;
}
int fibo_mod100(ll n){
    if(n<=2) return 1;
    int r[2][2]={{1,0},{0,1}};//result là ma trận đơn vị
    int b[2][2]={{1,1},{1,0}};//base là ma trận lũy thừa fibo
    int temp[2][2];// Ma trận chứa tích 2 ma trận 
    n-=1;
    while(n>0){
        if((n&1)==1){//Nếu bit cuối cùng bằng 1 thì nhân r vs b
            nhan(r,b,temp);
            //lưu temp về lại r
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    r[i][j]=temp[i][j]; 
        }
        nhan(b,b,temp);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                b[i][j]=temp[i][j];
        n>>=1;
    }
    return r[0][0]%100;
}
int main(){
    ll n;
    scanf("%lld",&n);
    int ans=fibo_mod100(n);
    printf("2 chữ số tận cùng fibo thứ %lld là : %02d",n,ans);
}
