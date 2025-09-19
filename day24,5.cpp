//So sánh chuỗi
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str1[]="Helloa";
    char str2[]="HelloA";
    //So sánh chuỗi:strcmp(<str1>,<str2>) (string compare)
    //Có so sánh viết hoa và thường bảng mã ASII
    //trả về -1 nếu str1<str2
    //trả về  0 nếu str1=str2
    //trả về  1 nếu str1>str2
    int kq=strcmp(str1,str2);
    cout<<"Kq1:"<<kq<<endl;
     //So sánh chuỗi n kí tự:strncmp(<str1>,<str2>,n) (string n compare)
    //Có so sánh viết hoa và thường bảng mã ASII
    //trả về -1 nếu str1<str2
    //trả về  0 nếu str1=str2
    //trả về  1 nếu str1>str2
    int kq2=strncmp(str1,str2,6);
    cout<<"Kq2:"<<kq2;


    
    
}