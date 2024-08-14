void LuuVaoFile(const string &tenFile, const DSLTC &dsltc)
{
    ofstream file(tenFile);
    if (!file.is_open())
    {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    for (int i = 0; i < dsltc.n; ++i)
    {
        file << dsltc.nodes[i]->MaMH << endl;
        file << dsltc.nodes[i]->NienKhoa << endl;
        file << dsltc.nodes[i]->HocKy << endl;
        file << dsltc.nodes[i]->Nhom << endl;
        file << dsltc.nodes[i]->SoSVMin << endl;
        file << dsltc.nodes[i]->SoSVMax << endl;
        file << dsltc.nodes[i]->TrangThaiLTC << endl;
        file << dsltc.nodes[i]->MaLopTC << endl;

        if (i < dsltc.n - 1)
        {
            file << endl; // Thêm dòng trống giữa các lớp tín chỉ, ngoại trừ lớp cuối cùng
        }
    }

    file.close();
    cout << "Luu danh sach lop tin chi vao file " << tenFile << " thanh cong." << endl;
}
void HienThiDanhSachLopTinChi(const DSLTC &dsltc, PTRMH root)
{
    if (dsltc.n == 0)
    {
        cout << "Khong co lop tin chi nao." << endl;
        return;
    }

    cout << "Danh sach lop tin chi hien co:" << endl;
    for (int i = 0; i < dsltc.n; ++i)
    {
        // Sử dụng hàm timKiemMonHoc để lấy tên môn học
        PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
        string tenMH;
        if (mhNode != nullptr)
        {
            tenMH = mhNode->mh.TenMH;
        }
        else
        {
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
void InDanhSachLopTinChi(const DSLTC &dsltc, PTRMH root, const string &nienKhoa, int hocKy)
{

    bool found = false;

    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->NienKhoa == nienKhoa && dsltc.nodes[i]->HocKy == hocKy)
        {
            found = true;
            cout << "Danh sach lop tin chi cho nien khoa " << nienKhoa << " va hoc ky " << hocKy << ":" << endl;
            PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
            string tenMH;
            if (mhNode != nullptr)
            {
                tenMH = mhNode->mh.TenMH;
            }
            else
            {
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
    if (!found)
    {
        cout << "Khong tim thay lop tin chi nao cho nien khoa " << nienKhoa << " va hoc ky " << hocKy << "." << endl;
        return;
    }
}
void ThemLopTinChi(DSLTC &dsltc, int &currentMaLopTC, PTRMH root)
{
    HienThiDanhSachLopTinChi(dsltc, root);

    if (dsltc.n >= MaxLTC)
    {
        cout << "Danh sach lop tin chi da day." << endl;
        return;
    }

    LopTinChi *newLTC = new LopTinChi;
    newLTC->MaLopTC = currentMaLopTC++;

    cout << "Nhap ma mon hoc: ";
    cin.ignore();
    getline(cin, newLTC->MaMH);

    // Kiểm tra mã môn học có tồn tại trong cây BST hay không
    if (timKiemMonHoc(root, newLTC->MaMH) == nullptr)
    {
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
    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->NienKhoa == newLTC->NienKhoa && dsltc.nodes[i]->HocKy == newLTC->HocKy &&
            dsltc.nodes[i]->Nhom == newLTC->Nhom && dsltc.nodes[i]->MaMH == newLTC->MaMH)
        {
            cout << "Lop tin chi da ton tai cho mon hoc, nien khoa, hoc ky, nhom nay. Vui long nhap lai." << endl;
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
    char save;
    cout << "Ban co muon  khong? (y/n): ";
    cin >> save;
    if (save == 'y' || save == 'Y')
    {
        dsltc.nodes[dsltc.n++] = newLTC;
        LuuVaoFile("DSLTC.txt", dsltc);
        cout << "Them lop tin chi thanh cong!" << endl;
    }
}

void XoaLopTinChi(DSLTC &dsltc, PTRMH root)
{
    HienThiDanhSachLopTinChi(dsltc, root);
    bool found = false;
    int maLopTC;
    cout << "Nhap ma lop tin chi can xoa: ";
    cin >> maLopTC;
    cin.ignore();
    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->MaLopTC == maLopTC)
        {
            found = true;
            cout << "Ban co that su muon xoa khong? (y/n): ";
            char save;
            cin >> save;
            if (save == 'y' || save == 'Y')
            {
                delete dsltc.nodes[i];
                dsltc.nodes[i] =
                    dsltc.nodes[--dsltc.n]; // Di chuyển lớp tín chỉ cuối cùng vào vị trí của lớp tín chỉ bị xóa
                cout << "Xoa lop tin chi thanh cong!" << endl;
                LuuVaoFile("DSLTC.txt", dsltc);
            }
            return;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay lop tin chi." << endl;
        system("pause");
        return;
    }
}

void HieuChinhLopTinChi(DSLTC &dsltc, PTRMH root)
{
    HienThiDanhSachLopTinChi(dsltc, root);
    bool found = false;
    int maLopTC;
    cout << "Nhap ma lop tin chi can hieu chinh: ";
    cin >> maLopTC;
    cin.ignore();
    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->MaLopTC == maLopTC)
        {
            found = true;
            LopTinChi *ltc = new LopTinChi();
            ltc->MaLopTC = dsltc.nodes[i]->MaLopTC;
            ltc->MaMH = dsltc.nodes[i]->MaMH;
            ltc->NienKhoa = dsltc.nodes[i]->NienKhoa;
            ltc->HocKy = dsltc.nodes[i]->HocKy;
            ltc->Nhom = dsltc.nodes[i]->Nhom;
            ltc->SoSVMin = dsltc.nodes[i]->SoSVMin;
            ltc->SoSVMax = dsltc.nodes[i]->SoSVMax;
            ltc->TrangThaiLTC = dsltc.nodes[i]->TrangThaiLTC;
            ltc->FirstDK = dsltc.nodes[i]->FirstDK;
            cout << "Nhap thong tin moi cho lop tin chi (de trong neu khong thay doi):\n";

            // Nhập các thông tin khác
            cout << "Nhap Nien Khoa (" << ltc->NienKhoa << "): ";
            string newNienKhoa;
            getline(cin, newNienKhoa);
            if (!newNienKhoa.empty())
                ltc->NienKhoa = newNienKhoa;

            cout << "Nhap Hoc Ky (" << ltc->HocKy << "): ";
            string newHocKy;
            getline(cin, newHocKy);
            if (!newHocKy.empty())
                ltc->HocKy = stoi(newHocKy);

            cout << "Nhap Nhom (" << ltc->Nhom << "): ";
            string newNhom;
            getline(cin, newNhom);
            if (!newNhom.empty())
                ltc->Nhom = stoi(newNhom);

            cout << "Nhap So SV toi thieu (" << ltc->SoSVMin << "): ";
            string newSoSVMin;
            getline(cin, newSoSVMin);
            if (!newSoSVMin.empty())
                ltc->SoSVMin = stoi(newSoSVMin);

            cout << "Nhap So SV toi da (" << ltc->SoSVMax << "): ";
            string newSoSVMax;
            getline(cin, newSoSVMax);
            if (!newSoSVMax.empty())
                ltc->SoSVMax = stoi(newSoSVMax);

            cout << "Nhap Trang Thai Lop Tin Chi (0: huy, 1: mo) (" << ltc->TrangThaiLTC << "): ";
            string newTrangThaiLTC;
            getline(cin, newTrangThaiLTC);
            if (!newTrangThaiLTC.empty())
                ltc->TrangThaiLTC = stoi(newTrangThaiLTC);
            char save;
            cout << "Ban co muon luu thay doi khong? (y/n): ";
            cin >> save;
            if (save == 'y' || save == 'Y')
            {
                // delete [] dsltc.nodes[i];
                dsltc.nodes[i] = ltc;
                LuuVaoFile("DSLTC.txt", dsltc);
            }
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay lop tin chi voi ma " << maLopTC << "\n";
        return;
    }
}
void DocLTC(const string &tenFile, DSLTC &dsltc, int &currentMaLopTC)
{
    ifstream inFile(tenFile);

    if (!inFile.is_open())
    {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    currentMaLopTC = 1;
    dsltc.n = 0;
    while (!inFile.eof())
    {
        dsltc.nodes[dsltc.n] = new LopTinChi;

        getline(inFile, dsltc.nodes[dsltc.n]->MaMH);
        if (dsltc.nodes[dsltc.n]->MaMH.empty())
        {
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
        inFile.ignore(); // Bỏ qua ký tự newline sau khi đọc số nguyên

        // Bỏ qua dòng trống
        string temp;
        getline(inFile, temp);

        if (dsltc.nodes[dsltc.n]->MaLopTC >= currentMaLopTC)
        {
            currentMaLopTC = dsltc.nodes[dsltc.n]->MaLopTC + 1;
        }

        dsltc.n++;
    }

    inFile.close();
    cout << "Tai du lieu thanh cong!" << endl;
}

void HuyLopTinChi(DSLTC &dsltc)
{
    for (int i = 0; i < dsltc.n; ++i)
    {
        LopTinChi *ltc = dsltc.nodes[i];
        int countSV = 0;
        PTRDK p = ltc->FirstDK;

        while (p != NULL)
        {
            if (p->dk.TrangThai == 1)
            {
                countSV++;
            }
            p = p->next;
        }

        if (countSV < ltc->SoSVMin)
        {
            cout << "Lop tin chi Ma Lop TC: " << ltc->MaLopTC
                 << " co so SV dang ky < So SV Min. Ban co muon huy lop nay? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
            {
                while (ltc->FirstDK != nullptr)
                {
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

void HienThiLopTinChiTrongHocKy(const DSLTC &dsltc, PTRMH root, const string &nienKhoa, int hocKy)
{
    cout << "Danh sach lop tin chi trong nien khoa " << nienKhoa << " va hoc ky " << hocKy << ":" << endl;
    bool found = false;
    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->NienKhoa == nienKhoa && dsltc.nodes[i]->HocKy == hocKy)
        {
            PTRMH mhNode = timKiemMonHoc(root, dsltc.nodes[i]->MaMH);
            string tenMH;
            if (mhNode != nullptr)
            {
                tenMH = mhNode->mh.TenMH;
            }
            else
            {
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
            while (p != nullptr)
            {
                if (p->dk.TrangThai == 1)
                {
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

    if (!found)
    {
        cout << "Khong tim thay lop tin chi nao trong nien khoa " << nienKhoa << " va hoc ky " << hocKy << "." << endl;
    }
}

// Hàm kiểm tra và in thông tin sinh viên
bool InThongTinSinhVien(const DSSV &dssv, const string &maSV)
{
    for (int i = 0; i < dssv.n; ++i)
    {
        if (dssv.nodes[i].MaSV == maSV)
        {
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

void DangKyLopTinChi(DSLTC &dsltc, PTRMH root, const DSSV &dssv)
{
    string maSV;
    bool found = false;
    do
    {
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
    for (int i = 0; i < dsltc.n; ++i)
    {
        if (dsltc.nodes[i]->MaLopTC == maLopTC)
        {
            LopTinChi *ltc = dsltc.nodes[i];

            // Kiểm tra số lượng sinh viên đã đăng ký
            int countSV = 0;
            PTRDK p = ltc->FirstDK;
            while (p != nullptr)
            {
                if (p->dk.TrangThai == 1)
                {
                    countSV++;
                }
                p = p->next;
            }

            if (countSV >= ltc->SoSVMax)
            {
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
            if (!outFile)
            {
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

// void NhapDiem(DSLTC &dsltc, PTRMH root, const DSSV &dssv)
// {
//     string maSV;
//     string maMH;
//     string nienKhoa;
//     string hocKy;
//     int nhom;

//     cout << "Nhap nien khoa: ";
//     getNumber_dash(nienKhoa, 9);
//     cout << "Nhap hoc ky: ";
//     batHocKy(hocKy, 1);
//     cout >> "Nhap nhom: ";
//     cin >> nhom;
//     cout << "Nhap mon hoc: ";
//     getOnlyWord_Number(maMH, 13);

//     LopTinChi ltc;

//     for (int i = 0; i < dsltc.n; ++i)
//     {
//         if (dsltc.nodes[i]->NienKhoa == nienKhoa && dsltc.nodes[i]->HocKy == hocKy)
//         {
//             PTRMH mhNode = timKiemMonHoc(root, maMH);
//             string tenMH;
//             if (mhNode != nullptr)
//             {
//                 tenMH = mhNode->mh.TenMH;
//                 ltc = dsltc.node[i];
//             }
//             else
//             {
//                 tenMH = "Khong tim thay";
//             }
//         }

//         int countSV = 0;
//         PTRDK p = ltc.FirstDK;
//         while (p != nullptr)
//         {
//             if (p->dk.TrangThai == 1)
//             {
//                 float diem;
//                 cin >> diem;
//                 p->dk.Diem = diem;
//             }
//             p = p->next;
//         }
//     }

//     return;
// }