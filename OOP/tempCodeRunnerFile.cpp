/* Tính đa hình: thì các đối tượng khác nhau thuộc các lớp khác nhau phản ứng với cùng một phương thức 
theo những cách khác nhau
Mục đích: trộn những đối tượng khác nhau thuộc các lớp khác nhau vào chung một mảng
Điều kiện: 
    1. Kế thừa
    2. Phương thức ảo/thuần ảo (virtual / pure virtual)
    3. Con trỏ 
*/

#include <iostream>
using namespace std;

class DONGVAT 
{
    private:

    protected:

    public:
        virtual void MoTa()  = 0; // phương thức thuần ảo
        //     cout << "\nKhong biet";
        // }
};

class CHO: public DONGVAT
{
    private:

    protected:

    public:
        void MoTa() {
            cout << "\nCon cho keu gau gau";
        }
};

class MEO: public DONGVAT
{
    private:

    protected:
    
    public:
        void MoTa() {
            cout << "\nCon meo keu meo meo";
        }
};

class VIT: public DONGVAT
{
    private:

    protected:
    
    public:
        void MoTa() {
            cout << "\nCon vit keu cap cap";
        }
};

class NONGTRAI
{
    private:
        // CHO cho[5];
        // MEO meo[3];
        // VIT vit[2];

        DONGVAT *ThuCung[10];
       

    protected:

    public:
        NONGTRAI()
        {
            for (int i = 0; i <= 4; i++) ThuCung[i] = new CHO;
            for (int i = 5; i <= 7; i++) ThuCung[i] = new MEO;
            for (int i = 8; i <= 9; i++) ThuCung[i] = new VIT;
        }

        ~NONGTRAI()
        {
            for (int i = 0; i < 10; i++) delete ThuCung[i];
        }

        void DiemDanh() {
            for (int i = 0;  i < 10; i++) ThuCung[i] -> MoTa();
            system("pause");
        }
};

int main() {
    NONGTRAI NongTraiXanh;
    NongTraiXanh.DiemDanh();
}