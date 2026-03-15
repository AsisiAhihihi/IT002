#include <iostream>

using namespace std;


class PhanSo{
private:
    int tuso;
    int mauso;
public:

    void SetPhanSo(int t, int m){
        tuso = t;
        mauso = m;
    }
    void GetPhanSo(){
        cout<<tuso<<" "<<mauso<<endl;
    }

    PhanSo Tong(PhanSo a, PhanSo b){
        PhanSo c;

        c.tuso = a.tuso*b.mauso + b.tuso*a.mauso;
        c.mauso = a.mauso * b.mauso;

        return c;
    }
    PhanSo Hieu(PhanSo a, PhanSo b){
        PhanSo c;

        c.tuso = a.tuso*b.mauso - b.tuso*a.mauso;
        c.mauso = a.mauso * b.mauso;

        return c;
    }
    PhanSo Tich(PhanSo a, PhanSo b){
        PhanSo c;

        c.tuso = a.tuso *b.tuso;
        c.mauso = a.mauso* b.mauso;

        return c;
    }
    PhanSo Thuong(PhanSo a, PhanSo b){
        PhanSo c;

        c.tuso = a.tuso *b.mauso;
        c.mauso = a.mauso* b.tuso;

        return c;
    }
};


int main()
{
    int m1,t1,m2,t2;
    PhanSo a;
    PhanSo b;

    cout<<"Nhap lan luot tu va mau cua phan so thu nhat: ";
    cin>>t1>>m1;
    while( m1 ==0){
        cout<<"Mau so phai khac 0, vui long nhap lai phan so: ";
        cin>>t1>>m1;
    }

    a.SetPhanSo(t1,m1);


    cout<<"Nhap lan luot tu va mau cua phan so thu nhat: ";
    cin>>t2>>m2;
    while( m2 ==0){
        cout<<"Mau so phai khac 0, vui long nhap lai phan so: ";
        cin>>t2>>m2;
    }

    b.SetPhanSo(t2,m2);

    PhanSo c= a.Tong(a,b);
    cout<<"Tong cua hai phan so vua nhap la: " ;
    c.GetPhanSo();

    PhanSo d= a.Hieu(a,b);
    cout<<"Hieu cua hai phan so vua nhap la: " ;
    d.GetPhanSo();

    PhanSo e= a.Tich(a,b);
    cout<<"Tich cua hai phan so vua nhap la: " ;
    e.GetPhanSo();

    PhanSo f= a.Thuong(a,b);
    cout<<"Thuong cua hai phan so vua nhap la: " ;
    f.GetPhanSo();

    return 0;
}
