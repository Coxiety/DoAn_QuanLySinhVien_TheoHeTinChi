#include <windows.h>
#include <iostream>
using namespace std;

// Khai báo các hàm
void gotoxy(short x, short y);
int wherex();
int wherey();
void SetColor(WORD color);
void SetBGColor(WORD color);
void clrscr();
void veHinhChuNhat(int width, int height, WORD color, const string& text);

int main() {
    // Xóa màn hình
    clrscr();
    
    // Đặt màu chữ
    SetColor(15);
    
    // Vẽ hình chữ nhật với chiều rộng, chiều cao và màu sắc được chỉ định
    // In văn bản bên trong hình chữ nhật
    veHinhChuNhat(30, 10, 2, "Hello, world!"); // chiều rộng: 30, chiều cao: 10, màu: xanh lá, văn bản: "Hello, world!"
    
    // Đợi người dùng nhấn phím
    system("pause");
    return 0;
}

void gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex() {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey() {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}

void SetColor(WORD color) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBGColor(WORD color) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void clrscr() {
    system("cls");
}

void veHinhChuNhat(int width, int height, WORD color, const string& text) {
    // Lấy kích thước cửa sổ console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    
    // Tính toán tọa độ góc trên bên trái của hình chữ nhật
    int startX = (columns - width) / 2;
    int startY = (rows - height) / 2;
    
    // Đặt màu nền
    SetBGColor(color);

    // Vẽ đường viền trên và dưới
    gotoxy(startX, startY);
    for (int i = 0; i < width; ++i) cout << " ";
    gotoxy(startX, startY + height - 1);
    for (int i = 0; i < width; ++i) cout << " ";
    
    // Vẽ đường viền bên trái và bên phải
    for (int i = 1; i < height - 1; ++i) {
        gotoxy(startX, startY + i);
        cout << " ";
        gotoxy(startX + width - 1, startY + i);
        cout << " ";
    }

    // Tính toán tọa độ để in văn bản bên trong hình chữ nhật
    int textX = startX + (width - text.length()) / 2;
    int textY = startY + height / 2;

    // Đặt lại màu nền để in văn bản
    SetBGColor(0);

    // In văn bản bên trong hình chữ nhật
    gotoxy(textX, textY);
    cout << text;
}
