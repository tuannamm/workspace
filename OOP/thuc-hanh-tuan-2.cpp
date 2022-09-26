/*
Sử dụng thư viện “vector”, viết chương trình tạo mảng 1 chiều gồm các số nguyên
ngẫu nhiên từ 0 -> 99 có n phần tử với n được nhập từ bàn phím.
Câu 1
Tìm và xóa phần tử có giá trị nhỏ nhất và giá trị lớn nhất ra khỏi mảng.

Câu 2
Nhập một giá trị kèm vị trí từ bàn phím và chèn vào mảng.

Câu 3
Tìm và xóa số lẻ ra khỏi mảng và thay bằng số chẵn ngẫu nhiên từ 0 -> 99 tại vị trí
tương ứng.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    vector<int> a;
    cout << "Nhap so phan tu: ";
    cin >> n;
    a.resize(n);

    srand(time(0));
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = rand() % 100;
    }

    cout << "\nMang ngau nhien: \n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }

    // ----- Câu 1 -----
    int max = 0;
    int min = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > a[max])
            max = i;
        if (a[i] < a[min])
            min = i;
    }

    a.erase(a.begin() + max);
    a.erase(a.begin() + min);
    cout << "\nMang sau khi xoa: \n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }

    // ----- Câu 2 -----
    int value;
    int pos;
    cout << "\n\nNhap gia tri can them: ";
    cin >> value;
    cout << "Nhap vi tri: ";
    cin >> pos;
    a.insert(a.begin() + pos, value);
    cout << "Mang sau khi them gia tri: \n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }

    // ----- Câu 3 -----
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 != 0)
        {
            a.erase(a.begin() + i);
            a.insert(a.begin() + i, rand() % 100 % 2 == 0);
        }
    }
    cout << "\n\nMang sau khi xoa so le: \n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }
}
