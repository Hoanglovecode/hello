#include <iostream>
using namespace std;
int main()
{
    cout << "Các số nguyên tố từ 1 đến 100 là :";
    for (int a = 2; a <= 100; a++)
    {
        bool isPrime = true;
        for (int i = 2; i * i <= a; i++)
        {
            if (a % i == 0){
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cout << a << " ";
    }
    cout<<endl;
}