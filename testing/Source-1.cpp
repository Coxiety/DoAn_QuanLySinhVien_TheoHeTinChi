#include <iostream>
#include "mylib.h"
#include "Header.h"
#include <fstream>
#include <sstream>
using namespace std; 
//============================= Mo lop TC ===========================
int MA = 0;
int MaLTC(string MaMH) {
	int MaLTC = ++MA;
	return MaLTC;
}
void them_lop_TC(dsLopTc& DSLTC) {
	LopTC* p = new LopTC();
	cout << "nhap ma mon hoc:";
	cin.ignore();
	getline(cin, p->MaMH);
	p->MaLopTc = MaLTC(p->MaMH);
	cout << "nhap nien khoa:";
	cin.ignore();
	getline(cin, p->nien_khoa);
	cout << "nhap hoc ky:";
	cin >> p->HK;
	cout << "nhap nhom:";
	cin >> p->Nhom;
	cout << "nhap so sinh vien max:";
	cin >> p->max;
	cout << "nhap so sinh vien min:";
	cin >> p->min;
	DSLTC.ds[DSLTC.damo] = p;
	++DSLTC.damo;
}
void in_ds_lop_tc(dsLopTc& DSLTC, int i) {
	cout << "ma lop TC:";
	cout << DSLTC.ds[i]->MaLopTc;
	cout << "ma mon hoc:";
	cout << DSLTC.ds[i]->MaMH;
	cout << "Nien khoa:";
	cout << DSLTC.ds[i]->nien_khoa;
	cout << "Hoc ky:";
	cout << DSLTC.ds[i]->HK;
	cout << "nhom:";
	cout << DSLTC.ds[i]->Nhom;
	cout << "so sinh vien min:";
	cout << DSLTC.ds[i]->min;
	cout << "so sinh vien max:";
	cout << DSLTC.ds[i]->max;
	cout << endl;
}
void xoa_lop_TC(dsLopTc& DSLTC, LopTC* lop) {
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (lop->MaLopTc == DSLTC.ds[i]->MaLopTc) {
			delete DSLTC.ds[i];
			for (int j = i; j < DSLTC.damo; ++j) {
				DSLTC.ds[j] = DSLTC.ds[j + 1];
			}
			--DSLTC.damo;
		}
	}
}
void hieu_chinh_lop_TC(dsLopTc& DSLTC, LopTC* lop) {
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (lop->MaLopTc == DSLTC.ds[i]->MaLopTc) {
			cout << "Nhap ma mon hoc: ";
			cin.ignore();
			getline(cin, DSLTC.ds[i]->MaMH);

			cout << "Nhap nien khoa: ";
			getline(cin, DSLTC.ds[i]->nien_khoa);

			cout << "Nhap hoc ky: ";
			cin >> DSLTC.ds[i]->HK;

			cout << "Nhap nhom: ";
			cin >> DSLTC.ds[i]->Nhom;

			cout << "Nhap so sinh vien min: ";
			cin >> DSLTC.ds[i]->min;

			cout << "Nhap so sinh vien max: ";
			cin >> DSLTC.ds[i]->max;

			cout << "Trang thai huy lop (1: Da huy, 0: Chua huy): ";
			cin >> DSLTC.ds[i]->huylop;
		}
		break;
	}
}
LopTC* menu_Mo_Lop_TC(dsLopTc& DSLTC, int& page, int maxpage) {
	int choice = page * 11 - 11;
	int option = DSLTC.damo;
	while (true) {
		int count = 0;
		int jy = 3;
		clrscr();
		for (int i = page * 11 - 11; i < 11 * page ; ++i) {
			if (choice == i) {
				SetColor(3);
				highlight(i);
			}
			else {
				SetBGColor(7);
				normal(i);
			}
			in_ds_lop_tc(DSLTC, i);
			jy += 2;
		}
		char key;
		key = _getch();
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = DSLTC.damo - 1;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 11 - 11;
				highlight(choice);
			}
			else if(choice > page * 11 - 1){
				choice = page * 11 - 11;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case 13: {
			if (choice >= 0 && choice < DSLTC.damo) {
				return DSLTC.ds[choice];
			}
		}
		}
		}
	}
}
void khung_LTC(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 15) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 2, y += 1); cout << "MA LOP TC";
	gotoxy(x += 15, y); cout << "MA MH";
	gotoxy(x += 15, y); cout << "NIEN KHOA";
	gotoxy(x += 15, y); cout << "HOC KI";
	gotoxy(x += 15, y); cout << "NHOM";
	gotoxy(x += 15, y); cout << "SO SV MAX";
	gotoxy(x += 15, y); cout << "SO SV MIN";
	gotoxy(x += 15, y); cout << "TRANG THAI";
}
// chua hoan thien
void MO_LOP_TC(dsLopTc& dsltc) {

}
// ================================================ DANH SACH SINH VIEN ==============================================
void nhap_ho_SV(string& hoSV) {
	char c;
	cout << hoSV;

	while (true) {
		c = _getch();
		if (c == '\r') {
			break;
		}
		if (hoSV.length() > 21) continue;
		if (!isalpha(c) && c != ' ' && c != 8) continue;
		if (c == ' ' || isalpha(c)) {
			if ((hoSV.empty() && c == ' ') || (!hoSV.empty() && hoSV[hoSV.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == 8) {
			if (hoSV.empty()) continue;
			else {
				hoSV.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		hoSV += c;
	}
}
void nhap_ten_SV(string& tenSV) {
	char c;
	cout << tenSV;
	while (1) {
		c = _getch();

		if (c == '\r') {
			break;
		}
		if (c == 8) {
			if (!tenSV.empty()) {
				tenSV.pop_back();
				cout << "\b \b";
			}
		}
		if (tenSV.length() > 10) continue;
		if (c == ' ' || !isalpha(c)) {
			continue;
		}
		if (c >= 'a' && c <= 'z') {
			c = toupper(c);
		}
		cout << c;
		tenSV += c;
	}
}
void nhap_MSV(string& MSV) {
}
void nhap_gioi_tinh(string& phai) {
	while (1)
	{
		char key;
		key = _getch();
		if (key == 8) {
			if (!phai.empty()) {
				phai.pop_back();
				cout << "\b \b";
			}
		}
		if (key == '0') {
			phai = "NU";
			cout << phai;
			break;
		}
		else if (key == '1') {
			phai = "NAM";
			cout << phai;
			break;
		}
		else continue;
	}
}
void nhap_SDT(string& sdt) {
	while (1) {
		char c;
		c = _getch();
		if (c == 8) {
			if (!sdt.empty()) {
				sdt.pop_back();
				cout << "\b \b";
			}
		}
		if (sdt.length() > 10) continue;
		if ('0' <= c && c <= '9') {
			cout << c;
			sdt += c;
		}
		if (c == 13) return;
	}
}
void khung(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 23) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 10, y += 1); cout << "MSV";
	gotoxy(x += 23, y); cout << "HO";
	gotoxy(x += 23, y); cout << "TEN";
	gotoxy(x += 20, y); cout << "GIOI TINH";
	gotoxy(x += 26, y); cout << "SDT";
	gotoxy(0, 27); cout << "A:Them SV";
	gotoxy(15, 27); cout << "E: Hieu chinh";
	gotoxy(35, 27); cout << "D: Xoa SV";
	gotoxy(55, 27); cout << "ESC: Thoat";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void in_ds_SV(dsSV& ds, int page) {
	dsSV SV = ds;
	int i = 1;
	int j = 3;
	int count = 0;
	if (page > 1) {
		for (int h = 1; h <= 11 * (page - 1); ++h) {
			SV.phead = SV.phead->pnext;
			++count;
		}
	}
	while (SV.phead != NULL && count < 11 * page) {
		int i = 1;
		gotoxy(i, j);
		cout << SV.phead->MaSV << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->ho << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->ten << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->phai << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->SDT << endl;
		SV.phead = SV.phead->pnext;
		j += 2;
		++count;
	}
}
void in_thong_tin_SV(Sinhvien* sv, int j) {
	int i = 1;
	gotoxy(i, j);
	cout << sv->MaSV << ' ';
	gotoxy(i += 23, j);
	cout << sv->ho << ' ';
	gotoxy(i += 23, j);
	cout << sv->ten << ' ';
	gotoxy(i += 23, j);
	cout << sv->phai << ' ';
	gotoxy(i += 23, j);
	cout << sv->SDT << ' ';
}
void nhap_SV(dsSV& dssv) {
	Sinhvien* SV;
	Sinhvien* current = dssv.phead;
	Sinhvien* prevSV = NULL;
	int i;
	int j = 3;
	int count = 0;
	do {
		i = 1;
		if (count == 11) {
			system("cls");
			count = 0;
			khung(0, 0, 115, 2);
			j = 3;
		}
		gotoxy(i, j);
		string maSV;
		SV = new Sinhvien();
		getline(cin, maSV);
		if (maSV.empty()) {
			break;
		}
		SV->MaSV = maSV;
		SV->pnext = NULL;
		gotoxy(i += 23, j);
		nhap_ho_SV(SV->ho);
		gotoxy(i += 23, j);
		nhap_ten_SV(SV->ten);
		gotoxy(i += 23, j);
		nhap_gioi_tinh(SV->phai);
		gotoxy(i += 23, j);
		nhap_SDT(SV->SDT);
		j += 2;
		++count;
		if (current == NULL || (SV->ten < current->ten) || (SV->ten == current->ten && SV->ho < current->ho)) {
			SV->pnext = current;
			if (prevSV != NULL) {
				prevSV->pnext = SV;
			}
			else {
				dssv.phead = SV;
			}
		}
		else {
			while (current->pnext != NULL && (current->pnext->ten < SV->ten || (current->pnext->ten == SV->ten && current->pnext->ho < SV->ho))) {
				current = current->pnext;
			}
			SV->pnext = current->pnext;
			current->pnext = SV;
		}
		dssv.sl++;
		prevSV = NULL;
		current = dssv.phead;
	} while (true);
}
Sinhvien* menu_ds_SV(dsSV& dssv, int& page, int maxpage) {
	int choice = page * 11 - 11;
	int option = dssv.sl;
	Sinhvien* SV = dssv.phead;
	do {
		int count = 0;
		int jy = 3;
		Sinhvien* SV = dssv.phead;
		system("cls");
		khung(0, 0, 115, 2);
		if (page > 1) {
			for (int h = 1; h <= 11 * (page - 1); ++h) {
				SV = SV->pnext;
				++count;
			}
		}
		for (int i = page * 11 - 11; i < 11 * page && SV != NULL; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			in_thong_tin_SV(SV, jy);
			SV = SV->pnext;
			jy += 2;
		}
		char key;
		key = _getch();
		if (key == 27) return NULL;
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = dssv.sl - 1;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 11 - 11;
				highlight(choice);
			}
			else if (choice > page * 11 - 1) {
				choice = page * 11 - 11;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case 13: {
			SV = dssv.phead;
			for (int i = 0; i < choice && SV != NULL; ++i) {
				SV = SV->pnext;
			}
			return SV;
		}
		case 75: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		case 77: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		}
	} while (1);
}
void xoa_SV(dsSV& dssv, Sinhvien* sv) {
	Sinhvien* current = dssv.phead;
	Sinhvien* prev = nullptr;
	if (sv == NULL) return;
	if (current == nullptr) {
		cout << "Danh sach rong." << endl;
		return;
	}
	if (current != nullptr && current->MaSV == sv->MaSV) {
		dssv.phead = current->pnext;
		delete current;
		dssv.sl--;
		return;
	}
	while (current != nullptr && current->MaSV != sv->MaSV) {
		prev = current;
		current = current->pnext;
	}
	if (current == nullptr) {
		cout << "Khong tim thay sinh vien can xoa." << endl;
		return;
	}
	prev->pnext = current->pnext;
	delete current;
	dssv.sl--;
}
void hieu_chinh_SV(dsSV& dssv, Sinhvien* sv) {
	system("cls");
	Sinhvien* tmp = dssv.phead;
	Sinhvien* prevtmp = NULL;
	if (sv == NULL) return;
	while (tmp != NULL) {
		if (tmp->MaSV == sv->MaSV) {
			cout << "Nhap ho sinh vien:";
			nhap_ho_SV(tmp->ho);
			cout << "\nnhap ten sinh vien:";
			nhap_ten_SV(tmp->ten);
			cout << "\nnhap gioi tinh: ";
			nhap_gioi_tinh(tmp->phai);
			cout << "\nnhap so dien thoai: ";
			nhap_SDT(tmp->SDT);
			break;
		}
		prevtmp = tmp;
		tmp = tmp->pnext;
	}
	if (tmp == NULL) {
		cout << "Khong tim thay sinh vien co MaSV = " << sv->MaSV << endl;
		return;
	}
	if (prevtmp != NULL) {
		prevtmp->pnext = tmp->pnext;
	}
	else {
		dssv.phead = tmp->pnext;
	}
	Sinhvien* cur = dssv.phead;
	Sinhvien* prevcur = NULL;

	while (cur != NULL && (cur->ten < tmp->ten || (cur->ten == tmp->ten && cur->ho < tmp->ho))) {
		prevcur = cur;
		cur = cur->pnext;
	}
	if (prevcur != NULL) {
		tmp->pnext = cur;
		prevcur->pnext = tmp;
	}
	else {
		tmp->pnext = dssv.phead;
		dssv.phead = tmp;
	}
}
void kiem_tra_ds_SV(dsLop& dslop) {
	string malop;
	char c;
	int curpage = 1;
	cout << "nhap ma lop: ";
	cin.ignore();
	getline(cin, malop);
	for (int i = 0; i < dslop.soluong; ++i) {
		if (malop == dslop.ds_lop[i].MALOP) {
			while (1) {
				int page;
				if (dslop.ds_lop[i].pdsSV.sl % 11 != 0) {
					page = dslop.ds_lop[i].pdsSV.sl / 11 + 1;
				}
				else page = dslop.ds_lop[i].pdsSV.sl / 11;
				system("cls");
				khung(0, 0, 115, 2);
				in_ds_SV(dslop.ds_lop[i].pdsSV, curpage);
				gotoxy(120, 0); cout << curpage << "/" << page;
				c = _getch();
				if (c == 27) return;
				switch (c) {
				case 'a': {
					system("cls");
					khung(0, 0, 115, 2);
					nhap_SV(dslop.ds_lop[i].pdsSV);
					break;
				}
				case 'e': {
					system("cls");
					khung(0, 0, 115, 2);
					hieu_chinh_SV(dslop.ds_lop[i].pdsSV, menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page));
					break;
				}
				case 'd': {
					system("cls");
					khung(0, 0, 115, 2);
					xoa_SV(dslop.ds_lop[i].pdsSV, menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page));
					break;
				}
				case 75: {
					if (curpage > 1)
						curpage--;
				}
				case 77: {
					if (curpage < page)
						curpage++;
				}
				}
			}
		}
		else continue;
	}
	if (dslop.soluong < 2000) {
		dslop.ds_lop[dslop.soluong].MALOP = malop;
		while (1) {
			int page;
			if (dslop.ds_lop[dslop.soluong].pdsSV.sl % 11 != 0) {
				page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11 + 1;
			}
			else page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11;
			system("cls");
			khung(0, 0, 115, 2);
			gotoxy(120, 0); cout << curpage << "/" << page;
			in_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage);
			c = _getch();
			if (c == 27) break;
			switch (c) {
			case 'a': {
				system("cls");
				khung(0, 0, 115, 2);
				nhap_SV(dslop.ds_lop[dslop.soluong].pdsSV);
				break;
			}
			case 'e': {
				system("cls");
				khung(0, 0, 115, 2);
				hieu_chinh_SV(dslop.ds_lop[dslop.soluong].pdsSV, menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page));
				break;
			}
			case 'd': {
				system("cls");
				khung(0, 0, 115, 2);
				xoa_SV(dslop.ds_lop[dslop.soluong].pdsSV, menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page));
				break;
			}
			case 75: {
				if(curpage > 1)
				--curpage;
				break;
			}
			case 77: {
				if(curpage < page)
				++curpage;
				break;
			}
			}
		}
		dslop.soluong++;
	}
	else {
		cout << "danh sach lop da day!";
	}
}
void In_ds_SV_cua_lop(dsLop& dsLop) {
	Lop lop;
	cout << "nhap ma lop:";
	cin.ignore();
	getline(cin, lop.MALOP);
	system("cls");
	khung(0, 0, 112, 2);
	for (int i = 0; i < dsLop.soluong; ++i) {
		if (dsLop.ds_lop[i].MALOP == lop.MALOP) {
			in_ds_SV(dsLop.ds_lop[i].pdsSV, 1);
			break;
		}
	}
}
void readfile(string str) {
	ifstream fileinput(str, ios::app);
	if (fileinput.fail()) {
		cout << "khong the mo file" << endl;
	}
	while (!fileinput.eof()) {
		string s;
		getline(fileinput, s);
		cout << s << endl;
	}
}
void writefile(string str) {
	ofstream fileoutput(str, ios::app);
	string s;
	getline(cin, s);
	if (fileoutput.is_open()) {
		//fileoutput.seekp(0,ios::end);
		fileoutput << s << endl;
	}
}
// ============================================ DANH SACH MON HOC ==================================================
string sinh_ma_mon(string tenMH) {
	string MM = "";
	stringstream ss(tenMH);
	string token;
	while (ss >> token) {
		MM += toupper(token[0]);
	}
	if (MM.length() < 16) {
		if ('1' < MM[MM.length() - 1] && MM[MM.length() - 1] < '9') MM.insert(MM.length() - 1, 1, '1');
		else MM.insert(MM.length(), 1, '1');
	}
	//++code_counter;
	//MM += to_string(code_counter);
	return MM;
}
void nhap_ten_MH(string& tenMH) {
	char c;
	cout << tenMH;
	while (true) {
		c = _getch();
		if (c == 13) {
			break;
		}
		if (tenMH.length() > 15) continue;
		if (!isalpha(c) && c != ' ' && c != 8) continue;
		if (c == ' ' || isalpha(c)) {
			if ((tenMH.empty() && c == ' ') || (!tenMH.empty() && tenMH[tenMH.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == 8) {
			if (tenMH.empty()) continue;
			else {
				tenMH.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		tenMH += c;
	}
}
void khung_ds_MH(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 29) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 10, y += 1); cout << "MA MH";
	gotoxy(x += 29, y); cout << "TEN MH";
	gotoxy(x += 29, y); cout << "STCLT";
	gotoxy(x += 29, y); cout << "STCTH";
	gotoxy(0, 27); cout << "A:Them SV";
	gotoxy(15, 27); cout << "E: Hieu chinh";
	gotoxy(35, 27); cout << "D: Xoa SV";
	gotoxy(55, 27); cout << "ESC: Thoat";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void xoay_trai(MonHoc*& MH) {
	MonHoc* tmp;
	if (MH == NULL) return;
	if (MH->pright == NULL) return;
	else {
		tmp = MH->pright;
		MH->pright = tmp->pleft;
		tmp->pleft = MH;
	}
}
void xoay_phai(MonHoc*& MH) {
	MonHoc* tmp;
	if (MH == NULL) return;
	if (MH->pleft == NULL) return;
	else {
		tmp = MH->pleft;
		MH->pleft = tmp->pright;
		tmp->pright = MH;
	}
}
int chieu_cao(MonHoc* MH) {
	if (MH == NULL) return 0;
	int left = chieu_cao(MH->pleft);
	int right = chieu_cao(MH->pright);
	return max(left, right) + 1;
}
int check_can_bang(MonHoc* MH) {
	if (MH == NULL) return 1;
	int lh = chieu_cao(MH->pleft);
	int rh = chieu_cao(MH->pright);
	if (abs(lh - rh) > 1) return 0;
	return check_can_bang(MH->pleft) && check_can_bang(MH->pright);
}
int bf(MonHoc* MH) {
	return chieu_cao(MH->pleft) - chieu_cao(MH->pright);
}
void can_bang(MonHoc*& MH) {
	if (!check_can_bang(MH)) {
		if (chieu_cao(MH->pleft) > chieu_cao(MH->pright)) {
			MonHoc* tmp = MH->pleft;
			if (chieu_cao(tmp->pleft) >= chieu_cao(tmp->pright)) {
				xoay_phai(MH);
			}
			else {
				xoay_trai(MH->pleft);
				xoay_phai(MH);
			}
		}
		else {
			MonHoc* tmp = MH->pright;
			if (chieu_cao(tmp->pright) >= chieu_cao(tmp->pleft)) {
				xoay_trai(tmp);
			}
			else {
				xoay_phai(tmp->pright);
				xoay_trai(tmp);
			}
		}
	}
	if (MH->pleft != NULL) can_bang(MH->pleft);
	if (MH->pright != NULL) can_bang(MH->pright);
}
int them_MH(MonHoc*& dsMH, string tenMH, int& y) {
	int x = 59;
	if (dsMH == NULL) {
		gotoxy(x, y);
		dsMH = new MonHoc();
		dsMH->TenMH = tenMH;
		cout << "Enter STCLT: ";
		cin >> dsMH->STCLT;
		gotoxy(x += 29, y);
		cout << "Enter STCTH: ";
		cin >> dsMH->STCTH;
		dsMH->MaMon = sinh_ma_mon(dsMH->TenMH);
		dsMH->pleft = NULL;
		dsMH->pright = NULL;
		return 1;
	}
	else if (dsMH->TenMH == tenMH) {
		cout << "Mon hoc da ton tai!" << endl;
		return 0;
	}
	else if (tenMH > dsMH->TenMH) {
		int result = them_MH(dsMH->pright, tenMH, y);
		return result;
	}
	else if (tenMH < dsMH->TenMH) {
		int result = them_MH(dsMH->pleft, tenMH, y);
		return result;
	}
	can_bang(dsMH);
	return 0;
}
void thay_the(MonHoc*& tmp, MonHoc*& MH) {
	if (MH->pleft != NULL) thay_the(tmp, MH->pleft);
	else {
		tmp->MaMon = MH->MaMon;
		tmp->TenMH = MH->TenMH;
		tmp->STCLT = MH->STCLT;
		tmp->STCTH = MH->STCTH;
		MonHoc* rightChild = MH->pright;
		delete MH;
		MH = rightChild;
	}
}
void xoa_MH(MonHoc*& dsMH, string tenMH) {
	if (dsMH == NULL) return;
	if (dsMH->TenMH < tenMH) xoa_MH(dsMH->pright, tenMH);
	else if (dsMH->TenMH > tenMH) xoa_MH(dsMH->pleft, tenMH);
	else {
		MonHoc* tmp = dsMH;
		if (tmp->pleft == NULL) dsMH = tmp->pright;
		else if (tmp->pright == NULL) dsMH = tmp->pleft;
		else {
			thay_the(tmp, tmp->pright);
		}
		delete tmp;
	}
}
void hieu_chinh_MH(MonHoc*& dsMH, string tenMH) {
	system("cls");
	int y = 3;
	if (dsMH == NULL) return;
	MonHoc* tmp = dsMH;
	while (tmp != NULL && tmp->TenMH != tenMH) {
		if (tmp->TenMH > tenMH) tmp = tmp->pleft;
		else if (tmp->TenMH < tenMH) tmp = tmp->pright;
	}
	cout << "nhap ten mon hoc: ";
	string newTenMH;
	nhap_ten_MH(newTenMH);
	them_MH(dsMH, newTenMH, y);
	xoa_MH(dsMH, tenMH);
}
void in_ds_MH(MonHoc*& MH, int& y, int& count, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH(MH->pleft, y, count, page);
		++count;
		if (page > 1) {
			if ((page - 1) * 22 < count && count < page * 22) {
				gotoxy(x, y);
				cout << MH->MaMon;
				gotoxy(x += 29, y);
				cout << MH->TenMH;
				gotoxy(x += 29, y);
				cout << MH->STCLT;
				gotoxy(x += 29, y);
				cout << MH->STCTH;
				y += 1;
			}
		}
		else if (count < 22) {
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 29, y);
			cout << MH->TenMH;
			gotoxy(x += 29, y);
			cout << MH->STCLT;
			gotoxy(x += 29, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH(MH->pright, y, count, page);
	}
}
void in_ds_MH(MonHoc*& MH, int choice, int& count, int& y, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH(MH->pleft, choice, count, y, page);
		count++;
		if ((page - 1) * 22 < count && count < page * 22) {
			if (choice == count - 1) SetColor(9);
			else SetColor(7);
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 29, y);
			cout << MH->TenMH;
			gotoxy(x += 29, y);
			cout << MH->STCLT;
			gotoxy(x += 29, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH(MH->pright, choice, count, y, page);
	}
}
string tim_MH(MonHoc*& dsMH, int choice, int& count) {
	if (dsMH != NULL) {
		string leftResult = tim_MH(dsMH->pleft, choice, count);
		++count;
		if (choice == count - 1) {
			return dsMH->TenMH;
		}
		string rightResult = tim_MH(dsMH->pright, choice, count);
		if (leftResult != "") {
			return leftResult;
		}
		else {
			return rightResult;
		}
	}
	return "";
}
string menu_ds_MH(dsMonHoc& dsMH, int page, int maxpage, string& selected) {
	int choice = page * 22 - 22;
	int option = dsMH.sl;
	while (1) {
		int count = 0;
		int y = 3;
		system("cls");
		khung_ds_MH(0, 0, 116, 2);
		in_ds_MH(dsMH.ds, choice, count, y, page);
		char key;
		key = _getch();
		if (key == 27) break;
		if (key == 13) {
			count = 0;
			selected = tim_MH(dsMH.ds, choice, count);
			return selected;
		}
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 22 - 22) {
				if (page < maxpage) {
					choice = page * 22 - 1;
				}
				else {
					choice = dsMH.sl - 1;
				}
			}
			//if (choice < 0) choice = option - 1;
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 22 - 22;
			}
			else if (choice > page * 22 - 1) {
				choice = page * 22 - 22;
			}
			//if (choice > option - 1) choice = 0;
			break;
		}
		case 75: {
			if (page > 1) {
				page--;
				choice = page * 22 - 22;
				//highlight(choice);
			}
			break;
		}
		case 77: {
			if (page * 22 < option) {
				page++;
				choice = page * 22 - 22;
				//highlight(choice);
			}
			break;
		}
		}
	}
}
void ds_MH(dsMonHoc& dsMH) {
	int maxpage;
	int page = 1;
	char c;
	while (1) {
		int count = 0;
		int y = 3;
		if (dsMH.sl % 22 != 0)
			maxpage = dsMH.sl / 22 + 1;
		else maxpage = dsMH.sl / 22;
		system("cls");
		khung_ds_MH(0, 0, 116, 2);
		in_ds_MH(dsMH.ds, y, count, page);
		gotoxy(120, 3);
		cout << page << '/' << maxpage;
		c = _getch();
		if (c == 27) break;
		switch (c) {
		case 'a': {
			while (1) {
				gotoxy(30, y);
				string tenMH = "";
				nhap_ten_MH(tenMH);
				if (tenMH == "") break;
				if (them_MH(dsMH.ds, tenMH, y)) {
					dsMH.sl++;
					++y;
				}
			}
			break;
		}
		case 'e': {
			string selected;
			menu_ds_MH(dsMH, page, maxpage, selected);
			hieu_chinh_MH(dsMH.ds, selected);
			break;
		}
		case 'd': {
			system("cls");
			string selected;
			menu_ds_MH(dsMH, page, maxpage, selected);
			xoa_MH(dsMH.ds, selected);
			dsMH.sl--;
			--y;
			break;
		}
		case 75: {
			if (page > 1)
				--page;
			break;
		}
		case 77: {
			if (page < maxpage)
				++page;
			break;
		}
		}
	}
}
int main() {   
	//SetColor(4);
	//readfile("graph.txt");
	//system("pause");
// ========================================== ds lop ==================================
	dsLop dslop;
	dsMonHoc dsMH;
	int choice = 0;
	int option = 4;
	while (1) {
		clrscr();
		gotoxy(20, 0);
		SetColor(7);
		cout << "MENU" << endl;
		for (int i = 0; i < option; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			switch (i) {
			case 0: {
				cout << "1. cap nhat sinh vien cua lop";
				break;
			}
			case 1: {
				cout << "2. mo lop TC";
				break;
			}
			case 2: {
				cout << "3. cap nhat danh sach mon hoc";
				break;
			}
			case 3: {
				cout << "4. thoat";
				break;
			}
			}
		}
		char key;
		key = _getch();
		switch (key)
		{
		case 72: {
			--choice;
			if (choice < 0) {
				choice = 2;
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = 0;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case 13: {
			system("cls");
			switch (choice) {
			case 0: {
				kiem_tra_ds_SV(dslop);
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				In_ds_SV_cua_lop(dslop);
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				ds_MH(dsMH);
				break;
			}
			case 3: {
				system("cls");
				return 0;
			}
			}
		}
		}
	}
// ========================================= ds lop TC =======================================
	//khung_LTC(0, 0, 120, 2);
	//_getch();
	return 0;
}
