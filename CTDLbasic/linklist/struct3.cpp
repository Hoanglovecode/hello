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
   sort(ds,ds+n);//sort ascending depending on line 12
   for(sinhvien x:ds){
      cout<<x.sothich.sports<<" "<<x.msv<<" "<<x.ten<<" "<<x.gpa<<endl;
   }
}
/*input.txt
4
badminton
102250068
A
3.89
football
102250069
B
3.36
volleyball
102250070
C
3.67
basketball
102250071
D
3.24
*/