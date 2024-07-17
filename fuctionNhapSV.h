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

void suaThongTin_SinhVien(DSSV &DanhSach)
{
    string MSSV;
    // cout << "Nhap ma lop: ";
    // getline(cin, maLop);
    cout << "Nhap MSSV: ";
    getline(cin, MSSV);
    for(int i = 0; i < DanhSach.n; i++)
    {
         for (int i = 0; i < DanhSach.n; ++i) 
    {
        if (DanhSach.nodes[i].MaSV == MSSV) 
        {
            SinhVien &sv = DanhSach.nodes[i];
            cout << "Nhap thong tin moi cho sinh vien (de trong neu khong thay doi):\n";

            cout << "Nhap Ma Lop (" << sv.MaLop << "): ";
            string newMaLop;
            getline(cin, newMaLop);
            if (!newMaLop.empty()) sv.MaLop = newMaLop;

            cout << "Nhap MSSV (" << sv.MaSV << "): ";
            string newMaSV;
            getline(cin, newMaSV);
            if (!newMaSV.empty()) sv.MaSV = newMaSV;

            cout << "Nhap ho (" << sv.Ho << "): ";
            string newHo;
            getline(cin, newHo);
            if (!newHo.empty()) sv.Ho = newHo;

            cout << "Nhap ten (" << sv.Ten << "): ";
            string newTen;
            getline(cin, newTen);
            if (!newTen.empty()) sv.Ten = newTen;

            cout << "Nhap gioi tinh (" << sv.Phai << "): ";
            string newPhai;
            getline(cin, newPhai);
            if (!newPhai.empty()) sv.Phai = newPhai;

            cout << "Nhap so DT (" << sv.SoDT << "): ";
            string newSoDT;
            getline(cin, newSoDT);
            if (!newSoDT.empty()) sv.SoDT = newSoDT;

            sort_SinhVien(DanhSach); // Sắp xếp lại danh sách sinh viên sau khi sửa đổi
            cout << "Thong tin sinh vien da duoc cap nhat.\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ma lop va ma sinh vien da nhap.\n";
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