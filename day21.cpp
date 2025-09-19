#include <iostream>
#include <algorithm> //cho phép dùng sort và reserve
#include <random>
using namespace std;
int main()
{
    // 1.khai báo mảng
    int M[5];
    string M2[7];
    // 2.khởi tạo(có gán giá trị)
    int M3[] = {1, 2, 3, 4, 5, 6, 7};
    string M4[] = {"mot", "hai", "ba", "bon", "nam"};
    //              0    1     2    3     4
    // 3.Truy xuất các phần tử của mảng
    cout << M3[3] << endl;
    cout << M4[3] << endl;
    // 4.Kiểm tra chiều dài của mảng
    int chieudai = size(M4);
    cout << "Chiều dài mảng M4 là: " << chieudai << endl;
    // 5.Duyệt mảng.  để xem
    int M7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Phần tử trong mảng M7=";
    for (int pt : M7)
    { // tạo biến nguyên duyệt trên mảng M7
        cout << pt << " ";
    }
    cout << endl;
    // 6.Duyệt mảng theo vị trí index;
    for (int i = 0; i < size(M7); i++)
    {
        // in ra vị trí index
        cout << "Index " << i << ": " << M7[i] << endl;
    }
    cout << endl;
    // 7.Thay đổi giá trị của mảng
    // Thay 1 phần tử
    int M8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Giá trị index 0 mảng M8 trước khi đổi:" << M8[0] << endl;
    M8[0] = 100;
    cout << "Giá trị index 0 mảng M8 sau khi đổi:" << M8[0] << endl;
    // Thay nhiều phần tử
    int M9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Giá trị mảng M9 ban đầu:";
    for (int pt : M9)
    {
        cout << pt << " ";
    }
    cout << endl;
    for (int i = 0; i < size(M9); i++)
    {
        if (i < 5)
            M9[i] *= 10;
    }
    cout << "Giá trị mảng M9 lúc sau:";
    for (int pt2 : M9)
    {
        cout << pt2 << " ";
    }
    cout << endl;
    /*8.Viết chương trình tạo 1 mảng 1 chiều gồm các phần tử
    là các số nguyên có 5 phần tử,các phần tử do người dùng
    nhập từ bàn phím*/
    int mang[5]; // Khai báo mảng có 5 phần tử
    for (int i = 0; i < size(mang); i++)
    {
        cout << "Mảng[" << i << "]:";
        cin >> mang[i];
    }
    cout << "Mảng bạn vừa nhập là:";
    for (int i = 0; i < size(mang); i++)
    {
        cout << mang[i] << " ";
    }
    cout << endl;
    // 9.Sắp xếp mảng
    /*sử dụng thư viện #include <algorithm>
    begin:trả con trỏ về phần tử đầu tiên của mảng
    end:trả phần tử đến vị trí sau phần tử cuối cùng
    của mảng
    */
    int mang2[9] = {1, 5, 4, 3, 6, 8, 54, -43, 423};
    sort(mang2, mang2 + size(mang2)); // hàm sort tăng dần
    cout << "Mảng sau khi được sắp xếp tăng dần:";
    for (int i = 0; i < size(mang2); i++)
    {
        cout << mang2[i] << " ";
    }
    cout << endl;
    reverse(mang2, mang2 + 9); // reverse:đảo ngược
    cout << "Mảng sau khi được sắp xếp giảm dần:";
    for (int i = 0; i < size(mang2); i++)
    {
        cout << mang2[i] << " ";
    }
    cout << endl;
    // 10.Random giá trị
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1000);
    int mang3[10];
    for (int i = 0; i < 10; i++)
    {
        mang3[i] = dis(gen);
    }
    cout << "Mảng ngẫu nhiên được ranđom:";
    for (int pt : mang3)
    {
        cout << pt << " ";
    }
}