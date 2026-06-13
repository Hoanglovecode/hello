/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * THUẬT TOÁN DIJKSTRA - TÌM ĐƯỜNG ĐI NGẮN NHẤT
 * 
 * Mô tả bài toán:
 *   Cho một đồ thị vô hướng liên thông có trọng số không âm gồm N đỉnh và M cạnh. 
 *   Tìm đường đi ngắn nhất từ một đỉnh xuất phát (đỉnh nguồn x) đến các đỉnh còn lại, 
 *   hoặc đến một đỉnh đích y cụ thể.
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số đỉnh n và số cạnh m.
 *     + Nhập m dòng, mỗi dòng chứa 3 số u, v, w thể hiện cạnh nối u và v với trọng số w.
 *     + Nhập lựa chọn:
 *       1: Từ đỉnh xuất phát tới tất cả các đỉnh khác (sau đó nhập đỉnh xuất phát).
 *       2: Từ đỉnh xuất phát tới một đỉnh kết thúc cụ thể (sau đó nhập đỉnh xuất phát và đỉnh kết thúc).
 *   - Output:
 *     + Bảng tối ưu hóa nhãn đỉnh qua các bước lặp dưới dạng (khoảng cách, đỉnh trước).
 *     + Khoảng cách ngắn nhất và đường đi chi tiết.
 * 
 * Ví dụ đồ thị minh họa 1 (6 đỉnh, 9 cạnh):
 *   Input:
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
 *     Nhập lựa chọn: 1
 *     Xuất phát tại đỉnh: 1
 * 
 * Ví dụ đồ thị minh họa 2 (10 đỉnh, 19 cạnh):
 *     10 19
 *     2 3 4
 *     3 4 6
 *     1 2 1
 *     2 5 1
 *     3 5 2
 *     3 6 2
 *     4 6 2
 *     4 7 2
 *     1 5 3
 *     5 6 4
 *     6 7 3
 *     4 8 3
 *     1 10 2
 *     1 9 3
 *     5 9 5
 *     6 9 5
 *     7 8 1
 *     8 9 3
 *     9 10 6
 *     Nhập lựa chọn: 1
 *     Xuất phát tại đỉnh: 1
 * 
 * Ví dụ đồ thị minh họa 3 (8 đỉnh, 14 cạnh):
 *     8 14
 *     1 2 12
 *     1 3 5
 *     2 3 5
 *     2 4 1
 *     3 4 10
 *     2 5 6
 *     4 5 5
 *     3 6 25
 *     4 6 1
 *     5 6 14
 *     5 7 15
 *     6 7 1
 *     7 8 1
 *     6 8 5
 *     Nhập lựa chọn: 1
 *     Xuất phát tại đỉnh: 1
 * ----------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9;
long n, m, x, y;
vector<pair<long, long>> adj[105]; // adj[u] = {v, w}

struct StepState {
    int selected_vertex;
    vector<long long> dist;
    vector<int> parent;
    vector<bool> visited_status;
};

vector<StepState> table;

void solve_dijkstra(int start) {
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);

    dist[start] = 0;
    parent[start] = start; // Đỉnh bắt đầu có đỉnh trước là chính nó

    // Lưu bước khởi tạo
    StepState init_state;
    init_state.selected_vertex = 0;
    init_state.dist = dist;
    init_state.parent = parent;
    init_state.visited_status = visited;
    table.push_back(init_state);

    for (int step = 1; step <= n; step++) {
        // Tìm đỉnh chưa duyệt có khoảng cách nhỏ nhất
        int u = -1;
        long long min_d = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min_d) {
                min_d = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // Không còn đỉnh nào đến được nữa

        visited[u] = true;

        // Tối ưu hóa nhãn các đỉnh kề của u
        for (auto edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }

        // Lưu trạng thái bước hiện tại
        StepState state;
        state.selected_vertex = u;
        state.dist = dist;
        state.parent = parent;
        state.visited_status = visited;
        table.push_back(state);
    }
}

