/*
8 14 
1 2 4
1 3 6
1 4 2
1 5 5
2 4 7
2 7 8
3 4 3
3 6 1
4 6 4
4 7 5
5 6 7
6 7 2
6 8 3
7 8 6
*/
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
        sz[i]=1;
    }
}
int find(int v){
    if(v==parent[v]) return v;
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
        cout<<"MST : "<<d<<endl;
        for(auto it:mst){
            cout<<it.u<<' '<<it.v<<' '<<it.w<<endl;
        }
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   inp();
   make_set();
   kruskal();
}
/*
 * # TRẢ LỜI: Giải thích cách xây dựng cây khung nhỏ nhất (MST) của thuật toán Kruskal:
 * - Ý tưởng: Duyệt và chọn các cạnh của đồ thị theo thứ tự trọng số tăng dần, đảm bảo cạnh được chọn không tạo thành chu trình với các cạnh đã chọn trước đó.
 * - Các bước thực hiện:
 *   1. Khởi tạo: Sắp xếp các cạnh tăng dần theo trọng số. Coi mỗi đỉnh là một tập hợp (thành phần liên thông) riêng biệt sử dụng cấu trúc DSU.
 *   2. Chọn cạnh: Lần lượt xét các cạnh e = (u, v) trong danh sách đã sắp xếp:
 *      + Nếu u và v thuộc hai tập hợp khác nhau (không tạo chu trình), chọn cạnh e vào cây khung và gộp (Union) hai tập hợp này lại.
 *      + Nếu trùng tập hợp (tạo chu trình), bỏ qua.
 *   3. Điều kiện dừng: Khi đã chọn đủ `N - 1` cạnh (với N là số đỉnh). Nếu duyệt hết các cạnh mà không đủ `N - 1` cạnh thì đồ thị không liên thông.
 */