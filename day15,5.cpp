#include <iostream>
using namespace std;
int main(){
cout<<"Những số chia hết cho 3 từ 10-50: ";
for(int c=10;c<=50;c+=1){
    if(c%3==0)  
    cout<<c<<" ";
}
}