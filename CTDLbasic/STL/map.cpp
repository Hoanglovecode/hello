#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   /*
   Các tính chất quan trọng của map : 

Các key trong map là riêng biệt, không có 2 key trùng nhau
Map duy trì thứ tự các phần tử theo giá trị key tăng dần
Map tìm kiếm giá trị key với độ phức tạp O(logN)
Map không hỗ trợ truy cập thông qua chỉ số như mảng hay vector, string.
Mỗi phần tử trong map chính là 1 pair
   */
  map<int,int>mp;
  mp[100]=200;//(100,200);
  mp[200]=300;//(200,300);
  mp.insert({100,500});
  mp.insert({300,400});
  mp.insert({500,500});
  //Duyệt map bằng 3 cách 
  for(pair<int,int>x:mp){
   cout<<x.first<<' '<<x.second<<endl;
  }
  cout<<endl;
  for(auto x:mp){
   cout<<x.first<<' '<<x.second<<endl;
  }
  cout<<endl;
  for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
   cout<<(*it).first<<' '<<(*it).second<<endl;
  }
}