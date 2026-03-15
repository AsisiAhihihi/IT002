#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string name;
    double toan;
    double van;
public:
    Student( string n, double t, double v){

        name = n;
        toan = t;
        van = v;

    }
    string Getname(){return name;}

    double Dtb(){
        return (toan + van)/2;
    }



};


int main()
{
    string name;
    double toan,van;

    cout<<"Nhap ho ten, diem toan, van cua hoc sinh: ";
    getline(cin,name);
    cin>>toan>>van;

    while( toan < 0 || toan > 10 || van < 0 || van> 10){
        cout<<"Input diem sai, Nhap lai diem: ";
        cin>>toan>>van;
    }
    Student a( name, toan , van );
    double b = a.Dtb();

    cout<<"Diem trung binh cua hoc sinh "<<a.Getname()<<" la: "<< b;


    return 0;
}
