/* Xây dựng lớp sinh viên có các thuộc tính sau:
1. MSSV
2. Họ tên
3. Điểm môn Thiết kế logic
4. Điểm môn Vi điều khiển
5. Điểm môn Kiến trúc máy tính
6. Điểm trung bình = trung bình 3 môn (có thể bỏ qua thuộc tính này)
Lớp sinh viên sẽ có phương thức cơ bản sau: nhập, xuất, tính điểm trung bình .
Sử dụng thư viện “vector”, viết chương trình tạo mảng 1 chiều gồm các sinh viên
có thông tin chi tiết như bảng bên dưới.

MSSV Họ và tên TKLG VĐK KTMT ĐTB
1     Tran A    10   9    4  7.67
2     Van B      5   1    3  3.00
3     Thi C    9.5  10  8.5  9.33
4     Nguyen D   4   5    2  3.67
5     Dang E     1   3    4  2.67

Câu 1
Sắp xếp danh sách sinh viên theo điểm trung bình từ cao xuống thấp.

Câu 2
Sắp xếp danh sách sinh viên theo điểm Thiết kế logic từ thấp đến cao.

Câu 3
Tìm những sinh viên rớt từ 2 môn trở lên.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SINHVIEN
{
private:
    int MSSV;
    string HoTen;
    float diemTKLG;
    float diemVDK;
    float diemCTMT;
    float diemTrungBinh = (diemTKLG + diemVDK + diemCTMT) / 3;

protected:
public:
    float tinhDiemTrungBinh()
    {
        return (diemTKLG + diemVDK + diemCTMT) / 3;
    }

    float get_tinhDiemTrungBinh()
    {
        return tinhDiemTrungBinh();
    }

    void Nhap()
    {
        cout << "\nNhap MSSV: ";
        cin >> MSSV;
        cout << "Nhap ho va ten: ";
        cin >> HoTen;
        cin.ignore();
        cout << "Nhap diem TKLG: ";
        cin >> diemTKLG;
        cout << "Nhap diem VDK: ";
        cin >> diemVDK;
        cout << "Nhap diem CTMT: ";
        cin >> diemCTMT;
    }

    void Xuat()
    {
        cout << MSSV << "\t";
        cout << HoTen << "\t\t";
        cout << diemTKLG << "\t";
        cout << diemVDK << "\t";
        cout << diemCTMT << "\t";
        cout << tinhDiemTrungBinh() << "\n";
    }

    friend istream &operator>>(istream &is, SINHVIEN &sv);
    friend ostream &operator<<(ostream &os, SINHVIEN &sv);
};
istream &operator>>(istream &is, SINHVIEN &sv)
{
    sv.Nhap();
    return is;
}

ostream &operator<<(ostream &os, SINHVIEN &sv)
{
    sv.Xuat();
    return os;
}

class MENU
{
private:
    int n;
    vector<SINHVIEN> sv;
    struct DTBGiam_key
    {
        inline bool operator()(SINHVIEN *sv1, SINHVIEN *sv2)
        {
            return (sv1->get_tinhDiemTrungBinh() > sv2->get_tinhDiemTrungBinh());
        }
    };

protected:
public:
    void nhap()
    {
        cout << "\nNhap so sinh vien: ";
        cin >> n;
        sv.resize(n);

        for (int i = 0; i < sv.size(); i++)
            sv[i].Nhap();
    }

    void xuat()
    {
        cout << "MSSV\tHọ và tên\tTKLG\tVĐK\tKTMT\tĐTB\n";
        for (int i = 0; i < sv.size(); i++)
            sv[i].Xuat();
    }

    void sapXepDTBGiam()
    {
        cout << "\nSap xep danh sach sinh vien theo Luong giam dan:";
        sort(sv.begin(), sv.end(), DTBGiam_key());
        xuat();
    }

    void SapXepDiemTKLG()
    {
    }

    void inMenu()
    {
        int opt;

        do
        {
            cout << "\n1. Nhap thong tin sinh vien\n";
            cout << "2. Xuat thong tin sinh vien\n";
            cout << "3. Sap xep sinh vien theo diem trung binh tu cao xuong thap\n";
            cout << "4. Sap xep sinh vien theo diem TKLG tu thap den cao\n";
            cout << "5. Xuat sinh vien rot tu 2 mon tro len\n";
            cout << "0. Thoat chuong trinh\n";
            cout << "\nNhap lua chon: ";
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
                sapXepDTBGiam();
                break;
            case 4:
                SapXepDiemTKLG();
                break;
            }
        } while (opt != 0);
    }
};

int main()
{
    MENU menu1;
    menu1.inMenu();
}
