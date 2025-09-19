#include <iostream>
using namespace std;
int main(){
  int x=0;
  while (x<10)
  {
    cout<<"x="<<x<<endl;
    x++;//x=x+1 //x+=1
  }
  // Bài tập nhập  vào số n cho đến khi thỏa điều kiện
  int n;
  cout<<"Nhập vào n nằm trong khoảng 1 đến 99: ";
  cin>>n;
  while(n<1 || n>99)
  {
   cout<<"Xin hãy nhập lại n: ";
  cin>>n;
  }
cout<<"Đã nhập vào thành số n là: "<<n<<endl;
}