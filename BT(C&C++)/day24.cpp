/*
Mảng ký tự là 1 mảng bao gồm các phần tử là các ký tự đơn lẻ 
ví dụ:a,c,g,1,2,3,...
Chuỗi là 1 mảng ký tự được kết thúc bằng ký tự null ('0')
*/
#include <iostream>
using namespace std;
int main(){
    //khởi tạo mảng ký tự
    char M1[30];
    char kytu[6] = {'a', 'b', 'c', 'd', 'e'};//Chừa lại kí tự null
    cout << kytu<<endl;
    //khai báo dùng con trỏ
    char *chuoi;
    //cấp phát bộ nhớ
    chuoi=new char[51];
    //gán giá trị theo vị trí index
    chuoi[0]='e';
    chuoi[1]='a';
    chuoi[2]='b';
    chuoi[3]='c';
    chuoi[4]='\0';
    cout<<"Mảng ký tự khai báo dùng con trỏ:"<<chuoi<<endl;
    //Khai báo hằng chuỗi
    char chuoi2[]="'Xin chào tôi mới học lập trình từ ngày 5/7/2025'";
    cout<<"Chuỗi="<<chuoi2<<endl;
    cout<<"Có "<<size(chuoi2)<<" ký tự trong chuỗi bao gồm ký tự null";

}