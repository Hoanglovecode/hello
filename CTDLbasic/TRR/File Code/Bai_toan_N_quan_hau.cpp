/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * BÀI TOÁN N QUÂN HẬU (N-QUEENS PROBLEM)
 * 
 * Mô tả bài toán:
 *   Tìm tất cả các cách xếp N quân hậu trên một bàn cờ kích thước N x N 
 *   sao cho không có hai quân hậu nào tấn công nhau (không nằm cùng hàng, 
 *   cùng cột, hoặc cùng đường chéo).
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Nhập số nguyên dương N (ví dụ: N = 4 hoặc N = 8).
 *   - Output: 
 *     + Dòng đầu ghi số thứ tự cách xếp.
 *     + Dòng tiếp theo in ra N số đại diện cho vị trí cột của quân hậu 
 *       từ hàng 1 đến hàng N.
 *     + Dòng cuối cùng in tổng số cách xếp.
 * 
 * Ví dụ (N = 4):
 *   - Input: 4
 *   - Output:
 *     1
 *     2 4 1 3 
 *     2
 *     3 1 4 2 
 *     Co 2 cach xep.
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

long long n,dem=0;
int a[31][31]={0};

//in ra ma tran nxn voi 1 la quan hau
void init(){
	cout<<dem<<endl;
	for (int i=1; i<=n; i++){
		for (int k=1; k<=n; k++){
			//cout<<a[i][k]<<" ";
			if( a[i][k] == 1){cout<<k<<" "; break;}
		}
	}
	cout<<endl;
}


bool check(int y, int x){  //Check tai toa do y x
	for (int i=1; i<=n; i++){   //Check hang ngang
		if (i==x)continue;
		if(a[y][i]==1) return false;
	}
	for (int i=1; i<=n; i++){   //Check hang doc
		if (i==y)continue;
		if(a[i][x]==1) return false;
	}

	if (y>=x){   //Check duong cheo chinh
		for (int i = -x+1; i<= n-y; i++){
			if (i==0) continue;
			if (a[y+i][x+i]==1) return false;
		}
	} else{
		for (int i = -y+1; i<= n-x; i++){
			if (i==0) continue;
			if (a[y+i][x+i]==1) return false;
		}
	}
	
	if ( y+x <= n+1){   //Check duong cheo phu
		for (int i = -x+1; i<= y-1; i++){
			if (i==0) continue;
			if (a[y-i][x+i]==1) return false;
		}
	} else{
		for (int i = y-n ; i<= n-x; i++){
			if (i==0) continue;
			if (a[y-i][x+i]==1) return false;
		}
	}
	
	return true;
}


void quanhau(int hang, int n){
	if (hang>n){
		dem +=1;
		init();
		return;
	}
	for (int k=1; k<=n; k++){
		a[hang][k]=1;
		if(check(hang,k)){
			quanhau(hang+1, n);
		}
		a[hang][k]=0;
	}
}

int main(){
	cout<<"Nhap n: ";	cin>>n;
	if(n==1){cout<<"1";return 0;}
	else if (n==2){cout<<"0"; return 0;}
	quanhau(1,n);
	cout<<"Co "<<dem<<" cach xep."<<endl;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// long long n, dem = 0;
// int a[51][51] = {0};

// bool check(int y, int x) {
//     for (int i = 1; i <= n; i++) {
//         if (i != x && a[y][i] == 1) return false; // Check hàng ngang
//         if (i != y && a[i][x] == 1) return false; // Check hàng dọc
//     }
    
// 	//Check duong cheo chinh
//     if (y >= x) {
//         for (int i = -x + 1; i <= n - y; i++) {
//             if (i != 0 && a[y + i][x + i] == 1) return false;
//         }
//     } else {
//         for (int i = -y + 1; i <= n - x; i++) {
//             if (i != 0 && a[y + i][x + i] == 1) return false;
//         }
//     }
    
// 	//Check duong cheo phu
//     if (y + x <= n + 1) {
//         for (int i = -x + 1; i <= y - 1; i++) {
//             if (i != 0 && a[y - i][x + i] == 1) return false; 
//         }
//     } else {
//         for (int i = y - n; i <= n - x; i++) {
//             if (i != 0 && a[y - i][x + i] == 1) return false;
//         }
//     }
    
//     return true;
// }

// void init(){
// 	printf("\n%lld: ", dem);
// 	for (int i=1; i<=n; i++){
// 		for (int k=1; k<=n; k++){
// 			if (a[i][k] == 1){
// 				printf("%d ", k);
// 				break;
// 			}
// 		}
// 	}
// }

// void quanhau(int hang, int n) {
//     if (hang > n) {
//         dem++;
// 		init();
//         return;
//     }
//     for (int k = 1; k <= n; k++) {
//         a[hang][k] = 1;
//         if (check(hang, k)) {
//             quanhau(hang + 1, n);
//         }
//         a[hang][k] = 0;
//     }
// }

// int main() {
//     printf("Nhap n: ");
//     scanf("%lld", &n);
    
//     if (n == 1) {
//         printf("1\n");
//         return 0;
//     } else if (n == 2) {
//         printf("0\n");
//         return 0;
//     }
// 	quanhau(1, n);
//     printf("\nCo %lld cach xep.\n",dem);
    
// }

/*
 * # TRẢ LỜI: Giải thích thuật toán quay lui xếp N quân hậu:
 * - Ý tưởng: Ta xếp quân hậu theo từng hàng (từ hàng 1 đến n). Ở mỗi hàng, thử đặt quân hậu vào các cột từ 1 đến n.
 * - Đệ quy & Quay lui:
 *   + Thử đặt ở cột k: gán a[hang][k] = 1 và kiểm tra an toàn bằng hàm `check(hang, k)`.
 *   + Nếu an toàn, gọi đệ quy quanhau(hang + 1, n). Xong mỗi lần thử, khôi phục lại trạng thái a[hang][k] = 0 (quay lui).
 *   + Khi xếp hết n hàng (hang > n), ghi nhận và in cách xếp ra.
 * - Hàm check: Kiểm tra cột dọc có bị trùng không; kiểm tra 2 đường chéo: đường chéo chính có hiệu hàng-cột không đổi (y - x = const), đường chéo phụ có tổng hàng-cột không đổi (y + x = const).
 */

