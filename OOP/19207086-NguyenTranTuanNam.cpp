#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class NHANVIEN
{
private:
protected:
    string HoTen;
    float LuongThang;
    static int soLuong;

public:
    NHANVIEN()
    {
        soLuong++;
    }

    NHANVIEN(string hoten)
    {
        soLuong++;
        this->HoTen = hoten;
    }

    ~NHANVIEN()
    {
        soLuong--;
    }

    float get_LuongThang()
    {
        return LuongThang;
    }

    string getHoTen()
    {
        return HoTen;
    }

    void setHoTen(string hoten)
    {
        this->HoTen = hoten;
    }

    virtual void nhap()
    {
        cout << "\nNhap Ho ten: ";
        cin.ignore();
        getline(cin, HoTen);
    }

    virtual void xuat() const
    {
        cout << HoTen << "\t";
        cout << LuongThang << "\n";
    }

    virtual void chinh()
    {
        string Hoten;
        cout << "\nNhap Ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        setHoTen(Hoten);
    }

    static int getSoLuong()
    {
        return soLuong;
    }

    void NhapFile(ifstream &file)
    {
        getline(file, HoTen, '\t');
        file >> LuongThang;
    }

    void XuatFile(ofstream &file)
    {
        file << HoTen << "\t";
        file << LuongThang;
    }

    friend istream &operator>>(istream &is, NHANVIEN &sv);
    friend ostream &operator<<(ostream &os, NHANVIEN &sv);
};
istream &operator>>(istream &is, NHANVIEN &sv)
{
    sv.nhap();
    return is;
}

ostream &operator<<(ostream &os, NHANVIEN &sv)
{
    sv.xuat();
    return os;
}

class VANPHONG : public NHANVIEN
{
private:
    int HeSo;

protected:
public:
    VANPHONG(string HoTen, int HeSo) : NHANVIEN(HoTen)
    {
        this->HeSo = HeSo;
        LuongThang = 1000000 * HeSo;
    }
    VANPHONG() {}
    void nhap()
    {
        NHANVIEN::nhap();
        cout << "\nNhap he so: ";
        cin >> HeSo;
        LuongThang = 1000000 * HeSo;
    }

    void xuat() const
    {
        cout << setw(20) << HoTen;
        cout << setw(10) << fixed << setprecision(2) << LuongThang;
    }

    void setHeSo(int heso)
    {
        HeSo = heso;
    }

    void chinh()
    {
        NHANVIEN::chinh();
        float HeSo;
        cout << "\nNhap he so: ";
        cin >> HeSo;
        setHeSo(HeSo);
        LuongThang = 1000000 * HeSo;
    }
};

class LAPTRINHVIEN : public NHANVIEN
{
private:
    int SoPhanMem;

protected:
public:
    LAPTRINHVIEN(string HoTen, int SoPhanMem) : NHANVIEN(HoTen)
    {
        this->SoPhanMem = SoPhanMem;
        LuongThang = 5000000 * SoPhanMem;
    }
    LAPTRINHVIEN()
    {
    }
    void nhap()
    {
        NHANVIEN::nhap();
        cout << "\nNhap so phan mem: ";
        cin >> SoPhanMem;
        LuongThang = 5000000 * SoPhanMem;
    }
    void xuat() const
    {
        ;
        cout << setw(20) << HoTen;
        cout << setw(10) << fixed << setprecision(2) << LuongThang;
    }
    void setSoPhanMem(int sophanmem)
    {
        SoPhanMem = sophanmem;
    }

    void chinh()
    {
        NHANVIEN::chinh();
        int SoPhanMem;
        cout << "\nNhap so phan mem: ";
        cin >> SoPhanMem;
        setSoPhanMem(SoPhanMem);
        LuongThang = 5000000 * SoPhanMem;
    }
};

