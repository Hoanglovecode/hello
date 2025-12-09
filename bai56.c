/*
Bài 56. Viết chương trình có sử dụng hàm
a. Viết chương trình nhập mảng một chiều A với n phần tử, n được nhập từ bàn
phím. Xuất mảng A ra màn hình ?
b. Số hoàn hảo là số nguyên dương và bằng tổng các ước thực sự của nó không kể
chính nó. Ví dụ: 6=1+2+3.
Xuất các số hoàn hảo trong mảng A ra màn hình ?
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
int kiemtrasohoanhao(int n){
    int tong=0;
    for(int i=1;i<n;i++){
        if(n%i==0) tong+=i;
    }
    return tong==n;//Nếu đúng trả về 1 sai thì trả về 0
}
void xuatsohoanhao(int a[],int n){
    int dem=0;
    for(int i=0;i<n;i++){
        if(kiemtrasohoanhao(a[i])){
            printf("%d",a[i]);
            dem++;
        }
    }
    if(dem==0)printf("\nKhông có số hoàn hảo trong mảng A");
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
  printf("\nKiểm tra số hoàn hảo trong mảng A:");
  xuatsohoanhao(a,n);
}