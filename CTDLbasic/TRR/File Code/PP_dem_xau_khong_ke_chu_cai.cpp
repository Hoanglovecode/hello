/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * ĐẾM VÀ LIỆT KÊ XÂU ĐỘ DÀI N TRÊN TẬP X = {1, 2, 3, 4, A, B, C, D, E, F, G, H}
 * ĐIỀU KIỆN: KHÔNG CÓ HAI CHỮ CÁI KỀ NHAU (NO TWO ADJACENT LETTERS)
 * 
 * Mô tả bài toán:
 *   Sinh và đếm các xâu ký tự S có độ dài n sao cho không có 2 chữ cái nào đứng cạnh nhau.
 *   - Tập chữ số: D = {1, 2, 3, 4} (4 phần tử)
 *   - Tập chữ cái: L = {A, B, C, D, E, F, G, H} (8 phần tử)
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập độ dài xâu n (nguyên dương).
 *   - Output: 
 *     + Danh sách xâu hợp lệ (nếu n <= 4).
 *     + Kết quả đếm bằng Quy hoạch động và Quay lui.
 * ----------------------------------------------------
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string X = "1234ABCDEFGH";
int n;
long long backtrack_cnt = 0;
string current_str = "";

// Kiểm tra xem ký tự có phải là chữ cái không
bool is_letter(char c) {
    return (c >= 'A' && c <= 'H');
}

// Kiểm tra tính hợp lệ khi đặt ký tự next_char vào vị trí pos
bool is_valid(char next_char, int pos) {
    if (pos == 0) return true;
    char prev_char = current_str[pos - 1];
    
    // Không cho phép 2 chữ cái kề nhau
    if (is_letter(prev_char) && is_letter(next_char)) {
        return false;
    }
    return true;
}

// Thuật toán quay lui để liệt kê và đếm
void backtrack(int pos) {
    if (pos == n) {
        backtrack_cnt++;
        if (n <= 4) {
            cout << backtrack_cnt << ": " << current_str << "\n";
        }
        return;
    }

    for (char c : X) {
        if (is_valid(c, pos)) {
            current_str.push_back(c);
            backtrack(pos + 1);
            current_str.pop_back(); // Quay lui
        }
    }
}

// Cách 1: Quy hoạch động dùng mảng O(n)
long long count_no_adjacent_letters_dp(int length) {
    if (length == 0) return 0;
    
    // dp[i][0]: xâu hợp lệ độ dài i kết thúc bằng chữ số (D)
    // dp[i][1]: xâu hợp lệ độ dài i kết thúc bằng chữ cái (L)
    vector<vector<long long>> dp(length + 1, vector<long long>(2, 0));

    dp[1][0] = 4;
    dp[1][1] = 8;

    for (int i = 2; i <= length; i++) {
        dp[i][0] = 4 * (dp[i - 1][0] + dp[i - 1][1]);
        dp[i][1] = 8 * dp[i - 1][0];
    }

    return dp[length][0] + dp[length][1];
}

// Cách 2: Quy hoạch động tối ưu bộ nhớ O(1)
long long count_no_adjacent_letters_optimized(int length) {
    if (length <= 0) return 0;
    
    long long end_digit = 4;
    long long end_letter = 8;

    for (int i = 2; i <= length; i++) {
        long long next_digit = 4 * (end_digit + end_letter);
        long long next_letter = 8 * end_digit;

        end_digit = next_digit;
        end_letter = next_letter;
    }

    return end_digit + end_letter;
}

int main() {
    cout << "=== KHONG CO HAI CHU CAI KE NHAU ===\n";
    cout << "Nhap do dai n: ";
    if (!(cin >> n) || n < 1) {
        cout << "Do dai khong hop le.\n";
        return 0;
    }

    // 1. Tính bằng Quy hoạch động
    cout << "\n[Quy hoach dong] Tong so xau thoa man: " << count_no_adjacent_letters_optimized(n) << "\n\n";

    // 2. Chạy quay lui để kiểm chứng (nếu n <= 4)
    if (n <= 4) {
        cout << "Danh sach cac xau thoa man:\n";
        backtrack(0);
        cout << "\n[Quay lui] Tong so xau dem duoc: " << backtrack_cnt << "\n";
    }

    return 0;
}

/*
 * # TRẢ LỜI: Giải thích phương pháp đếm và liệt kê xâu ký tự không có hai chữ cái kề nhau:
 * 1. Phương pháp Quay lui (Backtracking):
 *    - Thử điền từng ký tự từ tập X vào vị trí pos từ 0 đến n-1.
 *    - Tại vị trí pos, kiểm tra nếu ký tự trước đó (prev_char) và ký tự hiện tại (next_char) đều là chữ cái (is_letter) thì không hợp lệ, bỏ qua.
 *    - Khi pos == n, ta thu được xâu hợp lệ, tăng biến đếm và in ra nếu n <= 4.
 * 
 * 2. Phương pháp Quy hoạch động (Dynamic Programming):
 *    - dp[i][0] là số xâu độ dài i kết thúc bằng chữ số. Vì chữ số có thể đứng sau chữ cái hoặc chữ số, nên dp[i][0] = 4 * (dp[i-1][0] + dp[i-1][1]).
 *    - dp[i][1] là số xâu độ dài i kết thúc bằng chữ cái. Vì không cho phép hai chữ cái đứng cạnh nhau, chữ cái bắt buộc phải đứng sau chữ số, nên dp[i][1] = 8 * dp[i-1][0].
 *    - Kết quả là dp[n][0] + dp[n][1].
 *    - Dạng tối ưu O(1) chỉ cần dùng hai biến end_digit và end_letter để lưu kết quả của bước i-1, tiết kiệm không gian bộ nhớ.
 */

