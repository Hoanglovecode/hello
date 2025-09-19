#include <iostream>
#include <limits>
#include <cstring>
using namespace std;
int main(){
    // Viết Hoa
    // cách 1
    char kytuhoa = toupper('a');//Truyền theo kí tự
    cout << "Viết hoa cách 1a:" << kytuhoa << endl;
    // cách 2
    char kytuhoa2 = toupper(97);//Truyền theo số
    cout << "Viết hoa a cách 2:" << kytuhoa << endl;
    // Viết Thường
    char kytuthuong = tolower('A');
    cout << "Viết thường A:" << kytuthuong;
    // Tìm kí tự ASII bằng số
    char aaa = 98; // in ra kí tự 98 trong bản ASII
    cout << "Kí tự trong bảng ASII ô 98 là:" << aaa << endl;
    //Bài tập cho người dùng nhập vào 1 mảng kí tự
    //1.Chuyển sang in hoa
    char chuoi1[100];
    cout<<"Mời mời dùng nhập vào chuỗi 1:";
    cin.getline(chuoi1,100);
    cout<<"In hoa chuỗi 1:";
    for(int i=0;i<strlen(chuoi1);i++){
       chuoi1[i]=toupper(chuoi1[i]);
       cout<<chuoi1[i];
    }
    cout<<endl;
    //2.Chuyển sang in thường
    cout<<"In thường chuỗi 1:";
      for(int i=0;i<strlen(chuoi1);i++){
       chuoi1[i]=tolower(chuoi1[i]);
       cout<<chuoi1[i];
    }

}