// In đường đi ra
void show(int u, int v, const vector<int>& parent){
    if (u == v){
        cout << "Điểm xuất phát trùng với điểm kết thúc." << endl;
        return;
    }
    if (parent[v] == 0) {
        cout << "Không có đường đi từ " << u << " đến " << v << endl;
        return;
    }

    vector<int> path;
    int curr = v;
    while (curr != u && curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());

    cout << "Đường đi: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    cout << "Nhập số đỉnh, cạnh: ";
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= m; i++) {
        cout << "Nhập cạnh thứ " << i << " là (đỉnh u, đỉnh v, trọng số w): ";
        long u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng
    }

    cout << "1. Xuất phát từ 1 đỉnh đến tất cả các đỉnh còn lại" << endl;
    cout << "2. Xuất phát từ đỉnh x đến đỉnh y" << endl;
    cout << "Nhập lựa chọn của bạn: ";
    int option; cin >> option;
    if (option == 1) {
        cout << "Xuất phát tại đỉnh: ";
        cin >> x;
    } else {
        cout << "Xuất phát tại đỉnh: ";
        cin >> x;
        cout << "Kết thúc tại đỉnh: ";
        cin >> y;
    }

    solve_dijkstra(x);

    // In bảng kết quả
    cout << "\nBẢNG TIẾN TRÌNH THUẬT TOÁN DIJKSTRA:\n";
    cout << "Bước | Đỉnh chọn | ";
    for (int j = 1; j <= n; j++) {
        cout << "   d[" << j << "]   | ";
    }
    cout << "\n--------------------------------------------------------------\n";
    for (size_t i = 0; i < table.size(); i++) {
        cout << setw(4) << i << " | ";
        if (table[i].selected_vertex == 0) {
            cout << " Khởi tạo | ";
        } else {
            cout << "    " << setw(2) << table[i].selected_vertex << "    | ";
        }
        for (int j = 1; j <= n; j++) {
            // Nếu đỉnh đã được chọn trước bước này, in dấu "-" thể hiện đã đóng nhãn cố định
            if (i > 0 && table[i - 1].visited_status[j]) {
                cout << "     -     | ";
                continue;
            }
            long long d_val = table[i].dist[j];
            int p_val = table[i].parent[j];
            if (d_val == INF) {
                cout << "  (+vc,0)  | ";
            } else {
                cout << "  (" << setw(2) << d_val << "," << p_val << ")  | ";
            }
        }
        cout << "\n";
    }
    cout << "--------------------------------------------------------------\n\n";

    // Lấy trạng thái cuối cùng
    const auto& last_state = table.back();

    if (option == 1) {
        for (int i = 1; i <= n; i++) {
            if (last_state.dist[i] == INF) {
                cout << "Không có đường đi từ đỉnh " << x << " đến " << i << endl;
            } else {
                cout << "Khoảng cách từ đỉnh " << x << " đến " << i << " là: " << last_state.dist[i] << endl;
                show(x, i, last_state.parent);
            }
        }  
    } else {
        if (last_state.dist[y] == INF) {
            cout << "Không có đường đi từ đỉnh " << x << " đến " << y << endl;
        } else {
            cout << "Khoảng cách từ đỉnh " << x << " đến " << y << " là: " << last_state.dist[y] << endl;
            show(x, y, last_state.parent);
        }
    }

    return 0;
}

/*
 * # TRẢ LỜI: Giải thích cách tìm kiếm đường đi của thuật toán Dijkstra:
 * - Nguyên lý: Tìm đường đi ngắn nhất từ đỉnh nguồn S đến mọi đỉnh khác bằng cách liên tục cố định nhãn đỉnh u có d[u] nhỏ nhất.
 * - Các bước thực hiện:
 *   1. Khởi tạo: Đặt d[S] = 0, d[v] = vô cùng với các đỉnh v khác; parent[v] = 0; visited[v] = false.
 *   2. Chọn đỉnh u chưa duyệt (visited[u] = false) có d[u] nhỏ nhất. Đánh dấu u đã duyệt (`visited[u] = true`).
 *   3. Cập nhật nhãn (Relaxation): Với mỗi đỉnh v kề u chưa duyệt, nếu `d[v] > d[u] + w(u, v)`, ta cập nhật `d[v] = d[u] + w(u, v)` và gán `parent[v] = u`.
 *   4. Lặp lại bước 2 và 3 cho đến khi duyệt hết đồ thị.
 * - Truy vết đường đi: Đi ngược từ đỉnh đích T về S theo mảng `parent[]` (T -> parent[T] -> ... -> S), sau đó đảo ngược chuỗi thu được.
 */