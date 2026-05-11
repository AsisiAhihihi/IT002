#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class CVector {
public:
    int iKichThuoc;
    vector<double> iDuLieu;

    CVector(int n = 0) : iKichThuoc(n) {
        iDuLieu.assign(n, 0.0);
    }

    friend ostream& operator<<(ostream& os, const CVector& v) {
        os << "(";
        for (int i = 0; i < v.iKichThuoc; ++i)
            os << v.iDuLieu[i] << (i == v.iKichThuoc - 1 ? "" : ", ");
        os << ")";
        return os;
    }
};

class CMatrix {
private:
    int iSoDong, iSoCot;
    vector<vector<double>> iDuLieu;

public:
    CMatrix(int m = 0, int n = 0) : iSoDong(m), iSoCot(n) {
        iDuLieu.assign(m, vector<double>(n, 0.0));
    }

    CVector operator*(const CVector& v) const {
        if (iSoCot != v.iKichThuoc) {
            cout << "Loi: Kich thuoc khong khop (Matrix Col != Vector Size)!" << endl;
            return CVector(0);
        }
        CVector kq(iSoDong);
        for (int i = 0; i < iSoDong; ++i) {
            for (int j = 0; j < iSoCot; ++j) {
                kq.iDuLieu[i] += iDuLieu[i][j] * v.iDuLieu[j];
            }
        }
        return kq;
    }

    CMatrix operator*(const CMatrix& other) const {
        if (iSoCot != other.iSoDong) {
            cout << "Loi: Kich thuoc khong khop de nhan hai ma tran!" << endl;
            return CMatrix(0, 0);
        }
        CMatrix kq(iSoDong, other.iSoCot);
        for (int i = 0; i < iSoDong; ++i) {
            for (int j = 0; j < other.iSoCot; ++j) {
                for (int k = 0; k < iSoCot; ++k) {
                    kq.iDuLieu[i][j] += iDuLieu[i][k] * other.iDuLieu[k][j];
                }
            }
        }
        return kq;
    }

    friend ostream& operator<<(ostream& os, const CMatrix& m) {
        for (int i = 0; i < m.iSoDong; ++i) {
            for (int j = 0; j < m.iSoCot; ++j) {
                os << setw(8) << m.iDuLieu[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, CMatrix& m) {
        cout << "Nhap so dong: "; is >> m.iSoDong;
        cout << "Nhap so cot: "; is >> m.iSoCot;
        m.iDuLieu.assign(m.iSoDong, vector<double>(m.iSoCot, 0.0));
        for (int i = 0; i < m.iSoDong; ++i) {
            for (int j = 0; j < m.iSoCot; ++j) {
                cout << "  Phan tu [" << i << "][" << j << "]: ";
                is >> m.iDuLieu[i][j];
            }
        }
        return is;
    }
};

int main() {
    CMatrix A, B;
    CVector V;

    cin >> A;

    cout << "Nhap so chieu vector (nen la " << 2 << "): ";

    int n; cin >> n;
    V = CVector(n);
    for(int i=0; i<n; ++i) {
        cout << "  V[" << i << "]: "; cin >> V.iDuLieu[i];
    }

    CVector resV = A * V;
    cout << resV << endl;

    cout << "\n--- NHAP MA TRAN B DE NHAN (A * B) ---" << endl;
    cin >> B;

    CMatrix resM = A * B;
    cout << resM << endl;

    return 0;
}
