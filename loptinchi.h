void HienThiDanhSachLopTinChi(const DSLTC& dsltc, PTRMH root) {
    if (dsltc.n == 0) {
        cout << "Khong co lop tin chi nao." << endl;
        return;
    }

    cout << "Danh sach lop tin chi hien co:" << endl;
    for (int i = 0; i < dsltc.n; ++i) {
        // Sử dụng hàm timKiemMonHoc để lấy tên môn học
        PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
        string tenMH;
        if (mhNode != nullptr) {
            tenMH = mhNode->mh.TenMH;
        }
        else {
            tenMH = "Khong tim thay";
        }

        // Hiển thị thông tin chi tiết của từng lớp tín chỉ
        cout << "Ma Lop TC: " << dsltc.nodes[i]->MaLopTC << endl;
        cout << "Ma MH: " << dsltc.nodes[i]->MaMH << endl;
        cout << "Ten MH: " << tenMH << endl;
        cout << "Nien khoa: " << dsltc.nodes[i]->NienKhoa << endl;
        cout << "Hoc ky: " << dsltc.nodes[i]->HocKy << endl;
        cout << "Nhom: " << dsltc.nodes[i]->Nhom << endl;
        cout << "So SV toi thieu: " << dsltc.nodes[i]->SoSVMin << endl;
        cout << "So SV toi da: " << dsltc.nodes[i]->SoSVMax << endl;
        cout << "Trang thai: " << (dsltc.nodes[i]->TrangThaiLTC == 1 ? "Mo" : "Huy") << endl;
        cout << "-----------------------------" << endl;
    }
}
void InDanhSachLopTinChi(const DSLTC& dsltc, PTRMH root, const string& nienKhoa, int hocKy) {
    bool found = false;
    cout << "Danh sach lop tin chi cho nien khoa " << nienKhoa << " va hoc ky " << hocKy << ":" << endl;
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->NienKhoa == nienKhoa && dsltc.nodes[i]->HocKy == hocKy) {
            found = true;
            PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
            string tenMH;
            if (mhNode != nullptr) {
                tenMH = mhNode->mh.TenMH;
            }
            else {
                tenMH = "Khong tim thay";
            }

            // Hiển thị thông tin chi tiết của từng lớp tín chỉ
            cout << "Ma Lop TC: " << dsltc.nodes[i]->MaLopTC << endl;
            cout << "Ma MH: " << dsltc.nodes[i]->MaMH << endl;
            cout << "Ten MH: " << tenMH << endl;
            cout << "Nien khoa: " << dsltc.nodes[i]->NienKhoa << endl;
            cout << "Hoc ky: " << dsltc.nodes[i]->HocKy << endl;
            cout << "Nhom: " << dsltc.nodes[i]->Nhom << endl;
            cout << "So SV toi thieu: " << dsltc.nodes[i]->SoSVMin << endl;
            cout << "So SV toi da: " << dsltc.nodes[i]->SoSVMax << endl;
            cout << "Trang thai: " << (dsltc.nodes[i]->TrangThaiLTC == 1 ? "Mo" : "Huy") << endl;
            cout << "-----------------------------" << endl;
        }

    }

    if (!found) {
        cout << "Khong tim thay lop tin chi nao cho nien khoa " << nienKhoa << " va hoc ky " << hocKy << "." << endl;
    }
}
void ThemLopTinChi(DSLTC& dsltc, int& currentMaLopTC, PTRMH root) {
    HienThiDanhSachLopTinChi(dsltc, root);

    if (dsltc.n >= MaxLTC) {
        cout << "Danh sach lop tin chi da day." << endl;
        return;
    }

    LopTinChi* newLTC = new LopTinChi;
    newLTC->MaLopTC = currentMaLopTC++;

    cout << "Nhap ma mon hoc: ";
    cin.ignore();
    getline(cin, newLTC->MaMH);

    // Kiểm tra mã môn học có tồn tại trong cây BST hay không
    if (timKiemMonHoc(root, newLTC->MaMH) == nullptr) {
        cout << "Ma mon hoc khong ton tai. Vui long nhap lai." << endl;
        delete newLTC;
        currentMaLopTC--; // Giảm mã lớp tín chỉ vì không thêm được lớp mới
        return;
    }

    cout << "Nhap nien khoa: ";
    getline(cin, newLTC->NienKhoa);

    cout << "Nhap hoc ky: ";
    cin >> newLTC->HocKy;
    cin.ignore();

    cout << "Nhap nhom: ";
    cin >> newLTC->Nhom;
    cin.ignore();

    // Kiểm tra trùng niên khóa, học kỳ, nhóm trong danh sách lớp tín chỉ
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->NienKhoa == newLTC->NienKhoa &&
            dsltc.nodes[i]->HocKy == newLTC->HocKy &&
            dsltc.nodes[i]->Nhom == newLTC->Nhom) {
            cout << "Lop tin chi da ton tai cho nien khoa, hoc ky, nhom nay. Vui long nhap lai." << endl;
            delete newLTC;
            currentMaLopTC--; // Giảm mã lớp tín chỉ vì không thêm được lớp mới
            return;
        }
    }

    cout << "Nhap so SV toi thieu: ";
    cin >> newLTC->SoSVMin;
    cin.ignore();

    cout << "Nhap so SV toi da: ";
    cin >> newLTC->SoSVMax;
    cin.ignore();

    newLTC->TrangThaiLTC = 1;
    newLTC->FirstDK = nullptr;
    dsltc.nodes[dsltc.n++] = newLTC;

    cout << "Them lop tin chi thanh cong!" << endl;
    cout << "Thong tin lop tin chi vua them:\n";
    cout << "Ma Lop TC: " << newLTC->MaLopTC << endl;
    cout << "Ma MH: " << newLTC->MaMH << endl;
    cout << "Ten MH: " << timKiemMonHoc(root, newLTC->MaMH)->mh.TenMH << endl;
    cout << "Nien khoa: " << newLTC->NienKhoa << endl;
    cout << "Hoc ky: " << newLTC->HocKy << endl;
    cout << "Nhom: " << newLTC->Nhom << endl;
    cout << "So SV toi thieu: " << newLTC->SoSVMin << endl;
    cout << "So SV toi da: " << newLTC->SoSVMax << endl;
    cout << "Trang thai: " << (newLTC->TrangThaiLTC == 1 ? "Mo" : "Huy") << endl;
}



