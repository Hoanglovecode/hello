/*
Bài 76.Viết chương trình có sử dụng hàm để nhập ma trận A cấp nxn (với n nhập từ bàn
phím):
a. Xuất ma trận A ra màn hình
b. Đưa phần tử bé nhất của từng hàng của ma trận lên đường chéo phụ, và tính
tổng các phần tử bé nhất đó 
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
int tongduongcheophu(int n,int a[100][100],int b[100][100]){
    int tong=0;
    for(int i=0;i<n;i++){
        int min=a[i][0];
        for(int j=0;j<n;j++){
           if(min>=a[i][j])min=a[i][j];
        }
        b[i][n-1-i]=min;
        tong+=min;
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
    printf("Nhập hàng và cột ma trận A:\n");
    scanf("%d",&n);
    int a[100][100];
    nhapham(n,a);
    printf("Ma trận A vừa nhập:\n");
    xuatham(n,a);
    int b[100][100]={0};
    int tong=tongduongcheophu(n,a,b);
    printf("Ma trận có đường chéo phụ là phần tử nhỏ nhất ở từng hàng ma trận A:\n");
    xuatham2(n,b);
    printf("Tổng các phần tử bé nhất ở đường chéo phụ = %d",tong);
}