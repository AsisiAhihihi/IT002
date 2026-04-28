#include <iostream>
#include <cmath>
using namespace std;

class cDiem {
private:
    double x, y;
public:
    cDiem(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    ~cDiem() {}
    void Nhap() {
        cout << "Nhap x, y: ";
        cin >> x >> y;
    }
    void Xuat() {
        cout << "(" << x << ", " << y << ")";
    }
    void TinhTien(double dx, double dy) {
        x += dx;
        y += dy;
    }
    void Quay(double goc) {
        double rad = goc * M_PI / 180.0;
        double newX = x * cos(rad) - y * sin(rad);
        double newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }
    double getX() { return x; }
    double getY() { return y; }
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
};

class cDaGiac {
private:
    int n;
    cDiem* dinh;
public:
    cDaGiac() { n = 0; dinh = nullptr; }
    ~cDaGiac() { if (dinh != nullptr) delete[] dinh; }
    void Nhap() {
        cout << "Nhap so dinh n (n >= 3): ";
        cin >> n;
        if (n < 3) return;
        dinh = new cDiem[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap dinh thu " << i + 1 << ":\n";
            dinh[i].Nhap();
        }
    }
    void Xuat() {
        if (n < 3) return;
        cout << "Da giac tao boi cac dinh: ";
        for (int i = 0; i < n; i++) {
            dinh[i].Xuat();
            if (i < n - 1) cout << " - ";
        }
        cout << endl;
    }
    double ChuVi() {
        if (n < 3) return 0;
        double cv = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            double dx = dinh[i].getX() - dinh[next].getX();
            double dy = dinh[i].getY() - dinh[next].getY();
            cv += sqrt(dx*dx + dy*dy);
        }
        return cv;
    }
    double DienTich() {
        if (n < 3) return 0;
        double s = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            s += (dinh[i].getX() * dinh[next].getY() - dinh[next].getX() * dinh[i].getY());
        }
        return abs(s) / 2.0;
    }
    void TinhTien(double dx, double dy) {
        for (int i = 0; i < n; i++) {
            dinh[i].TinhTien(dx, dy);
        }
    }
    void Quay(double goc) {
        for (int i = 0; i < n; i++) {
            dinh[i].Quay(goc);
        }
    }
    void PhongTo(double k) {
        for (int i = 0; i < n; i++) {
            dinh[i].setX(dinh[i].getX() * k);
            dinh[i].setY(dinh[i].getY() * k);
        }
    }
    void ThuNho(double k) {
        PhongTo(1/k);
    }
};

int main() {
    cDaGiac dg;
    cout << "--- BAI 2: LOP DA GIAC ---\n";
    dg.Nhap();
    dg.Xuat();
    cout << "Chu vi: " << dg.ChuVi() << endl;
    cout << "Dien tich: " << dg.DienTich() << endl;

    dg.TinhTien(1, 1);
    cout << "Sau khi tinh tien (1, 1): \n"; dg.Xuat();

    return 0;
}