void XoaLopTinChi(DSLTC& dsltc, PTRMH root) {
    HienThiDanhSachLopTinChi(dsltc, root);

    int maLopTC;
    cout << "Nhap ma lop tin chi can xoa: ";
    cin >> maLopTC;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->MaLopTC == maLopTC) {
            // Hiển thị thông tin lớp tín chỉ trước khi xóa
            LopTinChi* ltc = dsltc.nodes[i];
            cout << "Thong tin lop tin chi can xoa:\n";
            cout << "Ma Lop TC: " << ltc->MaLopTC << endl;
            cout << "Ma MH: " << ltc->MaMH << endl;
            cout << "Ten MH: " << timKiemMonHoc(root, ltc->MaMH)->mh.TenMH << endl;
            cout << "Nien khoa: " << ltc->NienKhoa << endl;
            cout << "Hoc ky: " << ltc->HocKy << endl;
            cout << "Nhom: " << ltc->Nhom << endl;
            cout << "So SV toi thieu: " << ltc->SoSVMin << endl;
            cout << "So SV toi da: " << ltc->SoSVMax << endl;
            cout << "Trang thai: " << (ltc->TrangThaiLTC == 1 ? "Mo" : "Huy") << endl;

            // Xóa lớp tín chỉ
            delete dsltc.nodes[i];
            dsltc.nodes[i] = dsltc.nodes[--dsltc.n]; // Di chuyển lớp tín chỉ cuối cùng vào vị trí của lớp tín chỉ bị xóa
            cout << "Xoa lop tin chi thanh cong!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay lop tin chi." << endl;
    }
}


