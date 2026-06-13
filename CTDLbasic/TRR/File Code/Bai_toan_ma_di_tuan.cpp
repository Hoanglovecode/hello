/*
 * ĐỀ BÀI / VÍ DỤ MINH HỌA
 * ----------------------------------------------------
 * BÀI TOÁN MÃ ĐI TUẦN (KNIGHT'S TOUR PROBLEM)
 * 
 * Mô tả bài toán:
 *   Tìm một hành trình di chuyển của quân mã trên bàn cờ kích thước 8 x 8
 *   bắt đầu từ ô (1,1) sao cho đi qua tất cả các ô của bàn cờ, mỗi ô
 *   đúng một lần.
 * 
 * Hướng dẫn nhập xuất:
 *   - Input: Không yêu cầu (chương trình tự khởi chạy với kích thước 8 x 8 
 *            và vị trí xuất phát mặc định là ô hàng 1, cột 1).
 *   - Output: In ra ma trận 8 x 8 thể hiện số thứ tự các bước đi của 
 *             quân mã trên bàn cờ (từ bước 1 đến bước 64).
 * 
 * Ví dụ kết quả một phần ma trận:
 *   1  16 13  ...
 *   12 29  2  ...
 *   15 14 17  ...
 *   ...
 * ----------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10][10]={0};

void cal(int count, int type, int y, int x ){
   if (count == 65){
      for (int i=1; i<=n; i++){
         for (int k=1; k<=m; k++){
            cout<<a[i][k]<<" ";
         }
         cout<<endl;
      }
      exit(0);
   }

   if (type==1){
      if(y+2<=n && x+1<=m){
         y+=2; x+=1; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==2){
      if(y+1<=n && x+2<=m){
         y+=1; x+=2; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==3){
      if(y-1>=1 && x+2<=m){
         y-=1; x+=2; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==4){
      if(y-2>=1 && x+1<=m){
         y-=2; x+=1; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==5){
      if(y-2>=1 && x-1>=1){
         y-=2; x-=1; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==6){
      if(y-1>=1 && x-2>=1){
         y-=1; x-=2; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==7){
      if(y+1<=n && x-2>=1){
         y+=1; x-=2; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }
   else if (type==8){
      if(y+2<=n && x-1>=1){
         y+=2; x-=1; 
         if (a[y][x]==0){a[y][x]= count;}
         else return;
      }
      else return;
   }

   
   /*
   for (int i=1; i<=n; i++){
        for (int k=1; k<=m; k++){
            cout<<a[i][k]<<" ";
        }
        cout<<endl;
   }
   */
   //cout<<"Type= "<<type<<". a["<<y<<"]["<<x<<"]= "<<a[y][x]<<endl<<endl;
   
   
   for(int i=1; i<=8; i++){
      cal(count+1, i, y, x);
   }
   a[y][x]=0; // di lui thi tra gia tri ve lai 0
   return;
}
int main(){
   int y=1,x=1;
   a[1][1]=1;
   n=8; m=8;
   cal(1, 0, y,x);
}

/*
 * # TRẢ LỜI: Giải thích thuật toán quay lui bài toán mã đi tuần:
 * - Ý tưởng: Tìm đường đi cho quân mã đi qua tất cả 64 ô bàn cờ (8x8), mỗi ô đúng 1 lần.
 * - Cơ chế đệ quy & quay lui:
 *   + Hàm đệ quy `cal(count, type, y, x)` thử nhảy từ ô (y,x) theo hướng `type`. Có tất cả 8 hướng nhảy của quân mã.
 *   + Nếu ô mới nằm trong bàn cờ và chưa đi (`a[new_y][new_x] == 0`), đánh dấu nước đi `a[new_y][new_x] = count`.
 *   + Sau đó gọi đệ quy thử tiếp 8 hướng từ ô mới này.
 *   + Quay lui: Nếu đi tiếp thất bại, khôi phục ô mới về trống (`a[new_y][new_x] = 0`) để nhánh khác đi qua.
 *   + Khi đi đủ 64 bước (count == 65), in ra toàn bộ lịch trình bàn cờ và exit(0) dừng chương trình.
 */
