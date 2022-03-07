#include "Dictionary.h"
#include <fstream>
#include <iostream>

const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt)";

Dictionary::Dictionary() {
    Dictionary::LoadDictionary();
}

void Dictionary::LoadDictionary() {
    std::string file_path = DEFAULT_SOURCE_PATH;
    std::fstream fs;
    std::string line;

    std::cout << "! Opening data file... " << DEFAULT_SOURCE_PATH << "\n";

    while (true) {
        fs.open(file_path, std::ios::in);
        if (fs.is_open()) {
            while (std::getline(fs, line)) {
                std::cout << line << std::endl;
            }
            fs.close();
            return;
        }

        std::cout << "<!>ERROR<!> ===> File could not be opened.\n";
        std::cout << "<!>ERROR<!> ===> Provided file path: " << file_path << "\n";
        std::cout << "<!>Enter the CORRECT data file path: ";
        std::cin >> file_path;
    }
}

