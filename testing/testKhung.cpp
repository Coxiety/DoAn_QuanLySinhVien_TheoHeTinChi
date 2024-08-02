#include "mylibTest.h"

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

int main()
{
    khung_LTC(0, 0, 120, 2);
	_getch();
	return 0;
}