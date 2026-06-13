#include <bits/stdc++.h>
using namespace std;
int n,S;
int tryy1(int i,int start,int sum){
    int count=0;
    for(int j=1;j<=S;j++){
        if(sum>S)break;
        sum+=j;
        if(i==n){
            if(sum==S) count++;
        }
        else{
            count+=tryy1(i+1,j,sum);
        }
        sum-=j;
    }
    return count;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>S>>n;
   cout<<tryy1(1,1,0);
}
//Input 6 4 Output 10