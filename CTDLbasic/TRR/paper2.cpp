#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
ll n,b;
int a[100];
void xuat(){
    for(int i=1;i<=n;i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}
void phuongphapquaylui(int i,ll tong) {
    if(i == n) {
        a[i] = b - tong;
        if (a[i] >= 0) {
            xuat();
        }
        return;
    }
    for(int k=0; k<=b-tong;k++) {
        a[i] = k;
        phuongphapquaylui(i+1, tong+k);
    }
}
int main() {
    printf("Nhap n, b: ");
    scanf("%lld %lld", &n, &b);
    phuongphapquaylui(1, 0);
    return 0;
}