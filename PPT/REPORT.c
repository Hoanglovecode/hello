#include <stdio.h>
#include <math.h>
#define MAX 100
int n;
double a[MAX];
double eps = 0.000000001;
void nhapdathuc() {
    printf("Nhap bac da thuc: ");
    scanf("%d",&n);
    printf("Nhap he so tu bac 0 den bac %d:\n",n);
    for(int i=0;i<=n;i++) scanf("%lf",&a[i]);
}
double hoocner(double x){
    double result=a[n];
    for(int i=n-1;i>=0;i--)result=result*x+a[i];
    return result;
}
double daoham(double x){
    double result=0;
    for(int i=1;i<=n;i++)result+=i*a[i]*pow(x,i-1);
    return result;
}
double tieptuyen(double x0){
    double x=x0;
    int cnt=0;
    printf("\n=== Bang lap (Tieptuyen) ===\n");
    printf("Lan\t x\t\t f(x)\n");
    while(cnt<1000){
        double fx=hoocner(x);
        double fdh=daoham(x);
        if(fdh==0){
            printf("Dao ham bang 0\n");
            return x;
        }
        double x1=x-fx/fdh;
        printf("%d\t %.6lf\t %.6lf\n",cnt, x,fx);
        if(fabs(x1-x) < eps) return x1;
        x = x1;
        cnt++;
    }
    return x;
}
double chiadoi(double l,double r){
    double mid;
    int cnt=0;
    if(hoocner(l)*hoocner(r) > 0){
        printf("Khoang khong hop le\n");
        return -1;
    }
    printf("\n=== Bang lap (Chia doi) ===\n");
    printf("Lan\t l\t\t r\t\t mid\t\t f(mid)\n");
    while(fabs(r-l) > eps){
        mid = (l+r)/2;
        printf("%d\t %.6lf\t %.6lf\t %.6lf\t %.6lf\n",cnt,l,r,mid,hoocner(mid));
        if(hoocner(l)*hoocner(mid) <= 0)r=mid;
        else l=mid;
        cnt++;
    }
    return (l+r)/2;
}
double daycung(double x0,double x1){
    double x2;
    int cnt=0;
    printf("\n=== Bang lap (Day cung) ===\n");
    printf("Lan\t x0\t\t x1\t\t x2\t\t f(x2)\n");
    while(cnt < 1000){
        double f0=hoocner(x0);
        double f1=hoocner(x1);
        if((f1-f0)==0){
            printf("Khong the chia\n");
            return x1;
        }
        x2=x0-f0*(x1-x0)/(f1-f0);
        printf("%d\t %.6lf\t %.6lf\t %.6lf\t %.6lf\n",cnt,x0,x1,x2,hoocner(x2));
        if(fabs(x2-x1) < eps) return x2;
        x0=x1;
        x1=x2;
        cnt++;
    }
    return x2;
}
double g(double x){
    double lambda = 0.1;
    return x-lambda*hoocner(x);
}
double lap(double x0){
    double x=x0, y;
    int cnt=0;
    printf("\n=== Bang lap (Lap don) ===\n");
    printf("Lan\t x\t\t g(x)\n");
    while(cnt<1000){
        y=x;
        x=g(y);
        printf("%d\t %.6lf\t %.6lf\n",cnt, y, x);
        if(fabs(x-y) < eps) return x;
        cnt++;
    }
    return x;
}
int main(){
    nhapdathuc();
    int choice;
    do{
        printf("\n===== MENU =====\n");
        printf("1.Hoocner\n");
        printf("2.Tieptuyen\n");
        printf("3.Chia doi\n");
        printf("4.Day cung\n");
        printf("5.Lap don\n");
        printf("0.Thoat\n");
        printf("Chon: ");
        scanf("%d",&choice);
        if(choice==1){
            double x;
            printf("Nhap x: ");
            scanf("%lf",&x);
            printf("Gia tri da thuc = %.6lf\n", hoocner(x));
        }
        else if(choice==2){
            double x0;
            printf("Nhap x0: ");
            scanf("%lf",&x0);
            printf("Nghiem = %.6lf\n", tieptuyen(x0));
        }
        else if(choice==3){
            double a,b;
            printf("Nhap [a,b]: ");
            scanf("%lf %lf",&a,&b);
            printf("Nghiem = %.6lf\n", chiadoi(a,b));
        }
        else if(choice==4){
            double x0,x1;
            printf("Nhap x0 x1: ");
            scanf("%lf %lf",&x0,&x1);
            printf("Nghiem = %.6lf\n", daycung(x0,x1));
        }
        else if(choice==5){
            double x0;
            printf("Nhap x0: ");
            scanf("%lf",&x0);
            printf("Nghiem = %.6lf\n", lap(x0));
        }
    }while(choice != 0);
    return 0;
}