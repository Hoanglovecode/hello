#include <iostream>
using namespace std;
int main()
{
double a=4;
double tong=12;
do{
tong+=a;
a++;
}
while (a<=100);
{
    cout<<"Tổng từ 1 đến 100 là: "<<tong<<endl;

}
//vòng lặp while true 
int n;
while (true)
{
    cout<<"n="<<n<<endl;
    n++;
    if (n>100)
    break;
}

}