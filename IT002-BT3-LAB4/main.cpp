#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

class CTime {
private:
    int iGio, iPhut, iGiay;

public:

    void chuanHoa() {
        while (iGiay >= 60) { iPhut += iGiay / 60; iGiay %= 60; }
        while (iGiay < 0) { iPhut -= 1; iGiay += 60; }
        while (iPhut >= 60) { iGio += iPhut / 60; iPhut %= 60; }
        while (iPhut < 0) { iGio -= 1; iPhut += 60; }
        iGio %= 24;
        if (iGio < 0) iGio += 24;
    }

    CTime(int h = 0, int m = 0, int s = 0) : iGio(h), iPhut(m), iGiay(s) {
        chuanHoa();
    }

    CTime operator+(int s) const { return CTime(iGio, iPhut, iGiay + s); }
    CTime operator-(int s) const { return CTime(iGio, iPhut, iGiay - s); }

    CTime& operator++() { iGiay++; chuanHoa(); return *this; }
    CTime operator++(int) { CTime temp = *this; ++(*this); return temp; }
    CTime& operator--() { iGiay--; chuanHoa(); return *this; }
    CTime operator--(int) { CTime temp = *this; --(*this); return temp; }

    friend ostream& operator<<(ostream& os, const CTime& t) {
        os << setfill('0') << setw(2) << t.iGio << ":"
           << setw(2) << t.iPhut << ":"
           << setw(2) << t.iGiay;
        return os;
    }

    friend istream& operator>>(istream& is, CTime& t) {
        cout << "Nhap iGio: "; is >> t.iGio;
        cout << "Nhap iPhut: "; is >> t.iPhut;
        cout << "Nhap iGiay: "; is >> t.iGiay;
        t.chuanHoa();
        return is;
    }
};

void goToXY(int x, int y) {
    printf("\033[%d;%df", y, x);
}

int main() {
    CTime dongHo;
    cin >> dongHo;


    cout << "Thoi gian goc:    " << dongHo << endl;
    cout << "Cong 100 iGiay:    " << (dongHo + 100) << endl;
    cout << "Tru 100 iGiay:     " << (dongHo - 100) << endl;
    cout << "Tang 1 iGiay (++): " << ++dongHo << " (Gia tri nay se dung de chay tiep)" << endl;

    cout << "\nNhan Enter de bat dau chay dong ho tai goc phai man hinh...";
    cin.ignore();
    cin.get();

    system("cls || clear");
    cout << "Dong ho dang chay..." << endl;

    while (true) {

        goToXY(65, 1);
        cout << " TIME: [" << dongHo << "] ";

        this_thread::sleep_for(chrono::seconds(1));
        dongHo++;
    }

    return 0;
}
