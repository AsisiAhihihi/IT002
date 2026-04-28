#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int UCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (a * b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

class cPhanSo {
private:
    int tu, mau;
public:
    cPhanSo(int _tu = 0, int _mau = 1) : tu(_tu), mau(_mau) {}
    void Nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> mau;
        } while (mau == 0);
    }
    void Xuat() {
        cout << tu << "/" << mau;
    }
    double GiaTri() {
        return (double)tu / mau;
    }
    int getTu() { return tu; }
    void RutGon() {
        int u = UCLN(tu, mau);
        tu /= u; mau /= u;
        if (mau < 0) { tu = -tu; mau = -mau; }
    }
    cPhanSo Cong(cPhanSo p) {
        cPhanSo kq;
        kq.tu = tu * p.mau + p.tu * mau;
        kq.mau = mau * p.mau;
        kq.RutGon();
        return kq;
    }
};

class cDSPhanSo {
private:
    int n;
    cPhanSo* ds;
public:
    cDSPhanSo() { n = 0; ds = nullptr; }
    ~cDSPhanSo() { if (ds != nullptr) delete[] ds; }
    void Nhap() {
        cout << "Nhap so luong phan so: "; cin >> n;
        ds = new cPhanSo[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan so thu " << i + 1 << ":\n";
            ds[i].Nhap();
        }
    }
    void Xuat() {
        for (int i = 0; i < n; i++) {
            ds[i].Xuat();
            cout << " ";
        }
        cout << endl;
    }
    cPhanSo Tong() {
        cPhanSo sum(0, 1);
        for (int i = 0; i < n; i++) sum = sum.Cong(ds[i]);
        return sum;
    }
    cPhanSo Max() {
        if (n == 0) return cPhanSo(0,1);
        cPhanSo m = ds[0];
        for (int i = 1; i < n; i++) {
            if (ds[i].GiaTri() > m.GiaTri()) m = ds[i];
        }
        return m;
    }
    cPhanSo Min() {
        if (n == 0) return cPhanSo(0,1);
        cPhanSo m = ds[0];
        for (int i = 1; i < n; i++) {
            if (ds[i].GiaTri() < m.GiaTri()) m = ds[i];
        }
        return m;
    }
    void PhanSoTuLaSNTMax() {
        int maxTu = -1;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (isPrime(ds[i].getTu()) && ds[i].getTu() > maxTu) {
                maxTu = ds[i].getTu();
                idx = i;
            }
        }
        if (idx != -1) {
            cout << "Phan so co tu nguyen to lon nhat la: "; ds[idx].Xuat(); cout << endl;
        } else {
            cout << "Khong co phan so nao co tu la so nguyen to.\n";
        }
    }
    void SapXepTangDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].GiaTri() > ds[j].GiaTri()) {
                    cPhanSo temp = ds[i]; ds[i] = ds[j]; ds[j] = temp;
                }
            }
        }
    }
    void SapXepGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].GiaTri() < ds[j].GiaTri()) {
                    cPhanSo temp = ds[i]; ds[i] = ds[j]; ds[j] = temp;
                }
            }
        }
    }
};

int main() {
    cDSPhanSo dsps;
    cout << "--- BAI 3: LOP DANH SACH PHAN SO ---\n";
    dsps.Nhap();
    cout << "Danh sach phan so vua nhap: "; dsps.Xuat();
    
    cout << "Tong cac phan so: "; dsps.Tong().Xuat(); cout << endl;
    cout << "Phan so lon nhat: "; dsps.Max().Xuat(); cout << endl;
    cout << "Phan so nho nhat: "; dsps.Min().Xuat(); cout << endl;
    dsps.PhanSoTuLaSNTMax();
    
    dsps.SapXepTangDan();
    cout << "Danh sach sau khi sap xep tang dan: "; dsps.Xuat();
    dsps.SapXepGiamDan();
    cout << "Danh sach sau khi sap xep giam dan: "; dsps.Xuat();
    
    return 0;
}
