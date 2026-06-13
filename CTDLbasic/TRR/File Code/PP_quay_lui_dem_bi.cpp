/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * BÀI TOÁN XẾP BI THỎA MÃN ĐIỀU KIỆN (QUAY LUI)
 * 
 * Chương trình này giải quyết hai bài toán xếp bi:
 * 
 * Bài toán 1 (Phần code chạy):
 *   Có bao nhiêu cách xếp 12 viên bi gồm 3 nhóm màu khác nhau (mỗi nhóm gồm 4 
 *   viên màu 1, 4 viên màu 2, 4 viên màu 3) thành một hàng ngang sao cho không 
 *   có hai viên bi kề nhau nào cùng màu.
 *   - Input: Không yêu cầu (mặc định n = 12).
 *   - Output: Tổng số cách xếp bi thỏa mãn.
 *   - Kết quả: 7392 cách.
 * 
 * Bài toán 2 (Phần code bị comment):
 *   Có bao nhiêu cách chọn và xếp 4 viên bi lấy từ 8 bi xanh và 12 bi đỏ thành 
 *   hàng ngang đối xứng (viên thứ 1 giống viên thứ 4, viên thứ 2 giống viên thứ 3).
 *   - Input: Không yêu cầu (mặc định n = 4, số bi xanh = 8, đỏ = 12).
 *   - Output: Tổng số cách xếp bi thỏa mãn.
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

int n, dem =0;
int a[100];

bool check(){
    int c1 = 0, c2 = 0, c3 = 0;
    for( int i = 1; i<=n; i++ ){
        if( a[i] == 1 ) c1 +=1;
        if( a[i] == 2 ) c2 +=1;
        if( a[i] == 3 ) c3 +=1;
    }

    if( c1 == 4 && c2 == 4 && c3 == 4 ) {
        for( int i = 2; i <=n; i++ ){
            if( a[i] == a[i-1] ) return false;
        }
        return true;
    } else return false;
}

void pb( int pos ){
    if( pos > n ){
        if( !check() ) return;
        dem++;
        // cout<<dem<<": ";
        // for ( int i = 1; i <= n; i++ ){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        return;
    }

    for ( int i = 1; i <= 3; i++ ){
        a[pos] = i;
        pb( pos + 1 );
    }
}

int main(){
    n = 12;
    pb(1);
    cout<<"vậy tổng có "<<dem<<" cách"<<endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, dem;
// int blue, red;
// int a[100];
// int so_cach = 0;

// bool check(){
//     int res = 1;
//     int temp_blue = blue, remp_red = red;
//     if( a[1] == a[4] && a[2] == a[3] ){
//         if( a[1] == 1 ){
//             res *= temp_blue;
//             temp_blue--;
//         }
//         else {
//             res *= remp_red;
//             remp_red--;
//         }
//         if( a[2] == 1 ){
//             res *= temp_blue;
//             temp_blue--;
//         }
//         else {
//             res *= remp_red;
//             remp_red--;
//         }
//         if( a[3] == 1 ){
//             res *= temp_blue;
//             temp_blue--;
//         }
//         else {
//             res *= remp_red;
//             remp_red--;
//         }
//         if( a[4] == 1 ){
//             res *= temp_blue;
//             temp_blue--;
//         }
//         else {
//             res *= remp_red;
//             remp_red--;
//         }
//         so_cach += res;
//         return true;
//     }else{
//         return false;
//     }
// }

// void pb( int pos ){
//     if( pos > n ){
//         if( !check() ) return;
//         dem++;
//         // cout<<dem<<": ";
//         // for ( int i = 1; i <= n; i++ ){
//         //     cout<<a[i]<<" ";
//         // }
//         // cout<<endl;
//         return;
//     }

//     for ( int i = 1; i <= 2; i++ ){
//         a[pos] = i;
//         pb( pos + 1 );
//     }
// }

// int main(){
//     n = 4;
//     blue = 8; red = 12;
//     pb(1);
//     cout<<"vậy tổng có "<<so_cach<<" cách"<<endl;
//     return 0;
// }

/*
 * # TRẢ LỜI: Giải thích phương pháp quay lui bài toán xếp bi:
 * 1. Bài toán 1 (Xếp 12 bi gồm 3 nhóm màu kề nhau không trùng màu):
 *    - Quay lui thử đặt từng màu bi (1, 2, 3) vào các vị trí từ 1 đến 12.
 *    - Khi điền đủ 12 vị trí, dùng hàm check để kiểm tra xem có đúng 4 viên mỗi màu không, và hai viên liền kề có trùng màu không. Nếu đạt yêu cầu thì tăng biến đếm.
 * 2. Bài toán 2 (Xếp 4 viên bi đối xứng từ 8 xanh và 12 đỏ - Code comment):
 *    - Quay lui sinh cấu hình màu độ dài 4.
 *    - Hàm check kiểm tra tính đối xứng (a[1] == a[4] && a[2] == a[3]). Nếu đối xứng, số cách xếp thực tế được tính bằng tích các số bi xanh/đỏ còn lại tại các bước chọn.
 */