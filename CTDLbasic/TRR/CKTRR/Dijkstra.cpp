/*
 * GIẢI THÍCH DỮ LIỆU INPUT:
 * 
 * Dòng đầu tiên: 8 14 1
 * - 8  : Số lượng đỉnh của đồ thị (N = 8, tương ứng các đỉnh A=1, B=2, C=3, D=4, E=5, F=6, G=7, H=8)
 * - 14 : Số lượng cạnh của đồ thị (M = 14)
 * - 1  : Đỉnh bắt đầu (S = 1, tương ứng đỉnh A)
 * 
 * 14 dòng tiếp theo (Mô tả cạnh nối giữa đỉnh u và đỉnh v với trọng số/độ dài w):
 * Cấu trúc: u v w
 * - 1 2 4 : Cạnh nối đỉnh A(1) và B(2) có độ dài 4
 * - 1 3 6 : Cạnh nối đỉnh A(1) và C(3) có độ dài 6
 * - ... tương tự với các cạnh còn lại
 *
 * INPUT thực tế:
8 14 1
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

 * OUTPUT thực tế:
 * Khoảng cách ngắn nhất từ đỉnh nguồn 1 (A) lần lượt đến các đỉnh 1 (A), 2 (B), 3 (C), 4 (D), 5 (E), 6 (F), 7 (G), 8 (H)
0 4 5 2 5 6 7 9
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];
void nhap(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}
const int INF = 1e9;
int pre[maxn];
void dijkstra(int s){
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << ' ';
	}
}
int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s);
}
/*
 * # TRẢ LỜI: Trình bày phương pháp giải tìm đường đi ngắn nhất bằng thuật toán Dijkstra:
 * - Nguyên lý: Tìm đường đi ngắn nhất từ đỉnh nguồn S đến tất cả các đỉnh còn lại của đồ thị bằng cách liên tục chọn ra đỉnh u chưa tối ưu có khoảng cách nhỏ nhất, cố định nhãn d[u], và cập nhật khoảng cách đến các đỉnh kề của u.
 * - Các bước thực hiện chi tiết:
 *   1. Khởi tạo:
 *      + Gán d[S] = 0 (khoảng cách đến chính nó bằng 0).
 *      + Gán d[v] = INF (vô cùng) với mọi đỉnh v khác nguồn S.
 *      + Sử dụng một hàng đợi ưu tiên Q (priority_queue) chứa các cặp {khoảng cách, đỉnh} để tối ưu hóa việc tìm đỉnh có nhãn nhỏ nhất. Đưa {0, S} vào Q.
 *   2. Bước lặp (Chọn đỉnh tối ưu và cập nhật):
 *      + Lấy ra từ hàng đợi đỉnh u có d[u] nhỏ nhất chưa tối ưu.
 *      + Nếu khoảng cách tạm thời lấy từ hàng đợi lớn hơn khoảng cách hiện tại d[u] (kc > d[u]), ta bỏ qua.
 *      + Ngược lại, thực hiện cập nhật nhãn (Relaxation) cho các đỉnh v kề với u:
 *        Nếu d[v] > d[u] + w(u, v) (với w(u, v) là trọng số cạnh u -> v):
 *        * Cập nhật d[v] = d[u] + w(u, v).
 *        * Đưa cặp mới {d[v], v} vào hàng đợi Q để tiếp tục xét ở bước tiếp theo.
 *   3. Điều kiện kết thúc:
 *      + Thuật toán lặp liên tục cho đến khi hàng đợi Q rỗng (tất cả các đỉnh liên thông với nguồn S đã được tối ưu hóa).
 */
