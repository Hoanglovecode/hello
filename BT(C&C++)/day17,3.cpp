#include <iostream>
#include <cmath>
using namespace std;
void d(double a, double b, string pheptinh){
    if (pheptinh == "+")
        cout << a + b;
    else if (pheptinh == "-")
        cout << a - b;
    else if (pheptinh == "*")
        cout << a * b;
    else if (pheptinh == "/")
    {
        if (b != 0)
            cout << a / b;
        else
            cout << "Errors:Mẫu phải khác 0";
    }
    else
        cout << "Phép tính không hợp lệ";
}
int main()
{
    double a, b;
    string pheptinh;
    cout << "Nhập vào số a:";
    cin >> a;
    cout << "Nhập vào số b:";
    cin >> b;
    cout << "Mời nhập vào phép tính(+,-,*,/):";
    cin >> pheptinh;
    d(a, b, pheptinh);
}