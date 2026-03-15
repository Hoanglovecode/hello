/*Bài tập con trỏ
1.Viết chương trình nhập vào 1 mảng 1 chiều M,gồm n phần tử nguyên ngẫu nhiêm [0,100]
2.Sắp xếp mảng M theo chiều giảm dần,lưu ý:yêu cầu sử dụng tên mảng như con trỏ
*/
#include <iostream>
#include <random>
using namespace std;
void nhap(int *&M, int n)// dấu & ở đây là chuyền tham chiếu chứ k phải cache
{
    M = new int(n);//cấp phát bộ nhớ vì M không được gán value
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);
    for (int i = 0; i < n; i++)
    {
        //sử dụng M+i để di chuyển con trỏ
        *(M + i) = dis(gen);//gán giá trị con trỏ M+i
        cout << *(M + i) << "   ";
    }
}
void xuat(int *&M, int n){
    for (int i = 0; i < n; i++)
    {        
        cout << *(M + i) << "   ";
    }
}
void hoandoi(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void sapxep(int *&M,int n){
    //chạy 2 vòng forr so sánh số trước số sau
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<i<<"-"<<j<<"  ";
            if(*(M+i)<*(M+j)){
                hoandoi(M+i,M+j);
            }
        }
        cout<<endl;
    }
}
int main()
{
    //Khai báo con trỏ
    int*M;
    int n=10;   
    cout << "Mảng 1 chiều M,gồm 10 phần tử nguyên ngẫu nhiên (0,100):\n";
    nhap(M,n);
    cout<<endl;
    cout<<"Thuật toán sắp xếp nổi bọt(buble sort):Video(52)"<<endl;
    sapxep(M,n);
    cout<<"Mảng sau sắp xếp là:"<<endl;
    xuat(M,n);
}   