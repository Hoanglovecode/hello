/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * THUẬT TOÁN DIJKSTRA CÓ ĐIỀU KIỆN RÀNG BUỘC
 * 
 * Mô tả bài toán:
 *   Cho đồ thị vô hướng liên thông có trọng số không âm gồm N đỉnh và M cạnh.
 *   Tìm đường đi ngắn nhất từ đỉnh nguồn S đến đỉnh đích T thỏa mãn:
 *     - Trường hợp 1: Bắt buộc phải đi qua cạnh E1 = (u, v).
 *     - Trường hợp 2: Bắt buộc phải đi qua cạnh E1 = (u, v) và KHÔNG được đi qua cạnh E2 = (x, y).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số đỉnh n và số cạnh m.
 *     + Nhập m dòng, mỗi dòng chứa 3 số u, v, w thể hiện cạnh nối u và v với trọng số w.
 *     + Nhập đỉnh xuất phát S và đỉnh kết thúc T.
 *     + Nhập cạnh bắt buộc đi qua E1 = (u1, v1).
 *     + Nhập cạnh cần tránh E2 = (u2, v2) (Nếu không có cạnh cần tránh, nhập 0 0).
 *   - Output:
 *     + Đường đi ngắn nhất và độ dài của Trường hợp 1.
 *     + Đường đi ngắn nhất và độ dài của Trường hợp 2.
 * 
 * Ví dụ minh họa:
 *   Sử dụng đồ thị 6 đỉnh, 9 cạnh:
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
 *     Đỉnh xuất phát S và đích T: 1 6
 *     Cạnh bắt buộc đi qua E1: 2 3
 *     Cạnh cần tránh E2: 3 5
 * 
 *   Kết quả:
 *     1. TH1: Bắt buộc đi qua cạnh (2, 3):
 *        Độ dài: 13
 *        Đường đi: 1 -> 4 -> 2 -> 3 -> 5 -> 6
 * 
 *     2. TH2: Bắt buộc đi qua cạnh (2, 3) và KHÔNG đi qua cạnh (3, 5):
 *        Độ dài: 14
 *        Đường đi: 1 -> 4 -> 2 -> 3 -> 6
 * ----------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m;
vector<pair<int, int>> adj[105]; // adj[u] = {v, w}

// Tìm trọng số của cạnh (u, v) trên đồ thị
long long get_weight(int u, int v) {
    for (auto edge : adj[u]) {
        if (edge.first == v) return edge.second;
    }
    return -1; // Cạnh không tồn tại
}

