#ifndef MYLIB_H
#define MYLIB_H
#include "mylib.h"
#include <iostream>
#include <windows.h>  // Thư viện cho hàm Sleep và gotoxy
#include <string>

using namespace std;

void SetBGColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (color << 4) | 0x0F);
}

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Các ký tự để vẽ khung
const char traitren = 218;  // ┌
const char phaitren = 191;  // ┐
const char traiduoi = 192;  // └
const char phaiduoi = 217;  // ┘
const char ngang = 196;     // ─
const char doc = 179;       // │
const char ngangxuong = 194; // ┬
const char docphai = 195;   // ├
const char doctrai = 180;   // ┤
const char giua = 197;      // ┼
const char nganglen = 193;  // ┴

#endif

void khung_bao_loi(string bao_loi, int x, int y, int w, int h) {
    for (int i = x; i <= x + w; ++i) {
        for (int iy = y; iy <= y + h; ++iy) {
            SetBGColor(8);
            gotoxy(i, iy);
            cout << " ";
            gotoxy(x + w, iy);
            cout << " ";
        }
    }
    for (int ix = x; ix <= x + w; ++ix) {
        SetBGColor(8);
        gotoxy(ix, y);
        cout << " ";
        gotoxy(ix, y);
        cout << " ";
        gotoxy(ix, y + h);
        cout << " ";
    }
    gotoxy(x + 2, y + h / 2); SetColor(10); cout << bao_loi;
    Sleep(1500); 
    for (int i = x; i <= x + w; ++i) {
        for (int iy = y; iy <= y + h; ++iy) {
            SetBGColor(0);
            gotoxy(i, iy);
            cout << " ";
            gotoxy(x + w, iy);
            cout << " ";
        }
    }
    for (int ix = x; ix <= x + w; ++ix) {
        SetBGColor(0);
        gotoxy(ix, y);
        cout << " ";
        gotoxy(ix, y);
        cout << " ";
        gotoxy(ix, y + h);
        cout << " ";
    }
}

void khung_lua_chon(int x, int y, int w, int h) {
    for (int i = x; i <= x + w; ++i) {
        for (int iy = y; iy <= y + h; ++iy) {
            gotoxy(x, iy);
            cout << char(179);
            gotoxy(x + w, iy);
            cout << char(179);
        }
    }
    for (int ix = x; ix <= x + w; ++ix) {
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y + h);
        cout << char(196);
    }
    gotoxy(x, y); cout << char(218);
    gotoxy(x + w, y); cout << char(191);
    gotoxy(x, y + h); cout << char(192);
    gotoxy(x + w, y + h); cout << char(217);
}

void khung_giao_dien_chinh() {
    int x = 0, y = 0, w = 132, h = 5, col = 1, line = 30;
    for (int i = 0; i <= w;) {
        for (int iy = y; iy <= y + line; ++iy) {
            SetBGColor(3);
            gotoxy(x, iy);
            cout << " ";
            if (i == 45) {
                if (iy >= h) gotoxy(i, iy);
                else continue;
            } else {
                gotoxy(i, iy);
                cout << " ";
            }
        }
        if (i == 0) i += 45;
        else i += w - 45;
    }
    for (int ix = x; ix <= x + w; ++ix) {
        gotoxy(ix, y);
        cout << " ";
        gotoxy(ix, y + h);
        cout << " ";
        gotoxy(ix, y + line);
        cout << " ";
    }
}

void nhap_thong_tin_in_diem(int x, int y, int w, int h, int line, int col) {
    SetColor(3);
    for (int i = x; i <= x + w; i += w / col) {
        for (int iy = y; iy < y + line; ++iy) {
            gotoxy(x, iy);
            cout << char(179);
            gotoxy(i, iy);
            cout << char(179);
        }
    }
    for (int ix = x + 1; ix < x + w; ++ix) {
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y + h);
        cout << char(196);
        gotoxy(ix, y + line);
        cout << char(196);
    }
    gotoxy(x, y); cout << char(218);
    gotoxy(x + w, y); cout << char(191);
    gotoxy(x, y + line); cout << char(192);
    gotoxy(x + w, y + line); cout << char(217);
    gotoxy(x += 5, y += 1); cout << "NIEN KHOA";
    gotoxy(x += 20, y); cout << "HOC KY";
}

void veKhung(int rong, int dai) {
    for (int i = 0; i < rong; i++) {
        for (int j = 0; j < dai; j++) {
            if (i == 0) {
                if (j == 0) cout << traitren;
                else if (j == dai - 1) cout << phaitren;
                else cout << ngang;
            } else if (i == rong - 1) {
                if (j == 0) cout << traiduoi;
                else if (j == dai - 1) cout << phaiduoi;
                else cout << ngang;
            } else {
                if (j == 0 || j == dai - 1) cout << doc;
                else cout << " ";
            }
        }
        gotoxy(wherex() - dai, wherey() + 1);
    }
}

void VeKhungTenSV(int dai, int rong, int socot) {
    int x = rong / socot;
    int dem = 1;
    for (int i = 0; i < dai; i++) {
        for (int j = 0; j < rong; j++) {
            if (dem == 1) {
                dem = 3;
            }
            if (dem == 4) {
                dem = 8;
            }
            if (i == 0) {
                if (j == 0) cout << traitren;
                else if (j == rong - 1) cout << phaitren;
                else if (j == (rong / socot) * dem) cout << ngangxuong;
                else cout << ngang;
            } else if (i == 2) {
                if (j == 0) cout << docphai;
                else if (j == rong - 1) cout << doctrai;
                else if (j == (rong / socot) * dem) cout << giua;
                else cout << ngang;
            } else if (i == dai - 1) {
                if (j == 0) cout << traiduoi;
                else if (j == rong - 1) cout << phaiduoi;
                else if (j == (rong / socot) * dem) cout << nganglen;
                else cout << ngang;
            } else if (j == (rong / socot) * dem) {
                cout << doc;
            } else {
                if (j == 0 || j == rong - 1) cout << doc;
                else cout << " ";
            }
            if (j == dem * (rong / socot)) dem++;
            if (dem == socot) dem = 1;
        }
        gotoxy(wherex() - rong, wherey() + 1);
    }
}

int main() {
    // Thiết lập các thông số cho các hàm vẽ khung
    int x = 10, y = 5, w = 50, h = 10;
    int line = 15, col = 3;

    // Vẽ khung chính giao diện
    khung_giao_dien_chinh();
    
    // Vẽ khung báo lỗi
    khung_bao_loi("Loi! Khong the thuc hien thao tac", x, y, w, h);
    
    // Vẽ khung lựa chọn
    khung_lua_chon(x, y, w, h);
    
    // Nhập thông tin và in điểm
    nhap_thong_tin_in_diem(x, y, w, h, line, col);

    // Vẽ khung tuỳ chỉnh
    veKhung(10, 40);  // Kích thước khung 10x40
    
    // Vẽ khung tên sinh viên
    VeKhungTenSV(5, 50, 4);  // Kích thước khung 5x50 với 4 cột

    return 0;
}