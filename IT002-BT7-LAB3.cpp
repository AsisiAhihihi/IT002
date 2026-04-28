#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cNhanVienVP {
private:
    string ma, ten, ngaysinh;
    double luong;
public:
    cNhanVienVP() { ma = ""; ten = ""; ngaysinh = ""; luong = 0; }
    string getMa() { return ma; }
    string getTen() { return ten; }
    string getNgaySinh() { return ngaysinh; }
    double getLuong() { return luong; }
    void setMa(string _ma) { ma = _ma; }
    void setTen(string _ten) { ten = _ten; }
    void setNgaySinh(string _ns) { ngaysinh = _ns; }
    void setLuong(double _l) { luong = _l; }
    
    void Nhap() {
        cin.ignore();
        cout << "Nhap ma: "; getline(cin, ma);
        cout << "Nhap ten: "; getline(cin, ten);
        cout << "Nhap ngay sinh (dd/mm/yyyy): "; getline(cin, ngaysinh);
        cout << "Nhap luong: "; cin >> luong;
    }
    void Xuat() {
        cout << ma << " - " << ten << " (" << ngaysinh << ") - Luong: " << luong << endl;
    }
    int extractYear() {
        if (ngaysinh.length() >= 4) {
            string yStr = ngaysinh.substr(ngaysinh.length() - 4);
            return stoi(yStr);
        }
        return 0;
    }
};

int main() {
    int n;
    cout << "--- BAI 7: LOP NHAN VIEN VAN PHONG ---\n";
    cout << "Nhap so luong nhan vien VP: "; cin >> n;
    if (n <= 0) return 0;
    
    vector<cNhanVienVP> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "--- Nhan vien " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
    
    cout << "--- Danh sach nhan vien ---\n";
    double tongLuong = 0;
    double maxLuong = ds[0].getLuong();
    int minYear = ds[0].extractYear();
    
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
        tongLuong += ds[i].getLuong();
        if (ds[i].getLuong() > maxLuong) maxLuong = ds[i].getLuong();
        if (ds[i].extractYear() < minYear) minYear = ds[i].extractYear(); // nam sinh nho nhat -> tuoi cao nhat
    }
    
    cout << "Tong luong cong ty phai tra: " << tongLuong << endl;
    
    cout << "--- Nhan vien co luong cao nhat ---\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getLuong() == maxLuong) ds[i].Xuat();
    }
    
    cout << "--- Nhan vien co tuoi cao nhat ---\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].extractYear() == minYear) ds[i].Xuat();
    }
    
    cout << "--- Danh sach tang dan theo luong ---\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                cNhanVienVP temp = ds[i]; ds[i] = ds[j]; ds[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) ds[i].Xuat();
    
    return 0;
}
