#include "Struct.h"
#pragma once; 
bool compareSinhVien(const SinhVien &a, const SinhVien &b) /*Ham Dung De so sanh Ten va Ho, so sanh thong tin cua 
sinh vien A va B*/
{
    if (a.Ten != b.Ten) 
    {
        return a.Ten < b.Ten;
    }
    return a.Ho < b.Ho;
}

void sort_SinhVien(DSSV &DanhSach)//Sort su dung bubble sort
{
    for (int i = 0; i < DanhSach.n - 1; ++i) 
    {
        for (int j = i + 1; j < DanhSach.n - i - 1; ++j) 
        {
            if (!compareSinhVien(DanhSach.nodes[j], DanhSach.nodes[j + 1])) 
            {
                SinhVien temp = DanhSach.nodes[j];
                DanhSach.nodes[j] = DanhSach.nodes[j + 1];
                DanhSach.nodes[j + 1] = temp;
            }
        }
    }
}
void nhapSinhVien(DSSV &DanhSach)
{   
    SinhVien sv;
    while(true)
    {

        cout << "Nhap Ma Lop: ";
        cin >> sv.MaLop;
        cin.ignore();
        cout << "Nhap MSSV: ";
        getline(cin, sv.MaSV);
        if (sv.MaSV.empty())
        {
            break;
        }
        cout << "Nhap ho: ";
        cin >> sv.Ho;
        cin.ignore();
        cout << "Nhap ten: ";
        getline(cin, sv.Ten);
        cout << "Nhap gioi tinh: ";
        cin >> sv.Phai;
        cin.ignore();
        cout << "Nhap so DT: ";
        cin >> sv.SoDT;
        cin.ignore();
        if (DanhSach.n < MaxSV)
        {
            DanhSach.nodes[DanhSach.n++] = sv;
        }
        else
        {
            cout << "Danh sach sinh vien da day.\n";
            break;
        }
        sort_SinhVien(DanhSach);
    }
}

void inDanhSachSinhVien(const DSSV &DanhSach) {
    for (int i = 0; i < DanhSach.n; ++i) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        cout << "MSSV: " << DanhSach.nodes[i].MaSV << endl;
        cout << "Ho: " << DanhSach.nodes[i].Ho << endl;
        cout << "Ten: " << DanhSach.nodes[i].Ten << endl;
        cout << "Gioi tinh: " << DanhSach.nodes[i].Phai << endl;
        cout << "So DT: " << DanhSach.nodes[i].SoDT << endl;
        cout << "Ma Lop: " << DanhSach.nodes[i].MaLop << endl;
    }
}

int main()
{
    DSSV DanhSach;
    nhapSinhVien(DanhSach);
    return 0;
}