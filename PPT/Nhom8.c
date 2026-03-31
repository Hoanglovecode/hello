#include <stdio.h>
#include <math.h>
#define MAX 100
int n;
double a[MAX];
double eps=0.0000000001;
void nhapdathuc() {
    printf("Nhap bac da thuc: ");
    scanf("%d",&n);
    printf("Nhap he so tu bac 0 den bac %d:\n",n);
    for(int i=0;i<=n;i++)scanf("%lf",&a[i]);
}
double hoocner(double x){
    double result=a[n];
    for(int i=n-1;i>=0;i--)result=result*x+a[i];
    return result;
}
double Daoham(double x){
    double result=0;
    for(int i=1;i<=n;i++)result+=i*a[i]*pow(x,i-1);
    return result;
}
double newton(double x0){
    double x=x0;
    int cnt=0;
    do{
        double fx=hoocner(x);
        double fpx=Daoham(x);
        if(fpx==0){
            printf("Dao ham bang 0\n");
            return x;
        }
        double x1=x-fx/fpx;
        if(fabs(x1-x)<eps)
            return x1;
        x=x1;
        cnt++;
    }while(cnt<1000);
    return x;
}
double chiadoi(double l,double r){
    double mid;
    if(hoocner(l)*hoocner(r)>0){
        printf("Khoang khong hop le\n");
        return -1;
    }
    while(fabs(r-l)>eps){
        mid=(l+r)/2;
        if(hoocner(l)*hoocner(mid)<=0)r=mid;
        else l=mid;
    }
    return (l+r)/2;
}
double daycung(double x0,double x1){
    double x2;
    int cnt=0;
    do{
        double f0=hoocner(x0);
        double f1=hoocner(x1);
        if(f1-f0==0){
            printf("Khong the chia\n");
            return x1;
        }
        x2=x1-f1*(x1-x0)/(f1-f0);
        if(fabs(x2-x1)<eps)return x2;
        x0=x1;
        x1=x2;
        cnt++;
    }while(cnt<1000);
    return x2;
}
double lap(double x0){
    double x1;
    int cnt=0;
    do{
        x1=x0-hoocner(x0); 
        if(fabs(x1-x0)<eps)return x1;
        x0=x1;
        cnt++;
    }while(cnt<1000);
    return x1;
}
int main(){
    nhapdathuc();
    int choice=1;
    while(choice!=0){
        printf("\n===== MENU =====\n");
        printf("1.Tinh gia tri da thuc (Hoocner)\n");
        printf("2.Newton\n");
        printf("3.Chia doi\n");
        printf("4.Day cung\n");
        printf("5.lap\n");
        printf("0.Thoat\n");
        printf("Chon phuong phap: ");
        scanf("%d",&choice);
        if(choice==1){
            double x;
            printf("Nhap x: ");
            scanf("%lf",&x);
            printf("-------------------------------Gia tri da thuc = %lf\n",hoocner(x));
        }
        else if(choice==2){
            double x0;
            printf("Nhap x0: ");
            scanf("%lf",&x0);
            printf("-------------------------------Nghiem Newton = %lf\n",newton(x0));
        }
        else if(choice==3){
            double a,b;
            printf("Nhap khoang [a,b]: ");
            scanf("%lf %lf",&a,&b);
            printf("-------------------------------Nghiem chia doi = %lf\n",chiadoi(a,b));
        }
        else if(choice==4){
            double x0,x1;
            printf("Nhap x0 x1: ");
            scanf("%lf %lf",&x0,&x1);
            printf("-------------------------------Nghiem day cung = %lf\n",daycung(x0,x1));
        }
        else if(choice==5){
            double x0;
            printf("Nhap x0: ");
            scanf("%lf",&x0);
            printf("-------------------------------Nghiem lap = %lf\n",lap(x0));
        }
        else if(choice==0){
            printf("-------------------------------Ket thuc chuong trinh!\n");
        }
        else{
            printf("lua chon khong hop le\n");
        }
    }
}