#include <iostream>
using namespace std;
int z=4;//bien toan cuc
void A(){
    int x=3;//cuc bo dong
    static int y=4;//Cuc bo tinh
    x++;y++;
    cout<<"x="<<x<<"  y="<<y<<endl;
}
int main(){
    //Bai1
    int x = 1;
    cout << "x=" << x << ",&x=" << &x << endl;
    int &y = x;
    y = 2;
    cout << "&x =" << &x << ", &y =" << &y << ", x =" << x << endl;
    int *p = &x;
    //*p <- >x
    cout << *p << ", " << x << endl;
    // p <- >&x
    cout << p << "," << &x << endl;
    cout << &p << endl;
    //Bai2
    A();
    A();
    int z=6;
    cout<<"z="<<z<<' '<<"z="<<::z<<endl;

}