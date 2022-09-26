/*
Mảng động sử dụng thư viện <vector>
size();	//trả về kích cỡ hiện tại của mảng
resize(n);	//điều chỉnh kích cỡ mảng với n phần tử
push_back(<tên biến/giá trị>); //thêm phần tử vào cuối mảng
pop_back();	//xóa phần tử cuối mảng
clear();	//xóa tất cả phần tử trong mảng
max_size()	//trả về số phần tử tối đa
front();	//lấy phần tử đầu tiên của mảng
back();		//lấy phần tử cuối cùng của mảng
begin();	//con trỏ đầu mảng
end();		//con trỏ cuối mảng
insert(<vị trí con trỏ>,<giá trị>); //chèn phần tử
erase(<vị trí con trỏ>); 			//xóa phần tử
erase(<vị trí đầu>,<vị trí cuối>); 	//xóa phần tử
swap(<vector>)						//hoán đổi giá trị 2 mảng
*/

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> a; // khai báo mảng động a có kiểu dữ liệu int
    cout << "Nhap so phan tu: ";
    cin >> n;
    a.resize(n); // cấp phát

    for (int i = 0; i < a.size(); i++)
        a[i] = i + 1;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";

    a.insert(a.begin(), 99); // chèn số 99 vào vị trí đầu tiên
    cout << "\nSau khi chen:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";

    a.insert(a.begin() + 3, 99); // chèn số 99 vào vị trí thứ 3
    cout << "\nSau khi chen:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";

    a.insert(a.end(), 55); // chèn số 55 vào vị trí cuối
    cout << "\nSau khi chen:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";

    a.erase(a.end() - 1); // xoá phần tử cuối
    cout << "\nSau khi xoa:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";

    a.erase(a.begin() + 2, a.begin() + 4);
    cout << "\nSau khi xoa:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";
}
