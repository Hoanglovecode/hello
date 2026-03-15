#include <stdio.h>
#define N 10
void nhap(double a[N][N],int n){
    printf("Ma trận vuông cấp %dx%d\n",n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("a[%d][%d]= ",i,j);
            scanf("%lf",&a[i][j]);
        }
    }
}
void in(double a[N][N],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%8.4lf",a[i][j]);
        printf("\n");
    }
}
int nghichdao(double a[N][N],double inverse[N][N],int n){
    double aug[N][2*N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) aug[i][j]=a[i][j];
        for(int j=n;j<2*n;j++)aug[i][j]=(i==j-n)?1:0;
    }
    for(int i=0;i<n;i++){
        if(aug[i][i]==0){
            int k;
            for(int k=i+1;k<n;k++){
                if(aug[k][i]!=0)break;
                if(k==n) return 0;
                for(int j=0;j<2*n;j++){
                    double temp=aug[i][j];
                    aug[i][j]=aug[k][j];
                    aug[k][j]=temp;
                }
            }
        }
        double diag=aug[i][i];
        for(int j=0;j<2*n;j++)aug[i][j]/=diag;
        for(int k=0;k<n;k++){
            if(k!=i){
                double factor=aug[k][i];
                for(int j=0;j<2*n;j++) aug[k][j]-=factor*aug[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) inverse[i][j]=aug[i][j+n];
    }
    return 1;
}
int main(){

}