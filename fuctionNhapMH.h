#include <functional>
// ham da dược định nghĩa
void ghiMonHocRaFile(const string& tenFile, PTRMH root);

// In-order traversal để in cây
void inCay(PTRMH root) {
    if (root) {
        inCay(root->left);
        cout << "Ma Mon Hoc: " << root->mh.MaMH << endl;
        cout << "Ten Mon Hoc: " << root->mh.TenMH << endl;
        cout << "STCLT: " << root->mh.STCLT << endl;
        cout << "STCTH: " << root->mh.STCTH << endl;
        inCay(root->right);
    }
}
void xoaCay(PTRMH root) {
    if (root) {
        xoaCay(root->left);
        xoaCay(root->right);
        delete root;
    }
}

// Hàm kiểm tra mã môn học đã tồn tại trong cây chưa
bool checkTrungMaMH(PTRMH root, const string& maMH) {
    if (root == nullptr) return false;
    if (root->mh.MaMH == maMH) return true;
    if (maMH < root->mh.MaMH) return checkTrungMaMH(root->left, maMH);
    return checkTrungMaMH(root->right, maMH);
}

// Hàm thêm môn học vào cây nhị phân theo tên môn học
void themMonHoc(PTRMH& root, MonHoc mh) {
    if (root == nullptr) {
        root = new nodeMonHoc{ mh, nullptr, nullptr };
        return;
    }
    if (mh.TenMH < root->mh.TenMH) {
        themMonHoc(root->left, mh);
    }
    else if (mh.TenMH > root->mh.TenMH) {
        themMonHoc(root->right, mh);
    }
}
// Hàm tìm kiếm môn học trong cây nhị phân
PTRMH timKiemMonHoc(PTRMH root, const string& maMH) {
    if (root == nullptr || root->mh.MaMH == maMH) {
        return root;
    }
    else if (maMH < root->mh.MaMH) {
        return timKiemMonHoc(root->left, maMH);
    }
    else {
        return timKiemMonHoc(root->right, maMH);
    }
}

// Hàm xóa môn học trong cây nhị phân
PTRMH xoaMonHoc(PTRMH root, const string& maMH) {
    if (root == nullptr) {
        return nullptr;
    }

    if (maMH < root->mh.MaMH) {
        root->left = xoaMonHoc(root->left, maMH);
    }
    else if (maMH > root->mh.MaMH) {
        root->right = xoaMonHoc(root->right, maMH);
    }
    else {
        // Node to be deleted
        if (root->left == nullptr) {
            PTRMH temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            PTRMH temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        PTRMH temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        root->mh = temp->mh;
        root->right = xoaMonHoc(root->right, temp->mh.MaMH);
    }
    return root;
}
// Hàm sửa thông tin môn học trong cây nhị phân
void suaMonHoc(PTRMH& root, const string& maMH) {
    PTRMH node = timKiemMonHoc(root, maMH);
    if (node) {
        MonHoc& mh = node->mh;
cout << "Nhap thong tin moi cho mon hoc (de trong neu khong thay doi):\n";

        // Giu lai ma mon hoc cu de kiem tra trung lap
        string oldMaMH = mh.MaMH;

        // Nhap ma mon hoc va kiem tra trung lap
        while (true) {
            cout << "Nhap Ma Mon Hoc (" << mh.MaMH << "): ";
            string newMaMH;
            getline(cin, newMaMH);

            // Neu nguoi dung khong nhap gi, giu nguyen ma mon hoc cu
            if (newMaMH.empty()) {
                newMaMH = mh.MaMH;
            }

            // Neu ma mon hoc moi khong trung lap hoac trung voi ma cu, thi cho phep cap nhat
            if (newMaMH == oldMaMH || !checkTrungMaMH(root, newMaMH)) {
                
                mh.MaMH = newMaMH; // Cap nhat ma mon hoc moi
                break; // Thoat vong lap neu ma hop le
            }
            else {
                cout << "Ma mon hoc da ton tai. Vui long nhap lai.\n";
            }
        }

        // Nhap cac thong tin khac
        cout << "Nhap Ten Mon Hoc (" << mh.TenMH << "): ";
        string newTenMH;
        getline(cin, newTenMH);
        if (!newTenMH.empty()) mh.TenMH = newTenMH;

        cout << "Nhap So Tin Chi Ly Thuyet (" << mh.STCLT << "): ";
        string newSTCLT;
        getline(cin, newSTCLT);
        if (!newSTCLT.empty()) mh.STCLT = stoi(newSTCLT);

        cout << "Nhap So Tin Chi Thuc Hanh (" << mh.STCTH << "): ";
        string newSTCTH;
        getline(cin, newSTCTH);
        if (!newSTCTH.empty()) mh.STCTH = stoi(newSTCTH);

        cout << "Thong tin mon hoc da duoc cap nhat.\n";
    }
    else {
        cout << "Khong tim thay mon hoc voi ma " << maMH << "\n";
    }
}


// Hàm đọc môn học từ file và lưu vào cây nhị phân
void docMonHocTuFile(const string& tenFile, PTRMH& root) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    MonHoc mh;
    string line;

    while (getline(file, mh.MaMH)) {
        getline(file, mh.TenMH);
        getline(file, line);
        istringstream iss(line);

        int stclt, stcth;
        if (!(iss >> stclt >> stcth)) {
            cerr << "Loi: Du lieu STCLT va STCTH khong hop le" << endl;
            continue; // Bo qua dong nay va tiep tuc voi dong tiep theo
        }

        mh.STCLT = stclt;
        mh.STCTH = stcth;

        // Kiem tra xem ma mon hoc co bi trung khong
        if (checkTrungMaMH(root, mh.MaMH)) {
            cout << "Ma mon hoc " << mh.MaMH << " da ton tai." << endl;
            suaMonHoc(root, mh.MaMH); // Goi ham suaMonHoc neu ma bi trung
        }
        else {
            themMonHoc(root, mh); // Them mon hoc moi neu khong trung
        }
    }

    file.close();

    // Sau khi sua xong, cap nhat danh sach mon hoc vao file
    ghiMonHocRaFile(tenFile, root);
}
// Hàm ghi môn học ra file mà không xóa dữ liệu cũ và không chèn lên dữ liệu cũ
void ghiMonHocRaFile(const string& tenFile, PTRMH root) {
    ofstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Khong the mo file " << tenFile << endl;
        return;
    }

    // Duyet cay theo thu tu in-order
    function<void(PTRMH)> ghiDanhSach = [&](PTRMH node) {
        if (node) {
            ghiDanhSach(node->left);
            file << node->mh.MaMH << endl
                << node->mh.TenMH << endl
                << node->mh.STCLT << " " << node->mh.STCTH << endl;
            ghiDanhSach(node->right);
        }
        };

    ghiDanhSach(root);
    file.close();
}
// Hàm kiểm tra file có trống hay không
bool fileIsEmpty(const string& tenFile) {
    ifstream file(tenFile);
    return file.peek() == ifstream::traits_type::eof();
}

