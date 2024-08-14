bool compareSinhVien(const SinhVien &a, const SinhVien &b) /*Ham Dung De so sanh Ten va Ho, so sanh thong tin cua
sinh vien A va B*/
{
    if (a.MaLop != b.MaLop)
    {
        return a.MaLop < b.MaLop;
    }
    if (a.Ten != b.Ten)
    {
        return a.Ten < b.Ten;
    }
    return a.Ho < b.Ho;
}

bool check_TrungMaSV(DSSV &DanhSach, const string &maSV)
{
    for (int i = 0; i < DanhSach.n; ++i)
    {
        if (DanhSach.nodes[i].MaSV == maSV)
        {
            return true;
        }
    }
    return false;
}

// Doc thong tin SV tu File
void docList_SinhVien(const string &tenFile, DSSV &DanhSach)
{
    ifstream file(tenFile);
    if (!file.is_open())
    {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    while (!file.eof())
    {
        SinhVien sv;
        string line;

        // Doc thong tin MaLop & MaSV & Ho tren mot dong
        getline(file, line);
        istringstream iss(line);
        iss >> sv.MaLop >> sv.MaSV;
        // Doc ho tren mot dong
        getline(file, sv.Ho);
        // Doc ten tren mot dong
        getline(file, sv.Ten);

        // Doc gioi tinh và SDT trên một dòng
        getline(file, line);
        istringstream iss2(line);
        iss2 >> sv.Phai >> sv.SoDT;

        // Lay khoan trong trong file
        getline(file, line);
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

    file.close();
}

void sortDanhSachSinhVien(DSSV &DanhSach)
{
    for (int i = 0; i < DanhSach.n - 1; ++i)
    {
        for (int j = i + 1; j < DanhSach.n; ++j)
        {
            if (!compareSinhVien(DanhSach.nodes[i], DanhSach.nodes[j]))
            {
                // Hoán đổi vị trí của hai sinh viên
                SinhVien temp = DanhSach.nodes[i];
                DanhSach.nodes[i] = DanhSach.nodes[j];
                DanhSach.nodes[j] = temp;
            }
        }
    }
}

// ghi Thong Tin Vao File
void ghiThongTinVaoFile(const string &tenFile, DSSV &DanhSach)
{
    ofstream file(tenFile);
    if (!file.is_open())
    {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    for (int i = 0; i < DanhSach.n; ++i)
    {
        if (i > 0) // Chỉ thêm dòng trống nếu không phải sinh viên đầu tiên
        {
            file << endl << endl;
        }
        file << DanhSach.nodes[i].MaLop << " " << DanhSach.nodes[i].MaSV << endl;
        file << DanhSach.nodes[i].Ho << endl;
        file << DanhSach.nodes[i].Ten << endl;
        file << DanhSach.nodes[i].Phai << " " << DanhSach.nodes[i].SoDT;
    }
    sortDanhSachSinhVien(DanhSach);
    file.close();
}
// Hàm sử dụng để dùng trong các chức năng nhập
void inDanhSachSinhVienChoCacHam(const DSSV &DanhSach, string maLopCanTim)
{
    for (int i = 0; i < DanhSach.n; ++i)
    {
        if (DanhSach.nodes[i].MaLop == maLopCanTim)
        {
            cout << "Sinh vien thu " << i + 1 << ":\n";
            cout << "MSSV: " << DanhSach.nodes[i].MaSV << endl;
            cout << "Ho: " << DanhSach.nodes[i].Ho << endl;
            cout << "Ten: " << DanhSach.nodes[i].Ten << endl;
            cout << "Gioi tinh: " << DanhSach.nodes[i].Phai << endl;
            cout << "So DT: " << DanhSach.nodes[i].SoDT << endl;
            cout << "Ma Lop: " << DanhSach.nodes[i].MaLop << endl;
            cout << "--------------------------\n";
        }
    }
}

void inDanhSachSinhVien(const DSSV &DanhSach)
{
    string maLopCanTim;
    cout << "Nhap ma lop can in danh sach sinh vien: ";
    getline(cin, maLopCanTim);

    bool found = false; // Biến kiểm tra có sinh viên nào thuộc mã lớp nhập vào hay không

    for (int i = 0; i < DanhSach.n; ++i)
    {
        if (DanhSach.nodes[i].MaLop == maLopCanTim)
        {
            found = true;
            cout << "Sinh vien thu " << i + 1 << ":\n";
            cout << "MSSV: " << DanhSach.nodes[i].MaSV << endl;
            cout << "Ho: " << DanhSach.nodes[i].Ho << endl;
            cout << "Ten: " << DanhSach.nodes[i].Ten << endl;
            cout << "Gioi tinh: " << DanhSach.nodes[i].Phai << endl;
            cout << "So DT: " << DanhSach.nodes[i].SoDT << endl;
            cout << "Ma Lop: " << DanhSach.nodes[i].MaLop << endl;
            cout << "--------------------------\n";
        }
    }

    if (!found)
    {
        cout << "Khong tim thay ma lop" << maLopCanTim;
    }
}

void nhapSinhVien(DSSV &DanhSach)
{
    SinhVien sv;
    char ch;
    // string maLopChung;
    cout << "Nhap Ma Lop chung cho tat ca sinh vien: ";
    getOnlyWord_Number_forMaSV(sv.MaLop, 15);
    cout << endl;
    inDanhSachSinhVienChoCacHam(DanhSach, sv.MaLop);

    while (true)
    {
        cout << "Nhap MSSV: ";
        getOnlyWord_Number_forMaSV(sv.MaSV, 15);
        cout << endl;
        if (sv.MaSV.empty())
        {
            break;
        }
        if (check_TrungMaSV(DanhSach, sv.MaSV) == true)
        {
            cout << "Da Trung Ma Sinh Vien\n";
            continue;
        }
        cout << "Nhap ho: ";
        getOnlyWord_Space(sv.Ho, 50);
        cout << endl;
        cout << "Nhap ten: ";
        getOnlyWord(sv.Ten, 10);
        cout << endl;
        cout << "Nhap gioi tinh: ";
        getOnlyWord(sv.Phai, 4);
        cout << endl;
        cout << "Nhap so DT: ";
        getOnlyNumber(sv.SoDT, 10);
        cout << endl;
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
    ghiThongTinVaoFile("list_SinhVien.txt", DanhSach);
}

void xoa_SinhVien(DSSV &DanhSach)
{
    SinhVien sv;
    cout << "Nhap ma lop cua sinh can duoc xoa: ";
    getOnlyWord_Number_forMaSV(sv.MaLop, 15);
    cout << endl;
    inDanhSachSinhVienChoCacHam(DanhSach, sv.MaLop);
    string MSSV;
    cout << "Nhap MSSV: ";
    getOnlyWord_Number_forMaSV(MSSV, 15, false);
    for (int i = 0; i < DanhSach.n; i++)
    {
        if (DanhSach.nodes[i].MaSV == MSSV)
        {
            for (int j = i; j < DanhSach.n - 1; ++j)
            {
                DanhSach.nodes[j] = DanhSach.nodes[j + 1];
            }
            --DanhSach.n;
            cout << "Da xoa sinh vien co MSSV: " << MSSV << endl;
            return;
        }
        ghiThongTinVaoFile("list_SinhVien.txt", DanhSach);
        break;
    }
    cout << "Khong tim thay sinh vien co MSSV: " << MSSV << endl;
}

void suaThongTin_SinhVien(DSSV &DanhSach)
{
    SinhVien sv;
    cout << "Nhap ma lop cua sinh can duoc xoa: ";
    getOnlyWord_Number_forMaSV(sv.MaLop, 15);
    cout << endl;
    inDanhSachSinhVienChoCacHam(DanhSach, sv.MaLop);
    while (true)
    {
        string MSSV;
        cout << "Nhap MSSV: ";
        getOnlyWord_Number(MSSV, 15);
        cout << endl;
        // Kiểm tra MSSV có trong danh sách không
        bool found = false;
        for (int i = 0; i < DanhSach.n; i++)
        {
            if (DanhSach.nodes[i].MaSV == MSSV)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong co thong tin MSSV trong danh sach. Vui long nhap lai.\n";
            continue;
        }

        // Sửa thông tin sinh viên nếu MSSV tồn tại
        for (int i = 0; i < DanhSach.n; i++)
        {
            if (DanhSach.nodes[i].MaSV == MSSV)
            {
                SinhVien &sv = DanhSach.nodes[i];
                cout << "Nhap thong tin moi cho sinh vien (de trong neu khong thay doi):\n";

                cout << "Nhap Ma Lop (" << sv.MaLop << "): ";
                string newMaLop = sv.MaLop;
                getOnlyWord_Number(newMaLop, 15, false);
                cout << endl;
                if (!newMaLop.empty())
                    sv.MaLop = newMaLop;

                cout << "Nhap MSSV (" << sv.MaSV << "): ";
                string newMaSV = sv.MaSV;
                sv.MaSV = "";
                getOnlyWord_Number(newMaSV, 15, false);
                cout << endl;
                // if (!newMaSV.empty()) sv.MaSV = newMaSV;
                if (check_TrungMaSV(DanhSach, newMaSV) == true)
                {
                    cout << "Trung ma voi sinh vien khac. Vui long nhap lai MSSV.\n";
                    continue;
                }
                if (!newMaSV.empty())
                    sv.MaSV = newMaSV;

                cout << "Nhap ho (" << sv.Ho << "): ";
                string newHo = sv.Ho;
                getOnlyWord_Space(newHo, 50, false);
                cout << endl;
                if (!newHo.empty())
                    sv.Ho = newHo;

                cout << "Nhap ten (" << sv.Ten << "): ";
                string newTen = sv.Ten;
                getOnlyWord(newTen, 10, false);
                cout << endl;
                if (!newTen.empty())
                    sv.Ten = newTen;

                cout << "Nhap gioi tinh (" << sv.Phai << "): ";
                string newPhai = sv.Phai;
                getOnlyWord(newPhai, 4, false);
                cout << endl;
                if (!newPhai.empty())
                    sv.Phai = newPhai;

                cout << "Nhap so DT (" << sv.SoDT << "): ";
                string newSoDT = sv.SoDT;
                getOnlyWord_Number(newSoDT, 10, false);
                cout << endl;
                if (!newSoDT.empty())
                    sv.SoDT = newSoDT;

                ghiThongTinVaoFile("list_SinhVien.txt", DanhSach);
                cout << "Thong tin sinh vien da duoc cap nhat.\n";
                return;
            }
        }
    }
}