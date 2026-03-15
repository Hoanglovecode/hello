/*Bài tập vận dụng:
1.Viết chương trình tạo 1 mảng 1 chiều gồm các phần tử
là các số nguyên,có 7 phần tử ngẫu nhiên.
2.Xuất các giá trị trong mảng.
3.Đảo ngược mảng,và xuất ra.
4.Sắp xếp mảng tăng dần.
5.Tính tổng các phần tử trong mảng.
6.Cho người dùng nhập 1 số bất kì,kiểm tra số đó có tồn tại
trong mảng hay không,nếu có thì có bao nhiêu số?
*/
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int main(){
//1.Viết chương trình tạo 1 mảng 1 chiều gồm các phần tử
//là các số nguyên,có 7 phần tử ngẫu nhiên.
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<>dis(0,100);
int mang[7];
for(int i=0;i<7;i++){
   mang[i]=dis(gen);
}
cout<<"7 phần tử ngẫu nhiên:";
//Xuất các giá trị trong mảng.
for(int pt:mang){
cout<<pt<<" ";
}
cout<<endl;
//3.Đảo ngược mảng,và xuất ra.
reverse(mang,mang+7);
cout<<"Mảng sau khi đổi ngược:";
//Xuất các giá trị trong mảng.
for(int pt:mang){
cout<<pt<<" ";
}
cout<<endl;
//4.Sắp xếp mảng tăng dần.
sort(mang,mang+7);
cout<<"Mảng tăng dần:";
//Xuất các giá trị trong mảng.
for(int pt:mang){
cout<<pt<<" ";
}
cout<<endl;
//5.Tính tổng các phần tử trong mảng.
int tong=0;
for(int i=0;i<7;i++){
tong+=mang[i];
}
cout<<"Tổng các giá trị trên="<<tong<<endl;
//6.Cho người dùng nhập 1 số bất kì,kiểm tra số đó có tồn tại
//trong mảng hay không,nếu có thì có bao nhiêu số?
int c;
cout<<"Mời nhập số:";
cin>>c;
int dem=0;
for(int i=0;i<7;i++){
   if(c==mang[i])
     dem++;
}
if(dem==0)
cout<<"Không có số "<<c<<" trong mảng";
else
cout<<"Có "<<dem<<" số "<<c<<" trong mảng";
}