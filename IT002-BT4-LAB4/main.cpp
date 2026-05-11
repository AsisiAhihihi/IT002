#include <iostream>
#include <cmath>

using namespace std;

class CDate {
private:
    int iNgay, iThang, iNam;

public:

    bool laNamNhuan(int n) const {
        return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
    }

    int soNgayTrongThang(int m, int n) const {
        int ngay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && laNamNhuan(n)) return 29;
        return ngay[m];
    }

    long toDays() const {
        long total = iNgay;
        for (int y = 1; y < iNam; ++y) total += (laNamNhuan(y) ? 366 : 365);
        for (int m = 1; m < iThang; ++m) total += soNgayTrongThang(m, iNam);
        return total;
    }

    static CDate fromDays(long days) {
        int y = 1, m = 1;
        while (days > (CDate(1, 1, y).laNamNhuan(y) ? 366 : 365)) {
            days -= (CDate(1, 1, y).laNamNhuan(y) ? 366 : 365);
            y++;
        }
        CDate temp(1, 1, y);
        while (days > temp.soNgayTrongThang(m, y)) {
            days -= temp.soNgayTrongThang(m, y);
            m++;
        }
        return CDate(days, m, y);
    }

    CDate(int d = 1, int m = 1, int y = 1) : iNgay(d), iThang(m), iNam(y) {}

    CDate operator+(int n) const {
        return fromDays(this->toDays() + n);
    }

    CDate operator-(int n) const {
        return fromDays(this->toDays() - n);
    }

    CDate& operator++() { *this = *this + 1; return *this; }
    CDate operator++(int) { CDate temp = *this; ++(*this); return temp; }
    CDate& operator--() { *this = *this - 1; return *this; }
    CDate operator--(int) { CDate temp = *this; --(*this); return temp; }

    long operator-(const CDate& other) const {
        return (this->toDays() - other.toDays());
    }

    friend ostream& operator<<(ostream& os, const CDate& d) {
        os << (d.iNgay < 10 ? "0" : "") << d.iNgay << "/"
           << (d.iThang < 10 ? "0" : "") << d.iThang << "/" << d.iNam;
        return os;
    }

    friend istream& operator>>(istream& is, CDate& d) {
        is >> d.iNgay >> d.iThang >> d.iNam;
        return is;
    }
};

int main() {
    CDate ngayGui, ngayRut;
    double soTienGui, laiSuatNam;

    cout << "Nhap ngay gui:"; cin >> ngayGui;
    cout << "\nNhap ngay rut:"; cin >> ngayRut;
    cout << "\nNhap so tien gui (VND): "; cin >> soTienGui;
    cout << "\nNhap lai suat nam (%): "; cin >> laiSuatNam;

    long soNgay = ngayRut - ngayGui;

    if (soNgay <= 0) {
        cout << "Loi: Ngay rut phai sau ngay gui!" << endl;
    } else {
        double tienLai = soTienGui * (laiSuatNam / 100.0) * (soNgay / 365.0);

        cout << "Thoi gian gui: " << soNgay << " ngay." << endl;
        cout << "Tien lai nhan duoc: " << (long long)tienLai << " VND" << endl;
        cout << "Tong so tien (Goc + Lai): " << (long long)(soTienGui + tienLai) << " VND" << endl;
    }

    return 0;
}
