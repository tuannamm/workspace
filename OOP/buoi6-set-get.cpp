/*
set --> đặt giá trị cho thuộc tính
get --> hỏi để nhận một thuộc tính private
*/

/*
Xây dựng menu chương trình
1. Nhập danh sách sinh viên: nhập n là tổng số sinh viên, cấp phát mảng động dùng thư viện vector.
2. Xuất danh sách sinh viên
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class SinhVien
{
private:
    string HoTen;
    int MSSV;
    float diemCTMT;
    float diemVDK;
    float diemTKLG;
    float diemTrungBinh;

public:
    int tinhDiemTrungBinh()
    {
        return (diemCTMT + diemVDK + diemTKLG) / 3;
    }

    void Nhap()
    {
        cout << "Nhap MSSV: ";
        cin >> MSSV;
        cout << "Nhap ho va ten: ";
        cin >> HoTen;
        cin.ignore();
        cout << "Nhap diem CTMT: ";
        cin >> diemCTMT;
        cout << "Nhap diem VDK: ";
        cin >> diemVDK;
        cout << "Nhap diem TKLG: ";
        cin >> diemTKLG;
        diemTrungBinh = (diemTKLG + diemVDK + diemCTMT) / 3;
    }

    void Xuat()
    {
        cout << MSSV << "\t";
        cout << HoTen << "\t";
        cout << diemCTMT << "\t";
        cout << diemVDK << "\t";
        cout << diemTKLG << "\t";
        cout << tinhDiemTrungBinh() << "\n";
    }

    float get_diemTrungBinh()
    {
        return diemTrungBinh;
    }

    float set_diemTKLG(float diem)
    {
        diemTKLG = diem;
        diemTrungBinh = (diemTKLG + diemVDK + diemCTMT) / 3;
    }
};

// class MENU
// {
// private:
//     int n;
//     vector<SinhVien> sv;

// public:
//     void nhap()
//     {
//         cout << "\nNhap so sinh vien : ";
//         cin >> n;
//         sv.resize(n);

//         for (int i = 0; i < sv.size(); i++)
//         {
//             sv[i].Nhap();
//         }
//     }

//     void xuat()
//     {
//         cout << "MSSV\tHoTen\tdiemCTMT\tdiemVDK\tdiemTrungBinh\n";

//         for (int i = 0; i < sv.size(); i++)
//         {
//             sv[i].Xuat();
//         }
//     }

//     void inMenu()
//     {
//         int opt;

//         do
//         {
//             cout << "\n\n1. Nhap thong tin sinh vien\n";
//             cout << "2. Xuat thong tin sinh vien\n";
//             cout << "0. Thoat chuong trinh\n";
//             cout << "Nhap lua chon: ";
//             cin >> opt;

//             switch (opt)
//             {
//             case 1:
//                 nhap();
//                 break;
//             case 2:
//                 xuat();
//                 break;
//             }
//         } while (opt != 0);
//     }
// };

// int main()
// {
//     MENU menu1;
//     menu1.inMenu();
// }

int main()
{
    SinhVien TunNom;
    TunNom.Nhap();
    TunNom.set_diemTKLG(9);
    cout << "Diem trung binh: " << TunNom.get_diemTrungBinh();
}