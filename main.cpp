#include "mylib.h"
#include "Struct.h"

enum MENU_OPTIONS 
{
    DANH_SACH_SINH_VIEN = 0,
    LOP_TIN_CHI,
    DANH_SACH_MON_HOC,
    NHAP_DIEM_MON_HOC,
    KET_THUC
};

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenu(int highlight) 
{
    string menuItems[] = 
    {
        "1. Danh sach sinh vien",
        "2. Lop tin chi",
        "3. Danh sach Mon Hoc",
        "4. Nhap diem cho mon hoc",
        "5. Ket thuc chuong trinh"
    };

    for (int i = 0; i < 5; ++i) 
    {
        if (i == highlight) 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240); // Màu sáng
        } 
        else 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Màu thường
        }
        gotoxy(0, i);
        cout << menuItems[i] << endl;
    }
}



int main() 
{
    int highlight = 0;
    int option;
    bool running = true;

    while (running) 
    {
        printMenu(highlight);

        int key = _getch();

        switch (key) 
        {
            case 72: // Mũi tên lên
                highlight = (highlight - 1 + 5) % 5;
                break;
            case 80: // Mũi tên xuống
                highlight = (highlight + 1) % 5;
                break;
            case 13: // Phím Enter
                option = highlight;
                switch (option) 
                {
                    case DANH_SACH_SINH_VIEN:
                        system("cls");
                        cout << "Danh sach sinh vien" << endl;
                        system("pause");
                        break;
                    case LOP_TIN_CHI:
                        system("cls");
                        cout << "Lop tin chi" << endl;
                        system("pause");
                        break;
                    case DANH_SACH_MON_HOC:
                        system("cls");
                        cout << "Danh sach Mon Hoc" << endl;
                        system("pause");
                        break;
                    case NHAP_DIEM_MON_HOC:
                        system("cls");
                        cout << "Nhap diem cho mon hoc" << endl;
                        system("pause");
                        break;
                    case KET_THUC:
                        running = false;
                        break;
                }
                system("cls");
                break;
        }
    }

    return 0;
}