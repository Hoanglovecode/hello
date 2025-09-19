#include <iostream>
#include <random>
using namespace std;
int main()
{
    // 1.1 Khởi tạo mảng 2 chiều
    int mang1[3][4];
    string mang2[3][3];
    double mang3[4][5];
    // 1.2 Khởi tạo và gán giá trị
    const int row = 3;
    const int col = 4;
    int mang4[row][col] = {{1, 2, 3, 4}, {4, 6, 2, 7}, {9, 5, 8, 2}};
    // 1.3 Xuất giá trị của mảng
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mang4[i][j] << "    ";
        }
        cout << endl;
    }
    //1.4 Gán giá trị trực tiếp
    mang4[0][0]=100;
    mang4[2][2]=99;
    cout<<"Mảng sau khi bị đổi:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mang4[i][j] << "    ";
        }
        cout << endl;
    }
    //1.5 Dùng random trong mảng 2 chiều
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(0,100);
    int a,b;
    cout<<"Tạo ma trận với số dòng và cột nhập từ bàn phím"<<endl;
    cout<<"Vui lòng nhập số dòng:";
    cin>>a;
    cout<<"Vui lòng nhập số cột:";
    cin>>b;
    int mang5[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            mang5[i][j]=dis(gen);
        }
    }
     cout<<"Mảng 2 chiều ngẫu nhiên có "<<a<<" dòng "<<b<<" cột:"<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout<<mang5[i][j]<<"   ";
        }
        cout << endl;
    }

}