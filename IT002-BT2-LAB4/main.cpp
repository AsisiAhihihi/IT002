#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

public:

    void rutGon() {
        if (iMau == 0) return;
        int common = gcd(iTu, iMau);
        iTu /= common;
        iMau /= common;
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }


    PhanSo(int t = 0, int m = 1) : iTu(t), iMau(m) {
        rutGon();
    }

    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(iTu * other.iMau + other.iTu * iMau, iMau * other.iMau);
    }

    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(iTu * other.iMau - other.iTu * iMau, iMau * other.iMau);
    }

    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(iTu * other.iTu, iMau * other.iMau);
    }

    PhanSo operator/(const PhanSo& other) const {
        return PhanSo(iTu * other.iMau, iMau * other.iTu);
    }

    bool operator==(const PhanSo& other) const {
        return iTu == other.iTu && iMau == other.iMau;
    }

    bool operator>(const PhanSo& other) const {
        return (double)iTu / iMau > (double)other.iTu / other.iMau;
    }

    bool operator<(const PhanSo& other) const {
        return (double)iTu / iMau < (double)other.iTu / other.iMau;
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.iMau == 1) os << ps.iTu;
        else os << ps.iTu << "/" << ps.iMau;
        return os;
    }

    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: "; is >> ps.iTu;
        do {
            cout << "Nhap mau so (khac 0): "; is >> ps.iMau;
            if (ps.iMau == 0) cout << "Loi: Mau so phai khac 0! Nhap lai.\n";
        } while (ps.iMau == 0);
        ps.rutGon();
        return is;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout <<"Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout <<"Nhap phan so thu hai:\n";
    cin >> ps2;

    cout << "   " << ps1 << " + " << ps2 << " = " << (ps1 + ps2) << endl;
    cout << "   " << ps1 << " - " << ps2 << " = " << (ps1 - ps2) << endl;
    cout << "   " << ps1 << " * " << ps2 << " = " << (ps1 * ps2) << endl;
    cout << "   " << ps1 << " / " << ps2 << " = " << (ps1 / ps2) << endl;

    cout << "   " << ps1 << " == " << ps2 << " ? -> " << (ps1 == ps2 ? "Dung" : "Sai") << endl;
    cout << "   " << ps1 << " >  " << ps2 << " ? -> " << (ps1 > ps2  ? "Dung" : "Sai") << endl;
    cout << "   " << ps1 << " <  " << ps2 << " ? -> " << (ps1 < ps2  ? "Dung" : "Sai") << endl;

    return 0;
}
