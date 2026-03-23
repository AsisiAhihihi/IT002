#include <iostream>

using namespace std;

class SoPhuc{
private:
    double iThuc;
    double iAo;
public:

    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc b);
    SoPhuc Hieu(SoPhuc b);
    SoPhuc Tich(SoPhuc b);
    SoPhuc Thuong(SoPhuc b);
};

void SoPhuc::Nhap(){
   cout<<"Nhap phan thuc: "; cin>> iThuc;
   cout<<"Nhap phan ao: "; cin>> iAo;
}

void SoPhuc::Xuat(){
    cout<<iThuc;

    if(iAo >= 0)
        cout << " + " << iAo << "i";
    else
        cout << " - " << -iAo << "i";
}

SoPhuc SoPhuc::Tong(SoPhuc b){
    SoPhuc temp;
    temp.iThuc = this -> iThuc + b.iThuc;
    temp.iAo = this-> iAo + b.iAo;
    return temp;
}

SoPhuc SoPhuc::Hieu(SoPhuc b){
    SoPhuc temp;
    temp.iThuc = this -> iThuc - b.iThuc;
    temp.iAo = this-> iAo - b.iAo;
    return temp;
}

SoPhuc SoPhuc::Tich(SoPhuc b){
    SoPhuc temp;
    temp.iThuc = this -> iThuc * b.iThuc - this->iAo * b.iAo;
    temp.iAo = this->iThuc * b.iAo + this->iAo * b.iThuc;
    return temp;
}

SoPhuc SoPhuc::Thuong(SoPhuc e){
    double a = this ->iThuc;
    double b = this ->iAo;
    double c = e.iThuc;
    double d = e.iAo;

    SoPhuc temp;
    double mau = c*c + d*d;

    if(mau == 0){
        cout << "Khong the chia cho so phuc 0!\n";
        temp.iThuc = temp.iAo = 0;
        return temp;
    }

    temp.iThuc = (a*c + b*d)/mau;
    temp.iAo = (b*c - a*d)/mau;

    return temp;
}
int main()
{
    SoPhuc a, b;

    cout << "Nhap so phuc a:\n";
    a.Nhap();

    cout << "Nhap so phuc b:\n";
    b.Nhap();

    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);

    cout << "\nTong: "; tong.Xuat();
    cout << "\nHieu: "; hieu.Xuat();
    cout << "\nTich: "; tich.Xuat();
    cout << "\nThuong: "; thuong.Xuat();

    return 0;
}
