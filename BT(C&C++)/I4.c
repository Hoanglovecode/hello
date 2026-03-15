#include <stdio.h>
#include <math.h>
int main(){
  int dem=0;
  int s[1000000];
  for(int i=0;i<=1000000;i++){
    scanf("%d",&s[i]);
    if(s[i]%2!=0){
        dem++;
    }
    if(s[i]==0)
    break;
  }
  printf("%d",dem);
}