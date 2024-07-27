#include "header.h"
#pragma once

int main() 
{
    int option = 0;
    int highlight = 0;
    docList_SinhVien("list_SinhVien.txt", DanhSach_SinhVien);
    sortDanhSachSinhVien(DanhSach_SinhVien);
    main_menu(highlight, option); // Ham Main menu

    return 0;
}