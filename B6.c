#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
//Khi muốn sắp xếp tăng dần a nhỏ hơn b thì trả về -1
//Khi muốn sắp xếp giảm dần a lớn hơn b thì trả về 1
int cmp(const void*a,const void*b){
    int x= *(int*)a;
    int y=*(int*)b;
    return x-y;
}
int main(){
int n,k;
scanf("%d %d",&n, &k);
//Cấp phát động giúp tối ưu run time
int *a = (int*)malloc(n * sizeof(int));//n có thể tối đa là 1 tỷ
for(int i=0;i<n;i++) scanf("%d",&a[i]);
//sắp xếp tăng dần
qsort(a,n,sizeof(int),cmp);
//Sài ll thay vì int để tránh bị tràn
ll tong=0;
for(int i=0;i<k;i++) tong+=a[i];
printf("%lld",tong);
free(a);//Giải phóng bộ nhớ xin cấp phát
}
//Cách giải khác tham khảo thêm
/*
int main(){   
int n,k;
int a[100];
scanf("%d %d",&n, &k);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
int tong=0;
for(int i=0;i<k;i++){
    tong+=a[i];   
}
printf("%d",tong);
}
*/