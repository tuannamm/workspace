#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    // int x ; // biến tĩnh
    // int *px;
    // px = &x;
    // cout << "Gia tri x = " << x;
    // cout << "\nDia chi bien x = " << px;
    // cout << "\nGia tri x = " << *px;

    // *px = 20;
    // cout << "\nGia tri x sau khi thay doi = " << *px;

    // phép toán liên quan đến con trỏ
    int value = 5;
    int *ptr = &value;
    cout << ptr;
    cout << "\n"
         << *ptr;

    int arr[] = {5, 6, 7, 8};
    cout << "\nElement 0 is at address: " << &arr[0] << "\n";
    cout << "Element 1 is at address: " << &arr[1] << "\n";
    cout << "Element 2 is at address: " << &arr[2] << "\n";
    cout << "Element 3 is at address: " << &arr[3] << "\n";

    cout << &arr[1] << "\n"; // địa chỉ vùng nhớ phần tử 1
    cout << arr + 1 << "\n"; // địa chỉ vùng nhớ phần tử 1

    cout << arr[1] << "\n";     // 5
    cout << *(arr + 1) << "\n"; // 5
}