class PHUCVU : public NHANVIEN
{
private:
    float Thuong;

protected:
public:
    PHUCVU(string HoTen, float thuong) : NHANVIEN(HoTen)
    {
        this->Thuong = thuong;
        LuongThang = 3000000 + Thuong;
    }
    PHUCVU()
    {
    }
    void nhap()
    {
        NHANVIEN::nhap();
        cout << "\nNhap tien thuong: ";
        cin >> Thuong;
        LuongThang = 3000000 + Thuong;
    }
    void xuat() const
    {
        cout << HoTen << "\t";
        cout << LuongThang << "\n";
    }
    void setThuong(float thuong)
    {
        Thuong = thuong;
    }
    void chinh()
    {
        NHANVIEN::chinh();
        float Thuong;
        cout << "\nNhap so tien thuong: ";
        cin >> Thuong;
        setThuong(Thuong);
        LuongThang = 3000000 + Thuong;
    }
};

class MENU
{
private:
    vector<NHANVIEN *> dsNV;
    int n, m, p;
    int option;
    struct LuongGiam_key
    {
        inline bool operator()(NHANVIEN *nv1, NHANVIEN *nv2)
        {
            return (nv1->get_LuongThang() > nv2->get_LuongThang());
        }
    };

public:
    MENU()
    {
        dsNV.push_back(new VANPHONG("Tran A", 9));
        dsNV.push_back(new VANPHONG("Van B", 12));
        dsNV.push_back(new LAPTRINHVIEN("Thi C", 2));
        dsNV.push_back(new PHUCVU("Nguyen D", 2000000));
    }
    void menuClear()
    {
        for (int i = 0; i < dsNV.size(); i++)
        {
            delete dsNV[i];
        }
        dsNV.clear();
    }

    ~MENU()
    {
        menuClear();
    }

    void nhapDSNV()
    {
        cout << "\nNhap so nhan vien VP: ";
        cin >> n;
        cout << "\nNhap so nhan vien LTV: ";
        cin >> m;
        cout << "\nNhap so nhan vien PV: ";
        cin >> p;
        dsNV.resize(n + m + p);
        cout << "\nNhap danh sach nhan vien VP:";
        for (int i = 0; i < n; i++)
        {
            cout << "\nNhan vien [" << i << "]:";
            dsNV[i] = new VANPHONG();
            cin >> *dsNV[i];
        }

        cout << "\nNhap danh sach nhan vien LTV:";
        for (int i = 0; i < m; i++)
        {
            cout << "\nNhan vien [" << i << "]:";
            dsNV[i] = new LAPTRINHVIEN();
            cin >> *dsNV[i];
        }

        cout << "\nNhap danh sach nhan vien PV:";
        for (int i = 0; i < p; i++)
        {
            cout << "\nNhan vien [" << i << "]:";
            dsNV[i] = new PHUCVU();
            cin >> *dsNV[i];
        }
    }

