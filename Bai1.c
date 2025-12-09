/*
Bài 1. Viêt chương trình có sử dụng hàm thực các công việc sau
1. Nhập 2 ma trận thực  A và B  gồm  cấp mxn và pxq
2. Xuất 2 ma trận đó ra màn hình
3. Thực hiện nhân 2 nhân 2 ma trận  A và B trong điều kiện số cột của ma trận A bằng số hàng của ma trận B
4. Chuyển vị ma  trận tích của A và B
5. Đưa phần tử lớn nhất của từng hàng của ma trận A lên đường chéo chính khi ma trận A là 1 ma trận vuông. Tính tổng các phần tử của lớn nhất của từng hàng trên đường chéo chính sau đó đổi sang cơ số bất kỳ ( cơ số nhập từ bàn phím : Cơ số từ 2 đến 16)
6. Đưa phần tử bé nhất của của từng cột của ma trận B lên đường chéo phụ khi ma trận B là 1 ma trận vuông
7. Tìm hạng của ma trận B
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
#define MAX 200
int m,n,p,q;
void nhap(double a[N][N],double b[N][N]){
    printf("Nhập dòng và cột ma trận A:\n");
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("a[%d][%d]=",i,j);
            scanf("%lf",&a[i][j]);
        }
    }
    printf("\nNhập dòng và cột ma trận B:\n");
    scanf("%d %d",&p,&q);
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("b[%d][%d]=",i,j);
            scanf("%lf",&b[i][j]);
        }
    }
}
void in(double a[N][N],double b[N][N]){
    printf("\nMa trận A:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%lf ",a[i][j]);
        printf("\n");
    }
    printf("\nMa trận B:\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++)
            printf("%lf ",b[i][j]);
        printf("\n");
    }
}
void nhan2matran(double a[N][N],double b[N][N],double c[N][N]){
    if(n==p){
        printf("\nTích 2 ma trên:\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                c[i][j]=0;
                for(int k=0;k<n;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
                printf("%lf ",c[i][j]);
            }
            printf("\n");
        }
    }
    else printf("Không thể nhân hai ma trận");
}
void chuyenvi(double c[N][N],int m,int q){
    double temp[N][N];
    for(int i=0;i<q;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=c[j][i];
        }
    }
    printf("\nMa trận chuyển vị:\n");
    for(int i=0;i<q;i++){
        for(int  j=0;j<m;j++){
            printf("%lf",temp[i][j]);
        }
        printf("\n");
    }
}
double tonglonnhat(double a[N][N],double d[N][N]){
    double tong=0;
    for(int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            d[i][j]=0;
    for(int i=0;i<m;i++){
        double max=a[i][0];
        for(int j=0;j<n;j++){
           if(max<=a[i][j])max=a[i][j];
        }
        d[i][i]=max;
        tong+=max;
    }
    return tong;
}
void dualonnhat(double a[N][N],double d[N][N]){
    printf("\nĐưa phần tử lớn nhất của từng hàng của ma trận A lên đường chéo chính khi ma trận A là 1 ma trận vuông:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%lf ",d[i][j]);
        }
        printf("\n");
    }
}
double tongnhonhat(double a[N][N],double e[N][N]){
    double tong=0;
    for(int j=0;j<n;j++){
        double min=a[0][j];
        for(int i=0;i<n;i++){
           if(min>=a[i][j])min=a[i][j];
        }
        e[j][n-1-j]=min;
        tong+=min;
    }
    return tong;
}
void duanhonhat(double b[N][N],double e[N][N]){
    printf("\nĐưa phần tử bé nhất của của từng cột của ma trận B lên đường chéo phụ khi ma trận B là 1 ma trận vuông:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%lf ",e[i][j]);
        }
        printf("\n");
    }
}
void chuyenPhanNguyen(unsigned long long n,int coSo,char *ketQua){
    char cs[]="0123456789ABCDEF";
    char temp[MAX];
    int id=0;
    if(n==0){
        strcpy(ketQua,"0");
        return;
    }
    while(n>0){
        temp[id++]=cs[n%coSo];
        n/=coSo;
    }
    for(int i=0;i<id;i++)
        ketQua[i]=temp[id-1-i];
    ketQua[id]='\0';
}
void chuyenPhanThapPhan(double x,int coSo,char *ketQua,int limit){
    char cs[]="0123456789ABCDEF";
    int id=0;
    while(id<limit && fabs(x)>1e-15){
        x*=coSo;
        int digit=(int)x;
        ketQua[id++]=cs[digit];
        x-=digit;
    }
    ketQua[id]='\0';
}
void doiCoSo(double x,int coSo,char *ketQuaCuoi){
    char ng[MAX],tp[MAX];
    int am=x<0;
    if(am) x=-x;
    unsigned long long nguyen=(unsigned long long)x;
    double thapPhan=x-nguyen;
    chuyenPhanNguyen(nguyen,coSo,ng);
    chuyenPhanThapPhan(thapPhan,coSo,tp,20);
    if(strlen(tp)==0)
        sprintf(ketQuaCuoi,"%s%s",am?"-":"",ng);
    else
        sprintf(ketQuaCuoi,"%s%s.%s",am?"-":"",ng,tp);
}
int rank(double b[N][N],int n){
    int rank=0;
    for(int i=0;i<n;i++){
        int pivot=i;
        while(pivot<n && fabs(b[pivot][i])<1e-9)pivot++;
        if(pivot==n) continue;
        if(pivot!=i){
            for(int j=0;j<n;j++){
                double temp=b[i][j];
                b[i][j]=b[pivot][j];
                b[pivot][j]=temp;
            }
        }
        for(int row=i+1;row<n;row++){
            double factor=b[row][i]/b[i][i];
            for(int j=i;j<n;j++){
                b[row][j]-=factor*b[i][j];
            }
        }
        rank++;
    }
    return rank;
}
int main(){
  double a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];
  nhap(a,b);
  in(a,b);
  nhan2matran(a,b,c);
  chuyenvi(c,m,q);
  double tongMax=tonglonnhat(a,d);
  dualonnhat(a,d);
  printf("\nTổng các phần tử lớn nhất mỗi hàng = %.6lf\n", tongMax);
  int coSo;
  printf("Nhập cơ số cần đổi (2->16): ");
  scanf("%d", &coSo);
  char ketQua[MAX];
  doiCoSo(tongMax, coSo, ketQua);
  printf("Tổng sau khi đổi sang cơ số %d = %s\n", coSo, ketQua);
  double tongMin=tongnhonhat(b,e);
  duanhonhat(b,e);
  printf("\nHạng ma trận B = %d",rank(b,n));
}