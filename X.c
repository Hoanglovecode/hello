#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(){
  int n;
  long long tong=1;
  scanf("%d",&n);
  if(n==0 || n==1){
    printf("1");
  }
  else{
    for(int i=1;i<=n;i++){
          tong*=i;
    }
    printf("%lld",tong);
  }
}