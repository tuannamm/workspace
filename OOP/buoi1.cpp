#include <iostream>
using namespace std;

int main()
{

    // Nhap
    // int x;
    // cout << "Nhap x: ";
    // cin >> dec >> x;
    // cin >> oct >> x;
    // cin >> hex >> x;

    // // Gan
    int x = 10;  // thap phan
    int x = 012; // bat phan
    int x = 0xa; // thap luc phan

    // Xuat
    cout << "\nGia tri thap phan: " << dec << x;
    cout << "\nGia tri bat phan: " << oct << x;
    cout << "\nGia tri thap luc phan: " << hex << x;

    cout << "\n\n\n";
    system("pause");
}