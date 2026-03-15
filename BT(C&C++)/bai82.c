/*
Bài 82. Tạo một ma trận xoắn có dạng như sau:
a. Xoắn từ ngoài vào trong
b. Xoắn từ trong ra ngoài.
Ví dụ ma trận cấp (n x m): N=6 và n=7 cho ta dạng như sau:
1  2  3  4  5  6  7
22 23 24 25 26 27 8
21 36 37 38 39 28 9
20 35 42 41 40 29 10
19 34 33 32 31 30 11
18 17 16 15 14 13 12
*/
#include <stdio.h>
int a[1000][1000];
int b[1000][1000];
void xoanA(int n,int m){
    int tren=0,duoi=n-1;
    int trai=0,phai=m-1;
    int value=0;
    while(tren<=duoi && trai<=phai){
        for(int i=trai;i<=phai;i++)
            a[tren][i]=++value;
        tren++;
        for(int j=tren;j<=duoi;j++)
            a[j][phai]=++value;
        phai--;
        if(tren<=duoi){
            for(int i=phai;i>=trai;i--)
                a[duoi][i]=++value;
            duoi--;
        }
        if(trai<=phai){
            for(int j=duoi;j>=tren;j--)
                a[j][trai]=++value;
            trai++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
}
void xoanB(int n, int m) {
    int value=0,step=1;
    int row=n/2;
    int col=m/2;
    if(n%2==0)row--;
    if(m%2==0)col--;
    b[row][col]=++value;
    while(value<n*m){
        //Đi ngược kim đồng hồ bắt đầu bước qua trái
        for(int i=0;i<step && value<n*m;i++){
            col--;// Đi qua trái
            if(row>=0 && row<n && col<m && col>=0) b[row][col]=++value;
        }
        for(int i=0;i<step && value<n*m;i++){
            row++;//Đi xuống
            if(row>=0 && row<n && col<m && col>=0) b[row][col]=++value;
        }
        step++;//Ta cần qua phải lại step+=1 bước!
        for(int i=0;i<step && value<n*m;i++){
            col++;//Đi qua phải
            if(row>=0 && row<n && col<m && col>=0) b[row][col]=++value;
        }
        for(int i=0;i<step && value<n*m;i++){
            row--;//Đi lên
            if(row>=0 && row<n && col<m && col>=0) b[row][col]=++value;
        }
        step++;
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%4d",b[i][j]);
            }
            printf("\n");
    }
}
int main(){
    int n,m;
    printf("Nhập dòng và cột ma trận A:\n");
    scanf("%d %d",&n,&m);
    printf("\nXoắn ngoài vào trong:\n");
    xoanA(n,m);
    printf("Xoắn trong ra ngoài:\n");
    xoanB(n,m);
    return 0;
}