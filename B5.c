#include <stdio.h>
#include <math.h>
#define ll long long
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
  ll a,b;
  scanf("%lld %lld",&a,&b);
  if(a>=1 && b>=1 &&a<=pow(10,18) &&b<=pow(10,18))printf("%lld",gcd(a,b));
}