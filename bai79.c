/*
Bài 79. Viết chương trình có sử dụng hàm để nhập ma trận A cấp nxn (với n nhập từ
bàn phím):
a. Xuất ma trận A ra màn hình
b. Đưa phần tử lớn nhất của từng hàng của ma trận lên đường chéo chính và
tính tổng các phần tử lớn nhất đó
*/
#include <stdio.h>
void nhapham(int n,int a[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("a[%d][%d]=",j,i);
            scanf("%d",&a[i][j]);
        }
    }
}
void xuatham(int n,int a[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int tongduongcheochinh(int n,int a[100][100],int b[100][100]){
    int tong=0;
    for(int i=0;i<n;i++){
        int max=a[i][0];
        for(int j=0;j<n;j++){
           if(max<=a[i][j])max=a[i][j];
        }
        b[i][i]=max;
        tong+=max;
    }
    return tong;
}
void xuatham2(int n,int b[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Nhập số chiều ma trận A:\n");
    scanf("%d",&n);
    int a[100][100];
    nhapham(n,a);
    printf("Ma trận A vừa nhập:\n");
    xuatham(n,a);
    int b[100][100]={0};
    int tong=tongduongcheochinh(n,a,b);
    printf("Ma trận có đường chéo chính là phần tử lớn nhất ở từng hàng ma trận A:\n");
    xuatham2(n,b);
    printf("Tổng các phần tử lớn nhất ở đường chéo chính = %d",tong);
}