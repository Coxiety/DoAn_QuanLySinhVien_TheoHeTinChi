#include <iostream>
#include <conio.h> // Thư viện conio.h chỉ có trên Windows

void displayInfo(int highlight) {
    std::string fields[] = {"Lop: CNTT", "MSSV: 123456", "Ten: Nguyen Van A"};
    
    system("cls"); // Dùng để xóa màn hình, chỉ trên Windows

    for (int i = 0; i < 3; ++i) {
        if (i == highlight) {
            std::cout << "> " << fields[i] << std::endl;
        } else {
            std::cout << "  " << fields[i] << std::endl;
        }
    }
}

int main() {
    int highlight = 0;
    char ch;

    while (true) {
        displayInfo(highlight);
        
        ch = _getch(); // Bắt sự kiện phím

        switch (ch) {
            case 72: // Phím mũi tên lên
                highlight = (highlight - 1 + 3) % 3;
                break;
            case 80: // Phím mũi tên xuống
                highlight = (highlight + 1) % 3;
                break;
            case 27: // Phím ESC để thoát
                return 0;
        }
    }

    return 0;
}