#include <bits/stdc++.h>
using namespace std;
int n,a[100],S;
vector<int>v;
void nhap(){
    cin>>n>>S;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
}
void tryy(int start,int sum){
    for(int j=start;j<n;j++){
        if(sum>S)break;
        v.push_back(a[j]);
        sum+=a[j];
        if(sum==S){
            for(int x:v)cout<<x<<' ';
            cout<<endl;
        }
        else if(sum<S){
            tryy(j+1,sum);
        }
        v.pop_back();
        sum-=a[j];
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   nhap();
   tryy(0,0);
}