// Giải Dijkstra có thể bỏ qua một cạnh cụ thể (avoid_u, avoid_v)
vector<long long> dijkstra_helper(int start, int avoid_u, int avoid_v, vector<int>& parent) {
    vector<long long> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    parent.assign(n + 1, 0);

    dist[start] = 0;
    parent[start] = start;

    for (int step = 1; step <= n; step++) {
        int u = -1;
        long long min_d = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min_d) {
                min_d = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            // Bỏ qua cạnh cần tránh (avoid_u, avoid_v)
            if ((u == avoid_u && v == avoid_v) || (u == avoid_v && v == avoid_u)) {
                continue;
            }
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    return dist;
}

// Truy vết đường đi ngược từ đích về nguồn
vector<int> trace_path(int start, int end, const vector<int>& parent) {
    vector<int> path;
    int curr = end;
    while (curr != start && curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    if (curr == start) {
        path.push_back(start);
    } else {
        path.clear(); // Không thể truy vết
    }
    reverse(path.begin(), path.end());
    return path;
}

// Giải và in kết quả cho một trường hợp cụ thể
void solve_case(int S, int T, int req_u, int req_v, int avoid_x, int avoid_y, string label) {
    long long w_req = get_weight(req_u, req_v);
    if (w_req == -1) {
        cout << label << ": Cạnh bắt buộc đi qua (" << req_u << ", " << req_v << ") không tồn tại trên đồ thị!\n";
        return;
    }

    // Nếu bắt buộc đi qua cạnh req mà lại bắt tránh chính cạnh req đó
    if ((req_u == avoid_x && req_v == avoid_y) || (req_u == avoid_y && req_v == avoid_x)) {
        cout << label << ": Mâu thuẫn điều kiện (cạnh bắt buộc trùng với cạnh cần tránh)!\n";
        return;
    }

    // Chạy Dijkstra từ các đỉnh liên quan (S, req_u, req_v) tránh cạnh (avoid_x, avoid_y)
    vector<int> parent_S, parent_u, parent_v;
    vector<long long> dist_S = dijkstra_helper(S, avoid_x, avoid_y, parent_S);
    vector<long long> dist_u = dijkstra_helper(req_u, avoid_x, avoid_y, parent_u);
    vector<long long> dist_v = dijkstra_helper(req_v, avoid_x, avoid_y, parent_v);

    // Phương án 1: S -> req_u -> req_v -> T
    long long d1 = INF;
    if (dist_S[req_u] != INF && dist_v[T] != INF) {
        d1 = dist_S[req_u] + w_req + dist_v[T];
    }

    // Phương án 2: S -> req_v -> req_u -> T
    long long d2 = INF;
    if (dist_S[req_v] != INF && dist_u[T] != INF) {
        d2 = dist_S[req_v] + w_req + dist_u[T];
    }

    long long min_d = min(d1, d2);

    if (min_d >= INF) {
        cout << label << ": Không tìm thấy đường đi thỏa mãn điều kiện!\n";
    } else {
        cout << label << ":\n";
        cout << "  - Độ dài: " << min_d << endl;
        cout << "  - Đường đi: ";
        
        vector<int> final_path;
        if (min_d == d1) {
            // S -> req_u
            vector<int> p1 = trace_path(S, req_u, parent_S);
            // req_v -> T
            vector<int> p2 = trace_path(req_v, T, parent_v);
            
            final_path.insert(final_path.end(), p1.begin(), p1.end());
            final_path.insert(final_path.end(), p2.begin(), p2.end());
        } else {
            // S -> req_v
            vector<int> p1 = trace_path(S, req_v, parent_S);
            // req_u -> T
            vector<int> p2 = trace_path(req_u, T, parent_u);
            
            final_path.insert(final_path.end(), p1.begin(), p1.end());
            final_path.insert(final_path.end(), p2.begin(), p2.end());
        }
        
        for (size_t i = 0; i < final_path.size(); i++) {
            cout << final_path[i];
            if (i < final_path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Nhập số đỉnh, cạnh: ";
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= m; i++) {
        cout << "Nhập cạnh thứ " << i << " là (đỉnh u, đỉnh v, trọng số w): ";
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S, T;
    cout << "Nhập đỉnh xuất phát S và đỉnh kết thúc T: ";
    cin >> S >> T;

    int req_u, req_v;
    cout << "Nhập cạnh bắt buộc đi qua E1 (u1 v1): ";
    cin >> req_u >> req_v;

    int avoid_x, avoid_y;
    cout << "Nhập cạnh cần tránh E2 (u2 v2) [nhập 0 0 nếu không có]: ";
    cin >> avoid_x >> avoid_y;

    cout << "\n================ KẾT QUẢ TÌM ĐƯỜNG ĐI NGOẠI LỆ ================\n";
    // 1. TH1: Chỉ bắt buộc đi qua E1 (không tránh cạnh nào)
    solve_case(S, T, req_u, req_v, 0, 0, "1. Trường hợp 1: Bắt buộc đi qua cạnh (" + to_string(req_u) + ", " + to_string(req_v) + ")");

    // 2. TH2: Bắt buộc đi qua E1 và tránh E2 (nếu E2 được nhập khác 0)
    if (avoid_x != 0 && avoid_y != 0) {
        solve_case(S, T, req_u, req_v, avoid_x, avoid_y, "2. Trường hợp 2: Bắt buộc đi qua cạnh (" + to_string(req_u) + ", " + to_string(req_v) + ") và tránh cạnh (" + to_string(avoid_x) + ", " + to_string(avoid_y) + ")");
    } else {
        cout << "2. Trường hợp 2: Không yêu cầu cạnh cần tránh.\n";
    }
    cout << "================================================================\n";

    return 0;
}

/*
 * # TRẢ LỜI: Giải thích cách tìm đường đi Dijkstra có điều kiện ràng buộc:
 * 1. Cạnh cần tránh E2 (x, y):
 *    - Bỏ qua, không xét cạnh này trong mọi lượt chạy thuật toán Dijkstra.
 * 2. Cạnh bắt buộc đi qua E1 (u, v):
 *    - Đường đi từ S đến T qua E1 phải theo một trong hai hướng:
 *      + Hướng 1: S -> u -> v -> T. Độ dài = d(S, u) + w(u, v) + d(v, T).
 *      + Hướng 2: S -> v -> u -> T. Độ dài = d(S, v) + w(v, u) + d(u, T).
 *    - Cách tính: Chạy Dijkstra 3 lượt độc lập từ S, từ u, và từ v (tất cả đều tránh E2).
 *      + Lượt 1 từ S cho ta d(S, u) và d(S, v).
 *      + Lượt 2 từ u cho ta d(u, T).
 *      + Lượt 3 từ v cho ta d(v, T).
 *    - Kết quả tối ưu là giá trị nhỏ nhất giữa Hướng 1 và Hướng 2. Đường đi được ghép từ 3 chặng tương ứng.
 */

