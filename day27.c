//ÔN tập hàm
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
ll tong(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
double Tong(int n){
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=(double)1/i;
    }
    return sum;
}
void sochinhphuong1(int n){
    int can=sqrt(n);
    if(can*can==n) printf("YES");
    else printf("NO");
}
int sochinhphuong2(int n){
    int can=sqrt(n);
    if(can*can==n) return 1;
    else return 0;
}
/*Kiểm tra các số từ 1 đến k nhập từ bàn phím có thõa
tổng các chữ số nó bằng 16 và và chia hết cho 8(check1),Số đó có chia hết cho 2 (check2)
và nó có số 6 trong dãy hay không.Nếu có thì in ra*/
//tổng các chữ số nó bằng 16(check1) 
int check1(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
//chia hết cho 2 (check2)
int check2(int n){
    if(n%2==0) return 1;
    else return 0;
}
//nó có số 6 trong dãy hay không(check 3)
int check3(int n){
    while(n>0){
        if(n%10==6) return 1;
        n/=10;
    }
    return 0;
}
int main(){
    int n,m,k;
    scanf("%d %d",&n,&m);
    printf("Tính tổng các số tự nhiên từ 1 đến %d = %lld\n",n,tong(n));
    printf("Tính tổng 1+1/2+1/3+...+1/%d = %.2f\n",m,Tong(m));
    sochinhphuong1(n);
    printf("\n");
    if(sochinhphuong2(m)==1) printf("YES");
    else printf("NO");
    printf("\nXin mời nhập 1 số nguyên dương k:");
    scanf("%d",&k);
    printf("\nDãy các số từ 1 đến %d là số chẵn(có mặt chữ số 6) có tổng các chữ số chính nó bằng 16 và chia hết cho 8:\n",k);
    for(int i=1;i<=k;i++){
        if(check1(i)==16 && check1(i)%8==0 && check2(i)==1 && check3(i)==1) printf("%d ",i);
    }
}