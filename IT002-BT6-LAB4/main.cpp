#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class CVector {
private:
    int iKichThuoc;
    vector<double> iDuLieu;

public:
    CVector(int n = 0) : iKichThuoc(n) {
        iDuLieu.assign(n, 0.0);
    }

    CVector operator+(const CVector& other) const {
        if (iKichThuoc != other.iKichThuoc) {
            cout << "Loi: Hai vector khong cung so chieu!" << endl;
            return CVector(0);
        }
        CVector kq(iKichThuoc);
        for (int i = 0; i < iKichThuoc; ++i) {
            kq.iDuLieu[i] = iDuLieu[i] + other.iDuLieu[i];
        }
        return kq;
    }

    CVector operator-(const CVector& other) const {
        if (iKichThuoc != other.iKichThuoc) {
            cout << "Loi: Hai vector khong cung so chieu!" << endl;
            return CVector(0);
        }
        CVector kq(iKichThuoc);
        for (int i = 0; i < iKichThuoc; ++i) {
            kq.iDuLieu[i] = iDuLieu[i] - other.iDuLieu[i];
        }
        return kq;
    }

    CVector operator*(double k) const {
        CVector kq(iKichThuoc);
        for (int i = 0; i < iKichThuoc; ++i) {
            kq.iDuLieu[i] = iDuLieu[i] * k;
        }
        return kq;
    }

    double operator*(const CVector& other) const {
        if (iKichThuoc != other.iKichThuoc) {
            cout << "Loi: Hai vector khong cung so chieu!" << endl;
            return 0;
        }
        double dot = 0;
        for (int i = 0; i < iKichThuoc; ++i) {
            dot += iDuLieu[i] * other.iDuLieu[i];
        }
        return dot;
    }

    double tinhDoDai() const {
        double sum = 0;
        for (double val : iDuLieu) {
            sum += val * val;
        }
        return sqrt(sum);
    }

    friend ostream& operator<<(ostream& os, const CVector& v) {
        os << "(";
        for (int i = 0; i < v.iKichThuoc; ++i) {
            os << v.iDuLieu[i] << (i == v.iKichThuoc - 1 ? "" : ", ");
        }
        os << ")";
        return os;
    }

    friend istream& operator>>(istream& is, CVector& v) {
        cout << "Nhap so chieu cua vector: ";
        is >> v.iKichThuoc;
        v.iDuLieu.assign(v.iKichThuoc, 0.0);
        for (int i = 0; i < v.iKichThuoc; ++i) {
            cout << "  Thanh phan thu " << i + 1 << ": ";
            is >> v.iDuLieu[i];
        }
        return is;
    }
};

int main() {
    CVector v1, v2;
    cout << "Vector v1:\n"; cin >> v1;
    cout << "Vector v2:\n"; cin >> v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    if (true) {
        CVector vTong = v1 + v2;
        cout << "v1 + v2 = " << vTong << endl;

        CVector vHieu = v1 - v2;
        cout << "v1 - v2 = " << vHieu << endl;
    }

    double k = 2.5;
    cout << "v1 * " << k << " = " << (v1 * k) << endl;

    cout << "Tich vo huong (v1 * v2) = " << (v1 * v2) << endl;

    cout << "Do dai v1 = " << v1.tinhDoDai() << endl;

    return 0;
}
