#include <stdio.h>
#include <math.h>
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
int nghichdao(double a[N][N],double inverse[N][N],int n){
    double aug[N][2*N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)aug[i][j]=a[i][j];
        for(int j=n;j<2*n;j++)aug[i][j]=(i==j-n)?1:0;
    }
    for(int i=0;i<n;i++){
        if(aug[i][i]==0){
            int k;
            for(k=i+1;k<n;k++){
                if(aug[k][i]!=0) break;
            }
            if(k==n) return 0;
            for(int j=0;j<2*n;j++){
                double temp=aug[i][j];
                aug[i][j]=aug[k][j];
                aug[k][j]=temp;
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
  int n;
  double a[N][N],inv[N][N];
  printf("Nhập kích cỡ ma trận vuông:");
  scanf("%d",&n);
  nhap(a,n);
  printf("\nMa trận vừa nhập:\n");
  in(a,n);
  if(nghichdao(a,inv,n)){
    printf("\nMa trận trận nghịch đảo:\n");
    in(inv,n);
  }
  else printf("\nMa trận trên không khả nghịch");
  printf("\nDet ma trận trên = %lf",dinhthuc(a,n));
}