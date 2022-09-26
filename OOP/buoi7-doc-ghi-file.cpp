/* open : mở file
   is_open: kiểm tra đã mở được file -> đọc/ghi
   close : đóng file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    void XuatFile(ofstream &file)
    {
        file << MSSV << "\t";
        file << HoTen << "\t";
        file << diemCTMT << "\t";
        file << diemVDK << "\t";
        file << diemTKLG << "\t";
        file << (diemCTMT + diemVDK + diemTKLG) / 3 << "\n";
    }

    void NhapFile(ifstream &file)
    {
        file >> MSSV;
        file.ignore();
        getline(file, HoTen);
        file >> diemCTMT;
        file >> diemVDK;
        file >> diemTKLG;
        diemTrungBinh = (diemCTMT + diemVDK + diemTKLG) / 3;
    }
};

class MENU
{
private:
    int n;
    vector<SinhVien> sv;

public:
    void nhap()
    {
        cout << "\nNhap so sinh vien : ";
        cin >> n;
        sv.resize(n);

        for (int i = 0; i < sv.size(); i++)
        {
            sv[i].Nhap();
        }
    }

    void xuat()
    {
        cout << "MSSV\tHoTen\tdiemCTMT\tdiemVDK\tdiemTrungBinh\n";

        for (int i = 0; i < sv.size(); i++)
        {
            sv[i].Xuat();
        }
    }

    void GhiFile()
    {
        ofstream file;                                          // khai báo file
        file.open("/Users/nguyentrantuannam/Desktop/test.txt"); // đường đãn lưu file
        if (file.is_open())
        {
            file << "Si so lop: " << sv.size() << "\n"; // ghi si so lop
            file << "MSSV\tHoten\tdiemCTMT\tdiemVDK\tdiemTKLG\tdiemTrungBinh\n";
            for (int i = 0; i < sv.size(); i++)
            {
                sv[i].XuatFile(file);
            }
        }
        file.close();
    }

    void DocFile()
    {
        ifstream file; // khai bao
        int n;
        file.open("/Users/nguyentrantuannam/Desktop/test.txt"); // đường dẫn mở file
        if (file.is_open())
        {
            file >> n;
            sv.resize(n);
            for (int i = 0; i < sv.size(); i++)
                sv[i].NhapFile(file);
        }
        file.close();
    }

    void inMenu()
    {
        int opt;

        do
        {
            cout << "\n\n1. Nhap thong tin sinh vien\n";
            cout << "2. Xuat thong tin sinh vien\n";
            cout << "3. Ghi danh sach sinh vien ra file ds.txt\n";
            cout << "4. Doc danh sach sinh vien tu file ds.txt\n";
            cout << "0. Thoat chuong trinh\n";
            cout << "Nhap lua chon: ";
            cin >> opt;

            switch (opt)
            {
            case 1:
                nhap();
                break;
            case 2:
                xuat();
                break;
            case 3:
                GhiFile();
                break;
            case 4:
                DocFile();
                break;
            }
        } while (opt != 0);
    }
};

int main()
{
    MENU menu1;
    menu1.inMenu();

    cout << "\n\n\n";
    system("pause");
}
