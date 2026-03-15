#include <iostream>
using namespace std;
int cong(int x, int y);
void xinchao(string gioitinh);
int main()
{
    int a = cong(4, 304);
    int b = cong(3, 77677);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    xinchao("nam");
    xinchao("nu");
}
int cong(int x, int y)
{
    return x + y;
}
void xinchao(string gioitinh)
{
    if (gioitinh == "nam")
        cout << "xin chào,tôi là nhân viên nam\n";
    else if (gioitinh == "nu")
        cout << "xin chào,tôi là nhân viên nữ\n";
}