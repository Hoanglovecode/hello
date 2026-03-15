#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "Hãy nhập vào số bất  kì: ";
    cin >> a;
    int div = a % 2;
    switch (div)
    {
    case 0:
        cout << "Đây là số chẵn"<<endl;
        break;
    default:
        cout << "Đây là số lẻ"<<endl;
        break;
    }
int b;
cout<<"Hãy nhập vào tháng: ";
cin>>b;
switch (b)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
    cout <<"Tháng này có 31 ngày";
    break;
case 4:
case 6:
case 9:
case 11:
cout<<"Tháng này có 30 ngày";
break;
default:
cout <<"Tháng này có 28 hoặc 29 ngày"<<endl;
int b;
cout <<"Bạn hãy đề xuất thêm đây là năm bao nhiêu? ";
cin>>b;
if (b%4==0)
cout<<"Tháng này có 29 ngày";
else
cout<<"Tháng này có 28 ngày";
    break;
}
}