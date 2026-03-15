#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll s=a*b/gcd(a,b);
    return s;
}
int main(){
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    if (n >= 1 && a >= 1 && b >= 1 && n <= pow(10, 9) && a <= pow(10, 9) && b <= pow(10, 9))
    {
        ll dem=n/a+n/b-n/lcm(a,b);
        printf("%lld",dem);
    }
}
