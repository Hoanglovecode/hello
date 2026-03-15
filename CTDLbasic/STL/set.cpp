#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   //Set có 2 tính chất
   //1.Không lưu trùng phần tử đã có sẵn
   //2.Tự Sắp xếp tăng dần
   set<int>s;
   s.insert(1);
   s.insert(2);
   s.insert(3);
   s.insert(4);
   s.insert(4);
   cout<<s.size()<<endl;
   for(int x:s)cout<<x<<' ';
   cout<<endl;
   for(auto it=s.begin();it!=s.end();it++){
      cout<<*it<<' ';
   }
   cout<<endl;
   //Duyet reverse
   for(auto it=s.rbegin();it!=s.rend();it++){
      cout<<*it<<' ';
   }
   auto it=s.begin();
   ++it;//set k asssit it+=1 like to vector
   cout<<"\n"<<*it<<endl;
   /*
   khi find một phần tử thì có thể mất o(N) còn se.find()thì chỉ o(log(N))
   */
  int a[7]={3,4,2,3,3,1,2};
  multiset<int>se(a,a+7);//1 2 2 3 3 3 4
  //multiset can store nhiều ptu giống nhau
  //muitiset giống set nhưng find(),erase() và count() cho ra kq khác
  //erase có thể delete nhiều ptu,muốn xóa 1 ptu phải gán nó thông qua find() biến khác
  //hàm find(2) sẽ tìm đến giá trị đầu tiên ví dụ a[1] trong dãy trên;
  //hàm count(3) có thể đếm nhiều và cho kq là 3 ptu 3
  int n;cin>>n;
  multiset<int>ss;
  for(int i=0;i<n;i++){
   int x;cin>>x;//8
   ss.insert(x);//1 3 2 1 3 2 4 5
  }
  auto itt=ss.count(3);
  cout<<itt<<endl;;//2
  auto ittt=ss.find(3);
  ss.erase(ittt);
  for(int x:ss)cout<<x<<' ';//1 1 2 2 3 4 5 
  cout<<endl;


}