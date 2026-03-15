#include <iostream>
using namespace std;
int main (){
int a;
cout<<"Nhập vào tháng:";
cin>>a;
if (a==1 || a==2 ||a==3)
cout <<"Tháng này là quý 1:"<<endl;
else if (a==4 || a==5 || a==6)
cout <<"Tháng này là quý 2:"<<endl;
else if (a==7 || a==8 || a==9)
cout <<"Tháng này là quý 3:"<<endl;
else if (a==10 || a==11 || a==12)
cout <<"Tháng này là quý 4:"<<endl;
else
cout <<"Tháng này không hợp lệ"<<endl;
return 0;
}