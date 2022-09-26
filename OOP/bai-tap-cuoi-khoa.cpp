/*
Viết chương trình quản lý sinh viên
1. Xây dựng lớp sinh viên có các thuộc tính:
MSSV
Họ tên
Điểm môn Thiết kế logic
Điểm môn Vi điều khiển
Điểm môn Kiến trúc máy tính
Điểm trung bình = trung bình 3 môn


Quản lý sinh viên các hệ 

+ Xây dựng lớp sinh viên CLC có thêm các thuộc tính và phương thức sau:
Điểm môn Lập trình hướng đối tượng
Điểm môn DSP
Điểm môn Truyền thông số
Điểm trung bình = trung bình 6 môn


+ Xây dựng lớp sinh viên chính quy có thêm các thuộc tính và phương thức sau:
Điểm môn Lập trình Java
Điểm môn Cơ sở dữ liệu
Điểm trung bình (Java và Cơ sở dữ liệu hệ số 2)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SINHVIEN 
{
    private:
        int MSSV;
        string HoTen;
        float diemTKLG;
        float diemVDK;
        float diemKTMT;
        float diemTrungBinh;

    protected:

    public:
        
        void Nhap() {
            cout << "Nhap MSSV: ";
            cin >> MSSV;
            cout << "Nhap ten: ";
            getline(cin, HoTen);
            cout << "Nhap diem VDK: ";
            cin >> diemVDK;
            cout << "Nhap diem KTMT: ";
            cin >> diemKTMT;
        }

        void Xuat() {
            cout << MSSV << "\t";
            cout << HoTen << "\t";
            cout << diemTKLG << "\t";
            cout << diemVDK << "\t";
            cout << diemKTMT << "\t";
            cout << (diemTKLG + diemVDK + diemKTMT) / 3;
        }
        
};

class CLC: public SINHVIEN
{
    private:
        float diemOOP;
        float diemDSP;
        float diemTTS;
        float diemTrungBinh;

    protected:

    public:
        
    
};

class DAITRA: public SINHVIEN
{
    private:
        float diemLTJava;
        float diemCSDL;

    protected:

    public:
    
};

class DTVT {
    private:
        SINHVIEN *SinhVien[10];

    protected:
        
    public:
        DTVT() {
            for (int i = 0; i < 4; i++) SinhVien[i] = new CLC;
            for (int i = 5; i < 10; i++) SinhVien[i] = new DAITRA;
        }

        ~DTVT() {
            for (int i = 0; i < 9; i++) delete SinhVien[i];
        }

        void DiemDanh() {
            for (int i = 0; i < 9; i++) SinhVien[i] -> 
        }


};

int main() {

}