#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// Function to set cursor position
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to get console window dimensions
void getConsoleSize(int &cols, int &rows)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Function to draw the menu
void drawMenu(int highlight, const string options[], int menuSize)
{
    // Clear the console
    system("cls");

    int cols, rows;
    getConsoleSize(cols, rows);

    int menuWidth = 20;
    int menuHeight = menuSize * 2;

    // Calculate top left corner to center the menu
    int startX = (cols - menuWidth) / 2;
    int startY = (rows - menuHeight) / 2;

    // Draw the menu
    for (int i = 0; i < menuSize; ++i)
    {
        // Highlight selected option
        if (i == highlight)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240); // Highlight color
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal color
        }

        // Draw the outline
        for (int j = 0; j < menuWidth; ++j)
        {
            gotoxy(startX + j, startY + i * 2);
            cout << "-";
        }
        for (int j = 0; j < menuWidth; ++j)
        {
            gotoxy(startX + j, startY + i * 2 + 1);
            cout << " ";
        }
        gotoxy(startX, startY + i * 2 + 1);
        cout << "|";
        gotoxy(startX + menuWidth - 1, startY + i * 2 + 1);
        cout << "|";

        // Draw the menu text
        gotoxy(startX + 3, startY + i * 2 + 1);
        cout << options[i];
    }

    // Reset text attribute
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    // Reset cursor position
    gotoxy(0, startY + menuHeight + 1);
}

// Function to handle arrow key input and menu navigation
void moveByArrow(int &highlight, int menuSize)
{
    int key = _getch();
    if (key == 224) // Arrow keys are preceded by 224
    {
        key = _getch();
        switch (key)
        {
            case 72: // Up arrow key
                highlight = (highlight - 1 + menuSize) % menuSize;
                break;
            case 80: // Down arrow key
                highlight = (highlight + 1) % menuSize;
                break;
        }
    }
}

// Function to display and handle menu
void displayMenu()
{
    string options[] = {
        "1. Option 1",
        "2. Option 2",
        "3. Option 3",
        "4. Option 4",
        "5. Exit"
    };

    int highlight = 0;
    int option = 0;
    int menuSize = sizeof(options) / sizeof(options[0]);

    while (true)
    {
        drawMenu(highlight, options, menuSize);
        moveByArrow(highlight, menuSize);

        if (_kbhit())
        {
            int key = _getch();
            if (key == 13) // Enter key
            {
                option = highlight;
                system("cls");
                cout << "Option " << option + 1 << " Selected" << endl;
                if (option == 4) // Exit option
                {
                    break;
                }
                system("pause");
            }
        }
    }
}

int main()
{
    displayMenu();
    return 0;
}
