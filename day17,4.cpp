// Tương tự day17,3.cpp nhưng dùng switch case thay cho if else
#include <iostream>
#include <cmath>
using namespace std;
void d(double a, double b, char pheptinh)
{
    double kq;
    switch (pheptinh)
    {
    case '+':
        kq = a + b;
        cout << a << "+" << b << "=" << kq << endl;
        break;
    case '-':
        kq = a - b;
        cout << a << "-" << b << "=" << kq << endl;
        break;
    case '*':
        kq = a * b;
        cout << a << "*" << b << "=" << kq << endl;
        break;
    case '/':
        kq = a / b;
        if (b != 0)
            cout << a << "/" << b << "=" << kq << endl;
        else
            cout << "Errors:Mẫu phải khác 0";
        break;
    default:
        cout << "Phép tính không hợp lệ";
        break;
    }
}
int main()
{
    double a, b;
    char pheptinh;
    cout << "Nhập vào số a:";
    cin >> a;
    cout << "Nhập vào số b:";
    cin >> b;
    cout << "Mời nhập vào phép tính(+,-,*,/):";
    cin >> pheptinh;
    d(a, b, pheptinh);
}