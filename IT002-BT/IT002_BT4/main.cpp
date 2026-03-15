#include <iostream>

using namespace std;


class Day{
private:
    int day;
    int month;
    int year;
public:
    Day(){}
    void SetDay(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    void GetDay(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }

    // Kiểm tra năm nhuận đế tính ngày tháng 2 và hàm tính số ngày tron tháng
    bool KtraNamNhuan(int y){
        if( y%4 ==0 && y%100 != 0 || y%400 ==0) return true;
        return false;

    }
    int NgayTrongThang(int m, int y){
        switch(m){
            case 1: case 3: case 5 : case 7: case 8 : case 10: case 12: return 31;
            case 4: case 6 : case 9: case 11: return 30;
            case 2: if(KtraNamNhuan(y)) return 29;
                    else return 28;
        }
    }

    // Kiểm tra input có hợp lệ hay không
    bool KtraNgayHopLe(int d, int m, int y){

        if(m < 1 || m > 12) return false;

        if(d < 1) return false;

        if(d > NgayTrongThang(m,y)) return false;

        return true;
}
    // Tăng biến ngày thêm 1
    Day FindNextDay(){

        Day b;
        day ++;
        int a = NgayTrongThang(month, year);

        if( day > a){
            day -= a;
            month ++;
        }
        if( month > 12){
            month -=12;
            year ++;
        }
        b.SetDay(day,month,year);
        return b;
    }

};
int main()
{
    int dd,mm,yy;

    cout<<"Nhap ngay thang nam: ";
    cin>>dd>>mm>>yy;
    Day a;

    // Vòng lặp kiếm tra ngày tháng năm
    while( !a.KtraNgayHopLe(dd,mm,yy)){
        cout<<"Ngay thang nam khong hop le, nhap lai: ";
        cin>>dd>>mm>>yy;
    }

    a.SetDay(dd,mm,yy);

    a = a.FindNextDay();

    cout<<"Sau khi tang len 1 ngay: ";
    a.GetDay();

    return 0;
}
