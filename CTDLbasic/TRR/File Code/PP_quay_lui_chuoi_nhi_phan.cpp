/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * SINH CHUỖI NHỊ PHÂN ĐỘ DÀI N (QUAY LUI)
 * 
 * Mô tả bài toán:
 *   Sinh tất cả các chuỗi nhị phân (chỉ gồm các ký tự '0' và '1') độ dài N 
 *   sử dụng thuật toán quay lui (Backtracking).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Không yêu cầu nhập từ bàn phím (trong code gán cứng n = 5).
 *   - Output: 
 *     + Danh sách các chuỗi nhị phân độ dài 5 được đánh số thứ tự từ 1 đến 32.
 *     + Tổng số cách sinh chuỗi nhị phân.
 * 
 * Ví dụ kết quả chạy (n = 5):
 *   1: 00000
 *   2: 00001
 *   ...
 *   32: 11111
 *   Tổng có 32 cách
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n, stt = 0;
int a[100];

void pb( int pos ){
    if( pos > n ){
        stt++;
        cout<<stt<<": ";
        for( int i = n; i>=1; i-- ) cout<<a[i];
        cout<<endl;
        return;
    }

    for( int i=0; i<=1; i++ ){
        a[pos] = i;
        pb(pos+1);
    }
}

int main(){
    n = 5;
    for( int i=1; i<=n; i++ ) a[i] = 0;
    pb(1);
    cout<<"Tổng có "<<stt<<" cách";
}

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui sinh chuỗi nhị phân:
 * - Ý tưởng: Ta dùng đệ quy duyệt từng vị trí pos từ 1 đến n. Tại mỗi vị trí, thử gán lần lượt giá trị 0 rồi 1 (a[pos] = i).
 * - Cơ chế: 
 *   + Mỗi lần gán xong a[pos], gọi đệ quy tiếp cho vị trí sau: pb(pos + 1).
 *   + Khi pos vượt quá n (pos > n), ta đã hoàn thành 1 chuỗi nhị phân, in ra cấu hình và tăng biến đếm.
 *   + Bản chất quay lui thể hiện ở việc hàm tự kết thúc (return) để chạy tiếp các nhánh vòng lặp của các bước đệ quy trước đó.
 */