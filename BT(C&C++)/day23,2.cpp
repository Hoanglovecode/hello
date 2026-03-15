#include <iostream>
using namespace std;
int main(){
  int mang[]={1,2,3,4,5,6,7,8,9};
  int*controT;
  controT=mang;
  for(int i=0;i<9;i++){
    cout<<*(controT+i)<<":";
    cout<<controT+i<<" ";
  }
  cout<<endl;
  for(int i=0;i<9;i++){
    cout<<mang[i]<<" ";
  }
  cout<<endl;
  cout<<"Mảng sau khi đổi các con số nhân lên cho 10:"<<endl;
  for(int i=0;i<9;i++){
    *(controT+i) *=10;
    cout<<mang[i]<<" ";
  }
  cout<<endl;
  int*mangcontro[5];
  for(int i=0;i<5;i++){
    *mangcontro=new int;
    cout<<mangcontro[i]<<"  ";
  }


       
}