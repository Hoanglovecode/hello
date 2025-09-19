#include <iostream>
using namespace std;
//Truyền tham trị là không thay đổi giá trị của biến sau khi gọi hàm
void thamtri(int a){
    a=100;
    cout<<"a trong truyền tham trị:"<<a<<endl;
}
//Truyền tham biến(tham chiếu)thay đổi giá trị của biến sau khi gọi hàm
void thamchieu(int&b){//Thêm dấu & trước biến để cope địa chỉ
    b=100;
    cout<<"b trong truyền tham chiếu:"<<b<<endl;
}
int main(){
int a=1;
cout<<"a trước khi truyền tham trị:"<<a<<endl;
thamtri(a);
cout<<"a sau khi truyền tham trị:"<<a<<endl;
int b=2;
cout<<"b trước khi truyền tham chiếu:"<<b<<endl;
thamchieu(b);
cout<<"b sau khi truyền tham chiếu:"<<b<<endl;
}