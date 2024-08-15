#include "header.h"
using namespace std;
int main() 
{
    int option = 0;
    int highlight = 0;
    PTRMH root = nullptr;
    DSLTC dsltc;
    PTRMHTheoTen rootTheoTen = nullptr;
    int currentMaLopTC = 1;

    ShowConsoleCursor(false);
    DocLTC("DSLTC.txt", dsltc, currentMaLopTC);
    docMonHocTuFile("list_MonHoc.txt", root);
    docList_SinhVien("list_SinhVien.txt", DanhSach_SinhVien);
    sortDanhSachSinhVien(DanhSach_SinhVien);
    main_menu(highlight, option, root, dsltc, rootTheoTen);
    return 0;
}