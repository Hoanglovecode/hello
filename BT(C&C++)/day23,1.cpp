#include <iostream>
using namespace std;
int main(){
int nguyenA=1;
float thucB=1.43;
int * contronguyen;
float* controthuc;
//Gán con trỏ hợp lệ
controthuc=&thucB;
cout<<"Giá trị c1: "<<*controthuc<<endl;
cout<<"Giá trị c2: "<<thucB<<endl;
cout<<"Địa chỉ c1:"<<&thucB<<endl;
cout<<"Địa chỉ c2:"<<controthuc<<endl;
// Gán con trỏ không hợp lệ
// contronguyen = &thucB;
//void có thể trỏ bất kì dữ liệu nào khác 
void*gicungduoc;
gicungduoc=&nguyenA;
//gicungduoc=&thucB;
cout<<"Địa chỉ gicungduoc c1: "<<gicungduoc<<endl;
cout<<"Địa chỉ gicungduoc c2: "<<&nguyenA<<endl;
//Void để trỏ nhiều kiểu dữ liệu nhưng khi can thiệp đến giá trị
//thì cần phải ép kiểu dữ liệu mà nó trỏ tới(int,float,..)
*(int*)gicungduoc=45;//Phải như này mới gán giá trị được
cout<<"Giá trị gicungduoc c1: "<<*(int*)gicungduoc<<endl;//Phải ép y chang
cout<<"Giá trị gicungduoc c2: "<<nguyenA<<endl;
//Con trỏ null:
//Tức là k chạy nếu không cấp phát bộ nhớ nếu
//nếu k hề gán cho nó 1 giá trị hay địa chỉ
int*contronull;
contronull=new int;//Nếu k có line này thì sẽ k xuất ddc cache
cout<<"Địa chỉ contronull: "<<contronull;
}