//strchr(1 kí tự)
//strstr(chuỗi kí tự)
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    //-Vị trí index=strchr(<Tên chuỗi>,Kí tự cần tìm)
    char*thutu,kytu;
    char str[100]="Hoangcoder";
    kytu='g';
    //Tìm kiếm kí tự trong chuỗi
    thutu=strchr(str,kytu);
    if(thutu==NULL){
        cout<<"Không tìm thấy";
    }
    else
    cout<<"Tìm thấy kí tự ở vị trí index số:"<<(thutu-str)<<endl;
    char*thutu2;
    char str2[100]="Hoang coder";
    //Tìm kiếm chuỗi trong chuỗi
    thutu2=strstr(str2,"coder");
    if(thutu2==NULL){
        cout<<"Không tìm thấy";
    }
    else
    cout<<"Tìm thấy kí tự ở vị trí index số:"<<(thutu2-str2);
     
}