void HieuChinhLopTinChi(DSLTC& dsltc, PTRMH root) {
    HienThiDanhSachLopTinChi(dsltc, root);

    int maLopTC;
    cout << "Nhap ma lop tin chi can hieu chinh: ";
    cin >> maLopTC;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < dsltc.n; ++i) {
        if (dsltc.nodes[i]->MaLopTC == maLopTC) {
            LopTinChi& ltc = *dsltc.nodes[i];
            found = true;

            cout << "Nhap thong tin moi cho lop tin chi (de trong neu khong thay doi):\n";

            // Nhập các thông tin khác
            cout << "Nhap Nien Khoa (" << ltc.NienKhoa << "): ";
            string newNienKhoa;
            getline(cin, newNienKhoa);
            if (!newNienKhoa.empty()) ltc.NienKhoa = newNienKhoa;

            cout << "Nhap Hoc Ky (" << ltc.HocKy << "): ";
            string newHocKy;
            getline(cin, newHocKy);
            if (!newHocKy.empty()) ltc.HocKy = stoi(newHocKy);

            cout << "Nhap Nhom (" << ltc.Nhom << "): ";
            string newNhom;
            getline(cin, newNhom);
            if (!newNhom.empty()) ltc.Nhom = stoi(newNhom);

            cout << "Nhap So SV toi thieu (" << ltc.SoSVMin << "): ";
            string newSoSVMin;
            getline(cin, newSoSVMin);
            if (!newSoSVMin.empty()) ltc.SoSVMin = stoi(newSoSVMin);

            cout << "Nhap So SV toi da (" << ltc.SoSVMax << "): ";
            string newSoSVMax;
            getline(cin, newSoSVMax);
            if (!newSoSVMax.empty()) ltc.SoSVMax = stoi(newSoSVMax);

            cout << "Nhap Trang Thai Lop Tin Chi (0: huy, 1: mo) (" << ltc.TrangThaiLTC << "): ";
            string newTrangThaiLTC;
            getline(cin, newTrangThaiLTC);
            if (!newTrangThaiLTC.empty()) ltc.TrangThaiLTC = stoi(newTrangThaiLTC);

            cout << "Thong tin lop tin chi da duoc cap nhat.\n";
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay lop tin chi voi ma " << maLopTC << "\n";
    }
}

void SaveData(const DSLTC& dsltc) {
    ofstream outFile("DSLTC.txt");

    if (!outFile) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    for (int i = 0; i < dsltc.n; ++i) {
        outFile << dsltc.nodes[i]->MaMH << endl;
        outFile << dsltc.nodes[i]->NienKhoa << endl;
        outFile << dsltc.nodes[i]->HocKy << endl;
        outFile << dsltc.nodes[i]->Nhom << endl;
        outFile << dsltc.nodes[i]->SoSVMin << endl;
        outFile << dsltc.nodes[i]->SoSVMax << endl;
        outFile << dsltc.nodes[i]->TrangThaiLTC << endl;
        outFile << dsltc.nodes[i]->MaLopTC << endl;
    }

    outFile.close();
    cout << "Luu du lieu thanh cong!" << endl;
}

void LoadData(DSLTC& dsltc, int& currentMaLopTC) {
    ifstream inFile("DSLTC.txt");

    if (!inFile) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    currentMaLopTC = 1;
    dsltc.n = 0;

    while (!inFile.eof()) {
        dsltc.nodes[dsltc.n] = new LopTinChi;
        getline(inFile, dsltc.nodes[dsltc.n]->MaMH);
        if (dsltc.nodes[dsltc.n]->MaMH.empty()) {
            delete dsltc.nodes[dsltc.n];
            break;
        }
        getline(inFile, dsltc.nodes[dsltc.n]->NienKhoa);
        inFile >> dsltc.nodes[dsltc.n]->HocKy;
        inFile >> dsltc.nodes[dsltc.n]->Nhom;
        inFile >> dsltc.nodes[dsltc.n]->SoSVMin;
        inFile >> dsltc.nodes[dsltc.n]->SoSVMax;
        inFile >> dsltc.nodes[dsltc.n]->TrangThaiLTC;
        inFile >> dsltc.nodes[dsltc.n]->MaLopTC;
        inFile.ignore();

        if (dsltc.nodes[dsltc.n]->MaLopTC >= currentMaLopTC) {
            currentMaLopTC = dsltc.nodes[dsltc.n]->MaLopTC + 1;
        }

        dsltc.n++;
    }

    inFile.close();
    cout << "Tai du lieu thanh cong!" << endl;
}




void HuyLopTinChi(DSLTC& dsltc) {
    for (int i = 0; i < dsltc.n; ++i) {
        LopTinChi* ltc = dsltc.nodes[i];
        int countSV = 0;
        PTRDK p = ltc->FirstDK;

        while (p != NULL) {
            if (p->dk.TrangThai == 1) {
                countSV++;
            }
            p = p->next;
        }

        if (countSV < ltc->SoSVMin) {
            cout << "Lop tin chi Ma Lop TC: " << ltc->MaLopTC
                << " co so SV dang ky < So SV Min. Ban co muon huy lop nay? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                while (ltc->FirstDK != nullptr) {
                    PTRDK temp = ltc->FirstDK;
                    ltc->FirstDK = ltc->FirstDK->next;
                    delete temp;
                }

                ltc->TrangThaiLTC = 0;
                cout << "Da huy lop tin chi Ma Lop TC: " << ltc->MaLopTC << endl;
            }
        }
    }
}