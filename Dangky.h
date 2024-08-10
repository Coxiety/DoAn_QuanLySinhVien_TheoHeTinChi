void HienThiLopTinChiTrongHocKy(const DSLTC& dsltc, PTRMH root, const string& nienKhoa, int hocKy) {
    cout << "Danh sach lop tin chi trong nien khoa " << nienKhoa << " va hoc ky " << hocKy << ":" << endl;
    bool found = false;
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->NienKhoa == nienKhoa && dsltc.nodes[i]->HocKy == hocKy) {
            PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
            string tenMH;
            if (mhNode != nullptr) {
                tenMH = mhNode->mh.TenMH;
            } else {
                tenMH = "Khong tim thay";
            }

            // Hiển thị thông tin chi tiết của từng lớp tín chỉ
            cout << "Ma Lop TC: " << dsltc.nodes[i]->MaLopTC << endl;
            cout << "Ma MH: " << dsltc.nodes[i]->MaMH << endl;
            cout << "Ten MH: " << tenMH << endl;
            cout << "Nhom: " << dsltc.nodes[i]->Nhom << endl;

            // Đếm số lượng sinh viên đã đăng ký
            int countSV = 0;
            PTRDK p = dsltc.nodes[i]->FirstDK;
            while (p != nullptr) {
                if (p->dk.TrangThai == 1) {
                    countSV++;
                }
                p = p->next;
            }

            cout << "So SV da dang ky: " << countSV << endl;
            cout << "So slot con trong: " << (dsltc.nodes[i]->SoSVMax - countSV) << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay lop tin chi nao trong nien khoa " << nienKhoa << " va hoc ky " << hocKy << "." << endl;
    }
}

// Hàm kiểm tra và in thông tin sinh viên
bool InThongTinSinhVien(const DSSV& dssv, const string& maSV) {
    for (int i = 0; i < dssv.n; ++i) {
        if (dssv.nodes[i].MaSV == maSV) {
            cout << "Thong tin sinh vien: " << endl;
            cout << "Ma SV: " << dssv.nodes[i].MaSV << endl;
            cout << "Ho: " << dssv.nodes[i].Ho << endl;
            cout << "Ten: " << dssv.nodes[i].Ten << endl;
            cout << "Phai: " << dssv.nodes[i].Phai << endl;
            cout << "So DT: " << dssv.nodes[i].SoDT << endl;
            cout << "Ma Lop: " << dssv.nodes[i].MaLop << endl;
            return true;
        }
    }
    cout << "Khong tim thay sinh vien voi Ma SV: " << maSV << endl;
    return false;
}

void DangKyLopTinChi(DSLTC& dsltc, PTRMH root, const DSSV& dssv) {
    string maSV;
    bool found = false;
    do {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        found = InThongTinSinhVien(dssv, maSV);
    } while (!found);

    string nienKhoa;
    int hocKy;
    cout << "Nhap nien khoa: ";
    cin >> nienKhoa;
    cout << "Nhap hoc ky: ";
    cin >> hocKy;

    HienThiLopTinChiTrongHocKy(dsltc, root, nienKhoa, hocKy);

    int maLopTC;
    cout << "Nhap ma lop tin chi can dang ky: ";
    cin >> maLopTC;

    // Tìm lớp tín chỉ
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->MaLopTC == maLopTC) {
            LopTinChi* ltc = dsltc.nodes[i];

            // Kiểm tra số lượng sinh viên đã đăng ký
            int countSV = 0;
            PTRDK p = ltc->FirstDK;
            while (p != nullptr) {
                if (p->dk.TrangThai == 1) {
                    countSV++;
                }
                p = p->next;
            }

            if (countSV >= ltc->SoSVMax) {
                cout << "Lop tin chi da day. Khong the dang ky." << endl;
                return;
            }

            // Thêm sinh viên vào danh sách đăng ký
            PTRDK newDK = new nodeDangKy;
            newDK->dk.MaSV = maSV;
            newDK->dk.TrangThai = 1;
            newDK->dk.Diem = 0; // Chưa có điểm
            newDK->next = ltc->FirstDK;
            ltc->FirstDK = newDK;

            cout << "Dang ky thanh cong!" << endl;

            // Lưu mã sinh viên vào file của lớp tín chỉ
            ofstream outFile(to_string(ltc->MaLopTC) + ".txt", ios::app);
            if (!outFile) {
                cout << "Khong the mo file de ghi." << endl;
                return;
            }
            outFile << maSV << endl;
            outFile.close();

            return;
        }
    }
    cout << "Khong tim thay lop tin chi voi ma " << maLopTC << endl;
}
