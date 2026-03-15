#include <stdio.h>
int main(){
    int n,k;
    double a[10000];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)scanf("%lf",&a[i]);
    double l=0.0,r=100000.0,mid;
    for(int j=0;j<100;j++){
        int count=0;
        mid=(l+r)/2.0;
        for(int i=0;i<n;i++) count+=(int)(a[i]/mid);
        if(count>=k) l=mid;
        else r=mid;
    }
    printf("%.2lf",l);
}