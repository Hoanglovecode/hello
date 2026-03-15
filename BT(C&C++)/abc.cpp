#include <iostream>
#include <cmath>
using namespace std;
int main(){
    unsigned int bits;
    cout << "Nhập số nguyên 32 bit (dưới dạng thập phân hoặc hex, ví dụ 0x41C933FB): ";
    cin >> bits;

    int sign = (bits >> 31) & 1;
    int exponent = (bits >> 23) & 0xFF;
    int mantissa = bits & 0x7FFFFF;

    float decimal = 0.0;
    for (int i = 0; i < 23; i++) {
        if (mantissa & (1 << (22 - i))) {
            decimal += 1.0 / (1 << (i + 1));
        }
    }
    decimal += 1.0; // thêm phần nguyên

    decimal *= pow(2, exponent - 127);
    if (sign) decimal = -decimal;

    cout << "Giá trị thập phân: " << decimal << endl;
    return 0;
}