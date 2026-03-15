//Có return
#include <iostream>
#include <cmath>
using namespace std;
double delta(double a, double b, double c){
    return(b * b - 4 * a * c);
}
int main()
{
    double a,b,c;
    cout << "Nhập vào 3 số a b c:"<<endl;
    cin >> a >> b >> c;
    double kq=delta(a,b,c);
    if (kq> 0)
    {
        double x1,x2;
        x1=(-b + sqrt(kq)) / (2 * a);
        x2=(-b - sqrt(kq)) / (2 * a);
        cout << "pt có 2 nghiệm phân biệt:" << endl;
        cout << "x1=" << x1 << endl;
        cout << "x2=" << x2 << endl;
    }
    else if (kq== 0)
        cout << "pt có nghiệm kép x1=x2=" << -b / (2 * a);
    else
        cout << "pt vô nghiệm";
}