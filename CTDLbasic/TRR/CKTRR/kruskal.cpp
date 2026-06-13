#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
    int w;
};
const int maxn=1001;
int n,m;
int parent[maxn],sz[maxn];
vector<edge>canh;
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;//Số cạnh nối với đỉnh/giá trị gốc
    }
}
//Tìm giá trị gốc của đỉnh
int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);//Biến mọi đỉnh có 1 gốc nhỏ nhất
}
bool Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return false;//Không gộp được vì cùng cha,nếu gộp sẽ tạo thành chu trình
    if(sz[a]<sz[b])swap(a,b);
    parent[b]=a;//Luôn gắn tập nhỏ hơn vào tập lớn hơn
    sz[a]+=sz[b];
    return true;
}
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        edge e;
        e.u=x;e.v=y;e.w=w;
        canh.push_back(e);
    }
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void kruskal(){
    //Tạo cây khung cực tiểu rổng
    vector<edge>mst;
    int d=0;
    //sort inorder
    sort(canh.begin(),canh.end(),cmp);
    for(int i=0;i<m;i++){
        if(mst.size()==n-1)break;
        edge e=canh[i];
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    if(mst.size()!=n-1){
        cout<<"Đồ thị không liên thông"<<endl;
    }
    else{
        cout<<"MST : "<<d<<endl;
        for(auto it:mst){
            cout<<it.u<<' '<<it.v<<' '<<it.w<<endl;
        }
    }
}
int main(){
   inp();
   make_set();
   kruskal();
}