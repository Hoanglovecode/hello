//Bài tập in ra mã ASII
#include <iostream>
#include <limits>
#include <cstring>
using namespace std;
int main(){
   char chuoi[1000];
   cout<<"Mời nhập vào một chuỗi:";
   cin.getline(chuoi,1000);
   for(int i=0;i<strlen(chuoi);i++){
    int maASII=(int)(chuoi[i]);
    cout<<chuoi[i]<<" Mã ASII là:"<<maASII<<endl;
   }
}