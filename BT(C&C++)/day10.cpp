#include <iostream>
using namespace std;
int main (){
    int a;
    cout << "Nhập vào số nguyên a: ";
    cin >> a;
    string traloi = (a % 2 == 0) ? "chẵn" : "lẻ";
    cout << traloi;

}