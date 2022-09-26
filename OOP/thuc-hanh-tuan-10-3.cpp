#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class SinhVien
{
private:
protected:
    int MSSV;
    string Hoten;
    float TKLG, VDK, KTMT, DTB;
    static int siSo;

public:
    SinhVien()
    {
        siSo++;
    }
    SinhVien(int MSSV, string Hoten, float TKLG, float VDK, float KTMT)
    {
        siSo++;
        this->MSSV = MSSV;
        this->Hoten = Hoten;
        this->TKLG = TKLG;
        this->VDK = VDK;
        this->KTMT = KTMT;
        DTB = (TKLG + VDK + KTMT) / 3;
    }
    ~SinhVien()
    {
        siSo--;
    }
    int getMSSV()
    {
        return MSSV;
    }
    float get_diemTrungBinh()
    {
        return DTB;
    }
    float getTKLG()
    {
        return TKLG;
    }
    float getVDK()
    {
        return VDK;
    }
    float getKTMT()
    {
        return KTMT;
    }
    void setMSSV(int MSSV)
    {
        this->MSSV = MSSV;
    }
    void setHoTen(string Hoten)
    {
        this->Hoten = Hoten;
    }
    void setTKLG(float diem)
    {
        TKLG = diem;
    }
    void setVDK(float diem)
    {
        VDK = diem;
    }
    void setKTMT(float diem)
    {
        KTMT = diem;
    }
    virtual void nhap()
    {
        cout << "\nNhap MSSV: ";
        cin >> MSSV;
        cout << "\nNhap Ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        cout << "\nNhap diem Thiet ke logic: ";
        cin >> TKLG;
        cout << "\nNhap diem Vi dieu khien: ";
        cin >> VDK;
        cout << "\nNhap diem Kien truc may tinh: ";
        cin >> KTMT;
        DTB = (TKLG + VDK + KTMT) / 3;
    }
    virtual void xuat() const
    {
        cout << "\n"
             << setw(10) << left << MSSV;
        cout << setw(20) << Hoten;
        cout << setw(10) << fixed << setprecision(2) << TKLG;
        cout << setw(10) << fixed << setprecision(2) << VDK;
        cout << setw(10) << fixed << setprecision(2) << KTMT;
        cout << setw(10) << fixed << setprecision(2) << DTB;
    }
    virtual void chinh()
    {
        int MSSV;
        string Hoten;
        float TKLG, VDK, KTMT;
        cout << "\nNhap MSSV: ";
        cin >> MSSV;
        setMSSV(MSSV);
        cout << "\nNhap Ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        setHoTen(Hoten);
        cout << "\nNhap diem Thiet ke logic: ";
        cin >> TKLG;
        setTKLG(TKLG);
        cout << "\nNhap diem Vi dieu khien: ";
        cin >> VDK;
        setVDK(VDK);
        cout << "\nNhap diem Kien truc may tinh: ";
        cin >> KTMT;
        setKTMT(KTMT);
        DTB = (TKLG + VDK + KTMT) / 3;
    }
    static int getSiSo()
    {
        return siSo;
    }
    void nhapFile(ifstream &file)
    {
        file >> MSSV;
        file.ignore(); // Read string.
        getline(file, Hoten, '\t');
        file >> TKLG;
        file >> VDK;
        file >> KTMT;
        file >> DTB;
    }
    void xuatFile(ofstream &file)
    {
        file << MSSV << "\t";
        file << Hoten << "\t";
        file << TKLG << "\t";
        file << VDK << "\t";
        file << KTMT << "\t";
        file << DTB << "\n";
    }
    friend istream &operator>>(istream &is, SinhVien &sv);
    friend ostream &operator<<(ostream &os, SinhVien &sv);
};
istream &operator>>(istream &is, SinhVien &sv)
{
    sv.nhap();
    return is;
}

ostream &operator<<(ostream &os, SinhVien &sv)
{
    sv.xuat();
    return os;
}

