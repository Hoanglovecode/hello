/*
Câu 3 ( 3 điểm) Cho phương trình X1 + X2 +....+ Xk = n
 a) Viết chương trình liệt nghiệm nguyên dương của phương trình trên bằng quay lui
*/
#include <bits/stdc++.h>
using namespace std;
int n1,target1;
int n2,target2;
//Option 1:Use array
int a[100];
void inkq1(){
    for(int i=1;i<=n1;i++)cout<<a[i]<<' ';
}
void tryy1(int i,int start,int sum){
    for(int j=1;j<=target1;j++){
        if(sum>target1)break;
        a[i]=j;
        sum+=j;
        if(i==n1){
            if(sum==target1){
                inkq1();
                cout<<endl;
            }
        }
        else tryy1(i+1,j,sum);
        sum-=j;
    }
}
//Option 2:Use vector
vector<int>v;
void inkq2(){
    for(int x:v)cout<<x<<' ';
}
void tryy2(int sum){
    for(int j=1;j<=target2;j++){
        if(sum>target2)break;
        v.push_back(j);
        sum+=j;
        if(v.size()==n2){
                if(sum==target2){
                    inkq2();
                    cout<<endl;
                }
        }
        else tryy2(sum);
        v.pop_back();
        sum-=j;
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin>>target1>>n1;
   cin>>target2>>n2;
   cout<<"Array"<<endl;
   tryy1(1,1,0);
   cout<<"Vector"<<endl;
   tryy2(0);
}
/*
Input:
6 4
8 5
Output:
Array
1 1 1 3
1 1 2 2
1 1 3 1
1 2 1 2
1 2 2 1
1 3 1 1
2 1 1 2
2 1 2 1
2 2 1 1
3 1 1 1
Vector
1 1 1 1 4 
1 1 1 2 3 
1 1 1 3 2 
1 1 1 4 1 
1 1 2 1 3 
1 1 2 2 2 
1 1 2 3 1 
1 1 3 1 2 
1 1 3 2 1 
1 1 4 1 1 
1 2 1 1 3 
1 2 1 2 2 
1 2 1 3 1 
1 2 2 1 2 
1 2 2 2 1 
1 2 3 1 1 
1 3 1 1 2 
1 3 1 2 1 
1 3 2 1 1 
1 4 1 1 1 
2 1 1 1 3 
2 1 1 2 2 
2 1 1 3 1 
2 1 2 1 2 
2 1 2 2 1 
2 1 3 1 1 
2 2 1 1 2 
2 2 1 2 1 
2 2 2 1 1 
2 3 1 1 1 
3 1 1 1 2 
3 1 1 2 1 
3 1 2 1 1 
3 2 1 1 1 
4 1 1 1 1 
*/