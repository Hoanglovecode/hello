#include <iostream>
using namespace  std;
int main()
{
    double dtb1;
    cout << "Nhập điểm trung bình của bạn là: ";
    cin >> dtb1;
    if (dtb1 >= 5)
    {
        cout << "bạn đỗ\n";
    }
    else
    {
        cout << "bạn rớt\n";
    }
    double dtb2;
    cout << "Nhập điểm trung bình của bạn: ";
    cin >> dtb2;
    if (dtb2 >= 8 && dtb2 <= 10)
    {
        cout << "Bạn đạt học sinh giỏi";
    }
    else if (dtb2 >= 6.5 && dtb2 < 8)
    {
        cout << "Bạn đạt học sinh khá";
    }
    else if (dtb2 >= 5 && dtb2 < 6.5)
    {
        cout << "Bạn đạt học sinh trung bình";
    }
    else if (dtb2 >= 3.5 && dtb2 < 5)
    {
        cout << "Bạn đạt học sinh yếu";
    }
    else
        cout << "Bạn đạt học sinh kém ";
}
