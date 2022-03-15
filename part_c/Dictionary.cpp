#include <fstream>
#include <iostream>
#include <vector>

#include "Dictionary.h"
#include "DictEntry.h"

const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt)";
std::unordered_map<std::string, std::vector<DictEntry>> entries;

Dictionary::Dictionary() {
    Dictionary::LoadDictionary();
}

void Dictionary::LoadDictionary() {
    std::string file_path = DEFAULT_SOURCE_PATH;
    std::fstream fs;

    std::cout << "! Opening data file... " << DEFAULT_SOURCE_PATH << "\n";

    while (true) {
        fs.open(file_path, std::ios::in);

        if (!fs.is_open()) {
            std::cout << "<!>ERROR<!> ===> File could not be opened.\n"
                      << "<!>ERROR<!> ===> Provided file path: " << file_path << "\n"
                      << "<!>Enter the CORRECT data file path: ";
            std::cin >> file_path;
            continue;
        }

        std::string line;
        while (std::getline(fs, line)) {
            std::string term;
            std::istringstream line_stream(line);
            std::getline(line_stream, term, '|');

            std::string rawDef;
            std::vector<DictEntry> definitions;
            while (std::getline(line_stream, rawDef, '|')) {
                definitions.push_back(ParseEntry(rawDef));
            }

            Dictionary::entries.emplace(term, definitions);
        }

        fs.close();
        return;
    }
}

DictEntry Dictionary::ParseEntry(const std::string &s) {
    const std::string delim = " -=>> ";
    int delim_pos = s.find(delim);
    const std::string pos = s.substr(0, delim_pos);
    const std::string definition = s.substr(delim_pos + delim.length());
    std::cout << "POS: " << pos << ", def: " << definition << "\n";
    return {pos, definition};
}
