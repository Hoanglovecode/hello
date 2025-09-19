#include <iostream>
#include <climits>
using namespace std;
int main()
{
  cout<<"max của  kiểu int là: "<<INT_MAX<<endl;
  cout<<"min của kiểu int là: "<<INT_MIN<<endl;
  
  cout<<"max của  kiểu short là: "<<SHRT_MAX<<endl;
  cout<<"min của kiểu short là: "<<SHRT_MIN<<endl;
  //khai báo
  int toan;//kiểu nguyên
  float diemtoan;
  double tienluong;
  //khởi tạo
  bool check =true;
  char kytu= 'a';//kiểu kí tự
  int canNang= 60;
  float diemsinh=8.4f;
  short test=200;
  cout << "giá trị test là: " << test << endl;
  // khai báo nhiều biến có cùng kiểu dữ liệu
  int a, b, c, d;
  //kiểm tra kiểu dữ liệu của biến 
  cout<< typeid(diemsinh).name()<<endl;
  float dtb;
  cout <<"mời nhập vào điểm trung bình ";
  cin>>dtb;
  cout<<"điểm trung bình của bạn là: "<<dtb;




}