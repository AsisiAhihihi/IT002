#include <iostream>


using namespace std;
int gcd(int  a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

class PhanSo{
private:
    int mauso;
    int tuso;
public:

    //ham nhap phan so
    void SetPhanSo(int x, int y){
        mauso = x;
        tuso = y;
    }
    //Xuat ket qua sau khi rut gon
    void GetPhanSo(){
        cout<<"Phan so sau khi rut gon: "<< tuso<<" "<<mauso;
    }
    void Rutgon(PhanSo &a){
    int g = gcd(a.mauso, a.tuso);
    a.mauso /= g;
    a.tuso /= g;

    if(a.tuso < 0 && a.mauso < 0){
        a.tuso *= -1;
        a.mauso *=-1;
    }
    if(a.mauso < 0 && a.tuso > 0){
          a.tuso *= -1;
        a.mauso *=-1;
    }
    }
};


int main()
{
    int m,t;
    cout<<"Vui long nhap phan so: ";
    cin>>t>>m;
    PhanSo a;

    //Kiem tra dieu kien cua mau so
    while(m ==0){
        cout<<"Mau so phai khac 0. Nhap lai: ";
        cin>>m>>t;
    }
    a.SetPhanSo(m,t);
    a.Rutgon(a);
    a.GetPhanSo();

    return 0;
}
