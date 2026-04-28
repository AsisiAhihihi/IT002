#include <iostream>
#include <cmath>
using namespace std;

class cDaThuc {
private:
    int n; // Bac cua da thuc
    double* heSo; // Mang chua he so a_0 den a_n (heSo[i] la he so cua x^i)
public:
    cDaThuc(int bac = 0) {
        n = bac;
        heSo = new double[n + 1];
        for (int i = 0; i <= n; i++) heSo[i] = 0;
    }
    ~cDaThuc() {
        if (heSo != nullptr) delete[] heSo;
    }
    cDaThuc(const cDaThuc& other) {
        n = other.n;
        heSo = new double[n + 1];
        for (int i = 0; i <= n; i++) heSo[i] = other.heSo[i];
    }
    cDaThuc& operator=(const cDaThuc& other) {
        if (this != &other) {
            delete[] heSo;
            n = other.n;
            heSo = new double[n + 1];
            for (int i = 0; i <= n; i++) heSo[i] = other.heSo[i];
        }
        return *this;
    }
    void Nhap() {
        cout << "Nhap bac cua da thuc: "; cin >> n;
        delete[] heSo;
        heSo = new double[n + 1];
        for (int i = n; i >= 0; i--) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }
    void Xuat() {
        bool isFirst = true;
        for (int i = n; i >= 0; i--) {
            if (heSo[i] != 0) {
                if (!isFirst && heSo[i] > 0) cout << " + ";
                else if (heSo[i] < 0) {
                    cout << (isFirst ? "-" : " - ");
                }
                double val = abs(heSo[i]);
                if (val != 1 || i == 0) cout << val;
                if (i > 0) cout << "x";
                if (i > 1) cout << "^" << i;
                isFirst = false;
            }
        }
        if (isFirst) cout << "0";
        cout << endl;
    }
    double TinhGiaTri(double x) {
        double result = 0;
        for (int i = 0; i <= n; i++) {
            result += heSo[i] * pow(x, i);
        }
        return result;
    }
    cDaThuc Cong(cDaThuc& dt) {
        int maxN = max(n, dt.n);
        cDaThuc result(maxN);
        for (int i = 0; i <= maxN; i++) {
            double h1 = (i <= n) ? heSo[i] : 0;
            double h2 = (i <= dt.n) ? dt.heSo[i] : 0;
            result.heSo[i] = h1 + h2;
        }
        return result;
    }
    cDaThuc Tru(cDaThuc& dt) {
        int maxN = max(n, dt.n);
        cDaThuc result(maxN);
        for (int i = 0; i <= maxN; i++) {
            double h1 = (i <= n) ? heSo[i] : 0;
            double h2 = (i <= dt.n) ? dt.heSo[i] : 0;
            result.heSo[i] = h1 - h2;
        }
        return result;
    }
};

int main() {
    cout << "--- BAI 5: LOP DA THUC ---\n";
    cDaThuc dt1, dt2;
    cout << "Da thuc 1:\n"; dt1.Nhap();
    cout << "Da thuc 2:\n"; dt2.Nhap();
    
    cout << "P1(x) = "; dt1.Xuat();
    cout << "P2(x) = "; dt2.Xuat();
    
    double x;
    cout << "Nhap x de tinh P1(x): "; cin >> x;
    cout << "P1(" << x << ") = " << dt1.TinhGiaTri(x) << endl;
    
    cDaThuc tong = dt1.Cong(dt2);
    cout << "P1(x) + P2(x) = "; tong.Xuat();
    
    cDaThuc hieu = dt1.Tru(dt2);
    cout << "P1(x) - P2(x) = "; hieu.Xuat();
    
    return 0;
}
