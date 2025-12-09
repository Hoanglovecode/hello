#include <stdio.h>
#define ll long long
int main(){
    long long m,n,k;
    scanf("%lld %lld %lld",&m,&n,&k);
    ll ans=1;
    while(n>0){
        if(n%2==1)ans=ans*m%k;
        m=m*m%k;
        n/=2;
    }  
    printf("%lld",ans);
}