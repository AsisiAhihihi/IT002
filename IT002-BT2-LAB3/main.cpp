#include <iostream>
#include <cmath>
using namespace std;

struct Diem{
    double x;
    double y;

    void NhapDiem(){
        cin>> x;
        cin>>y;
    }
};

class cDaGiac{
private:
    Diem *p;
    int n;
public:

    cDaGiac(int n){
        this-> n = n;
        p = new Diem[n];

        for(int i = 0; i< n; i ++){
            p[i].NhapDiem();
        }
    }

    ~cDaGiac(){
        delete p;
    }

    void XuatDaGiac(){
        cout<<"Da giac gom cac diem:"<<endl;
        for(int i = 0; i < n ; i++){
            cout<<"("<<p[i].x<<","<<p[i].y<<")"<<endl;
        }
    }

    double ChuViDaGiac(){
        double sum = 0;

        for(int i = 0; i < n; i ++){
            sum += sqrt(pow(p[i].x - p[i+1].x,2) + pow(p[i].y - p[i+1].y,2));
        }
        return sum;
    }

    void TinhTienTamGiac(double a, double b){
        for(int i =0; i < n; i++){
            p[i].x += a;
            p[i].y += b;
        }
    }

    void QuayTamGiac(double a){
        for(int i = 0; i < n; i++){
            p[i].x = p[i].x*cos(a) - p[i].y*sin(a);
            p[i].y = p[i].x*sin(a) + p[i].y*cos(a);
        }
    }

    void Phongto(double n){
        for(int i = 0; i < n; i++){
            p[i].x *= n;
            p[i].y *= n;
        }
    }

    void ThuNHo(double n){
        Phongto(1/n);
    }

};
int main()
{

    return 0;
}
