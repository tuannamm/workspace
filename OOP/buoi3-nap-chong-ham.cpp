// Nạp chồng hàm - Function Overloading
// Nạp chồng hàm dùng để định nghĩa hàm theo nhiều kiểu dữ liêu đầu vào và số lượng tham số đầu vào khác nhau
#include <iostream>
using namespace std;

// hàm tìm giá trị lớn nhất của 2 số nguyên
int timMax(int x, int y)
{
    if (x > y)
        return x;
    if (y > x)
        return y;
    if (x == y)
        return x;
}

// hàm tìm giá trị lớn nhất của 2 số thực
float timMax(float x, float y)
{
    if (x > y)
        return x;
    if (y > x)
        return y;
    if (x == y)
        return x;
}

// hàm tính tổng 2 số nguyên
int tinhTong(int a, int b)
{
    return a + b;
}

// hàm tính tổng 4 số nguyên
int tinhTong(int a, int b, int c, int d)
{
    return a + b + c + d;
}
int main()
{
    // int a =  10;
    // int b = 20;
    // cout << timMax(a, b);

    // float x = 10.2;
    // float y = 10.3;
    // cout << "\n" << timMax(x, y);

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    cout << "Tong 2 so nguyen: " << tinhTong(a, b);
    cout << "\n Tong 4 so nguyen: " << tinhTong(a, b, c, d);
    system("pause");
}