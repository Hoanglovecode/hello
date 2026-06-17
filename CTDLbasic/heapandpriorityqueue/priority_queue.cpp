#include <bits/stdc++.h>
using namespace std;
//Bài toán nối dây sao cho tổng tri phí nối dây là ngắn nhất
//priority_queue<int>pq;      pq.top() is a max value element

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int t;cin>>t;
   while(t--){
    int n;cin>>n;
    int a[n];
    for(int &x:a)cin>>x;
    priority_queue<int,vector<int>,greater<int>>pq; //pq.top() is a min value element
    int cost=0;
    for(int x:a)pq.push(x);
    while(pq.size()>1){
        int top1=pq.top();pq.pop();
        int top2=pq.top();pq.pop();
        cost+=top1+top2;
        pq.push(top1+top2);
    }
    cout<<cost<<' ';
   }
}