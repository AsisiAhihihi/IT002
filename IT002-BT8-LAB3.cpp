#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cNhanVienSX {
private:
    string ma, ten, ngaysinh;
    int soSP;
    double donGia;
public:
    cNhanVienSX() { ma = ""; ten = ""; ngaysinh = ""; soSP = 0; donGia = 0; }
    string getMa() { return ma; }
    string getTen() { return ten; }
    string getNgaySinh() { return ngaysinh; }
    int getSoSP() { return soSP; }
    double getDonGia() { return donGia; }
    
    void setMa(string _ma) { ma = _ma; }
    void setTen(string _ten) { ten = _ten; }
    void setNgaySinh(string _ns) { ngaysinh = _ns; }
    void setSoSP(int _sp) { soSP = _sp; }
    void setDonGia(double _dg) { donGia = _dg; }
    
    double TinhLuong() { return soSP * donGia; }
    
    void Nhap() {
        cin.ignore();
        cout << "Nhap ma: "; getline(cin, ma);
        cout << "Nhap ten: "; getline(cin, ten);
        cout << "Nhap ngay sinh (dd/mm/yyyy): "; getline(cin, ngaysinh);
        cout << "Nhap so san pham: "; cin >> soSP;
        cout << "Nhap don gia: "; cin >> donGia;
    }
    void Xuat() {
        cout << ma << " - " << ten << " (" << ngaysinh << ") - SP: " << soSP 
             << " - Don gia: " << donGia << " - Luong: " << TinhLuong() << endl;
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
    cout << "--- BAI 8: LOP NHAN VIEN SAN XUAT ---\n";
    cout << "Nhap so luong nhan vien SX: "; cin >> n;
    if (n <= 0) return 0;
    
    vector<cNhanVienSX> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "--- Nhan vien " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
    
    cout << "--- Danh sach nhan vien ---\n";
    double tongLuong = 0;
    double minLuong = ds[0].TinhLuong();
    int minYear = ds[0].extractYear();
    
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
        tongLuong += ds[i].TinhLuong();
        if (ds[i].TinhLuong() < minLuong) minLuong = ds[i].TinhLuong();
        if (ds[i].extractYear() < minYear) minYear = ds[i].extractYear(); 
    }
    
    cout << "Tong luong cong ty phai tra: " << tongLuong << endl;
    
    cout << "--- Nhan vien co luong thap nhat ---\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhLuong() == minLuong) ds[i].Xuat();
    }
    
    cout << "--- Nhan vien co tuoi cao nhat ---\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].extractYear() == minYear) ds[i].Xuat();
    }
    
    cout << "--- Danh sach tang dan theo luong ---\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                cNhanVienSX temp = ds[i]; ds[i] = ds[j]; ds[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) ds[i].Xuat();
    
    return 0;
}
