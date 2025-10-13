#include <bits/stdc++.h>
using namespace std;
int main(){
long long a;
long long dem=0;
cin>>a;
if(a>=0 && a<=pow(10,9)){
    for(int i=a;i<=a*a;i++){
        dem++;
    }
}
cout<<dem;
}