void TypeWordAndSpace(string &result, int &step, bool Edited, bool &Saved, int Limit_word_length, int distance)
{
    int length = result.length();
    int cnt = length;
    gotoxy(X_Add + distance, Y_Add + (step - 1) * 4);
    cout << result;
    int event;

    while (true)
    {
        while (_kbhit())
        {
            event = _getch();
            if (event != 224 && event != 0)
            {
                if (event == KEY_UP)
                {
                    // if (!Edited) {
                    step--;
                    //}

                    return;
                }
                else if (isalpha(char(event)))
                {
                    if (cnt <= Limit_word_length)
                    {
                        char c = char(event);
                        cnt++;
                        c = toupper(c);
                        cout << c;
                        result += c;
                    }
                }
                else if (event == SPACE)
                {
                    if (result[result.length() - 1] != ' ')
                    {
                        cout << char(event);
                        result += char(event);
                        cnt++;
                    }
                }
                else if (event == ENTER)
                {
                    if (result == "")
                    {
                        Notification("Thong tin khong hop le, vui long nhap lai!");
                        cnt = 0;
                        gotoxy(X_Add + distance, Y_Add + (step - 1) * 4);
                        cout << "                     ";
                        gotoxy(X_Add + distance, Y_Add + (step - 1) * 4);
                        break;
                    }
                    if (result != "" && result[result.length() - 1] == ' ')
                    {
                        result = result.substr(0, result.length() - 1);
                    }
                    return;
                }
                else if (event == BACKSPACE && cnt > 0)
                {
                    cout << "\b" << " " << "\b";
                    result.erase(result.length() - 1, 1);
                    cnt--;
                }
                else if (event == ESC)
                {
                    Saved = false;
                    return;
                }
            }
        }
    }
}