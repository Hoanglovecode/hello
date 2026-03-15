#include <iostream>
#include <cmath>
using namespace std;
int main(){
//viết chương trình nhập vào và đưa ra năm đó có phải là năm nhuận hay không
    int year;
    cout<<"Nhập vào năm :";
    cin>>year;
    if (year%4==0 && year%100!=0 || year%400==0)
    cout<< year<<" là năm nhuận"<<endl;
    else 
    cout<< year<<" không phải là năm nhuận"<<endl;

}