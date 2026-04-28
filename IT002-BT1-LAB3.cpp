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
    double KhoangCach(cDiem d) {
        return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
    }
    double getX() { return x; }
    double getY() { return y; }
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
};

class cTamGiac {
private:
    cDiem A, B, C;
public:
    cTamGiac() {}
    cTamGiac(cDiem _A, cDiem _B, cDiem _C) : A(_A), B(_B), C(_C) {}
    ~cTamGiac() {}
    void Nhap() {
        cout << "Nhap dinh A:\n"; A.Nhap();
        cout << "Nhap dinh B:\n"; B.Nhap();
        cout << "Nhap dinh C:\n"; C.Nhap();
    }
    void Xuat() {
        cout << "Tam giac qua 3 dinh: ";
        A.Xuat(); cout << " - "; B.Xuat(); cout << " - "; C.Xuat(); cout << endl;
    }
    bool KiemTraHopLe() {
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);
        return (a + b > c && a + c > b && b + c > a);
    }
    void PhanLoai() {
        if (!KiemTraHopLe()) {
            cout << "Khong phai tam giac hop le!" << endl;
            return;
        }
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);

        bool vuong = (abs(a*a + b*b - c*c) < 1e-5 || abs(a*a + c*c - b*b) < 1e-5 || abs(b*b + c*c - a*a) < 1e-5);
        bool can = (abs(a-b) < 1e-5 || abs(a-c) < 1e-5 || abs(b-c) < 1e-5);
        bool deu = (abs(a-b) < 1e-5 && abs(a-c) < 1e-5);

        if (deu) cout << "Tam giac deu\n";
        else if (vuong && can) cout << "Tam giac vuong can\n";
        else if (vuong) cout << "Tam giac vuong\n";
        else if (can) cout << "Tam giac can\n";
        else cout << "Tam giac thuong\n";
    }
    double ChuVi() {
        return B.KhoangCach(C) + A.KhoangCach(C) + A.KhoangCach(B);
    }
    double DienTich() {
        double p = ChuVi() / 2;
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void TinhTien(double dx, double dy) {
        A.TinhTien(dx, dy);
        B.TinhTien(dx, dy);
        C.TinhTien(dx, dy);
    }
    void Quay(double goc) {
        A.Quay(goc);
        B.Quay(goc);
        C.Quay(goc);
    }
    void PhongTo(double k) {
        A.setX(A.getX() * k); A.setY(A.getY() * k);
        B.setX(B.getX() * k); B.setY(B.getY() * k);
        C.setX(C.getX() * k); C.setY(C.getY() * k);
    }
    void ThuNho(double k) {
        PhongTo(1/k);
    }
};

int main() {
    cTamGiac tg;
    tg.Nhap();
    if (tg.KiemTraHopLe()) {
        tg.Xuat();
        tg.PhanLoai();
        cout << "Chu vi: " << tg.ChuVi() << endl;
        cout << "Dien tich: " << tg.DienTich() << endl;

        tg.TinhTien(2, 3);
        cout << "Sau khi tinh tien (2, 3): "; tg.Xuat();

        tg.PhongTo(2);
        cout << "Sau khi phong to 2 lan: "; tg.Xuat();

        tg.ThuNho(2);
        cout<<"Sau khi thu nho 2 lan: "; tg.Xuat();
    } else {
        cout << "Khong phai tam giac hop le!" << endl;
    }
    return 0;
}
