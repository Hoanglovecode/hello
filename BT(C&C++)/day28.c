//Ôn tập mảng 1 chiều
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
//hàm ktr có phải là 1 số nguyên tố
int snt(int n){
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  //Nhập các phần tử trong mảng
  int res=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    //Kiểm tra số nguyên tố
    if(snt(a[i])) res++;
  }
  //In ra số lượng số nguyên tố
  printf("%d",res);
}