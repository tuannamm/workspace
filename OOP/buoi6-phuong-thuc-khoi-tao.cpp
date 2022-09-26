/* Taọ các thuộc tính có giá trị sẵn --> sử dụng phương thức khởi tạo */
/* Phương thức khởi tạo có tên phương thức trùng với tên lớp và không có kiểu dữ liệu trả về */

#include <iostream>
using namespace std;

class SinhVien
{
private:
    int MSSV;
    string HoTen;
    float diemTKLG;
    float diemVDK;
    float diemCTMT;
    float diemTrungBinh;

public:
    SinhVien() // phương thức khởi tạo KHÔNG tham số
    {
        MSSV = 0;
        HoTen = "";
        diemTKLG = -1;
        diemVDK = -1;
        diemCTMT = -1;
        diemTrungBinh = -1;
    }

    SinhVien(int mssv, string ten, float TKLG, float VDK, float CTMT) // phương thức khởi tạo CÓ tham số
    {
        MSSV = mssv;
        HoTen = ten;
        diemTKLG = TKLG;
        diemVDK = VDK;
        diemCTMT = CTMT;
        diemTrungBinh = (diemTKLG + diemVDK + diemCTMT) / 3;
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
        cout << diemTrungBinh << "\n";
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

int main()
{

    // // Cách 1: Khai báo đối tượng
    // SinhVien TuanNam;
    // TuanNam.Xuat(); // có phương thức khởi tạo rồi thì không cần phương thức nhập nữa

    // // // Cách 2: Cấp phát bộ nhớ cho con trỏ
    // // SinhVien *pTuanNam;
    // // pTuanNam = new SinhVien;
    // // pTuanNam->Xuat();
    // // delete pTuanNam;

    // Sử dụng nạp chồng phương thức
    SinhVien TuanNam(1, "TuanNam", 10, 10, 10);
    SinhVien TunNom(2, "TunNom", 10, 10, 10);

    TuanNam.Xuat();
    TunNom.Xuat();
}