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
        cout<<tuso<<" "<<mauso;
    }
    PhanSo SoSanh(PhanSo a, PhanSo b){

    int a1= a.tuso * b.mauso;
    int b1 = b.tuso * a.mauso;

    return ( a1 > b1) ? a : b;
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

    cout<<"Nhap lan luot tu va mau cua phan so thu hai: ";
    cin>>t2>>m2;
    while( m2 ==0){
        cout<<"Mau so phai khac 0, vui long nhap lai phan so: ";
        cin>>t2>>m2;
    }

    b.SetPhanSo(t2,m2);

    PhanSo c = a.SoSanh(a,b);
    cout<<"Thuc hien so sanh hai phan so, Phan so lon nhat la: ";
    c.GetPhanSo();

    return 0;
}
