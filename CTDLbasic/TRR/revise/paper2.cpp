#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
int n,m;
int parent[1000],sz[1000];
vector<edge>canh;
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
bool Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return false;
    if(sz[a]<sz[b])swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        edge e;
        e.u=x;e.v=y;e.w=z;
        canh.push_back(e);
    }
}
void kruskal(){
    vector<edge>mst;
    int d=0;
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
        cout<<"MST:"<<d<<endl;
        for(auto it:mst){
            cout<<it.u<<' '<<it.v<<' '<<it.w<<endl;
        }
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   make_set();
   inp();
   kruskal();
}