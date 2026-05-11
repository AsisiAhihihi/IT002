#include <iostream>

using namespace std;

class SoPhuc {
private:
    double iThuc, iAo;

public:

    SoPhuc(double r = 0.0, double i = 0.0) : iThuc(r), iAo(i) {}

    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(iThuc + other.iThuc, iAo + other.iAo);
    }

    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(iThuc - other.iThuc, iAo - other.iAo);
    }

    SoPhuc operator*(const SoPhuc& other) const {
        return SoPhuc(iThuc * other.iThuc - iAo * other.iAo,
                      iThuc * other.iAo + iAo * other.iThuc);
    }

    SoPhuc operator/(const SoPhuc& other) const {
        double mau = other.iThuc * other.iThuc + other.iAo * other.iAo;
        return SoPhuc((iThuc * other.iThuc + iAo * other.iAo) / mau,
                      (iAo * other.iThuc - iThuc * other.iAo) / mau);
    }

    bool operator==(const SoPhuc& other) const {
        return (iThuc == other.iThuc && iAo == other.iAo);
    }

    bool operator!=(const SoPhuc& other) const {
        return !(*this == other);
    }

    friend  ostream& operator<<( ostream& os, const SoPhuc& sp) {
        os << sp.iThuc << (sp.iAo >= 0 ? " + " : " - ") <<  abs(sp.iAo) << "i";
        return os;
    }

    friend  istream& operator>>( istream& is, SoPhuc& sp) {
         cout << "Nhap phan iThuc: ";
        is >> sp.iThuc;
         cout << "Nhap phan iAo: ";
        is >> sp.iAo;
        return is;
    }
};

int main() {
    SoPhuc sp1, sp2;

     cout << "Nhap so phuc thu nhat:\n";
     cin >> sp1;
     cout << "Nhap so phuc thu hai:\n";
     cin >> sp2;

     cout << "(" << sp1 << ") + (" << sp2 << ") = " << (sp1 + sp2) <<  endl;
     cout << "(" << sp1 << ") - (" << sp2 << ") = " << (sp1 - sp2) <<  endl;
     cout << "(" << sp1 << ") * (" << sp2 << ") = " << (sp1 * sp2) <<  endl;

     cout << "(" << sp1 << ") / (" << sp2 << ") = " << (sp1 / sp2) <<  endl;

     cout << "sp1 == sp2: " << (sp1 == sp2 ? "Dung" : "Sai") <<  endl;
     cout << "sp1 != sp2: " << (sp1 != sp2 ? "Dung" : "Sai") <<  endl;

    return 0;
}
