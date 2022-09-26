#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NHANVIEN
{
private:
protected:
public:
};

class VANPHONG : public NHANVIEN
{
private:
    float HeSoChucVu;

protected:
public:
    int tinhLuongThang()
    {
        return
    }
};

class LAPTRINHVIEN : public NHANVIEN
{
private:
protected:
public:
    v
};

class PHUCVU : public NHANVIEN
{
private:
protected:
public:
};

class CONGTY
{
private:
    NHANVIEN *staff[4];

protected:
public:
    CONGTY()
    {
        for (int i = 0; i < 2; i++)
            staff[i] = new VANPHONG;
        for (int i = 2; i < 3; i++)
            staff[i] = new LAPTRINHVIEN;
        for (int i = 3; i < 4; i++)
            staff[i] = new PHUCVU;
    }

    ~CONGTY()
    {
        for (int i = 0; i < 5; i++)
            delete staff[i];
    }

    void inMenu()
    {
        int opt;

        do
        {
            cout << "\n1. Nhap danh sach ";
            cout << "\n2. In danh sach";
            cout << "\n3. Chen them thong tin nhan vien";
            cout << "\n4. Xoa thong tin nhan vien";
            cout << "\n5. Tim trong"
        } while (opt != 0);
    }
};