class SinhVienCLC : public SinhVien
{
private:
    float LTHDT, DSP, DCS, DTB;

protected:
public:
    SinhVienCLC(int MSSV, string Hoten, float TKLG, float VDK, float KTMT, float LTHDT, float DSP, float DCS) : SinhVien(MSSV, Hoten, TKLG, VDK, KTMT)
    {
        this->LTHDT = LTHDT;
        this->DSP = DSP;
        this->DCS = DCS;
        DTB = (TKLG + VDK + KTMT + LTHDT + DSP + DCS) / 6;
    }
    SinhVienCLC() {}
    void nhap()
    {
        SinhVien::nhap();
        cout << "\nNhap diem LT HDT: ";
        cin >> LTHDT;
        cout << "\nNhap diem DSP: ";
        cin >> DSP;
        cout << "\nNhap diem DCS: ";
        cin >> DCS;
        DTB = (TKLG + VDK + KTMT + LTHDT + DSP + DCS) / 6;
    }
    void xuat() const
    {
        cout << "\n"
             << setw(10) << left << MSSV;
        cout << setw(20) << Hoten;
        cout << setw(10) << fixed << setprecision(2) << TKLG;
        cout << setw(10) << fixed << setprecision(2) << VDK;
        cout << setw(10) << fixed << setprecision(2) << KTMT;
        cout << setw(10) << fixed << setprecision(2) << LTHDT;
        cout << setw(10) << fixed << setprecision(2) << DSP;
        cout << setw(10) << fixed << setprecision(2) << DCS;
        cout << setw(10) << "";
        cout << setw(10) << "";
        cout << setw(10) << fixed << setprecision(2) << DTB;
    }
    void setLTHDT(float diem)
    {
        LTHDT = diem;
    }
    void setDSP(float diem)
    {
        DSP = diem;
    }
    void setDCS(float diem)
    {
        DCS = diem;
    }
    void chinh()
    {
        SinhVien::chinh();
        float LTHDT, DSP, DCS;
        cout << "\nNhap diem LTHDT: ";
        cin >> LTHDT;
        setLTHDT(LTHDT);
        cout << "\nNhap diem DSP: ";
        cin >> DSP;
        setDSP(DSP);
        cout << "\nNhap diem DCS: ";
        cin >> DCS;
        setDCS(DCS);
        DTB = (TKLG + VDK + KTMT + LTHDT + DSP + DCS) / 6;
    }
};

class SinhVienCQ : public SinhVien
{
private:
    float LTJAVA, CSDL, DTB;

protected:
public:
    SinhVienCQ(int MSSV, string Hoten, float TKLG, float VDK, float KTMT, float LTJAVA, float CSDL) : SinhVien(MSSV, Hoten, TKLG, VDK, KTMT)
    {
        this->LTJAVA = LTJAVA;
        this->CSDL = CSDL;
        DTB = (TKLG + VDK + KTMT + LTJAVA * 2 + 2 * CSDL) / 7;
    }
    SinhVienCQ()
    {
    }
    void nhap()
    {
        SinhVien::nhap();
        cout << "\nNhap diem LT JAVA: ";
        cin >> LTJAVA;
        cout << "\nNhap diem CSDL: ";
        cin >> CSDL;

        DTB = (TKLG + VDK + KTMT + LTJAVA * 2 + 2 * CSDL) / 7;
    }
    void xuat() const
    {
        cout << "\n"
             << setw(10) << left << MSSV;
        cout << setw(20) << Hoten;
        cout << setw(10) << fixed << setprecision(2) << TKLG;
        cout << setw(10) << fixed << setprecision(2) << VDK;
        cout << setw(10) << fixed << setprecision(2) << KTMT;
        cout << setw(10) << "";
        cout << setw(10) << "";
        cout << setw(10) << "";
        cout << setw(10) << fixed << setprecision(2) << LTJAVA;
        cout << setw(10) << fixed << setprecision(2) << CSDL;
        cout << setw(10) << fixed << setprecision(2) << DTB;
    }
    void setLTJAVA(float diem)
    {
        LTJAVA = diem;
    }
    void setCSDL(float diem)
    {
        CSDL = diem;
    }
    void chinh()
    {
        SinhVien::chinh();
        float LTJAVA, CSDL;
        cout << "\nNhap diem LTJAVA: ";
        cin >> LTJAVA;
        setLTJAVA(LTJAVA);
        cout << "\nNhap diem CSDL: ";
        cin >> CSDL;
        setCSDL(CSDL);
        DTB = (TKLG + VDK + KTMT + LTJAVA * 2 + 2 * CSDL) / 7;
    }
};

