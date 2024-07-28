#pragma once
string getOnlyWord_Number(string &input, int limit)//Chỉ lấy chử và số
{
    char ch;
    input.clear();
    while (true) 
    {
        ch = _getch(); 
        if (ch == 13 && !input.empty()) //Khi enter thi break
        {
            break;
        }

        if (isalnum(ch) && size(input) < limit) //la chu thi them vao mang input
        { 
            char tempCout = toupper(ch);
            input += tempCout;
            cout << tempCout; 
        }
        else if (ch == 8 && !input.empty()) //neu la backspace thi luoi cout lai = xoa
        {
            input.pop_back();//pop_back la ham de xoa ky tu cuoi cung trong chuoi, dong thoi giam do dai cua chui -1
            cout << "\b \b";
        }
    }

    return input;
}

string getOnlyWord_Number_forMaSV(string &input, int limit)//Chỉ lấy chử và số
{
    char ch;
    input.clear();
    while (true) 
    {
        ch = _getch(); 
        if (ch == 13 && input.empty()) //Kiem tra neu rong thi break (chi su dung cho MSSV)
        {
            break;
        }
        if (ch == 13 && !input.empty()) //Khi enter thi break
        {
            break;
        }

        if (isalnum(ch) && size(input) < limit) //la chu thi them vao mang input
        { 
            char tempCout = toupper(ch);
            input += tempCout;
            cout << tempCout; 
        }
        else if (ch == 8 && !input.empty()) //neu la backspace thi luoi cout lai = xoa
        {
            input.pop_back();//pop_back la ham de xoa ky tu cuoi cung trong chuoi, dong thoi giam do dai cua chui -1
            cout << "\b \b";
        }
    }
    return input;
}
string getOnlyWord(string &input, int limit)//chỉ lấy chữ
{
    char ch;
    input.clear();
    while (true)
    {
        ch = _getch();

        if (ch == 13 && !input.empty())
        {
            break;
        }

        if (isalpha(ch) && size(input) < limit)
        {
            char tempCout = toupper(ch);
            input += tempCout;
            cout << tempCout; 
        }
        else if (ch == 8 && !input.empty())
        {
            input.pop_back();
            cout << "\b \b";
        }
    }
    return input;
}

string getOnlyWord_Space(string &input, int limit)
{
    char ch;
    bool haveSpaced = false;// Bien de danh dau viec da cách hay chua
    input.clear();
    while (true)
    {
        ch = _getch();

        if (ch == 13 && !input.empty())
        {
            break;
        }

        if (isalpha(ch) && size(input) < limit )
        {
            char tempCout = toupper(ch);
            input += tempCout;
            cout << tempCout;
            haveSpaced = false;//tra ve false khi input nhap vao la chu
        }
        else if (ch == 32 && !haveSpaced && !input.empty() && input.size() < limit)
        {
            input += ch;
            cout << ch;
            haveSpaced = true;
            //tra ve true khi input nhap vao la dau cach, de dieu kien tro thanh sai 
            //=> khong the nhan cach nua
        }
        else if (ch == 8 && !input.empty())
        {
            input.pop_back();
            cout << "\b \b";
        }
    }
    return input;
}

string getOnlyNumber(string &input, int limit)
{
    char ch;
    input.clear();
    while (true)
    {
        ch = _getch();
        if (ch == 13 && !input.empty())
        {
            break;
        }
        if (isdigit(ch) && size(input) < limit)
        {
            char tempCout = toupper(ch);
            input += tempCout;
            cout << tempCout; 
        }
        else if (ch == 8 && !input.empty())
        {
            input.pop_back();
            cout << "\b \b";
        }
    }
    return input;
}

