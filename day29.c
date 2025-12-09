//Ôn tập mảng 2 chiều
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
int main(){
    int n,m;
    printf("Nhập số hàng và cột:");
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Phần tử hàng %d cột %d là:",i,j);
            scanf("%d ",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}