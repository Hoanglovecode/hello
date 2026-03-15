#include <iostream>
using namespace std;
int main()
{
int a;
cout<<"Mời bấm số để chọn: "<<endl;
cout<<"1. Tìm theo tên"<<endl;
cout<<"2. Tìm theo tác giả"<<endl;
cout<<"3. Tìm theo nhà xuất bản"<<endl;
cout<<"4. Tìm theo tiêu đề"<<endl;
cin>>a;
switch (a)
{
case 1:
    cout<<"Tìm theo tên";
    break;
case 2:
    cout<<"Tìm theo tác giả";
    break;
case 3:
    cout<<"Tìm theo nhà xuất bản";
    break;
case 4:
    cout<<"Tìm theo tiêu đề";
    break;
default:
    cout<<"Phím bấm không hợp lệ";
    break;

}
}


