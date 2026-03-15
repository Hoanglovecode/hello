/*
Cho người dùng nhập từ bàn phím số dòng và số cột của 1 ma trận,
từ đó nhập các phần tử trong ma trận.Kết thúc chương trình in ra kết quả bao gồm:
-Định thức của ma trận trên(Kí hiệu Det(A),Sử dụng if-else nếu nó là ma trận vuông)
-Tính ma trận phụ hợp của ma trận trên(kí hiệu A*)
-Nếu A khả nghịch,không suy biến thì tính ma trận nghịch đảo của ma trận trên
(Sử dụng: A^(-1)= A* / Det(A) )
-Hạng của ma trận trên(Rank(A)=?)
-Ma trận chuyển vị của ma trận trên(A^(T))
-Ma trận cấp n của ma trận trên(A^(n))
*/
#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<double>>;
// In ma trận
void printMatrix(const Matrix &A) {
    for (auto &row : A) {
        for (auto &x : row) cout << setw(10) << x << " ";
        cout << "\n";
    }
}
// Ma trận chuyển vị
Matrix transpose(const Matrix &A) {
    int m = A.size(), n = A[0].size();
    Matrix T(n, vector<double>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}
// Tính định thức (đệ quy Laplace)
double determinant(Matrix A) {
    int n = A.size();
    if (n == 1) return A[0][0];
    if (n == 2) return A[0][0]*A[1][1] - A[0][1]*A[1][0];
    double det = 0;
    for (int col = 0; col < n; col++) {
        Matrix minor(n-1, vector<double>(n-1));
        for (int i = 1; i < n; i++) {
            int idx = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                minor[i-1][idx++] = A[i][j];
            }
        }
        det += ((col%2==0?1:-1) * A[0][col] * determinant(minor));
    }
    return det;
}
// Ma trận con (xóa dòng row và cột col)
Matrix getMinor(const Matrix &A, int row, int col) {
    int n = A.size();
    Matrix minor(n-1, vector<double>(n-1));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) continue;
            minor[r][c++] = A[i][j];
        }
        r++;
    }
    return minor;
}
// Ma trận phụ hợp (Adjoint / Adjugate)
Matrix adjoint(const Matrix &A) {
    int n = A.size();
    Matrix adj(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matrix minor = getMinor(A, i, j);
            double val = determinant(minor);
            adj[j][i] = ((i+j)%2==0 ? val : -val); // chú ý chuyển vị
        }
    }
    return adj;
}
// Ma trận nghịch đảo
Matrix inverse(const Matrix &A) {
    int n = A.size();
    double det = determinant(A);
    Matrix adj = adjoint(A);
    Matrix inv(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det;
    return inv;
}
// Nhân 2 ma trận
Matrix multiply(const Matrix &A, const Matrix &B) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    Matrix C(m, vector<double>(p, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
// Lũy thừa ma trận A^n
Matrix power(Matrix A, int n) {
    int sz = A.size();
    Matrix result(sz, vector<double>(sz, 0));
    for (int i = 0; i < sz; i++) result[i][i] = 1; // ma trận đơn vị
    while (n > 0) {
        if (n % 2 == 1) result = multiply(result, A);
        A = multiply(A, A);
        n /= 2;
    }
    return result;
}
// Hạng ma trận (dùng khử Gauss)
int rankMatrix(Matrix A) {
    int m = A.size(), n = A[0].size();
    int rank = 0;
    for (int col = 0, row = 0; col < n && row < m; col++) {
        int pivot = row;
        for (int i = row+1; i < m; i++)
            if (fabs(A[i][col]) > fabs(A[pivot][col]))
                pivot = i;
        if (fabs(A[pivot][col]) < 1e-9) continue;
        swap(A[row], A[pivot]);
        double div = A[row][col];
        for (int j = col; j < n; j++) A[row][j] /= div;
        for (int i = 0; i < m; i++) {
            if (i == row) continue;
            double factor = A[i][col];
            for (int j = col; j < n; j++) A[i][j] -= factor * A[row][j];
        }
        row++; rank++;
    }
    return rank;
}
int main() {
    int m, n;
    cout << "Nhap so dong: "; cin >> m;
    cout << "Nhap so cot: "; cin >> n;

    Matrix A(m, vector<double>(n));
    cout << "Nhap cac phan tu ma tran:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "\nMa tran vua nhap:\n"; printMatrix(A);
    if (m == n) {
        cout << "\nDet(A) = " << determinant(A) << "\n";

        cout << "\nMa tran phu hop (A*):\n";
        printMatrix(adjoint(A));

        double detA = determinant(A);
        if (fabs(detA) > 1e-9) {
            cout << "\nMa tran nghich dao (A^(-1)):\n";
            printMatrix(inverse(A));
        } else {
            cout << "\nMa tran suy bien, khong co nghich dao!\n";
        }
        int p;
        cout << "\nNhap so mu p de tinh A^p: "; cin >> p;
        cout << "A^" << p << " = \n";
        printMatrix(power(A, p));
    } else {
        cout << "\nKhong the tinh det, phu hop, nghich dao vi A khong vuong!\n";
    }
    cout << "\nHang cua ma tran: " << rankMatrix(A) << "\n";
    cout << "\nMa tran chuyen vi (A^T):\n"; printMatrix(transpose(A));
    return 0;
}
