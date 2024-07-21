#include "CTDL.h"
#include "xuly.h"
#include <windows.h>
#include "mylib.h"
#include <fstream>
using namespace std;
const int up = 72;
const int down = 80;
const int enter = 13;
int menu() {
	int choice = 0;
	int option = 4;
	while (true) {
		clrscr();
		gotoxy(20, 0);
		SetColor(7);
		cout << "MENU" << endl;
		for (int i = 0; i <= option; ++i) {
			if (choice == i) {
				SetColor(3);
				highlight(i);
			}
			else {
				SetColor(7);
				normal(i);
			}
			switch (i) {
			case 0: {
				cout << "Mo lop tin chi";
				break;
			}
			case 1: {
				cout << "lua chon so 2";
				break;
			}
			case 2: {
				cout << "lua chon so 3";
				break;
			}
			case 3: {
				cout << "lua chon so 4";
				break;
			}
			case 4: {
				cout << "exit!" << endl;
				break;
			}
			}
		}
		char key;
		key = _getch();
		switch (key)
		{
		case up: {
			--choice;
			if (choice < 0) {
				choice = 4;
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		}
		case down: {
			++choice;
			if (choice > option) {
				choice = 0;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case enter: {
			return choice;
		}
		}
	}
}
void savefile(string file) {
	ofstream fileoutput(file);
	string s;
	getline(cin, s);
	if (fileoutput.is_open()) {
		//fileoutput.seekp(0,ios::end);
		fileoutput << s << endl;
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
int main() {
	int key;
	//menu();
	switch (menu()) {
	case 1: {
		kekhung();
		gotoxy(1, 3);
		cout << "anh Hung DakLak";
	}
	}
	
	return 0;
}
/*#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <string>
#include "mylib.h"

using namespace std;
const int MAXLIST = 20000;

const int so_item = 8;
const int dong = 10;
const int cot = 30;
const int Up = 72; // Extended code 
const int Down = 80;

char thucdon[so_item][50] = { "1. Nhap danh sach hoc vien",
							  "2. Liet ke danh sach      ",
							  "3. Tim kiem hoc vien      ",
							  "4. Xoa hoc vien theo ten  ",
							  "5. Ghi danh sach          ",
							  "6. Mo  danh sach          ",
							  "7. Them sv co thu tu      ",
							  "8. Ket thuc chuong trinh  " };

struct Sinhvien {
	int maso;
	char ho[50];
	char ten[10];

};

struct list {
	int n = 0;
	Sinhvien* nodes[MAXLIST];
};

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void HighLight() {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td[so_item][50]) {

	Normal(); system("cls");
	int chon = 0;
	int i;
	for (i = 0; i < so_item; i++)
	{
		gotoxy(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoxy(cot, dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case Up:if (chon + 1 > 1)
		{
			Normal();
			gotoxy(cot, dong + chon);
			cout << td[chon];
			chon--;
			HighLight();
			gotoxy(cot, dong + chon);
			cout << td[chon];

		}
			   break;
		case Down:if (chon + 1 < so_item)
		{
			Normal();
			gotoxy(cot, dong + chon);
			cout << td[chon];
			chon++;
			HighLight();
			gotoxy(cot, dong + chon);
			cout << td[chon];

		}
				 break;
		case 13: return chon + 1;
		}  // end switch
	} while (1);
}

int Search(list& ds, int x) {// T(n)= 4n+1+1=4n+2
	for (int i = 0; i < ds.n; i++)
		if (ds.nodes[i]->maso == x) return i;
	return -1;
}


void BaoLoi(string s) {
	int x = wherex(), y = wherey();
	gotoxy(10, 24);
	cout << s;
	Sleep(2000);
	gotoxy(10, 24);
	clreol();
	gotoxy(x, y);
}
void NhapChuoi(string tieude, string S) {
	cout << tieude;  fflush(stdin);
	do
		getline(cin, S);
	while (strlen(S.c_str()) == 0);
}

int  NhapSV(list& ds, Sinhvien& sv) {
	while (1) {
		cout << "Nhap ma so (<=0 la ket thuc) : ";
		cin >> sv.maso;
		if (sv.maso <= 0) return 0;
		if (Search(ds, sv.maso) >= 0) {
			BaoLoi("Ma so sinh vien bi trung");
			continue;
		}
		NhapChuoi("Nhap Ho: ", sv.ho);  // cout << "Ho : " ; gets(sv.ho);
		NhapChuoi("Nhap ten:", sv.ten);
		return 1;
	}
}
void NhapDSSV(list& ds, int flag) {
	Sinhvien sv;

	if (flag == 0) // nhap moi tu dau
		while (ds.n > 0) {
			delete ds.nodes[ds.n - 1];
			ds.n--;
		}

	while (ds.n < MAXLIST)
	{
		if (NhapSV(ds, sv) == 0)  return;
		ds.nodes[ds.n] = new Sinhvien;
		*ds.nodes[ds.n] = sv;
		ds.n++;
	}
	if (ds.n == MAXLIST) BaoLoi("Danh sach day");
}
void LietKe(list& ds) {
	system("cls");
	printf("                     DANH SACH SINH VIEN \n");
	printf("   Ma so       Ho   va ten \n");
	for (int i = 0; i < ds.n; i++)
		printf("%8d %-30s%-10s\n", ds.nodes[i]->maso,
			ds.nodes[i]->ho, ds.nodes[i]->ten);
	_getch();
}

void ThongTinSv(list& ds, int maso) {
	int i = Search(ds, maso);
	if (i == -1) BaoLoi("Ma so sinh vien khong co trong danh sach");
	else {
		printf(" Ho ten sv : %30s%10s", ds.nodes[i]->ho, ds.nodes[i]->ten);
		_getch();
	}
}
void SaveFile(list& ds, char* filename) {
	FILE* f;
	if ((f = fopen(filename, "wb")) == NULL)
	{
		BaoLoi("Loi mo file de ghi"); return;
	}

	for (int i = 0; i < ds.n; i++)
		fwrite(ds.nodes[i], sizeof(Sinhvien), 1, f);
	fclose(f);
	BaoLoi("Da ghi xong danh sach vao file");

}
void OpenFile(list& ds, char* filename) {
	FILE* f; Sinhvien sv;
	if ((f = fopen(filename, "rb")) == NULL)
	{
		BaoLoi("Loi mo file de doc"); return;
	}

	while (fread(&sv, sizeof(Sinhvien), 1, f) != 0) {
		ds.nodes[ds.n] = new Sinhvien;
		*ds.nodes[ds.n] = sv;
		ds.n++;
	}

	fclose(f);
	BaoLoi("Da load xong danh sach vao bo nho");

}
void DeleteItem(list& ds, int i) {
	delete  ds.nodes[i];
	for (int j = i + 1; j < ds.n; j++)
		ds.nodes[j - 1] = ds.nodes[j];
	ds.n--;
}
void XoaSv(list& ds, int maso) {
	int i = Search(ds, maso);
	if (i == -1) BaoLoi("Ma so sinh vien khong co trong danh sach");
	else  DeleteItem(ds, i);
}
int XoaSvTheoTen(list& ds, string ten) {
	int dem = 0;
	for (int i = 0; i < ds.n; )
		if (strlen(ten.c_str()) == 0)
		{
			DeleteItem(ds, i);
			dem++;
		}
		else i++;
	return dem;
}
int InsertOrder(list& ds, Sinhvien& sv) {
	int i, k;
	if (ds.n == MAXLIST) return 0;
	for (i = 0; i < ds.n && ds.nodes[i]->maso < sv.maso; i++);
	//	if (j< ds.n && ds.nodes[j]->maso == sv.maso) return -1;

	for (k = ds.n - 1; k >= i; k--)
		ds.nodes[k + 1] = ds.nodes[k];
	ds.nodes[i] = new Sinhvien;
	*ds.nodes[i] = sv; ds.n++;
	return 1;

}

int XoaTenSv(list& ds, char* tentemp)
{
	int countDelete = 0;
	for (int i = 0; i < ds.n; i++)
		if (strcmp(ds.nodes[i]->ten, tentemp) == 0)
		{
			delete ds.nodes[i];
			for (int j = i + 1; j < ds.n; j++)
				ds.nodes[j - 1] = ds.nodes[j];
			ds.n--;
			// i--; 
			countDelete++;
		}
	return countDelete;
}

int main() {
	system("cls");
	char filename[80] = "D:\\DSSV.TXT";
	string ten;
	int chon;  list ds; ds.n = 0; int maso; Sinhvien sv;
	//OpenFile(ds, filename);
	do
	{
		chon = MenuDong(thucdon);
		system("cls");
		switch (chon) {
		case 1: NhapDSSV(ds, 1); break;
		case 2: LietKe(ds); break;
		case 3: { printf("\n Ban nhap ma so sinh vien : ");
			cin >> maso;
			ThongTinSv(ds, maso); break;
		};
		case 4: { printf("\n Ban nhap ten sinh vien muon xoa : "); fflush(stdin);
			getline(cin, ten);
			cout << "Da xoa duoc " << XoaSvTheoTen(ds, ten) << " sinh vien.";
			break;
		};
		//case 5: SaveFile(ds, filename); break;
			//case 6: OpenFile(ds,filename); break;
		case 7: { if (NhapSV(ds, sv) == 1) InsertOrder(ds, sv);
			break;
		};

		//case so_item: { SaveFile(ds, filename); return 0; }
		}
	} while (1);
	return 0;
}*/
