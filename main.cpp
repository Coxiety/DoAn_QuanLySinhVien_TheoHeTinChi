#include "header.h"

DSSV DanhSach_SinhVien;

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void get_highlight(int highlight, const string which_Menu[], int menu_size) 
{
    for (int i = 0; i < menu_size; ++i)
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
        cout << which_Menu[i] << endl;
    }
    // Đặt lại màu thường sau khi in menu
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void moveByArrow(int& highlight, int& option, int& haveEntered, int menu_size)
{
    int key = _getch();
    switch (key) 
    {
        case 72: // Mũi tên lên
            highlight = (highlight - 1 + menu_size) % menu_size;
            break;
        case 80: // Mũi tên xuống
            highlight = (highlight + 1) % menu_size;
            break;
        case 13: // Phím Enter
            option = highlight;
            haveEntered = 1;
            break;
    }
}

void SINHVIEN_menu(int& highlight, int option)
{
    enum option_SINHVIEN
    {
        THEM_SINH_VIEN = 0,
        IN_DANH_SACH = 1,
        SUA_THONG_TIN = 2,
        XOA = 3,
        THOAT = 4
    };
    string option_menu_SINHVIEN[]
    {
        "1. Them sinh vien",
        "2. In danh sach sinh vien",
        "3. Sua thong tin sinh vien",
        "4. Xoa sinh vien",
        "5. Thoat chuc nang"
    };

    cout << sizeof(option_menu_SINHVIEN);
    cout << sizeof(option_menu_SINHVIEN[0]);
    int menu_size = sizeof(option_menu_SINHVIEN) / sizeof(option_menu_SINHVIEN[0]);
    cout << sizeof(option_menu_SINHVIEN);
    cout << sizeof(option_menu_SINHVIEN[0]);
    cout << menu_size;
    while(true)
    {
        int haveEntered = 0;
        system("cls");
        get_highlight(highlight, option_menu_SINHVIEN, menu_size);
        moveByArrow(highlight, option, haveEntered, menu_size);
        if (haveEntered == 0)
        {
            continue;
        }
        cout << sizeof(option_menu_SINHVIEN);
        cout << sizeof(option_menu_SINHVIEN[0]);
        cout << menu_size;
        switch (option) 
        {
            case THEM_SINH_VIEN: // Them sinh vien
                system("cls");
                cout << "Them sinh vien" << endl;
                nhapSinhVien(DanhSach_SinhVien);
                system("pause");
                break;
            case IN_DANH_SACH:
                system("cls");
                cout << "In Danh Sach Sinh Vien \n";
                inDanhSachSinhVien(DanhSach_SinhVien);
                system("pause");
                break;
            case SUA_THONG_TIN: // Sua thong tin sinh vien
                system("cls");
                cout << "Sua thong tin sinh vien" << endl;
                suaThongTin_SinhVien(DanhSach_SinhVien);    
                system("pause");
                break;
            case XOA: // Xoa sinh vien
                system("cls");
                cout << "Xoa sinh vien" << endl;
                system("pause");
                break;

            case THOAT:
                return;
            default: return;
        }
    }
}

void main_menu(int& highlight, int option) 
{
    enum MENU_OPTIONS 
    {
        DANH_SACH_SINH_VIEN = 0,
        LOP_TIN_CHI = 1,
        DANH_SACH_MON_HOC = 2,
        NHAP_DIEM_MON_HOC = 3,
        KET_THUC = 4
    };

    string mainMenuItems[]
    {
        "1. Danh sach sinh vien",
        "2. Lop tin chi",
        "3. Danh sach Mon Hoc",
        "4. Nhap diem cho mon hoc",
        "5. Ket thuc chuong trinh"
    };
    int menu_size = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);

    while(true)
    {
        int haveEntered = 0;
        system("cls");
        get_highlight(highlight, mainMenuItems, menu_size);
        moveByArrow(highlight, option, haveEntered, menu_size);
        if (haveEntered == 0)
        {
            continue;
        }
        switch (option) 
        {
            case DANH_SACH_SINH_VIEN:
                system("cls");
                cout << "Danh sach sinh vien" << endl;
                SINHVIEN_menu(highlight, option);
                break;
            case LOP_TIN_CHI:
                system("cls");
                cout << "Nhap Lop tin chi" << endl;
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
                return;
            default: return;
        }
    }
}

int main() 
{
    int option = 0;
    int highlight = 0;

    main_menu(highlight, option); // Gọi hàm main_menu tại đây

    return 0;
}