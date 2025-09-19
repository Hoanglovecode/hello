#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a,b,c;
    cout <<"MỜI NHẬP VÀO ĐIỂM MÔN TOÁN:";
    cin>>a;
    cout <<"MỜI NHẬP VÀO ĐIỂM MÔN LÍ:";
    cin>>b;
    cout <<"MỜI NHẬP VÀO ĐIỂM MÔN HÓA:";
    cin>>c;
    double dtb=(a+b+c)/3;
    cout<<"ĐIỂM TRUNG BÌNH CỦA BẠN LÀ:"<<dtb<<endl;
    cout<<"KẾT QUẢ LÀM TRÒN ĐẾN HÀNG PHẦN NGHÌN:"<<setprecision(4)<<dtb<<endl;

}