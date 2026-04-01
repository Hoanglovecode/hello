// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các
// số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số.
// Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.
#include <bits/stdc++.h>
using namespace std;
int n,a[100],x[100],S;
void nhap(){
   cin>>n>>S;
   for(int i=0;i<n;i++)cin>>a[i];
   cout<<endl;
   sort(a,a+n);//sort lại mảng a[] tăng dần
}
void tryy1(int i,int start,int sum){
   for(int j=start;j<n;j++){
      x[i]=a[j];
      sum+=x[i];
      if(sum==S){
         for(int idx=1;idx<=i;idx++){//idx bắt đầu bằng 1 vì x[0] là giá trị rác
            cout<<x[idx]<<" ";
         }
         cout<<endl;
      }
      else if(sum<S){
         tryy1(i+1,j,sum);//start bắt đầu từ j vì t có thể backtrack lấy trùng giá trị
      }
      sum-=a[j];
   }
}
void tryy2(int i,int start,int sum){
   for(int j=start;j<n;j++){
      x[i]=a[j];
      sum+=x[i];
      if(sum==S){
         for(int idx=1;idx<=i;idx++){//idx bắt đầu bằng 1 vì x[0] là giá trị rác
            cout<<x[idx]<<" ";
         }
         cout<<endl;
      }
      else if(sum<S){
         tryy2(i+1,0,sum);//start bắt đầu từ 0 vì t muốn lấy hoán vị(FULL)
      }
      sum-=a[j];
   }
}
vector<int>v;
void tryy3(int start,int sum){
   for(int j=start;j<n;j++){
      if(sum>S) break;
      v.push_back(a[j]);
      sum+=a[j];
      if(sum==S){
         for(int x:v){
            cout<<x<<' ';
         }
         cout<<endl;
      }
      else if(sum<S){
         tryy3(j+1,sum);
      }
      v.pop_back();
      sum-=a[j];
   }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   nhap();
   cout<<"X1+X2+X3+..+Xn=Sum(Liệt kê bộ nghiệm)"<<endl;
   tryy1(1,0,0);
   cout<<"X1+X2+X3+..+Xn=Sum(Hoán vị các bộ nghiệm)"<<endl;
   tryy2(1,0,0);
   cout<<"X1+X2+X3+..+Xn=Sum(Liệt kê bộ nghiệm,các nghiệm phải khác nhau)"<<endl;
   tryy3(0,0);
}
// Đầu vào
// Dòng thứ nhất la hai số N và X
// Dòng tiếp theo đưa vào N số của mmảng A[]
/*
INPUT:
3 10
4 2 3
OUTPUT:
5
{2 2 2 22} 
{2 2 2 4}
{2 2 3 3}
{2 4 4}
{3 3 4}
*/