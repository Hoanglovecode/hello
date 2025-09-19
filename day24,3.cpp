// Nối chuỗi
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[100] = "Hello ";
    char str2[100] = "World";
    strcat_s(str1, str2); // Nối str2 vào str1
    cout << "Sau khi nối chuỗi:" <<str1<<endl;
    // Viết chương trình yêu cầu người dùng nhập vào chuỗi str3 str4
    // thực hiện nối chuỗi str3 str4 và in ra màn hình
    char str3[100],str4[100];
    cout << "Mời nhập vào chuỗi 1:";
    cin.getline(str3, 100);
    cout << "Mời nhập vào chuỗi 2:";
    cin.getline(str4, 100);
    // strcat_s(str3,str4);
    // cout << "Sau khi nối chuỗi:" <<str3<<endl;
    int n;
    cout<<"Bạn muốn lấy bao nhiêu kí tự chuỗi 2 nhét vào chuỗi 1:";
    cin>>n;
    strncat_s(str3,sizeof(str3),str4,n);//Lấy n kí tự chuỗi 2 vào chuỗi 1
    cout<<"Nhét "<<n<<" kí tự chuỗi 2 vào chuỗi 1:"<<str3;
}