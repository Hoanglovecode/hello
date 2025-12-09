#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
//UCLL
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
//BCNN
unsigned ll lcm(ll a ,ll b){
    return (unsigned ll)a*b/gcd(a,b);
}
int main(){
  ll a,b;
  scanf("%lld %lld",&a,&b);
  if(a>=1 && b>=1 &&a<=pow(10,18) &&b<=pow(10,18))printf("%llu",lcm(a,b));
}