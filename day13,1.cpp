#include <iostream>
using namespace std;
int main()
{
//Tính tổng các số chẵn từ 1 đến 100
//cách 1
int c=2;
int tong=0;
do {
tong+=c;
c+=2;
}while(c<=100);
cout<<"Tổng các số chẵn từ 1 đến 100 là: "<<tong<<endl;
//cách 2 dùng lệnh for
int Tong=0;
for(int d=2;d<=100;d+=2){
    Tong+=d;
     cout<<"d="<<d<<endl;
}
    cout<<"Tổng= "<<Tong<<endl;

}