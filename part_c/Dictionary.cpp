#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>

#include "Dictionary.h"
#include "DictEntry.h"
#include "DictClient.h"

//const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt)";
const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(Data.CS.SFSU.txt)";
const std::set<std::string>
    PARTS_OF_SPEECH{"adjective", "adverb", "conjunction", "interjection", "noun", "preposition", "pronoun", "verb"};

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

        int definition_count = 0, keyword_count = 0;

        std::string line;
        while (std::getline(fs, line)) {
            std::string term;
            std::istringstream line_stream(line);
            std::getline(line_stream, term, '|');

            std::string rawDef;
            std::vector<DictEntry> definitions;

            while (std::getline(line_stream, rawDef, '|')) {
                definitions.push_back(ParseEntry(rawDef));
                definition_count++;
            }

            Dictionary::entries.emplace(term, definitions);
            keyword_count++;
        }

        std::cout << "====== DICTIONARY 340 C++ =====\n"
                  << "------ Keywords: " << keyword_count << "\n"
                  << "------ Definitions: " << definition_count << "\n\n";

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

std::vector<DictEntry> Dictionary::QueryDict(std::string query_string) {
    std::transform(query_string.begin(), query_string.end(), query_string.begin(), ::tolower);
    std::istringstream iss(query_string);
    std::string arg;
    std::vector<DictEntry> query_res;

    std::vector<std::string> args_to_check = DictClient::QUERY_ARGS;

    int arg_index = -1;

    bool pos_filtered = false;
    std::string term;
    while (std::getline(iss, arg, ' ')) {
        if (arg.empty()) { continue; }
        arg_index++;


        // First arg must be the search term
        if (arg_index == 0) {
            auto itr = Dictionary::entries.find(arg);
            if (itr == Dictionary::entries.end()) {
                query_res = {};
                break;
            }
            term = itr->first;
            query_res = std::vector<DictEntry>(itr->second);
            std::sort(query_res.begin(), query_res.end());
            continue;
        }

        bool parsing_failed = false;
        for (std::string param : args_to_check) {

            if (!pos_filtered
                && ::PARTS_OF_SPEECH.find(arg) != ::PARTS_OF_SPEECH.end()) {
                query_res.erase(
                    std::remove_if(
                        query_res.begin(),
                        query_res.end(),
                        [arg](const DictEntry &e) { return e.part_of_speech != arg; }),
                    query_res.end()
                );
                pos_filtered = true;
                break;
            }

            if (arg == "distinct") {
                query_res.erase(
                    std::unique(query_res.begin(), query_res.end()),
                    query_res.end()
                );
                break;
            }

            if (arg == "reverse") {
                std::reverse(query_res.begin(), query_res.end());
                break;
            }

            parsing_failed = true;

        }

        if (parsing_failed) {
            DictClient::PrintParsingError(arg_index, arg);
        }

    }

    DictClient::PrintResults(term, query_res);

    return query_res;
}
std::vector<DictEntry> Dictionary::GetEntry(const std::string &q) {
}