// Hàm nhập môn học và ghi dữ liệu vào file
void nhapMonHoc(PTRMH& root) {
    MonHoc mh;
    while (true) {
        // Nhập mã môn học và kiểm tra trùng lặp
        while (true) {
            cout << "Nhap Ma Mon Hoc : ";
            getline(cin, mh.MaMH);
            if (mh.MaMH.empty()) return; // Kết thúc nếu người dùng nhập chuỗi rỗng

            if (timKiemMonHoc(root, mh.MaMH)) {
                cout << "Ma mon hoc da ton tai. Vui long nhap lai. \n ";
            }
            else {
                break; // Mã môn học hợp lệ
            }
        }

        // Nhập tên môn học và số tín chỉ
        cout << "Nhap Ten Mon Hoc : ";
        getline(cin, mh.TenMH);
        cout << "Nhap So Tin Chi Li Thuyet : ";
        cin >> mh.STCLT;
        cout << "Nhap So Tin Chi Thuc Hanh : ";
        cin >> mh.STCTH;
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập số

        themMonHoc(root, mh);

        // Ghi môn học mới vào file
        ghiMonHocRaFile("list_MonHoc.txt", root);
    }
}
// Hàm sửa thông tin môn học và ghi dữ liệu cập nhật vào file
void suaMonHocVaGhiRaFile(PTRMH& root, const string& tenFile) {
    string maMH;
    cout << "Nhap Ma Mon Hoc de sua: ";
    getline(cin, maMH);
    suaMonHoc(root, maMH);

    // Ghi lại toàn bộ dữ liệu từ cây vào file
    ghiMonHocRaFile(tenFile, root);
}
void suaMonHocVaGhiRaFile(const string& tenFile) {
    PTRMH root = nullptr;
    docMonHocTuFile(tenFile, root);  // Đọc dữ liệu từ file và xây dựng cây nhị phân

    suaMonHocVaGhiRaFile(root, tenFile);  // Sửa thông tin và ghi lại dữ liệu vào file

    // Giải phóng bộ nhớ (nếu cần)
     xoaCay(root);  // Hàm xóa cây nhị phân để giải phóng bộ nhớ
}
// Hàm in danh sách môn học từ file
void inDanhSachMonHocTuFile(const string& tenFile) {
    PTRMH root = nullptr;
    docMonHocTuFile(tenFile, root);  // Đọc từ file và xây dựng cây nhị phân

    if (root == nullptr) {
cout << "Danh sach mon hoc trong.\n";
    }
    else {
        inCay(root);  // In danh sách môn học từ cây nhị phân
    }

    // Giải phóng bộ nhớ (cần thêm hàm giải phóng nếu có)
    // xoaCay(root);  // Hàm xóa cây nhị phân để giải phóng bộ nhớ
}