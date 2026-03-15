#include <stdio.h>
#include <math.h>
#define N 100
void nhap(double a[N][N], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}
void in(double a[N][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}
double dinhthuc(double a[N][N],int n){
    double b[N][N];
    double det=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) b[i][j]=a[i][j];
    }
    for(int i=0;i<n;i++){
        if(fabs(b[i][i])<1e-9){
            int doi=i+1;//đổi=doi
            while(doi<n && fabs(b[doi][i])<1e-9)doi++;
            if(doi==n)return 0;
            for(int j=0;j<n;j++){
                double temp=b[i][j];
                b[i][j]=b[doi][j];
                b[doi][j]=temp;
            }
            det*=-1;
        }
        det*=b[i][i];
        for(int row=i+1;row<n;row++){
            double factor=b[row][i]/b[i][i];
            for(int j=i;j<n;j++){
                b[row][j]-=factor*b[i][j];
            }
        }
    }
    return det;
}
int main() {
    int n;
    double a[100][100];
    printf("Nhập số chiều ma trận vuông n = ");
    scanf("%d", &n);
    nhap(a, n);
    printf("\nMa trận vừa nhập:\n");
    in(a, n);
    printf("\nDet = %.2lf\n", dinhthuc(a, n));
    return 0;
}

