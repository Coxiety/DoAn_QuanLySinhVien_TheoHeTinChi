#include <iostream>
using namespace std;

int main()
{
    string mainMenuItems[]
        {
            "1. Danh sach sinh vien",
            "2. Lop tin chi",
            "3. Danh sach Mon Hoc",
            "4. Nhap diem cho mon hoc",
            "5. Ket thuc chuong trinh"
        };
    int menu_size = size(mainMenuItems);
    cout << menu_size << endl << sizeof(mainMenuItems) << endl << sizeof(mainMenuItems[0]);

    return 0;
}