/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * THUẬT TOÁN KRUSKAL TÌM MST CÓ ĐIỀU KIỆN RÀNG BUỘC
 * 
 * Mô tả bài toán:
 *   Cho một đồ thị vô hướng liên thông có trọng số gồm N đỉnh và M cạnh.
 *   Tìm cây khung nhỏ nhất (MST) của đồ thị sử dụng thuật toán Kruskal 
 *   thỏa mãn các điều kiện ràng buộc:
 *     - Bắt buộc phải chứa danh sách các cạnh cho trước (ví dụ: bắt buộc chứa AD và AB).
 *     - KHÔNG được chứa danh sách các cạnh cho trước (ví dụ: tránh cạnh CH).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số đỉnh n và số cạnh m.
 *     + Nhập m dòng chứa các cạnh dạng: u v w (đỉnh u, đỉnh v, trọng số w).
 *     + Nhập số lượng cạnh bắt buộc và danh sách các cặp đỉnh bắt buộc.
 *     + Nhập số lượng cạnh cần tránh và danh sách các cặp đỉnh cần tránh.
 *   - Output:
 *     + Tiến trình ép chọn các cạnh bắt buộc và chọn các cạnh tự do theo Kruskal.
 *     + Danh sách các cạnh được chọn vào MST thỏa mãn ràng buộc.
 *     + Tổng trọng số của MST.
 * 
 * Ví dụ minh họa:
 *   Sử dụng đồ thị 6 đỉnh, 9 cạnh:
 *     6 9
 *     1 2 15
 *     1 3 10
 *     2 3 5
 *     1 4 3
 *     3 4 8
 *     1 6 20
 *     4 6 15
 *     4 5 9
 *     5 6 10
 * 
 *   Yêu cầu:
 *     - Bắt buộc chứa 2 cạnh: (1, 2) và (1, 3)
 *     - Cần tránh 1 cạnh: (2, 3)
 * 
 *   Kết quả:
 *     Tổng trọng số MST thỏa mãn ràng buộc: 47
 *     Các cạnh chọn:
 *     - (1, 2) trọng số 15 [Bắt buộc]
 *     - (1, 3) trọng số 10 [Bắt buộc]
 *     - (1, 4) trọng số 3
 *     - (4, 5) trọng số 9
 *     - (5, 6) trọng số 10
 * ----------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    bool req;
    bool avoid;
    bool chosen;
};

int n, m;
vector<int> parent_node;
vector<int> sz;

void make_set() {
    parent_node.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
    }
}

