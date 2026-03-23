#include <iostream>

using namespace std;

class Time{
private:
    int iGio;
    int iPhut;
    int iGiay;
public:

    void Nhap();
    void Xuat();
    Time TinhCongThemMotGiay();
};

bool ThoiGianHopLe(int g, int p, int j){
    if( g < 0 || g > 23) return false;
    if( p < 0 || p > 59) return false;
    if( j < 0 || j > 59) return false;
    return true;
}

void Time::Nhap(){
    do{
        cout<<"Nhap gio phut giay hop le: ";
        cin>> iGio>> iPhut >> iGiay;
    }while(!ThoiGianHopLe(iGio,iPhut,iGiay));
}

void Time::Xuat(){
    cout<<iGio<<" Gio "<<iPhut<<" Phut "<<iGiay<<" Giay ";
}

Time Time::TinhCongThemMotGiay(){

    Time temp;

    temp.iGiay = iGiay + 1;
    temp.iGio = iGio;
    temp.iPhut = iPhut;

    if(temp.iGiay > 59){
        temp.iGiay = 0;
        temp.iPhut++;
    }

    if(temp.iPhut > 59){
        temp.iPhut = 0;
        temp.iGio++;
    }
    if(temp.iGio > 23){
        temp.iGio =0;
    }
    return temp;
}
int main(){
    Time t;
    t.Nhap();

    cout << "Thoi gian ban dau: ";
    t.Xuat();

    Time t2 = t.TinhCongThemMotGiay();

    cout << "\nSau khi cong them 1 giay: ";
    t2.Xuat();

    return 0;
}
