#include <iostream>
using namespace std;
int main()
{
    // mức độ so sánh int<long<float<double
    // 1. ép kiểu dữ liệu(từ bé ssang lớn hơn thì không lo mất dữ liệu)
    short a = 30000;
    cout << "a= " << a << endl;
    //int b=a;//ép ngầm(ép tắt)
    int b = (int)a;//ép tường minh
    cout << "b= " << b << endl;
    float c = (float)b;
    cout << "c= " << c << endl;
    double d = (double)c;
    cout << "d=" << d << endl;
    //2.ép kiểu dữ liệu (từ lớn sang bé thì có thể mất dữ liệu)
    double e=3.144234434234234234;
    cout<<"e="<<e<<endl;
    short f=e;
    cout<<"f="<<f<<endl;
    

}