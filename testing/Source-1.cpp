void printUniqueMaLop(const string& fileName) {
    ifstream infile(fileName);
    
    if (!infile.is_open()) {
        cout << "Không thể mở file " << fileName << endl;
        return;
    }

    string line;
    string lastMaLop = "";

    while (getline(infile, line)) {
        string maLop = line.substr(0, line.find(' '));
        
        if (maLop != lastMaLop) {
            cout << maLop << endl;
            lastMaLop = maLop;
        }

        // Bỏ qua các dòng khác của sinh viên
        for (int i = 0; i < 4; i++) {
            getline(infile, line);
        }
    }

    infile.close();
}