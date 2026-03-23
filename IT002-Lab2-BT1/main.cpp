#include <iostream>

using namespace std;

class Days{
private:
    int iNgay;
    int iThang;
    int iNam;
public:

    void Nhap();
    void Xuat();
    Days NgayThangNamTiepTheo();
};

bool NamNhuan(int y){
    return ((y%400 == 0) || (y %4 == 0 && y %100 !=0));
}

int NgayTrongThang(int m, int y){
    switch(m){
        case 1: case 3: case 5: case 7: case 8 : case 10 : case 12: return 31;

        case 2:
            if(NamNhuan(y)) return 29;
            else return 28;

        default: return 30;
    }
}

bool Kiemtrahople(int d, int m, int y){
        if( y < 0) return false;
        if( m > 12 || m < 1) return false;
        if( d < 1 || d > NgayTrongThang(m,y)) return false;
        return true;
}

void Days::Nhap(){
    do{
        cout<<"Nhap ngay thang nam hop le: ";
        cin>>iNgay>>iThang>>iNam;
    }while(!Kiemtrahople(iNgay,iThang,iNam));
}

void Days::Xuat(){
    cout<<"Ngay thang nam sau khi tang theem 1: ";
    cout<<iNgay<<"/"<<iThang<<"/"<<iNam;
}

Days Days::NgayThangNamTiepTheo(){
    Days temp;
    temp.iNgay = this -> iNgay + 1;
    temp.iThang = this ->iThang;
    temp.iNam = this ->iNam;
    if(temp.iNgay > NgayTrongThang(this ->iThang, this ->iNam)){
        temp.iNgay = 1;
        temp.iThang ++;
    }
    if( temp.iThang > 12){
        temp.iThang = 1;
        temp.iNam ++;
    }
    return temp;
}
int main()
{
    Days a;
    a.Nhap();

    Days b = a.NgayThangNamTiepTheo();
    b.Xuat();

    return 0;
}