class Menu
{
private:
    vector<SinhVien *> dsSV;
    int n, m;
    int option;
    struct DTBGiam_key
    {
        inline bool operator()(SinhVien *sv1, SinhVien *sv2)
        {
            return (sv1->get_diemTrungBinh() > sv2->get_diemTrungBinh());
        }
    };
    struct MSSVTang_key
    {
        inline bool operator()(SinhVien *sv1, SinhVien *sv2)
        {
            return (sv1->getMSSV() < sv2->getMSSV());
        }
    };

public:
    Menu()
    {
        dsSV.push_back(new SinhVienCLC(1, "Tran A", 8, 9, 6, 5, 9, 5));
        dsSV.push_back(new SinhVienCLC(2, "Van B", 5, 1, 5, 7, 9, 5));
        dsSV.push_back(new SinhVienCLC(3, "Thi C", 9.5, 10, 8.5, 10, 9, 8));
        dsSV.push_back(new SinhVienCQ(4, "Nguyen D", 8, 9, 8, 9, 10));
        dsSV.push_back(new SinhVienCQ(5, "Dang E", 1, 3, 4, 5, 6));
    }
    void menuClear()
    {
        for (int i = 0; i < dsSV.size(); i++)
        {
            delete dsSV[i];
        }
        dsSV.clear();
    }
    ~Menu()
    {
        menuClear();
    }
    void nhapDSSV()
    {
        cout << "\nNhap so sinh vien CLC: ";
        cin >> n;
        cout << "\nNhap so sinh vien CQ: ";
        cin >> m;
        dsSV.resize(n + m);
        cout << "\nNhap DSSV CLC:";
        for (int i = 0; i < n; i++)
        {
            cout << "\nSinh vien [" << i << "]:";
            dsSV[i] = new SinhVienCLC();
            cin >> *dsSV[i];
        }

        cout << "\nNhap DSSV CQ:";
        for (int i = n; i < dsSV.size(); i++)
        {
            cout << "\nSinh vien [" << i << "]:";
            dsSV[i] = new SinhVienCQ();
            cin >> *dsSV[i];
        }
    }
    void xuatTitle()
    {
        string title[] = {"MSSV", "Hoten", "TKLG", "VDK", "KTMT", "LTHDT", "DSP", "TTS", "Java", "CSDL", "DTB"};
        int margin[11] = {10, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        cout << "\n";
        for (int i = 0; i < 11; i++)
        {
            cout << setw(margin[i]) << left << title[i];
        }
        // cout << "\n";
    }
    void xuatDSSV()
    {
        xuatTitle();
        for (int i = 0; i < dsSV.size(); i++)
        {
            cout << *dsSV[i];
        }
    }
    void chinhSV()
    {
        int MSSV;
        cout << "\nNhap MSSV can chinh thong tin:";
        cin >> MSSV;
        for (int i = 0; i < dsSV.size(); i++)
        {
            if (dsSV[i]->getMSSV() == MSSV)
            {
                cout << "\nChinh sua thong tin sinh vien:";
                (*dsSV[i]).chinh();
                xuatDSSV();
                return;
            }
        }
        cout << "\nKhong tim thay sinh vien";
    }
    void themSV()
    {
        int he;
        cout << "\nLua chon he:";
        cout << "\n1. SV CLC";
        cout << "\n2. SV CQ";
        cout << "\nNhap lua chon: ";
        cin >> he;
        SinhVien *sv;
        switch (he)
        {
        case 1:
            sv = new SinhVienCLC;
            (*sv).nhap();
            dsSV.push_back(sv);
            break;
        case 2:
            sv = new SinhVienCQ;
            (*sv).nhap();
            dsSV.push_back(sv);
            break;
        default:
            cout << "\nHe khong hop le";
            break;
        }
        xuatDSSV();
    }
    void timSVMaxMin()
    {
        float max = dsSV[0]->get_diemTrungBinh(), min = dsSV[0]->get_diemTrungBinh();
        for (int i = 1; i < dsSV.size(); i++)
        {
            if (dsSV[i]->get_diemTrungBinh() > max)
                max = dsSV[i]->get_diemTrungBinh();
            if (dsSV[i]->get_diemTrungBinh() < min)
                min = dsSV[i]->get_diemTrungBinh();
        }
        cout << "\nSinh vien co diem trung binh cao nhat:";
        xuatTitle();
        for (int i = 0; i < dsSV.size(); i++)
        {
            if (dsSV[i]->get_diemTrungBinh() == max)
                cout << *dsSV[i];
        }
        cout << "\nSinh vien co diem trung binh thap nhat:";
        xuatTitle();
        for (int i = 0; i < dsSV.size(); i++)
        {
            if (dsSV[i]->get_diemTrungBinh() == min)
                cout << *dsSV[i];
        }
    }
    void sapXepDTBGiam()
    {
        cout << "\nSap xep danh sach sinh vien theo DTB giam dan:";
        sort(dsSV.begin(), dsSV.end(), DTBGiam_key());
        xuatDSSV();
    }
    void sapXepMSSVTang()
    {
        cout << "\nSap xep danh sach sinh vien theo MSSV tang dan:";
        sort(dsSV.begin(), dsSV.end(), MSSVTang_key());
        xuatDSSV();
    }
    void menuDeleteOneEle(int position)
    {
        delete dsSV[position];
        dsSV.erase(dsSV.begin() + position);
    }
    void xoaSV()
    {
        int mssv;
        cout << "\nNhap MSSV can xoa thong tin:";
        cin >> mssv;
        for (int i = 0; i < dsSV.size(); i++)
        {
            if (dsSV[i]->getMSSV() == mssv)
            {
                menuDeleteOneEle(i);
                xuatDSSV();
                return;
            }
        }
        cout << "\nKhong tim thay sinh vien";
    }

    void in()
    {
        cout << "\nChon 1 trong cac lua chon sau:";
        cout << "\n1. Nhap danh sach sinh vien";
        cout << "\n2. Xuat danh sach dinh vien";
        cout << "\n3. Chinh sua thong tin 1 sinh vien";
        cout << "\n4. Them thong tin 1 sinh vien vao danh sach";
        cout << "\n5. Tim kiem sinh vien co DTB cao nhat/thap nhat";
        cout << "\n6. Sap xep danh sach theo gia tri DTB giam dan";
        cout << "\n7. Sap xep danh sach theo MSSV tang dan";
        cout << "\n8. Xoa thong tin 1 sinh vien trong danh sach";
        cout << "\n0. Thoat!";

        cout << "\nNhap lua chon: ";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            nhapDSSV();
            break;
        case 2:
            xuatDSSV();
            break;
        case 3:
            chinhSV();
            break;
        case 4:
            themSV();
            break;
        case 5:
            timSVMaxMin();
            break;
        case 6:
            sapXepDTBGiam();
            break;
        case 7:
            sapXepMSSVTang();
            break;
        case 8:
            xoaSV();
            break;

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
            cout << "Si so sinh vien: " << SinhVien::getSiSo();
            in();
            cout << "\n\n\n";
            system("pause");
        } while (option);
    }
};
int SinhVien::siSo = 0;
void main()
{
    Menu menu1;
    menu1.inMenu();
}
