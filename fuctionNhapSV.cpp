#include "mylib.h"
#include "Struct.h"

void nhapSinhVien(DSSV &DanhSach)
{   
    SinhVien sv;
    while(true)
    {

        cout << "Nhap Ma Lop: ";
        cin >> sv.MaLop;
        cout << "Nhap MSSV: ";
        cin >> sv.MaSV;
        if (sv.MaSV == "")
        {
            break;
        }
        cout << "Nhap ho: ";
        cin >> sv.Ho;
        cout << "Nhap ten: ";
        cin >> sv.Ten;
        cout << "Nhap gioi tinh: ";
        cin >> sv.Phai;
        cout << "Nhap so DT: ";
        cin >> sv.SoDT;
        if (DanhSach.n < MaxSV)
        {
            DanhSach.nodes[DanhSach.n++] = sv;
        }
        else
        {
            cout << "Danh sach sinh vien da day.\n";
            break;
        }
    }
}



