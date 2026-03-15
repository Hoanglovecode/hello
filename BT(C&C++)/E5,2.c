//Fibo lũy thừa ma trận 
#include <stdio.h>
#define ll long long
ll m;
void nhan(ll a[2][2],ll b[2][2],ll c[2][2]){
    //Nhân 2 ma trận a và b và lưu vào ma trận c
    c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%m;
    c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%m;
    c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%m;
    c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%m;
}
ll fibo(ll n){
    if(n<=2) return 1;
    ll r[2][2]={{1,0},{0,1}};//result là ma trận đơn vị
    ll b[2][2]={{1,1},{1,0}};//base là ma trận lũy thừa fibo
    ll temp[2][2];// Ma trận chứa tích 2 ma trận 
    n-=1;
    while(n>0){
        if((n&1)==1){//Nếu bit cuối cùng bằng 1 thì nhân r vs b
            nhan(r,b,temp);
            for(ll i=0;i<2;i++)
                for(ll j=0;j<2;j++)
                    r[i][j]=temp[i][j];//lưu kế quả nhân về result
        }
        nhan(b,b,temp);
        for(ll i=0;i<2;i++)
            for(ll j=0;j<2;j++)
                b[i][j]=temp[i][j];//lưu kết quả nhân về lại base
        n>>=1;
    }
    return r[0][0]%m;
}
ll main(){
    ll n;
    scanf("%lld %lld",&n,&m);
    ll ans=fibo(n)%m;
    printf("%lld",ans);
}