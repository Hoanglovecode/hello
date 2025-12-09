//Bài 51:Viết chương trình sử dụng hàm để tính tổ hợp và xuất tam giác pascal
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
ll giaithua(ll n){
    ll tong=1;
    for(int i=1;i<=n;i++){
        tong*=i;
    }
    return tong;
}
ll tohop(ll n,ll k){
      ll a=giaithua(n)/(giaithua(n-k)*giaithua(k));
      return a;
}
int main(){
  ll n;
  printf("Nhập số hàng tam giác pascal:");
  scanf("%lld",&n);
  for(int i=0;i<n;i++){
    //In dấu khoảng các mỗi khi xuống dòng
    for(int cach=0;cach<n-i;cach++)printf(" ");
    //Liệt kê tổ hợp ra cùng 1 dòng
    for(int j=0;j<=i;j++) printf("%lld ",tohop(i,j));
    printf("\n");
  }
}