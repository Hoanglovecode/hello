#include <bits/stdc++.h>
using namespace std;
int main(){
    // Tìm tổng các số chia hết cho 7 từ 1 đến n
    int n;
    cout << "Nhập n=";
    cin >> n;
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0)
            tong += i;
    }
    cout <<"Tổng các số chia cho 7 từ 1 đến n="<<tong;
}