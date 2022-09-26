#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// int main() {
//     float dai, rong;
//     cout << "Nhap chieu dai: ";
//     cin >> dai;
//     cout << "Nhap chieu rong: ";
//     cin >> rong;

//     float dientich = dai * rong;
//     cout << "Dien tich: " << fixed << setprecision(2) << dientich;

//     cout <<"\n\n\n";
//     system("pause");
// }

// // Nhập xuất ký tự ASCII
// int main () {
//     char kyTu;
//     cout << "Nhap ky tu: ";
//     cin >> kyTu;

//     cout << "Ky tu vua nhap " << kyTu << "co ma ASCII la: " << (int) kyTu;

// }

// // String
// // Ghép chuỗi, trả về số ký tự
// int main() {
//     string ho, ten, hoTen;
//     cout << "Nhap ho: ";
//     getline(cin,  ho);
//     cout << "Nhap ten: ";
//     getline(cin, ten);
//     hoTen = ho + " " + ten;
//     cout << "Ho va ten: " << hoTen;

//     //length()
//     cout << "\nSo ky tu cua ten: " << hoTen.length();

//     //erase()
//     cout << "\nHo ten sau khi xoa: " << hoTen.erase(2,3);

//     //insert()
//     string tenDem = "Tun";
//     cout << "\nHo ten sau khi them ten dem: " << hoTen.insert(3, tenDem);

//     //substr()
//     string tenMoi = hoTen.substr(6,5);
//     cout << "\nHo ten moi la: " << tenMoi;

// }

// // Vẽ tam giác
// int main() {
//     int n;
//     cout << "Nhap dong: ";
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             cout << "*";
//         }
//         cout << "\n";
//     }
// }

int main()
{
    srand(time(0)); // khởi tạo cho hàm ngâũ nhiên

    for (int i = 0; i < 10; i++)
    {
        cout << rand() % 100 << "\t"; // số ngẫu nhiên từ 0 -> 99
    }
}