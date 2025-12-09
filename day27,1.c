//Nhập vào số nguyên dương vd 1234 dùng hàm in ra 1+2+3+4 và đếm số lượng chữ số
//Nếu số lượng là số chẵn và tổng nửa chữ số đầu bằng nửa số cuối thì in ra đó là số hạnh phúc
#include <stdio.h>
int tong1(int n){
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}
int dem(int n){
    int a=0;
    while(n>0){
        n/=10;
        a++;
    }
    return a;
}
int tong2(int n){//tính tổng các nửa chứ số đầu
    int s=0;
    int a=0;
    while(n>0){
        s+=n%10;
        a++;
        n/=10;
        if(a==dem(n)/2 +1) break;
    }
    return s;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",tong1(n));
    printf("Số lượng: %d\n",dem(n));
    int a=(tong1(n)-tong2(n));
    if(dem(n)%2==0 && a==tong1(n)/2) printf("Đây là số hạnh phúc");
    else printf("Đây không phải là số hạnh phúc");
}