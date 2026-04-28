#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

class cArray {
private:
    int n;
    int* arr;
public:
    cArray() { n = 0; arr = nullptr; }
    ~cArray() { if (arr != nullptr) delete[] arr; }
    void TaoNgauNhien(int _n) {
        n = _n;
        if (n <= 0) return;
        arr = new int[n];
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100; // 0 to 99
        }
    }
    void Xuat() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int DemX(int x) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) count++;
        }
        return count;
    }
    bool KiemTraTangDan() {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]) return false;
        }
        return true;
    }
    void TimPhanLeNhoNhat() {
        int minLe = -1;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                if (!found || arr[i] < minLe) {
                    minLe = arr[i];
                    found = true;
                }
            }
        }
        if (found) cout << "Phan tu le nho nhat: " << minLe << endl;
        else cout << "Khong co phan tu le trong mang.\n";
    }
    void TimSNTLonNhat() {
        int maxSNT = -1;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (isPrime(arr[i])) {
                if (!found || arr[i] > maxSNT) {
                    maxSNT = arr[i];
                    found = true;
                }
            }
        }
        if (found) cout << "SNT lon nhat: " << maxSNT << endl;
        else cout << "Khong co SNT trong mang.\n";
    }
    void SapXepTangDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                }
            }
        }
    }
    void SapXepGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                }
            }
        }
    }
};

int main() {
    cArray a;
    cout << "--- BAI 4: LOP MANG MOT CHIEU ---\n";
    int n;
    cout << "Nhap so luong phan tu: "; cin >> n;
    a.TaoNgauNhien(n);
    cout << "Mang ngau nhien vua tao: "; a.Xuat();

    int x; cout << "Nhap gia tri x can dem: "; cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << a.DemX(x) << endl;

    if (a.KiemTraTangDan()) cout << "Mang tang dan.\n";
    else cout << "Mang khong tang dan.\n";

    a.TimPhanLeNhoNhat();
    a.TimSNTLonNhat();

    a.SapXepTangDan();
    cout << "Mang tang dan: "; a.Xuat();

    a.SapXepGiamDan();
    cout << "Mang giam dan: "; a.Xuat();

    return 0;
}
