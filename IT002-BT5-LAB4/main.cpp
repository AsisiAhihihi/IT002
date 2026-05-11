#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class DaThuc {
private:
    vector<double> iHeSo;
    int iBac;

public:

    void chuanHoa() {
        while (iHeSo.size() > 1 && iHeSo.back() == 0) {
            iHeSo.pop_back();
        }
        iBac = iHeSo.size() - 1;
    }

    DaThuc(int b = 0) {
        iBac = b;
        iHeSo.resize(iBac + 1, 0);
    }

    DaThuc operator+(const DaThuc& other) const {
        int maxBac = max(iBac, other.iBac);
        DaThuc kq(maxBac);
        for (int i = 0; i <= maxBac; ++i) {
            if (i <= iBac) kq.iHeSo[i] += iHeSo[i];
            if (i <= other.iBac) kq.iHeSo[i] += other.iHeSo[i];
        }
        kq.chuanHoa();
        return kq;
    }

    DaThuc operator-(const DaThuc& other) const {
        int maxBac = max(iBac, other.iBac);
        DaThuc kq(maxBac);
        for (int i = 0; i <= maxBac; ++i) {
            if (i <= iBac) kq.iHeSo[i] += iHeSo[i];
            if (i <= other.iBac) kq.iHeSo[i] -= other.iHeSo[i];
        }
        kq.chuanHoa();
        return kq;
    }

    DaThuc operator*(const DaThuc& other) const {
        DaThuc kq(iBac + other.iBac);
        for (int i = 0; i <= iBac; ++i) {
            for (int j = 0; j <= other.iBac; ++j) {
                kq.iHeSo[i + j] += iHeSo[i] * other.iHeSo[j];
            }
        }
        kq.chuanHoa();
        return kq;
    }

    double tinhGiaTri(double x0) const {
        double val = 0;
        for (int i = iBac; i >= 0; --i) {
            val = val * x0 + iHeSo[i];
        }
        return val;
    }

    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        bool first = true;
        for (int i = dt.iBac; i >= 0; --i) {
            if (dt.iHeSo[i] == 0 && dt.iBac > 0) continue;

            if (!first && dt.iHeSo[i] > 0) os << " + ";
            if (dt.iHeSo[i] < 0) os << " - ";
            if (first && dt.iHeSo[i] < 0) {}
            double absVal = abs(dt.iHeSo[i]);
            if (absVal != 1 || i == 0) os << absVal;

            if (i > 0) os << "x";
            if (i > 1) os << "^" << i;

            first = false;
        }
        return os;
    }

    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap iBac cua da thuc: ";
        is >> dt.iBac;
        dt.iHeSo.resize(dt.iBac + 1);
        for (int i = dt.iBac; i >= 0; --i) {
            cout << "He so cua x^" << i << ": ";
            is >> dt.iHeSo[i];
        }
        dt.chuanHoa();
        return is;
    }
};

int main() {
    DaThuc p1, p2;

    cout << "Da thuc P1:\n"; cin >> p1;
    cout << "Da thuc P2:\n"; cin >> p2;

    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    cout << "P1 + P2 = " << (p1 + p2) << endl;
    cout << "P1 - P2 = " << (p1 - p2) << endl;
    cout << "P1 * P2 = " << (p1 * p2) << endl;

    double x;
    cout << "\nNhap gia tri x0 de tinh P1(x0): ";
    cin >> x;
    cout << "Gia tri P1(" << x << ") = " << p1.tinhGiaTri(x) << endl;

    return 0;
}
