/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * THUẬT TOÁN KRUSKAL - TÌM CÂY KHUNG NHỎ NHẤT (MST)
 * 
 * Mô tả bài toán:
 *   Cho một đồ thị vô hướng liên thông có trọng số gồm N đỉnh và M cạnh.
 *   Tìm cây khung nhỏ nhất (MST) của đồ thị sử dụng thuật toán Kruskal 
 *   kết hợp cấu trúc dữ liệu các tập hợp rời nhau (Disjoint Set Union - DSU).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số đỉnh n và số cạnh m.
 *     + Nhập m dòng, mỗi dòng gồm 3 số u, v, w tương ứng cạnh nối u và v với trọng số w.
 *   - Output:
 *     + Danh sách các cạnh sau khi sắp xếp tăng dần theo trọng số.
 *     + Danh sách các cạnh được chọn vào cây khung.
 *     + Tổng trọng số của cây khung nhỏ nhất (MST).
 * 
 * Ví dụ đồ thị minh họa (6 đỉnh, 9 cạnh):
 *   - Input:
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

 *   - Output:
 *     Danh sách sau khi sort theo trọng số:
 *     1. 1 -> 4:  3
 *     2. 2 -> 3:  5
 *     3. 3 -> 4:  8
 *     ...
 *     MST = 37
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    ll u, v, w;
    bool chosen;
};
vector<ll> parent_node, sz;
bool comp(Edge a, Edge b) {
    return a.w < b.w;
}
void show_list_sort(vector<Edge>& edges) {
    cout << "\nDanh sách sau khi sort theo trọng số:\n";
    for (size_t i = 0; i < edges.size(); i++) {
        cout << i + 1 << ". " << edges[i].u << " -> " << edges[i].v << ":  " << edges[i].w << endl;
    }
    cout << endl;
}
void make_set(ll n) {
    parent_node.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
    }
}
ll find_set(ll u) {
    if (parent_node[u] == u) return u;
    return parent_node[u] = find_set(parent_node[u]);
}
bool union_sets(ll u, ll v) {
    ll root_u = find_set(u);
    ll root_v = find_set(v);
    if (root_u == root_v) return false;
    if (sz[root_u] < sz[root_v]) swap(root_u, root_v);
    parent_node[root_v] = root_u;
    sz[root_u] += sz[root_v];
    return true;
}
int main() {
    cout << "Nhập số đỉnh và số cạnh: ";
    ll n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].chosen = false;
        cout << "Nhập cạnh thứ " << i + 1 << " (u v w): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), comp);
    show_list_sort(edges);
    make_set(n);
    ll total_w = 0, edgeCount = 0;
    for (Edge &e : edges) {
        if (union_sets(e.u, e.v)) {
            e.chosen = true;
            total_w += e.w;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }
    if (edgeCount != n - 1) {
        cout << "Đồ thị không liên thông! Không tồn tại cây khung nhỏ nhất.\n";
    } else {
        cout << "Các cạnh đã được chọn vào cây khung nhỏ nhất:\n";
        for (Edge &e : edges) {
            if (e.chosen) {
                cout << e.u << " -> " << e.v << ":  " << e.w << endl;
            }
        }
        cout << "Tổng trọng số của cây khung nhỏ nhất (MST) là: " << total_w << endl;
    }
    return 0;
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

