#include <iostream>
#include <string>
using namespace std;

class cCandidate {
private:
    string ma, ten, ngaysinh;
    float toan, van, anh;
public:
    cCandidate() {}
    void Nhap() {
        cin.ignore();
        cout << "Nhap ma: "; getline(cin, ma);
        cout << "Nhap ten: "; getline(cin, ten);
        cout << "Nhap ngay sinh: "; getline(cin, ngaysinh);
        cout << "Nhap diem Toan, Van, Anh: ";
        cin >> toan >> van >> anh;
    }
    void Xuat() {
        cout << ma << " - " << ten << " (" << ngaysinh << ") - Toan: " 
             << toan << ", Van: " << van << ", Anh: " << anh 
             << " - Tong: " << TongDiem() << endl;
    }
    float TongDiem() {
        return toan + van + anh;
    }
};

class cListCandidate {
private:
    int n;
    cCandidate* ds;
public:
    cListCandidate() { n = 0; ds = nullptr; }
    ~cListCandidate() { if (ds != nullptr) delete[] ds; }
    void Nhap() {
        cout << "Nhap so luong thi sinh n: "; cin >> n;
        ds = new cCandidate[n];
        for (int i = 0; i < n; i++) {
            cout << "--- Thi sinh " << i + 1 << " ---\n";
            ds[i].Nhap();
        }
    }
    void XuatTren15() {
        cout << "--- Cac thi sinh co tong diem > 15 ---\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].TongDiem() > 15) ds[i].Xuat();
        }
    }
    void XuatMax() {
        if (n == 0) return;
        float maxDiem = ds[0].TongDiem();
        for (int i = 1; i < n; i++) {
            if (ds[i].TongDiem() > maxDiem) maxDiem = ds[i].TongDiem();
        }
        cout << "--- Cac thi sinh co tong diem cao nhat ---\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].TongDiem() == maxDiem) ds[i].Xuat();
        }
    }
    void SapXepGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].TongDiem() < ds[j].TongDiem()) {
                    cCandidate temp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = temp;
                }
            }
        }
    }
    void XuatTatCa() {
        for (int i = 0; i < n; i++) {
            ds[i].Xuat();
        }
    }
};

int main() {
    cout << "--- BAI 6: LOP DANH SACH THI SINH ---\n";
    cListCandidate list;
    list.Nhap();
    
    list.XuatTren15();
    list.XuatMax();
    
    cout << "--- Danh sach giam dan theo tong diem ---\n";
    list.SapXepGiamDan();
    list.XuatTatCa();
    
    return 0;
}
