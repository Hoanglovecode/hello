//Nhập xuất chuỗi mảng char
#include <iostream>
#include <limits>//Để sử dụng cin.ignore
using namespace std;
int main(){
const int max=4;
char chuoi[max];//Khai báo chuỗi chứa tối đa 4 kí tự
cout<<"Mời bạn nhập chuỗi cách 1:";
cin.getline(chuoi,max);//cin.getline(<tên mảng>,<số kí tự tối đa>)
cout<<"Sau khi repair:"<<chuoi<<endl;
cin.clear();//xóa trạng thái lỗi
cin.ignore(numeric_limits<streamsize>::max(),'\n');//xóa bộ nhớ đệm
cout<<numeric_limits<streamsize>::max()<<endl;
//Dùng con trỏ
char* chuoi2=new char[max];
cout<<"Mời bạn nhập chuỗi cách 2:";
cin.getline(chuoi2,max);//cin.getline(<tên mảng>,<số kí tự tối đa>)
cout<<"Sau khi repair:"<<chuoi2<<endl;
delete[] chuoi2;//Giải phóng bộ nhớ
}