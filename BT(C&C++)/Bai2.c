/*
Bài 2. Viêt chương trình có sử dụng hàm thực các công việc sau:
1.	Nhập  ma trận thực  vuông A  gồm  cấp nxn 
2.	Xuất 1 ma trận đó ra màn hình
3.	Tính định thức ma trận bằng 5 phương pháp đã học
4.	Tính nghịch đảo của ma trận A
*/
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
double dinhthuc1(double a[N][N],int n){
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
double dinhthuc2(double a[N][N],int n){
    if(n==1) return a[0][0];
    if(n==2) return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    double det=0;
    double minor[N][N];
    for(int col=0;col<n;col++){
        int r=0,c=0;
        for(int i=1;i<n;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(j==col) continue;
                minor[r][c++]=a[i][j];
            }
            r++;
        }
        det+=((col%2==0)?1:-1)*a[0][col]*dinhthuc2(minor,n-1);
    }
    return det;
}
double dinhthuc3(double a[N][N]){
    return a[0][0]*a[1][1]*a[2][2]
        + a[0][1]*a[1][2]*a[2][0]
        + a[0][2]*a[1][0]*a[2][1]
        - a[0][2]*a[1][1]*a[2][0]
        - a[0][0]*a[1][2]*a[2][1]
        - a[0][1]*a[1][0]*a[2][2];
}
double dinhthuc4(double a[N][N],int n){
    double b[N][N],det=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            b[i][j]=a[i][j];

    for(int i=0;i<n;i++){
        if(fabs(b[i][i])<1e-12) return 0;
        for(int row=i+1;row<n;row++){
            double f=b[row][i]/b[i][i];
            for(int col=i;col<n;col++)
                b[row][col]-=f*b[i][col];
        }
        det*=b[i][i];
    }
    return det;
}
int sign(int p[],int n){
    int s=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(p[i]>p[j]) s=-s;
    return s;
}
double dinhthuc5(double a[N][N],int n){
    int p[N];
    for(int i=0;i<n;i++) p[i]=i;
    double det=0;
    while(1){
        double prod=1;
        for(int i=0;i<n;i++)
            prod*=a[i][p[i]];
        det+=sign(p,n)*prod;
        int k=n-2;
        while(k>=0 && p[k]>p[k+1]) k--;
        if(k<0) break;
        int j=n-1;
        while(p[j]<p[k]) j--;
        int t=p[k]; p[k]=p[j]; p[j]=t;
        for(int i=k+1,j=n-1;i<j;i++,j--){
            t=p[i]; p[i]=p[j]; p[j]=t;
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
  printf("\nDet ma trận trên theo phương pháp gauss = %lf",dinhthuc1(a,n));
  printf("\nDet ma trận trên theo phương pháp Laplace = %lf",dinhthuc2(a,n));
  if(n==3){
    printf("\nDet ma trận trên theo phương pháp Sarrus = %lf",dinhthuc3(a));
    printf("\nDet ma trận trên theo phương pháp phân rã LU = %lf",dinhthuc4(a,n));
    printf("\nDet ma trận trên theo phương pháp hoán vị Leibniz = %lf",dinhthuc5(a,n));
  }
  else{
    printf("\nDet ma trận trên theo phương pháp phân rã LU = %lf",dinhthuc4(a,n));
    printf("\nDet ma trận trên theo phương pháp hoán vị Leibniz = %lf",dinhthuc5(a,n));
  }
  if(nghichdao(a,inv,n)){
    printf("\nMa trận nghịch đảo:\n");
    in(inv,n);
  }
  else printf("\nMa trận trên không khả nghịch");
}