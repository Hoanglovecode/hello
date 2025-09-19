#include <iostream>
using namespace std;
int main()
{
// tính tổng từ 1 đến 100 loại trừ số chia hết cho 3
//continue
int tong=0;
for(int a=1;a<=100;a++){
if(a%3==0)
continue;//bỏ qua giá trị
else{
    tong+=a;
    cout<<"a="<<a<<endl;
}
}
cout<<"Tổng="<<tong<<endl;
//break
int n=1;
while (n<100)
{
   cout<<"n="<<n<<endl;
   n++;
   if(n==97)//if có thể trong curly brackets(dấu ngoặc nhọn) của while
   break;//Dừng lại chương trình
}
cout<<"Giá trị n cuối cùng="<<n<<endl;
}