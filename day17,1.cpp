//Không return
#include <iostream>
#include <cmath>
using namespace std;
void giaiptbac2(double a, double b, double c);
int main()
{
    double x, y, z;
    cout << "Nhập vào 3 số a b c:";
    cin >> x;
    cin >> y;
    cin >> z;
    giaiptbac2(x, y, z);
}
void giaiptbac2(double a, double b, double c)
{
    double x1, x2;
    double d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1=(-b + sqrt(d)) / (2 * a);
        x2=(-b - sqrt(d)) / (2 * a);
        cout << "pt có 2 nghiệm phân biệt" << endl;
        cout << "x1=" << x1 << endl;
        cout << "x2=" << x2 << endl;
    }
    else if (d = 0)
        cout << "pt có nghiệm kép x1=x2=" << -b / (2 * a);
    else
        cout << "pt vô nghiệm";
}