int find_set(int v) {
    if (v == parent_node[v]) return v;
    return parent_node[v] = find_set(parent_node[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent_node[b] = a;
    sz[a] += sz[b];
    return true;
}

bool compare_edges(Edge a, Edge b) {
    return a.w < b.w;
}

int find_edge_index(int u, int v, vector<Edge>& edges) {
    int idx = -1;
    long long min_w = 1e18;
    for (int i = 0; i < (int)edges.size(); i++) {
        if ((edges[i].u == u && edges[i].v == v) || (edges[i].u == v && edges[i].v == u)) {
            if (edges[i].w < min_w) {
                min_w = edges[i].w;
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cout << "Nhập số đỉnh và số cạnh: ";
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cout << "Nhập cạnh thứ " << i + 1 << " (u v w): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].req = false;
        edges[i].avoid = false;
        edges[i].chosen = false;
    }

    int num_req;
    cout << "Nhập số lượng cạnh BẮT BUỘC chứa: ";
    cin >> num_req;
    for (int i = 0; i < num_req; i++) {
        int req_u, req_v;
        cout << "  + Cạnh bắt buộc thứ " << i + 1 << " (u v): ";
        cin >> req_u >> req_v;
        int idx = find_edge_index(req_u, req_v, edges);
        if (idx != -1) {
            edges[idx].req = true;
        } else {
            cout << "Lỗi: Cạnh (" << req_u << ", " << req_v << ") không tồn tại trên đồ thị!\n";
            return 0;
        }
    }

    int num_avoid;
    cout << "Nhập số lượng cạnh CẦN TRÁNH (không chứa): ";
    cin >> num_avoid;
    for (int i = 0; i < num_avoid; i++) {
        int avoid_u, avoid_v;
        cout << "  + Cạnh cần tránh thứ " << i + 1 << " (u v): ";
        cin >> avoid_u >> avoid_v;
        int idx = find_edge_index(avoid_u, avoid_v, edges);
        if (idx != -1) {
            edges[idx].avoid = true;
        }
    }

    // Khởi tạo DSU
    make_set();

    long long total_weight = 0;
    int edge_count = 0;
    vector<Edge> mst_edges;

    // 1. Xử lý các cạnh bắt buộc trước
    cout << "\n--- BẮT ĐẦU XỬ LÝ CÁC ĐIỀU KIỆN ---" << endl;
    for (int i = 0; i < m; i++) {
        if (edges[i].req) {
            if (edges[i].avoid) {
                cout << "Mâu thuẫn: Cạnh (" << edges[i].u << ", " << edges[i].v << ") vừa bắt buộc chứa vừa cần tránh!\n";
                return 0;
            }
            if (union_sets(edges[i].u, edges[i].v)) {
                edges[i].chosen = true;
                total_weight += edges[i].w;
                edge_count++;
                mst_edges.push_back(edges[i]);
                cout << "-> Đã ép chọn cạnh bắt buộc: " << edges[i].u << " - " << edges[i].v << " (trọng số " << edges[i].w << ")" << endl;
            } else {
                cout << "Mâu thuẫn: Các cạnh bắt buộc tạo thành chu trình! Không thể tạo cây khung.\n";
                return 0;
            }
        }
    }

    // 2. Gom các cạnh còn lại để chạy Kruskal tham lam (loại trừ cạnh req đã chọn và cạnh avoid)
    vector<Edge> remaining_edges;
    for (int i = 0; i < m; i++) {
        if (!edges[i].req && !edges[i].avoid) {
            remaining_edges.push_back(edges[i]);
        }
    }

    // Sắp xếp các cạnh còn lại theo trọng số tăng dần
    sort(remaining_edges.begin(), remaining_edges.end(), compare_edges);

    cout << "\nDanh sách cạnh còn lại sau khi lọc và sắp xếp theo trọng số:" << endl;
    for (size_t i = 0; i < remaining_edges.size(); i++) {
        cout << i + 1 << ". " << remaining_edges[i].u << " - " << remaining_edges[i].v << ": " << remaining_edges[i].w << endl;
    }

    // 3. Chạy thuật toán Kruskal trên các cạnh còn lại
    for (Edge &e : remaining_edges) {
        if (edge_count == n - 1) break;
        if (union_sets(e.u, e.v)) {
            e.chosen = true;
            total_weight += e.w;
            edge_count++;
            mst_edges.push_back(e);
            cout << "-> Chọn thêm cạnh: " << e.u << " - " << e.v << " (trọng số " << e.w << ")" << endl;
        }
    }

    cout << "\n================ KẾT QUẢ CÂY KHUNG NHỎ NHẤT ================\n";
    if (edge_count != n - 1) {
        cout << "Đồ thị không liên thông hoặc mâu thuẫn ràng buộc! Không tồn tại cây khung nhỏ nhất thỏa mãn.\n";
    } else {
        cout << "Các cạnh được chọn vào cây khung nhỏ nhất:\n";
        for (size_t i = 0; i < mst_edges.size(); i++) {
            cout << "  " << i + 1 << ". " << mst_edges[i].u << " - " << mst_edges[i].v << ": " << mst_edges[i].w;
            if (mst_edges[i].req) cout << " [Bắt buộc]";
            cout << endl;
        }
        cout << "Tổng trọng số của cây khung nhỏ nhất (MST) là: " << total_weight << endl;
    }
    cout << "============================================================\n";

    return 0;
}

/*
 * # TRẢ LỜI: Giải thích cách xây dựng cây khung Kruskal có điều kiện ràng buộc:
 * 1. Cạnh cần tránh (ví dụ không chứa CH):
 *    - Loại bỏ hoàn toàn khỏi tập cạnh ban đầu trước khi sắp xếp, đảm bảo thuật toán không xét đến.
 * 2. Cạnh bắt buộc phải chứa (ví dụ chứa AD, AB):
 *    - Ép chọn các cạnh này vào cây khung ngay từ đầu (bước khởi tạo): Thực hiện Union các đầu mút của chúng trong DSU, cộng trọng số và tăng số cạnh đã chọn.
 *    - Nếu Union thất bại ở bước này (các cạnh bắt buộc tạo chu trình), dừng thuật toán và báo lỗi.
 * 3. Xét các cạnh tự do còn lại:
 *    - Sắp xếp tăng dần theo trọng số, duyệt chọn như thuật toán Kruskal chuẩn (chỉ chọn nếu Union thành công).
 *    - Dừng khi chọn đủ `N - 1` cạnh. Nếu duyệt hết mà không đủ `N - 1` cạnh thì đồ thị không liên thông hoặc ràng buộc không thể thỏa mãn.
 */

// 6 9
// 1 2 15
// 1 3 10
// 2 3 5
// 1 4 3
// 3 4 8
// 1 6 20
// 4 6 15
// 4 5 9
// 5 6 10