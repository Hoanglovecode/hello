//Bài 53. Viết chương trình có sử dụng hàm để tính 2^n (n nhập từ bàn phím và n <=2000)
#include <stdio.h>
#define max 1000
int main(){
// Mảng a[] lưu từng chữ số của kết quả.
// a[0] là chữ số hàng đơn vị, a[1] là hàng chục, ...
// Ví dụ: 1234 sẽ lưu thành [4, 3, 2, 1]
int a[max];//khai báo mảng a có 1000 phần tử 0 ban đầu.
int len=1;//số lượng chữ số ban đầu là 1
a[0]=1;//vì 2 mũ 0=1
int n;
printf("Nhập n với n<=2000:");
scanf("%d",&n);
//lặp n lần mỗi lần nhân kết quả hiện tại với 2
for(int i=0;i<n;i++){
    int nho=0;//Khai báo biến nhớ ban đầu
    for(int j=0;j<len;j++){
        int nhan=a[j]*2+nho;//Nhân từng phần tử a[j] với 2 cộng phần nhớ
        a[j]=nhan%10;//lấy phần đơn vị của phép nhân để lưu về lại a[j] mới
        nho=nhan/10;//Biến nhớ là phần chục (nếu có).Ví dụ 8*2=16 thì nho=1;a[0]=6
    }
    /*Nếu sau khi nhân hết các chữ số mà còn phần nhớ
    thì tách từng chữ số của biến nhớ và thêm vào mảng 
    Giả sử khi nho=12 thì thêm 2 trước sau đó thêm 1
    */
    while(nho>0){ 
        a[len]=nho%10;//Lấy chữ số đơn vị của biến nhớ
        nho/=10;//bỏ đi số vừa lấy
        len++;//Tăng độ dài lên để lưu số lượng chữ số trong kết quả
    }
}
printf("2 mũ %d = ",n);
//in ngược vì mảng a[i] lưu từ hàng đơn vị trước như đã nói ở trên.
for(int i=len-1;i>=0;i--)printf("%d",a[i]);
}