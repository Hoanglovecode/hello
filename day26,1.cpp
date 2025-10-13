#include <iostream>
#include <string>
using namespace std;
int main()
{
  // Viết lệnh nhập mật khẩu khi nào đúng thì thôi
  // cách 1 dùng vòng lặp vô hạn và để break hợp lí
  string matkhau = "1005";
  string input;
  for (;;)
  { // Vòng lặp vô hạn
    cout << "Nhập vào đúng mật khẩu:";
    cin >> input;
    if (matkhau == input)
    {
      cout << "Bạn đã nhập thành công";
      break;
    }
    else
      cout << "Bạn đã nhập sai,vui lòng nhập lại." << endl;
  }
  cout << endl;
  // Cách 2 dùng do while
  string matkhau2 = "1111";
  string nhap;
  do
  {
    cout << "Nhập vào đúng mật khẩu:";
    cin >> nhap;
    if (nhap != matkhau2)
    {
      cout << "Xin mời bạn nhập lại" << endl;
    }
  } while (nhap != matkhau2);
  cout << "Bạn đã nhập thành công";
}