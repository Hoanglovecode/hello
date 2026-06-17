/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * THUẬT TOÁN PRIM - TÌM CÂY KHUNG NHỎ NHẤT (MST)
 * 
 * Mô tả bài toán:
 *   Cho đồ thị vô hướng liên thông có trọng số. Tìm cây khung nhỏ nhất (MST) 
 *   của đồ thị sử dụng thuật toán Prim xuất phát từ một đỉnh được chọn trước 
 *   (trong chương trình mặc định xuất phát từ đỉnh 1).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số đỉnh n và số cạnh m.
 *     + Nhập m dòng, mỗi dòng chứa 3 số u, v, w tương ứng cạnh nối u và v có trọng số w.
 *   - Output:
 *     + Tiến trình chọn các đỉnh kề có trọng số nhỏ nhất qua từng bước.
 *     + Danh sách các cạnh được chọn vào cây khung.
 *     + Tổng trọng số của cây khung nhỏ nhất (MST).
 * 
 * Ví dụ đồ thị minh họa (6 đỉnh, 9 cạnh):
 *   - Input:
 *     6 9
 *     1 2 4
 *     1 4 2
 *     2 4 1
 *     2 3 5
 *     3 4 8
 *     4 5 10
 *     3 5 2
 *     3 6 6
 *     5 6 3
 *   - Output:
 *     Cây khung nhỏ nhất: 
 *     Chọn đỉnh 1 với trọng số 0
 *     Chọn đỉnh 4 với trọng số 2
 *     Chọn đỉnh 2 với trọng số 1
 *     Chọn đỉnh 3 với trọng số 5
 *     Chọn đỉnh 5 với trọng số 2
 *     Chọn đỉnh 6 với trọng số 3
 * 
 *     Những cạnh đã chọn là:
 *     1. 1 -> 4: 2
 *     2. 4 -> 2: 1
 *     3. 2 -> 3: 5
 *     4. 3 -> 5: 2
 *     5. 5 -> 6: 3
 *     Tổng trọng số của cây khung nhỏ nhất là: 14
 * ----------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll n, m;
vector<bool> visited;
vector<vector<pair<ll, ll>>> g; // g[u] = {v, w}
vector<ll> dist;
vector<ll> parent_node;

struct Edge {
    ll u, v, w;
};

void prim(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<Edge> mst_edges;
    ll total_weight = 0;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        ll w = top.first;
        ll u = top.second;

        if (visited[u]) continue;

        visited[u] = true;
        total_weight += w;

        if (u != start) {
            cout << "Chọn đỉnh " << u << " nối với đỉnh " << parent_node[u] << " với trọng số " << w << endl;
            mst_edges.push_back({parent_node[u], u, w});
        } else {
            cout << "Chọn đỉnh bắt đầu: " << u << " với trọng số 0" << endl;
        }

        for (auto x : g[u]) {
            ll v = x.first;
            ll cost = x.second;
            if (!visited[v] && cost < dist[v]) {
                dist[v] = cost;
                parent_node[v] = u;
                pq.push({cost, v});
            }
        }
    }

    if (mst_edges.size() != n - 1) {
        cout << "\nĐồ thị không liên thông! Không tồn tại cây khung nhỏ nhất.\n";
        return;
    }

    cout << "\nNhững cạnh đã chọn là:\n";
    for (size_t i = 0; i < mst_edges.size(); i++) {
        cout << i + 1 << ". " << mst_edges[i].u << " -> " << mst_edges[i].v << ": " << mst_edges[i].w << endl;
    }
    cout << "Tổng trọng số của cây khung nhỏ nhất là: " << total_weight << endl;
}

int main() {
    cout << "Nhập số đỉnh và số cạnh: ";
    if (!(cin >> n >> m)) return 0;
    
    g.resize(n + 1);
    visited.assign(n + 1, false);
    dist.assign(n + 1, INF);
    parent_node.assign(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        cout << "Nhập cạnh thứ " << i << " (u v w): ";
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    cout << "\nCây khung nhỏ nhất: " << endl;
    prim(1); // bắt đầu từ đỉnh 1
    return 0;
}

/*
 * # TRẢ LỜI: Giải thích thuật toán Prim tìm cây khung nhỏ nhất (MST):
 * - Nguyên lý hoạt động:
 *   + Bắt đầu từ một đỉnh nguồn (mặc định là đỉnh 1), đánh dấu đỉnh này đã thăm.
 *   + Sử dụng hàng đợi ưu tiên (priority_queue) để lưu trữ các cạnh nối từ các đỉnh đã thăm tới các đỉnh chưa thăm. Hàng đợi này luôn ưu tiên cạnh có trọng số nhỏ nhất ở trên cùng.
 *   + Ở mỗi bước, lấy ra cạnh có trọng số nhỏ nhất kết nối với một đỉnh chưa thăm v.
 *   + Đánh dấu v đã thăm, cộng trọng số cạnh vào tổng trọng số cây khung, và thêm các cạnh kề của v với những đỉnh chưa thăm vào hàng đợi.
 *   + Lặp lại cho đến khi tất cả các đỉnh đều được thăm (được n-1 cạnh) hoặc hàng đợi rỗng (đồ thị không liên thông).
 */

