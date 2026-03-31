//xây dựng hàm thuật toán quay lui
#include <stdio.h>
int d = 0;
void out(int s[], int n){
    printf("%d: ", ++d);
    for(int i = 1; i <= n; i++){
        printf("%d ", s[i]);
    }
    printf("\n");
}
void Try(int i, int s[], int b[], int n){
    for(int j = 1; j <= n; j++){
        if(b[j] == 1){
            s[i] = j;
            b[j] = 0;
            if(i == n){
                out(s, n);
            }
            else{
                Try(i + 1, s, b, n);
            }
            b[j] = 1;
        }
    }
}
int main(){
    int n;
    printf("input n = ");
    scanf("%d", &n);
    int b[n+1], s[n+1];

    for(int j = 1; j <= n; j++){
        b[j] = 1;
    }
    Try(1, s, b, n);
    return 0;
}
// void backtracking(int a[], int n, int k){
//     if(k == n){
//         //in ra kết quả
//         for(int i = 0; i < n; i++){
//             printf("%d ", a[i]);
//         }
//         printf("\n");
//     }else{
//         for(int i = 1; i <= n; i++){
//             a[k] = i;
//             backtracking(a, n, k + 1);
//         }
//     }
// }
// int main(){
//     int n;
//     printf("Nhap n: ");
//     scanf("%d", &n);
//     int a[100];
//     backtracking(a, n, 0);
//     return 0;
// }