/*
Bài 65.Viết chương trình nhập mảng 1 chiều A có N phần tử có sử dụng hàm(với N
nhập từ bàn phím). :
a. Xuất các phần tử đã nhập ra màn hình
b. Xuất ra màn hình giá trị nguyên dương lẻ lớn nhất
*/
#include <stdio.h>
//Câu a)
void nhap(int a[],int n){
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
}
void xuat(int a[],int n){
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}
//Câu b)
int solelonnhat(int a[],int n){
    int max=a[0];
    for(int i=0;i<n;i++) if(a[i]%2!=0)max=a[i];
    return max;
}
int main(){
  int n;
  printf("Nhập số lượng phần tử:");
  scanf("%d",&n);
  int a[n];
  printf("Nhập %d phần tử vào mảng A:\n",n);
  nhap(a,n);
  printf("Mảng A vừa nhập là:");
  xuat(a,n);
  printf("\nGiá trị nguyên dương lẻ lớn nhất trong mảng là: %d",solelonnhat(a,n));
}