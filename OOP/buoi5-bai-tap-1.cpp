#include <iostream>
using namespace std;

class HinhChuNhat
{
private:
    int Dai;
    int Rong;

public:
    int TinhChuVi()
    {
        return (Dai + Rong) * 2;
    }

    int TinhDienTich()
    {
        return Dai * Rong;
    }

    void Nhap()
    {
        cout << "Nhap chieu dai: ";
        cin >> Dai;
        cout << "Nhap chieu rong: ";
        cin >> Rong;
    }

    void Xuat()
    {
        cout << "\nChu vi = " << TinhChuVi();
        cout << "\nDien tich = " << TinhDienTich();
    }
};

int main()
{
    // HinhChuNhat hcn1;
    // hcn1.Nhap();
    // hcn1.Xuat();

    HinhChuNhat *pHCN;      // con trỏ lớp
    pHCN = new HinhChuNhat; // cấp phát vùng nhớ cho con trỏ
    pHCN->Nhap();
    pHCN->Xuat();
    delete pHCN; // xoá vùng nhớ mà con trỏ trỏ tới

    cout << "\n\n\n";
    system("pause");
}