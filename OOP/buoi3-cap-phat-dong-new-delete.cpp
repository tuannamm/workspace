#include <iostream>
using namespace std;

int main()
{
    // cấp phát động một số nguyên và gán địa chỉ cho con trỏ ptr nắm giữ
    // toán tử new tạo đối tượng sử dụng vùng nhớ đó và sau đó trả về một con trỏ chứa địa chỉ vùng nhớ đã được cấp phát

    // int *ptr = new int;
    // *ptr = 10; // int *ptr = new int(10);

    // delete ptr; // trả lại vùng nhớ ptr đang trỏ đén cho hệ điều hành
    // ptr = nullptr; // gán ptr thành con trỏ null

    // int x = 10; // biến tĩnh
    // int x[10]; // mảng tĩnh

    int *px = new int; // biến động
    *px = 10;

    cout << "Gia tri chua trong px = " << *px;
    cout << "\nDia chi con tro = " << px;

    delete px;
    cout << "\nGia tri chua trong px sau khi delete = " << *px << "\n";

    px = new int[10]; // mảng động
    for (int i = 0; i < 10; i++)
        px[i] = i + 1; // nhập
    for (int i = 0; i < 10; i++)
        cout << px[i] << "\t"; // xuẩt

    delete px;

    system("pause");
}