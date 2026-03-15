#include <stdio.h>
#include <stdlib.h>
#define ll long long
int cmp(const void*a,const void*b){
    ll x=*(const ll*)a;
    ll y=*(const ll*)b;
    if(x>y) return 1;
    if(x<y) return -1;
    return 0;
}
int main(){
    ll n,m;//n=3 hộp //m=5 viên kẹo
    scanf("%lld %lld",&n,&m);
    ll a[100000];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    qsort(a,n,sizeof(ll),cmp);
    ll tong = 0;
    int dem=0;
    for(int i=n-1;i>=0;i--){
        tong += a[i];
        dem++;
        if(tong>=m) break;
    }
    if(tong<m) printf("-1");
    else printf("%d",dem);
}