//Tạo ra mảng có các phần tử ngẫu nhiên
#include <iostream>
#include <random>
using namespace std;
int main(){
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<>dis(0,100);
int mang[10];//mảng có 10 phần tử random
for(int i=0;i<10;i++){
    mang[i]=dis(gen);
}
cout<<"Mảng ngẫu nhiên vừa tạo ra:";
for(int pt:mang){
    cout<<pt<<" ";
}
}