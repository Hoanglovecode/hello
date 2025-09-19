#include <iostream>
#include <random>
using namespace std;
int main()
{
    int tong = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);
    int mang[4][6];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            mang[i][j] = dis(gen);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << mang[i][j] << "   ";
            tong += mang[i][j];
        }
        cout << endl;
    }
    int max =mang[0][0];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(mang[i][j]>=max)
              max=mang[i][j];
        }
    }
    cout<<"GTLN trong mảng:"<<max<<endl;
    int min=mang[1][1];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(mang[i][j]<=min)
              min=mang[i][j];
        }
    }
    cout<<"GTNN trong mảng:"<<min<<endl;
    cout << "Tổng các giá trị trong mảng=" << tong << endl;
    int c;
    cout << "Mời nhập vào 1 số:";
    cin >> c;
    int dem = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (c == mang[i][j])
                dem++;
        }
    }
    if (dem == 0)
        cout << "Số này không tồn tại trong mảng";
    else
        cout << "Số này xuất hiện " << dem << " lần trong mảng";
}