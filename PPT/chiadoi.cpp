#include <bits/stdc++.h>
using namespace std;
double f(double x){
    double a=pow(x,3)+x-5;
    return a;
}
double c;
double value(double a,double b,double f(double x),double y){
    while(abs(a-b)>0.0000000001){
        c=(a+b)/2;
        if(f(a)<0&&f(b)>0){
            if(f(c)>0)b=c;
            else a=c;
        }
        else if(f(a)>0&&f(b)<0){
            if(f(c)>0)a=c;
            else b=c;
        }
        else 
           return -1;
    }
    return c;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double a,b;cin>>a>>b;
    cout<<fixed<<setprecision(10)<<value(a,b,f,0.0000000001);
}