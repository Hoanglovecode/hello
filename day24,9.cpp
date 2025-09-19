//Bài tập đão ngược chuỗi
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    //Cách 1 của tôi 
    char chuoi[1000];
    cout<<"Mời nhập vào một chuỗi:";
    cin.getline(chuoi,1000);
    reverse(chuoi,chuoi+strlen(chuoi));
    cout<<"Chuỗi sau khi đôi ngược:";
    for(int i=0;i<strlen(chuoi);i++){
        cout<<chuoi[i];
    }
    cout<<endl;
    //Cách 2
    const int max_len=1000;
    char str[max_len];
    cout<<"Mời nhập vào chuỗi:";
    cin.getline(str,max_len);
    cout<<"Chuỗi sau khi đổi ngược:";
    int len=strlen(str);
    for(int i=(len-1);i>=0;i--){
        cout<<str[i];
    }
}