#include <bits/stdc++.h>
using namespace std;

struct Node {
    string maHang, tenHang;
    int soLuong;
    double donGia;
    Node* next;
    Node* prev;
};
typedef Node* node;

// ================== 1. Khởi tạo ==================
node khoiTao() {
    node header = new Node;
    header->next = header;
    header->prev = header;
    return header;
}

// ================== Tạo node ==================
node taoNode(string maHang, string tenHang, int soLuong, double donGia) {
    node newNode = new Node;
    newNode->maHang = maHang;
    newNode->tenHang = tenHang;
    newNode->soLuong = soLuong;
    newNode->donGia = donGia;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// ================== 2. Thêm cuối ==================
void pushback(node header, string maHang, string tenHang, int soLuong, double donGia) {
    node nodeB = taoNode(maHang, tenHang, soLuong, donGia);

    node tmp = header;

    // tìm node cuối
    while (tmp->next != header) {
        tmp = tmp->next;
    }

    tmp->next = nodeB;
    nodeB->prev = tmp;

    nodeB->next = header;
    header->prev = nodeB;
}

// ================== Hàm nhập ==================
void nhapDanhSach(node header) {
    int n;
    cout << "Nhap so mat hang: ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string maHang, tenHang;
        int soLuong;
        double donGia;

        cout << "\nMat hang " << i << ":\n";
        cout << "Ma hang: ";
        getline(cin, maHang);

        cout << "Ten hang: ";
        getline(cin, tenHang);

        cout << "So luong: ";
        cin >> soLuong;

        cout << "Don gia: ";
        cin >> donGia;
        cin.ignore();

        pushback(header, maHang, tenHang, soLuong, donGia);
    }
}

// ================== 3. Xóa theo mã ==================
void xoaTheoMa(node header, string ma) {
    node cur = header->next;

    while (cur != header) {
        if (cur->maHang == ma) {
            node tmp = cur;

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            cur = cur->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
}

// ================== 4. In từ đầu ==================
void inTuDau(node header) {
    node cur = header->next;

    if (cur == header) {
        cout << "Danh sach rong!\n";
        return;
    }

    while (cur != header) {
        cout << cur->maHang << " | "
             << cur->tenHang << " | "
             << cur->soLuong << " | "
             << cur->donGia << endl;
        cur = cur->next;
    }
}

// ================== 5. In từ cuối ==================
void inTuCuoi(node header) {
    node cur = header->prev;

    if (cur == header) {
        cout << "Danh sach rong!\n";
        return;
    }

    while (cur != header) {
        cout << cur->maHang << " | "
             << cur->tenHang << " | "
             << cur->soLuong << " | "
             << cur->donGia << endl;
        cur = cur->prev;
    }
}

// ================== 6. Tổng tiền ==================
double tinhTongTien(node header) {
    node cur = header->next;
    double tong = 0;

    while (cur != header) {
        tong += cur->soLuong * cur->donGia;
        cur = cur->next;
    }

    return tong;
}

// ================== MAIN ==================
int main() {
    node header = khoiTao();

    nhapDanhSach(header);

    cout << "\nDanh sach tu dau:\n";
    inTuDau(header);

    cout << "\nDanh sach tu cuoi:\n";
    inTuCuoi(header);

    cout << "\nTong tien: " << tinhTongTien(header) << endl;

    string ma;
    cout << "\nNhap ma can xoa: ";
    getline(cin, ma);

    xoaTheoMa(header, ma);

    cout << "\nSau khi xoa:\n";
    inTuDau(header);

    return 0;
}