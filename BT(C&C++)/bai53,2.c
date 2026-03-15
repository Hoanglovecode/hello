#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int a[10000];
void giaithua(int a[],int n){
  printf("%d giai thừa = ",n);
  int len=1;
  a[0]=1;
  for(int i=2;i<=n;i++){
    int carry =0;
    for(int j=0;j<len;j++){
        int nhan=a[j]*i+carry;
        a[j]=nhan%10;
        carry=nhan/10;
    }
    while(carry>0){
        a[len]=carry%10;
        carry/=10;
        len++;
    }
  }
  for(int i=len-1;i>=0;i--) printf("%d",a[i]);
}
void mu2000(int a[],int n){
  printf("\n2 mũ %d = ",n);
  int len=1;
  a[0]=1;
  for(int i=0;i<n;i++){
    int carry =0;
    for(int j=0;j<len;j++){
        int nhan=a[j]*2+carry;
        a[j]=nhan%10;
        carry=nhan/10;
    }
    while(carry>0){
        a[len]=carry%10;
        carry/=10;
        len++;
    }
  }
  for(int i=len-1;i>=0;i--) printf("%d",a[i]);
}
int main(){
  int n;
  scanf("%d",&n);
  giaithua(a,n);
  mu2000(a,n);
}