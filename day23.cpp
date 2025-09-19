//1.Khai báo: <kiểu dữ liệu>*<tên biến>
//2.Cấp phát: <tên biến>= new <kiểu dữ liệu>
//3.Hủy bộ nhớ: delete <tên biến>
#include <iostream>
using namespace std;
int main(){
//Xem địa chỉ ô nhớ trên RAM
int nhietdo=32;
cout<<"Địa chỉ biến nhiệt độ:"<<&nhietdo<<endl;
//Khai báo con trỏ
int *a;
//Cấp phát bộ nhớ
a=new int;
//Xuất ra địa chỉ ô nhớ a chiếm
cout<<"Địa chỉ ô nhớ a chiếm:"<<a<<endl;//Bởi vì a là con trỏ nên không cần dấu &
//Gán giá trị
*a=87;
cout<<"Giá trị nằm trên ô nhớ con trỏ a:"<<*a<<endl;
//Khai báo controT
int *controT;
//Trỏ biến controT và ô nhớ của nhiệt độ
controT=&nhietdo;
cout<<"Địa chỉ ô nhớ controT:"<<controT<<endl;
cout<<"Giá trị controT:"<<*controT<<endl;
//Thay đổi giá trị controT
*controT=43;
cout<<"Giá trị controT mới:"<<*controT<<endl;
cout<<"Giá trị controT mới:"<<nhietdo<<endl;
//Giá trị controT kí hiệu *controT=nhietdo
//Địa chỉ nhietdo kí hiệu &nhietdo=controT
}