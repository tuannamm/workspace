#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    string HoTen;
    int MSSV;
    float diemTKLG;
    float diemVDK;
    float diemKTMT;
    float diemTrungBinh;

public:
    int TinhDiemTrungBinh()
    {
        return (diemTKLG + diemVDK + diemKTMT) / 3;
    }

    void Nhap()
    {
        cout << "Nhap ho va ten: ";
        getline(cin, HoTen);
        cout << "Nhap MSSV: ";
        cin >> MSSV;
        cin.ignore();
        cout << "Nhap diem TKLG: ";
        cin >> diemTKLG;
        cout << "Nhap diem VDK: ";
        cin >> diemVDK;
        cout << "Nhap diem KTMT: ";
        cin >> diemKTMT;
    }

    void Xuat()
    {
        cout << "\nHo va ten: " << HoTen;
        cout << "\nMSSV: " << MSSV;
        cout << "\nDiem TKLG: " << diemTKLG;
        cout << "\nDiem VDK: " << diemVDK;
        cout << "\nDiem KTMT: " << diemKTMT;
        cout << "\nDiem trung binh: " << TinhDiemTrungBinh();
    }
};

int main()
{
    SinhVien *pTuanNam;
    pTuanNam = new SinhVien;
    pTuanNam->Nhap();
    pTuanNam->Xuat();
    delete pTuanNam;

    cout << "\n\n\n";
    system("pause");
}