/*
Viết chương trình tạo mảng 1 chiều gồm các số nguyên ngẫu nhiên từ 0 -> 99 với n phần tử
1. Tìm và xoá phần tử có giá trị nhỏ nhất và giá trị lớn nhất ra khỏi mảng.
2. Tìm và xoá số lẻ ra khỏi mảng và thay bằng số chẵn ngẫu nhiên từ 0-> 99 tại vị trí tương ứng
3. Sắp xếp mảng tăng dần
*/

#include <iostream>
#include <ctime>
#include <vector>
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

    cout << "Mang ngau nhien\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << "Phan tu thu" << i << ":"
             << " " << a[i] << "\n";
    }

    int min = 0, max = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > a[max])
            max = i;
        if (a[i] < a[min])
            min = i;
    }

    a.erase(a.begin() + min);
    a.erase(a.begin() + max);
    cout << "\nMang sau khi xoa:\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }

    int temp, x, y;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    cout << "\nSap xep mang tang dan:\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }
}