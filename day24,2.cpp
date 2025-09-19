//Sao chép mảng ký tự
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char chuoi1[] = "Xin chào Lê Văn Hoàng";
    char chuoi2[30];
    strcpy_s(chuoi2, sizeof(chuoi2), chuoi1);//Sao chép chuỗi 1 vào chuỗi 2
    //Nếu chuỗi 1 vượt quá số ký tự tối đa của chuỗi 2 
    //Màn hình sẽ hiển thị lỗi không xuất được chuỗi 2
    cout << chuoi1 << endl;
    cout << chuoi2 << endl;
    char chuoi3[] = "Xin chào DATA ANALYSICS";
    char chuoi4[30];
    strncpy_s(chuoi4, sizeof(chuoi4), chuoi3,9);//Sao chép 9 ký tự từ chuỗi 3 vào chuỗi 4
    cout << chuoi3 << endl;
    cout << chuoi4 << endl;
}