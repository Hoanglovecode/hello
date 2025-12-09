/*
Bài 61. Viết chương trình có sử dụng hàm
a. Viết chương trình nhập mảng một chiều A với n phần tử (n>=15). Xuất mảng A
ra màn hình.
b. Tính tổng các số nguyên tố trong mảng,xuất kết quả ra màn hình.
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
int lasonguyento(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0) return 0;
    return 1;
}
int tongcacsonguyento(int a[],int n){
    int tong=0;
    for(int i=0;i<n;i++){
        if(lasonguyento(a[i])) tong+=a[i];
    }
    return tong;
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
  printf("\nTổng các số nguyên tố trong mảng = %d",tongcacsonguyento(a,n));
}
