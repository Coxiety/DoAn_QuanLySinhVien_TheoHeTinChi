#pragma once

void boxNhapDiem(int x, int y, int w, int h) {
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + 2);
		cout << char(196);
		gotoxy(ix, y + 4);
		cout << char(196);
		gotoxy(ix, y + 6);
		cout << char(196);
		gotoxy(ix, y + 8);
		cout << char(196);
		gotoxy(ix, y + 10);
		cout << char(196);
		gotoxy(ix, y + 12);
		cout << char(196);
		gotoxy(ix, y + 14);
		cout << char(196);
		gotoxy(ix, y + 16);
		cout << char(196);
		gotoxy(ix, y + 18);
		cout << char(196);
		gotoxy(ix, y + 20);
		cout << char(196);
		gotoxy(ix, y + 22);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + 7, iy);
		cout << char(179);
		gotoxy(x + 25, iy);
		cout << char(179);
		gotoxy(x + 77, iy);
		cout << char(179);
		gotoxy(x + 89, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + 7, y); cout << char(194);
	gotoxy(x + 25, y); cout << char(194);
	gotoxy(x + 77, y); cout << char(194);
	gotoxy(x + 89, y); cout << char(194);
	gotoxy(x + 7, y + h); cout << char(193);
	gotoxy(x + 25, y + h); cout << char(193);
	gotoxy(x + 77, y + h); cout << char(193);
	gotoxy(x + 89, y + h); cout << char(193);
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + 14, y + 1); cout << "MASV";
	gotoxy(x + 50, y + 1); cout << "HO";
	gotoxy(x + 81, y + 1); cout << "TEN";
	gotoxy(x + 91, y + 1); cout << "DIEM";

}
void boxXoa(int x, int y, int w, int h)
{
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + 2);
		cout << char(196);
		gotoxy(ix, y + 4);
		cout << char(196);
		gotoxy(ix, y + 6);
		cout << char(196);
		gotoxy(ix, y + 8);
		cout << char(196);
		gotoxy(ix, y + 10);
		cout << char(196);
		gotoxy(ix, y + 12);
		cout << char(196);
		gotoxy(ix, y + 14);
		cout << char(196);
		gotoxy(ix, y + 16);
		cout << char(196);
		gotoxy(ix, y + 18);
		cout << char(196);
		gotoxy(ix, y + 20);
		cout << char(196);
		gotoxy(ix, y + 22);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + 12, iy);
		cout << char(179);
		gotoxy(x + 64, iy);
		cout << char(179);
		gotoxy(x + 71, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x + w, y + h); cout << char(217);

	gotoxy(x + 12, y); cout << char(194);
	gotoxy(x + 64, y); cout << char(194);
	gotoxy(x + 71, y); cout << char(194);

	gotoxy(x + 12, y + h); cout << char(193);
	gotoxy(x + 64, y + h); cout << char(193);
	gotoxy(x + 71, y + h); cout << char(193);

	gotoxy(x + 4, y + 1); cout << "MAMH";
	gotoxy(x + 36, y + 1); cout << "TENMH";
	gotoxy(x + 65, y + 1); cout << "STCLT";
	gotoxy(x + 72, y + 1); cout << "STCTH";


}