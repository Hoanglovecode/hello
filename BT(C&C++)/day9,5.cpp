#include <iostream>
using namespace std;
int main() {
    int a,b;
    cout<<"Hãy nhập vào tháng:";
    cin>>a;
    if (a==1 || a==3 || a==5 || a==7 || a==8 || a==10 || a==12)
    cout<<"Tháng này có 31 ngày";
    if (a==4 || a==6 || a==9 || a==11)
    cout<<"Tháng này có 30 ngày";
    if (a==2)
    cout<<"Hãy nhập vào năm: ";
    cin>>b;
    if (b%4==0)
    cout <<"Tháng này có 29 ngày";
    else if (b%4!=0)
    cout<<"Tháng này có 28 ngày";
    return 0;
}