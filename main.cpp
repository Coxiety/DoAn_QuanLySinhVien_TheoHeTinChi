#include "header.h"
using namespace std;
int main() 
{
    int option = 0;
    int highlight = 0;
    PTRMH root = NULL;
    DSLTC dsltc;
    int currentMaLopTC = 1;

    LoadData(dsltc, currentMaLopTC);
    docMonHocTuFile("list_MonHoc.txt", root);
    docList_SinhVien("list_SinhVien.txt", DanhSach_SinhVien);
    sortDanhSachSinhVien(DanhSach_SinhVien);
    main_menu(highlight, option, root,dsltc); // Ham Main menu

    return 0;
}