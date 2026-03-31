#include <bits/stdc++.h>
using namespace std;
//<Ktao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
// <In ra cau hinh hien tai>
//<Sinh ra cau hinh tiep theo>}
int n,k,a[100],ok;
void ktao(){
    for(int i=1;i<=n;i++)a[i]=0;
}
bool check(){//condition
    int dem=0;
    for(int i=1;i<=n;i++)dem+=a[i];
    return dem==k;
}
void sinh(){
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    ok=1;
    ktao();
    while(ok){
        if(check()){
            for(int i=1;i<=n;i++){
                cout<<a[i];
            }
            cout<<endl;
        }
        sinh();
    }
}