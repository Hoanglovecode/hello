#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,m,s,x;
  cin>>h>>m>>s>>x;
  for(int i=1;i<=x;i++){
    s++;
    if(s==60){
        s=0;
        m++;
    }
    if(m==60){
        m=0;
        h++;
    }
    if(h==13){
        h=1;
        m=s=0;
    }
  }
  cout<<h<<" "<<m<<" "<<s;
}