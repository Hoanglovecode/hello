#include <iostream>
using namespace std;
int main(){
while (true)
    {
        int a;
        cout << "Mời nhập số nguyên dương a: ";
        cin >> a;
        if (a <= 0)
        {
            cout << "Xin vui lòng nhập lại số >0" << endl;
            continue;
        }
        bool isPrime = true;
        if(a<2)
        isPrime=false;
        for (int i=2;i*i<=a;i++){
            if(a%i==0){
            isPrime=false;
            break;}
        }
        if(isPrime)
        cout<<a<<" là số nguyên tố\n";
        else
        cout<<a<<" không phải là số nguyên tố\n";
        string b;
        cout<<"Bạn có muốn tiếp tục?"<<endl;
        cout<<"Nếu không nhập phím 'N' hoặc 'n'"<<endl;
        cin>>b;
        if (b=="N"|| b=="n")
        break;
    }
}


