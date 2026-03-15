#include <iostream>
using namespace std;
int main()
{
    const int dong = 3;
    const int cot = 4;
    int **caphai = new int *[dong];
    for (int i = 0; i < dong; i++)
    {
        // di chuyển con trỏ bên trong để cấp phát bộ nhớ
        *(caphai + i) = new int[cot]; // cấp phát bộ nhớ
    }
    // xuất địa chỉ ma trận cấp 2
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << &caphai[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            caphai[i][j] = i + j;
            cout << caphai[i][j] << " ";
        }
        cout << endl;
    }
    // Hủy con trỏ
    for (int i = 0; i < dong; i++)
    {
        delete *(caphai + i);
    }
    delete caphai;
}