    void xuatTitle()
    {
        string title[] = {"Hoten", "LuongThang"};
        int margin[11] = {10, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        cout << "\n";
        for (int i = 0; i < 11; i++)
        {
            cout << setw(margin[i]) << left << title[i];
        }
        // cout << "\n";
    }

    void xuatDSNV()
    {
        xuatTitle();
        for (int i = 0; i < dsNV.size(); i++)
        {
            cout << *dsNV[i];
        }
    }

    void chinhNV()
    {
        string HoTen;
        cout << "\nNhap ho ten can chinh thong tin:";
        getline(cin, HoTen);
        for (int i = 0; i < dsNV.size(); i++)
        {
            if (dsNV[i]->getHoTen() == HoTen)
            {
                cout << "\nChinh sua thong tin nhan vien:";
                (*dsNV[i]).chinh();
                xuatDSNV();
                return;
            }
        }
        cout << "\nKhong tim thay sinh vien";
    }

    void themNV()
    {
        int loai;
        cout << "\nLua chon loai nhan vien:";
        cout << "\n1. Nhan vien VP";
        cout << "\n2. Nhan vien LTV";
        cout << "\n3. Nhan vien PV";
        cout << "\nNhap lua chon: ";
        cin >> loai;
        NHANVIEN *nv;
        switch (loai)
        {
        case 1:
            nv = new VANPHONG;
            (*nv).nhap();
            dsNV.push_back(nv);
            break;
        case 2:
            nv = new LAPTRINHVIEN;
            (*nv).nhap();
            dsNV.push_back(nv);
            break;
        case 3:
            nv = new PHUCVU;
            (*nv).nhap();
            dsNV.push_back(nv);
            break;
        default:
            cout << "\nLoai khong hop le";
            break;
        }
        xuatDSNV();
    }

    void timNVMaxMin()
    {
        float max = dsNV[0]->get_LuongThang(), min = dsNV[0]->get_LuongThang();
        for (int i = 1; i < dsNV.size(); i++)
        {
            if (dsNV[i]->get_LuongThang() > max)
                max = dsNV[i]->get_LuongThang();
            if (dsNV[i]->get_LuongThang() < min)
                min = dsNV[i]->get_LuongThang();
        }
        cout << "\nNhan vien co luong thang cao nhat:";
        xuatTitle();
        for (int i = 0; i < dsNV.size(); i++)
        {
            if (dsNV[i]->get_LuongThang() == max)
                cout << *dsNV[i];
        }
        cout << "\nNhan vien co luong thang thap nhat:";
        xuatTitle();
        for (int i = 0; i < dsNV.size(); i++)
        {
            if (dsNV[i]->get_LuongThang() == min)
                cout << *dsNV[i];
        }
    }

    void sapXepLuongGiam()
    {
        cout << "\nSap xep danh sach sinh vien theo Luong giam dan:";
        sort(dsNV.begin(), dsNV.end(), LuongGiam_key());
        xuatDSNV();
    }

    void menuDeleteOneEle(int position)
    {
        delete dsNV[position];
        dsNV.erase(dsNV.begin() + position);
    }

    void xoaNV()
    {
        string HoTen;
        cout << "\nNhap ho ten can xoa thong tin:";
        getline(cin, HoTen);
        for (int i = 0; i < dsNV.size(); i++)
        {
            if (dsNV[i]->getHoTen() == HoTen)
            {
                menuDeleteOneEle(i);
                xuatDSNV();
                return;
            }
        }
        cout << "\nKhong tim thay nhan vien";
    }

    // void GhiFile()
    // {
    //     ofstream file;
    //     file.open("/Users/nguyentrantuannam/Desktop/test.txt");
    //     if (file.is_open())
    //     {
    //         file << "So luong nhan vien " << dsNV.size() << "\n";
    //         file << "Hoten\tLuongThang";
    //         {
    //             dsNV[i].XuatFile(file);
    //         }
    //     }
    //     file.close();
    // }

    void in()
    {
        cout << "\n\n1. Nhap danh sach nhan vien";
        cout << "\n2. Xuat danh sach nhan vien";
        cout << "\n3. Chinh sua thong tin 1 nhan vien";
        cout << "\n4. Chen thong tin 1 nhan vien vao danh sach";
        cout << "\n5. Tim kiem nhan vien co luong thang cao nhat/thap nhat";
        cout << "\n6. Sap xep danh sach theo gia tri luong thang giam dan";
        cout << "\n7. Xoa thong tin nhan vien bat ky trong danh sach";
        cout << "\n8. Ghi danh sach vao file";
        cout << "\n0. Thoat chuong trinh!";

        cout << "\nNhap lua chon: ";
        cin >> option;
        switch (option)
        {
        case 1:
            nhapDSNV();
            break;
        case 2:
            xuatDSNV();
            break;
        case 3:
            chinhNV();
            break;
        case 4:
            themNV();
            break;
        case 5:
            timNVMaxMin();
            break;
        case 6:
            sapXepLuongGiam();
            break;
        case 7:
            xoaNV();
            break;
        case 8:

        default:
            cout << "\nLua chon khong hop le!!!";
            break;
        }
    }

    void inMenu()
    {
        do
        {
            system("cls");
            cout << "So luong nhan vien: " << NHANVIEN::getSoLuong();
            in();
            cout << "\n\n\n";
            system("pause");
        } while (option);
    }
};
int NHANVIEN::soLuong = 0;
int main()
{
    MENU congtyTuanNam;
    congtyTuanNam.inMenu();
}
