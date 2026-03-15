#include <bits/stdc++.h>
using namespace std;
int main(){
  //Nhập chuỗi và in từng ký tự cho đến khi gặp dấu chấm 
  string s;
  cout<<"Nhập chuỗi:";
  getline(cin,s);
  for(char c:s){
    if(c=='.')break;
     cout<<c<<" ";
  }
}