#include <iostream>
using namespace std;
int main(){
//dùng hoán tử ba ngôi để nhập điểm trung bình xét loại học lực
    float diem;
    cout << "Nhập điểm trung bình: ";
    cin >> diem;
    string loai=(diem>=8)?"Giỏi":(diem<8 && diem>=6.5)?"Khá":(diem<6.5 && diem >=5)?"Trung bình":"yếu";
    cout << "Loại học lực: " << loai << endl;
    return 0;
}
