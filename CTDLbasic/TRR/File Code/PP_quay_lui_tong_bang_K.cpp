/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * BÀI TOÁN TỔ HỢP / HOÁN VỊ CÓ TỔNG BẰNG K (COMBINATION SUM)
 * 
 * Mô tả bài toán:
 *   Cho mảng A[] gồm N số nguyên dương phân biệt và số S. Tìm các tập hợp số trong mảng A[]
 *   sao cho tổng của chúng bằng S theo 3 yêu cầu:
 *     1. Tổ hợp số (được phép lấy lại số cũ nhiều lần, các bộ nghiệm không quan tâm thứ tự).
 *     2. Hoán vị số (được phép lấy lại số cũ nhiều lần, các bộ nghiệm phân biệt thứ tự sắp xếp).
 *     3. Tổ hợp số duy nhất (mỗi phần tử chỉ được sử dụng tối đa 1 lần, các bộ không quan tâm thứ tự).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input:
 *     + Nhập số lượng phần tử N và tổng S.
 *     + Nhập N số nguyên dương phân biệt của mảng A.
 *   - Output:
 *     + Liệt kê các tổ hợp và hoán vị thỏa mãn điều kiện theo từng phương án.
 * 
 * Ví dụ:
 *   - Input:
 *     3 10
 *     4 2 3
 *   - Output:
 *     1. Liệt kê các tổ hợp số có tổng bằng 10 (được dùng lại số):
 *     { 2 2 2 2 2 }
 *     { 2 2 2 4 }
 *     { 2 2 3 3 }
 *     { 2 4 4 }
 *     { 3 3 4 }
 * 
 *     2. Liệt kê các hoán vị số có tổng bằng 10 (được dùng lại số):
 *     [ 2 2 2 2 2 ]
 *     [ 2 2 2 4 ]
 *     ...
 *     [ 4 4 2 ]
 * 
 *     3. Liệt kê các tổ hợp số có tổng bằng 10 (mỗi số dùng tối đa 1 lần):
 *     (Không có tổ hợp nào của {2, 3, 4} có tổng bằng 10 nếu mỗi số chỉ được dùng 1 lần)
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n, S;
vector<int> a;
vector<int> x;
vector<int> v;

// 1. Liệt kê bộ nghiệm (tổ hợp các số có thể trùng lặp)
void try_combinations(int i, int start, int sum) {
    for (int j = start; j < n; j++) {
        x[i] = a[j];
        sum += x[i];
        if (sum == S) {
            cout << "{ ";
            for (int idx = 1; idx <= i; idx++) {
                cout << x[idx] << " ";
            }
            cout << "}\n";
        } else if (sum < S) {
            try_combinations(i + 1, j, sum);
        }
        sum -= a[j];
    }
}

// 2. Hoán vị các bộ nghiệm (hoán vị các số có thể trùng lặp)
void try_permutations(int i, int sum) {
    for (int j = 0; j < n; j++) {
        x[i] = a[j];
        sum += x[i];
        if (sum == S) {
            cout << "[ ";
            for (int idx = 1; idx <= i; idx++) {
                cout << x[idx] << " ";
            }
            cout << "]\n";
        } else if (sum < S) {
            try_permutations(i + 1, sum);
        }
        sum -= a[j];
    }
}

// 3. Liệt kê bộ nghiệm không trùng lặp (mỗi phần tử dùng tối đa 1 lần)
void try_combinations_unique(int start, int sum) {
    for (int j = start; j < n; j++) {
        if (sum + a[j] > S) break;
        v.push_back(a[j]);
        sum += a[j];
        if (sum == S) {
            cout << "{ ";
            for (int x_val : v) {
                cout << x_val << " ";
            }
            cout << "}\n";
        } else if (sum < S) {
            try_combinations_unique(j + 1, sum);
        }
        v.pop_back();
        sum -= a[j];
    }
}

int main() {
    cout << "Nhập số lượng phần tử N và tổng S: ";
    if (!(cin >> n >> S)) return 0;
    a.resize(n);
    x.resize(1005, 0);
    cout << "Nhập các phần tử của mảng A: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // Sắp xếp tăng dần

    cout << "\n1. Liệt kê các tổ hợp số có tổng bằng " << S << " (được dùng lại số):\n";
    try_combinations(1, 0, 0);

    cout << "\n2. Liệt kê các hoán vị số có tổng bằng " << S << " (được dùng lại số):\n";
    try_permutations(1, 0);

    cout << "\n3. Liệt kê các tổ hợp số có tổng bằng " << S << " (mỗi số dùng tối đa 1 lần):\n";
    try_combinations_unique(0, 0);

    return 0;
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui tìm các số có tổng bằng S:
 * 1. Tổ hợp lặp (dùng lại số, không phân biệt thứ tự):
 *    - Duyệt j từ `start` để phần tử sau >= phần tử trước (tránh trùng thứ tự).
 *    - Gọi đệ quy tiếp với chỉ số bắt đầu là `j` để được phép lấy lại chính số đó. Quay lui bằng cách trừ `a[j]` khỏi tổng.
 * 2. Hoán vị lặp (dùng lại số, phân biệt thứ tự):
 *    - Tương tự tổ hợp lặp nhưng vòng lặp duyệt phần tử luôn chạy từ 0 đến n-1 ở mọi bước (không dùng biến `start`).
 * 3. Tổ hợp không lặp (mỗi số dùng tối đa 1 lần, không phân biệt thứ tự):
 *    - Đệ quy với chỉ số bắt đầu `j + 1` để không lấy trùng số cũ.
 *    - Tối ưu hóa nhánh cận: Mảng đã sắp xếp tăng dần, nên nếu tổng hiện tại cộng a[j] vượt S thì dừng vòng lặp ngay (`break`).
 */
