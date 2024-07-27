#include "header.h"

// struct MonHoc {
//     char MaMH[11];
//     char TenMH[51];
//     int STCLT;
//     int STCTH;
// };

// struct nodeMonHoc {
//     MonHoc mh;
//     struct nodeMonHoc *left;
//     struct nodeMonHoc *right;
// };

// typedef nodeMonHoc *PTRMH;

// struct DangKy {
//     char MaSV[16];
//     int TrangThai;
//     float Diem;
// };

// struct nodeDangKy {
//     DangKy dk;
//     nodeDangKy *next;
// };

// typedef nodeDangKy *PTRDK;

// struct LopTinChi {
//     int MaLopTC;
//     char MaMH[11];
//     char NienKhoa[10];
//     int HocKy;
//     int Nhom;
//     int SoSVMin;
//     int SoSVMax;
//     int TrangThaiLTC;
//     PTRDK FirstDK;
// };

// const int MaxLTC = 10000;

// struct DSLTC {
//     LopTinChi *nodes[MaxLTC];
//     int n;
// };

// struct SinhVien {
//     char MaSV[16];
//     char Ho[51];
//     char Ten[11];
//     char Phai[4];
//     char SoDT[15];
//     char MaLop[16];
// };

// const int MaxSV = 5000;

// struct DSSV {
//     SinhVien nodes[MaxSV];
//     int n;
// };

istream& operator>>(istream &is, LopTinChi &ltc) {
    cout << "Nhap ma lop tin chi: ";
    is >> ltc.MaLopTC;
    cout << "Nhap ma mon hoc: ";
    is >> ltc.MaMH;
    cout << "Nhap nien khoa: ";
    is.ignore();
    is.getline(ltc.NienKhoa, 10);
    cout << "Nhap hoc ky: ";
    is >> ltc.HocKy;
    cout << "Nhap nhom: ";
    is >> ltc.Nhom;
    cout << "Nhap so SV min: ";
    is >> ltc.SoSVMin;
    cout << "Nhap so SV max: ";
    is >> ltc.SoSVMax;
    ltc.TrangThaiLTC = 1;
    ltc.FirstDK = NULL;
    return is;
}

ostream& operator<<(ostream &os, const LopTinChi &ltc) {
    os << "Ma Lop TC: " << ltc.MaLopTC << endl;
    os << "Ma Mon Hoc: " << ltc.MaMH << endl;
    os << "Nien Khoa: " << ltc.NienKhoa << endl;
    os << "Hoc Ky: " << ltc.HocKy << endl;
    os << "Nhom: " << ltc.Nhom << endl;
    os << "So SV Min: " << ltc.SoSVMin << endl;
    os << "So SV Max: " << ltc.SoSVMax << endl;
    os << "Trang Thai LTC: " << (ltc.TrangThaiLTC == 1 ? "Mo" : "Huy") << endl;
    return os;
}

void ThemLopTinChi(DSLTC &dsltc, LopTinChi &ltc) {
    if (dsltc.n >= MaxLTC) {
        cout << "Danh sach lop tin chi da day!" << endl;
        return;
    }
    dsltc.nodes[dsltc.n] = new LopTinChi;
    *dsltc.nodes[dsltc.n] = ltc;
    dsltc.n++;
    cout << "Da them lop tin chi thanh cong!" << endl;
}

void XoaLopTinChi(DSLTC &dsltc, int maLopTC) {
    for (int i = 0; i < dsltc.n; i++) {
        if (dsltc.nodes[i]->MaLopTC == maLopTC) {
            delete dsltc.nodes[i];
            for (int j = i; j < dsltc.n - 1; j++) {
                dsltc.nodes[j] = dsltc.nodes[j + 1];
            }
            dsltc.n--;
            cout << "Da xoa lop tin chi co ma " << maLopTC << endl;
            return;
        }
    }
    cout << "Khong tim thay lop tin chi co ma " << maLopTC << endl;
}

void HieuChinhLopTinChi(DSLTC &dsltc, int maLopTC, LopTinChi &ltcMoi) {
    for (int i = 0; i < dsltc.n; i++) {
        if (dsltc.nodes[i]->MaLopTC == maLopTC) {
            *dsltc.nodes[i] = ltcMoi;
            cout << "Da hieu chinh lop tin chi co ma " << maLopTC << endl;
            return;
        }
    }
    cout << "Khong tim thay lop tin chi co ma " << maLopTC << endl;
}

void LuuDSLTC(DSLTC &dsltc) {
    ofstream file("DSLTC.txt");
    for (int i = 0; i < dsltc.n; i++) {
        file << dsltc.nodes[i]->MaLopTC << " "
             << dsltc.nodes[i]->MaMH << " "
             << dsltc.nodes[i]->NienKhoa << " "
             << dsltc.nodes[i]->HocKy << " "
             << dsltc.nodes[i]->Nhom << " "
             << dsltc.nodes[i]->SoSVMin << " "
             << dsltc.nodes[i]->SoSVMax << " "
             << dsltc.nodes[i]->TrangThaiLTC << endl;
    }
    file.close();
    cout << "Da luu danh sach lop tin chi thanh cong!" << endl;
}

void XuatDSLTC(DSLTC &dsltc) {
    if (dsltc.n == 0) {
        cout << "Danh sach lop tin chi trong!" << endl;
        return;
    }
    for (int i = 0; i < dsltc.n; i++) {
        cout << *dsltc.nodes[i];
        cout << "----------------------------------------" << endl;
    }
}


int main() {
    DSLTC dsltc;
    dsltc.n = 0;
    bool flag = true;
    while (flag) {
    	system("cls");
        cout << "1. Them lop tin chi" << endl;
    	cout << "2. Xoa lop tin chi" << endl;
    	cout << "3. Hieu chinh lop tin chi" << endl;
    	cout << "4. Luu danh sach lop tin chi" << endl;
    	cout << "5. Xuat danh sach lop tin chi" << endl;
    	cout << "6. Thoat" << endl;
    	cout << "Nhap lua chon: ";
        int lc; cin>>lc;
        switch (lc) {
            case 1: {
                LopTinChi ltc;
                cin >> ltc;
                ThemLopTinChi(dsltc, ltc);
                break;
            }
            case 2: {
                int maLopTC;
                cout << "Nhap ma lop tin chi can xoa: ";
                cin >> maLopTC;
                XoaLopTinChi(dsltc, maLopTC);
                break;
            }
            case 3: {
                int maLopTC;
                LopTinChi ltcMoi;
                cout << "Nhap ma lop tin chi can hieu chinh: ";
                cin >> maLopTC;
                cout << "Nhap thong tin moi cua lop tin chi:" << endl;
                cin >> ltcMoi;
                ltcMoi.MaLopTC = maLopTC;
                HieuChinhLopTinChi(dsltc, maLopTC, ltcMoi);
                break;
            }
            case 4: {
                LuuDSLTC(dsltc);
                break;
            }
            case 5: {
                XuatDSLTC(dsltc);
                system("pause");
                break;
            }
            case 6: {
            	flag = false;
                break;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
            }
        }
    }
    return 0;
}

