#include <bits/stdc++.h>
using namespace std;
struct hoppy{
   string sports,food,beverages;
};
struct sinhvien{
   hoppy sothich;
   int msv;
   string ten;
   double gpa;
   bool operator < (const sinhvien other){
      return gpa<other.gpa;
   }
};
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   sinhvien ds[n];
   cin.ignore();//vì có cin>>n phía trc;
   for(int i=0;i<n;i++){
      getline(cin,ds[i].sothich.sports);
      cin>>ds[i].msv;cin.ignore();
      getline(cin,ds[i].ten);
      cin>>ds[i].gpa;
      cin.ignore();//vì đây là loop và next là getline
   }
   sort(ds,ds+n);//sort decline
   for(sinhvien x:ds){
      cout<<x.sothich.sports<<" "<<x.msv<<" "<<x.ten<<" "<<x.gpa<<endl;
   }
}