/*
Tính trừu tượng (abstraction): thể hiện thế giới thực, bỏ qua sự phức tạp bằng cách chỉ ra thuộc tính
và phuơng thức cần thiết của dối tượng. Nó còn thể hiện ở lớp trừu tượng chứa các phương thức thuần ảo.
--> Xây dựng thuộc tính và phương thức cho lớp

Tính đóng gói (encapsulation): bảo vệ dữ liệu che giấu thông tin. Thể hiện thông qua phạm vi truy cập.
Chỉ có phương thức bên trong lớp mới được thay đổi thuộc tính của lớp.
public
private
protected
*/

/*
Viết chương trình tính chu vi, diện tích hình chữ nhật tên đối tượng hcn1 thuộc lớp HinhChuNhat
*/

#include <iostream>
using namespace std;

// class HinhChuNhat
// {
//     private: // 2 thuộc tính
//         int Dai;
//         int Rong;

//     public: // 4 phương thức
//         int TinhChuVi()
//         {
//             return (Dai + Rong ) * 2;
//         }

//         int TinhDienTich()
//         {
//             return Dai * Rong;
//         }

//         void Nhap()
//         {
//             cout << "Nhap chieu dai: ";
//             cin >> Dai;
//             cout << "Nhap chieu rong: ";
//             cin >> Rong;
//         }

//         void Xuat()
//         {
//             cout << "\nChu vi = " << TinhChuVi();
//             cout << "\nDien tich = " << TinhDienTich();
//         }
// };

// int main() {
//     HinhChuNhat hcn1; // đối tượng hcn1 thuộc lớp HinhChuNhat
//     hcn1.Nhap();
//     hcn1.Xuat();

//     cout << "\n\n\n";
//     system("pause");
// }

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
    HinhChuNhat hcn1;
    hcn1.Nhap();
    hcn1.Xuat();

    cout << "\n\n\n";
    system("pause");
}