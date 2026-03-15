#include <stdio.h>
#include <string.h>
struct SinhVien {
    char ten[50];
    int tuoi;
    float diem;
};
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // đọc bỏ ký tự '\n' còn lại của scanf

    struct SinhVien sv[n];

    // ----------- NHAP -----------
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap sinh vien thu %d ---\n", i + 1);

        printf("Ten: ");
        fgets(sv[i].ten, sizeof(sv[i].ten), stdin);

        // Xóa ký tự '\n' nếu có
        size_t len = strlen(sv[i].ten);
        if (sv[i].ten[len-1] == '\n') sv[i].ten[len-1] = '\0';

        printf("Tuoi: ");
        scanf("%d", &sv[i].tuoi);

        printf("Diem: ");
        scanf("%f", &sv[i].diem);

        getchar(); // bỏ '\n'
    }

    // ----------- XUAT -----------
    printf("\n===== DANH SACH SINH VIEN =====\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        printf("Ten  : %s\n", sv[i].ten);
        printf("Tuoi : %d\n", sv[i].tuoi);
        printf("Diem : %.2f\n", sv[i].diem);
    }

    return 0;
}
