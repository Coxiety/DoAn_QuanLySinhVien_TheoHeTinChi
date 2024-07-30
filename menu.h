#pragma once

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

void SINHVIEN_menu(int& highlight, int option)
{
    string option_menu_MONHOC[]
    {
        "1. Them sinh vien",
        "2. In danh sach sinh vien",
        "3. Sua thong tin sinh vien",
        "4. Xoa sinh vien",
        "5. Thoat chuc nang"
    };
    while(true)
    {
        int haveEntered = 0;
        system("cls");
        get_highlight(highlight, option_menu_MONHOC, size(option_menu_MONHOC));
        moveByArrow(highlight, option, haveEntered, size(option_menu_MONHOC));
        if (haveEntered == 0)
        {
            continue;
        }
        switch (option) 
        {
            case 0: // Them sinh vien
                system("cls");
                cout << "Them sinh vien" << endl;
                inDanhSachSinhVien(DanhSach_SinhVien);
                nhapSinhVien(DanhSach_SinhVien);
                system("pause");
                break;
            case 1:
                system("cls");
                cout << "In Danh Sach Sinh Vien \n";
                inDanhSachSinhVien(DanhSach_SinhVien);
                system("pause");
                break;
            case 2: // Sua thong tin sinh vien
                system("cls");
                cout << "Sua thong tin sinh vien" << endl;
                inDanhSachSinhVien(DanhSach_SinhVien);
                suaThongTin_SinhVien(DanhSach_SinhVien);    
                system("pause");
                break;
            case 3: // Xoa sinh vien
                system("cls");
                inDanhSachSinhVien(DanhSach_SinhVien);
                xoa_SinhVien(DanhSach_SinhVien);
                cout << "Xoa sinh vien" << endl;
                system("pause");
                break;

            case 4:
                return;
            default: return;
        }
    }
}

void MONHOC_Menu(int& highlight, int option, PTRMH& root) {
    string option_menu_MONHOC[] = {
        "1. Them mon hoc",
        "2. In danh sach mon hoc",
        "3. Sua thong tin mon hoc",
        "4. Xoa mon hoc",
        "5. Thoat chuc nang"
    };

    while (true) {
        int haveEntered = 0; // Khởi tạo biến ngay trong vòng lặp
        system("cls");
        get_highlight(highlight, option_menu_MONHOC, static_cast<int>(size(option_menu_MONHOC)));
        moveByArrow(highlight, option, haveEntered, static_cast<int>(size(option_menu_MONHOC)));
        if (haveEntered == 0) {
            continue;
        }
        //string maMH;
        string maMHToDelete;
        switch (option) {
            case 0: // Thêm môn học
                system("cls");
                cout << "Them mon hoc" << endl;
                nhapMonHoc(root);
                system("pause");
                break;
            case 1: // In danh sách môn học từ file
                system("cls");
                cout << "In danh sach mon hoc" << endl;
                inDanhSachMonHocTuFile("list_MonHoc.txt");
                system("pause");
                break;
            case 2: // Sửa thông tin môn học
                system("cls");
                cout << "Sua thong tin mon hoc" << endl;
                inDanhSachMonHocTuFile("list_MonHoc.txt"); // In danh sách trước khi sửa
                //cout << "Nhap Ma Mon Hoc can sua: ";
                //cin.ignore();
                //getline(cin, maMH);
                suaMonHocVaGhiRaFile("list_MonHoc.txt");
                system("pause");
                break;
            case 3: // Xóa môn học
                system("cls");
                inDanhSachMonHocTuFile("list_MonHoc.txt");; // In danh sách trước khi xóa
                cout << "Nhap Ma Mon Hoc can xoa: ";
                cin.ignore();
                getline(cin, maMHToDelete);
                root = xoaMonHoc(root, maMHToDelete); // Đảm bảo bạn có hàm xoaMonHoc
                system("pause");
                break;
            case 4: // Thoát chức năng
                return;
            default:
                return;
        }
    }
}

void main_menu(int& highlight, int option, PTRMH& root) 
{
    string mainMenuItems[]
    {
        "1. Danh sach sinh vien",
        "2. Lop tin chi",
        "3. Danh sach Mon Hoc",
        "4. Nhap diem cho mon hoc",
        "5. Ket thuc chuong trinh"
    };
    while(true)
    {
        int haveEntered = 0;
        system("cls");
        get_highlight(highlight, mainMenuItems, size(mainMenuItems));
        moveByArrow(highlight, option, haveEntered, size(mainMenuItems));
        if (haveEntered == 0)
        {
            continue;
        }
        switch (option) 
        {
            case 0:
                system("cls");
                cout << "Danh sach sinh vien" << endl;
                SINHVIEN_menu(highlight, option);
                break;
            case 1:
                system("cls");
                cout << "Nhap Lop tin chi" << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Danh sach Mon Hoc" << endl;
                MONHOC_Menu(highlight, option, root);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Nhap diem cho mon hoc" << endl;
                system("pause");
                break;
            case 4:
                return;
            default: return;
        }
    }
}