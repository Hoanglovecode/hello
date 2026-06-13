/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * LIỆT KÊ TẤT CẢ TẬP CON CỦA TẬP HỢP N PHẦN TỬ (QUAY LUI)
 * 
 * Mô tả bài toán:
 *   Liệt kê tất cả các tập con của tập hợp X = {1, 2, ..., n}.
 *   Thuật toán sử dụng quay lui để tìm các tập con có số phần tử từ 1 đến n, 
 *   sau đó in ra thêm tập rỗng.
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương n.
 *   - Output: 
 *     + Danh sách các tập con (được đánh số thứ tự).
 *     + Dòng cuối cùng hiển thị tổng số tập con (kể cả tập rỗng), bằng 2^n.
 * 
 * Ví dụ (n = 3):
 *   - Input: 3
 *   - Output:
 *     1: 1 
 *     2: 2 
 *     3: 3 
 *     4: 1 2 
 *     5: 1 3 
 *     6: 2 3 
 *     7: 1 2 3 
 *     8: Tập rỗng
 *     Vậy tất cả có 8 tập con (kể cả tập rỗng)
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n, dem;
int a[100000];

void pb( int pos, int k){
    if( pos > k ){
        dem++;
        cout<<dem<<": ";
        for( int i=1; i<=k; i++ ){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for( int i = pos; i<=n; i++ ){
        a[pos] = i;
        if( pos > 1 && a[pos] <= a[pos-1] ) continue;
        pb( pos+1, k );
    }
}

int main(){
    cout<<"Nhập n: ";
    cin>>n;
    dem = 0;

    for( int i=1; i<=n; i++ ){
        pb( 1, i );
    }

    dem++;
    cout<<dem<<": Tập rỗng\n";
    cout<<endl<<"Vậy tất cả có "<<dem<<" tập con (kể cả tập rỗng)";
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui sinh tập con (tổ hợp):
 * - Ý tưởng: Liệt kê các tập con có k phần tử (k chạy từ 1 đến n) bằng cách chọn các số xếp tăng dần (a[1] < a[2] < ... < a[k]) để tránh trùng lặp.
 * - Cơ chế đệ quy:
 *   + Tại vị trí pos, thử gán a[pos] = i chạy từ pos đến n. Nếu a[pos] <= a[pos-1] thì bỏ qua (dùng continue) để đảm bảo tính tăng dần.
 *   + Gọi đệ quy pb(pos + 1, k) để tìm phần tử tiếp theo. Khi điền đủ k phần tử (pos > k), in kết quả ra và quay lui.
 *   + Trong hàm main, lặp k từ 1 đến n để in tất cả các tập con khác rỗng, cuối cùng in thêm tập rỗng.
 */