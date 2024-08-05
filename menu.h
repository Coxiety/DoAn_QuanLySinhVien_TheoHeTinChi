#pragma once
int currentMaLopTC;
DSSV DanhSach_SinhVien;

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
    system("cls");
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
        // system("cls");
        get_highlight(highlight, option_menu_MONHOC, size(option_menu_MONHOC));
        moveByArrow(highlight, option, haveEntered, size(option_menu_MONHOC));
        if (haveEntered == 0)
        {
            continue;
        }
        // else 
        // {
        //     system("cls");
        // }
        switch (option) 
        {
            case 0: // Them sinh vien
                system("cls");
                cout << "Them sinh vien" << endl;
                inDanhSachSinhVien(DanhSach_SinhVien);
                nhapSinhVien(DanhSach_SinhVien);
                system("cls");
                // system("pause");
                break;
            case 1:
                system("cls");
                cout << "In Danh Sach Sinh Vien \n";
                inDanhSachSinhVien(DanhSach_SinhVien);
                system("pause");
                system("cls");
                break;
            case 2: // Sua thong tin sinh vien
                system("cls");
                cout << "Sua thong tin sinh vien" << endl;
                inDanhSachSinhVien(DanhSach_SinhVien);
                suaThongTin_SinhVien(DanhSach_SinhVien);    
                system("pause");
                system("cls");
                break;
            case 3: // Xoa sinh vien
                system("cls");
                inDanhSachSinhVien(DanhSach_SinhVien);
                xoa_SinhVien(DanhSach_SinhVien);
                cout << "Xoa sinh vien" << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                return;
            // default: return;
        }
    }
}

void MonHoc_Menu(int& highlight, int option, PTRMH& root, PTRMHTheoTen rootTheoTen) {
    system("cls");
    saoChepCay(root, rootTheoTen);
    string option_menu_MONHOC[] = {
        "1. Them mon hoc",
        "2. In danh sach mon hoc",
        "3. Sua thong tin mon hoc",
        "4. Xoa mon hoc",
        "5. Thoat chuc nang"
    };

    while (true) {
        int haveEntered = 0; // Khởi tạo biến ngay trong vòng lặp
        // system("cls");
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
                system("cls");
                break;
            case 1: // In danh sách môn học 
                system("cls");
                // saoChepCay(root, rootTheoTen);
                cout << "In danh sach mon hoc" << endl;
                inDanhSachMonHocTheoTen(rootTheoTen);
                system("pause");
                system("cls");
                break;
            case 2: // Sửa thông tin môn học
                system("cls");
                cout << "Sua thong tin mon hoc" << endl;
                inDanhSachMonHoc(root); // In danh sách trước khi sửa
                suaMonHoc(root);
                system("pause");
                system("cls");
                break;
            case 3: // Xóa môn học
                system("cls");
                inDanhSachMonHoc(root); // In danh sách trước khi xóa
                cout << "Nhap Ma Mon Hoc can xoa: ";
                getline(cin, maMHToDelete);
                root = xoaMonHoc(root, maMHToDelete); 
                // saoChepCay(root, rootTheoTen);
                system("pause");
                system("cls");
                break;
            case 4: // Thoát chức năng
                system("cls");
                // saoChepCay(root, rootTheoTen);
                ghiDanhSachMonHoc(rootTheoTen, "list_MonHoc.txt"); // Ghi dữ liệu vào file trước khi thoát
                return;
            default:
                return;
        }
    }
}

void LTC_menu(int& highlight, int option, PTRMH& root,DSLTC dsltc) {

    string option_menu_MONHOC[] = {
        "1. Danh sach lop tin chi",
        "2. Them lop tin chi",
        "3. Sua lop tin chi",
        "4. Xoa lop tin chi",
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

        string nienKhoa; int hocKy;
        switch (option) {
        case 0: // in ltc
            system("cls");

            cout << "Nhap nien khoa: "; getline(cin, nienKhoa);
            cout << "Nhap hoc ky: "; cin >> hocKy;
            InDanhSachLopTinChi(dsltc, root, nienKhoa, hocKy);
            system("pause");
            break;
        case 1: // them ltc
            system("cls");
            ThemLopTinChi(dsltc, currentMaLopTC, root);
            system("pause");
            break;
        case 2: // Sua lop
            system("cls");
            HieuChinhLopTinChi(dsltc, root);
            system("pause");
            break;
        case 3: // Xóa lop
            system("cls");
            XoaLopTinChi(dsltc, root);
            system("pause");
            break;
        case 4: // Thoát chức năng
            return;
        default:
            return;
        }
    }
}

void main_menu(int& highlight, int option, PTRMH& root, DSLTC& dsLTC, PTRMHTheoTen& rootTheoTen)
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
        // system("cls");
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
                system("cls");
                break;
            case 1:
                system("cls");
                cout << "Nhap Lop tin chi" << endl;
                LTC_menu(highlight, option, root, dsLTC);
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "Danh sach Mon Hoc" << endl;
                MonHoc_Menu(highlight, option, root, rootTheoTen);
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "Nhap diem cho mon hoc" << endl;
                system("cls");
                break;
            case 4:
                // system("cls");
                return;
            default: return;
        }
    }
}