#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
struct canh{
    int x,y,w;
};
int n,m;
vector<pair<int,int>>adj[maxn];
bool used[maxn];
int parent[maxn],d[maxn];
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++)d[i]=INT_MAX;
}
void prim(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<canh>mst;
    int res=0;
    pq.push({0,u});
    d[u]=0;
    while(!pq.empty()){
        pair<int,int>top=pq.top();pq.pop();
        int trongso=top.first,dinh=top.second;
        if(used[dinh])continue;
        res+=trongso;
        used[dinh]=true;
        if(u!=dinh){
            mst.push_back({dinh,parent[dinh],trongso});
        }

        for(auto it:adj[dinh]){
            int y=it.first,w=it.second;
            if(!used[y]&&w<d[y]){
                pq.push({w,y});
                d[y]=w;
                parent[y]=dinh;
            }
        }
    }
    if(mst.size()!=n-1){
        cout<<"Đồ thị không liên thông"<<endl;
        return;
    }
    cout<<res<<endl;
    for(auto it:mst){
        cout<<it.x<<' '<<it.y<<' '<<it.w<<endl;
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   inp();
   prim(1);
}
// PRIM(u){
// Bước 1 : Khởi tạo
// V(MST) = {u}; // Thêm đỉnh u vào tập đỉnh của cây khung nhỏ nhất
// V = V\{u}; // Loại đỉnh u khỏi tập đỉnh ban đầu
// MST = Ø; // cây khung ban đầu rỗng
// d = 0; // Chiều dài ban đầu của cây khung là = 0

// Bước 2 : Lặp
// While(V != Ø){
// e = (x, y) : Cạnh ngắn nhất có x thuộc V và y thuộc V(MST)
// MST = MST U e; // thêm cạnh e vào cây khung
// d = d + d(e); // thêm chiều dài cạnh e vào độ dài cây khung
// V(MST) = V(MST) U {x}; // Thêm đỉnh x vào tập đỉnh cây khung
// V = VI{x}; // Xóa đỉnh x khỏi tập đỉnh ban đầu

// Bước 3 : Trả về kết quả
// <Trả về độ dài d và cây khung MST>;
// }