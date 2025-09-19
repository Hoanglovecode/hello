#include <iostream>
using namespace std;
int main(){
//Tạo mảng với các phần tử được nhập từ bàn phím
int a,b;
cout<<"Vui lòng nhập số dòng:";
cin>>a;
cout<<"Vui lòng nhập số cột:";
cin>>b;
int mang[a][b];
for (int i = 0; i < a; i++)
{
    for (int j = 0; j < b; j++)
    {
        cout << "Mảng[" << i << "]" << "[" << j << "]:";
        cin >> mang[i][j];
    }
}
for (int i = 0; i < a; i++)
{
    for (int j = 0; j < b; j++)
    {
       cout<<mang[i][j]<<"  ";
    }
    cout<<endl;
}
//Xuất theo dòng và cột nhập từ bàn phím
for(int e=0;e<100000;e++){
int c;
cout<<"Bạn muốn xem dòng nào:";
cin>>c;
for(int j=0;j<b;j++){
  cout<<mang[c][j]<<"  ";
}
cout<<endl;
int d;
cout<<"Bạn muốn xem cột nào:";
cin>>d;
for(int i=0;i<a;i++){
  cout<<mang[i][d]<<endl;
}
}
}
