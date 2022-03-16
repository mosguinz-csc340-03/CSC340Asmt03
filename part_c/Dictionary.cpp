#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>

#include "Dictionary.h"
#include "DictEntry.h"
#include "DictClient.h"
#include "QueryArg.h"

//const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt)";
const std::string Dictionary::DEFAULT_SOURCE_PATH = R"(Data.CS.SFSU.txt)";

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
    std::string definition = s.substr(delim_pos + delim.length());
    definition = (char) toupper(definition[0]) + definition.substr(1);
    return {pos, definition};
}

void Dictionary::QueryDict(std::string query_string) {
    std::transform(query_string.begin(), query_string.end(), query_string.begin(), ::tolower);
    std::istringstream iss(query_string);
    std::string arg;

    std::deque<QueryArg> args_to_check = QueryArg::VALID_ARGS;

    std::deque<std::string> args;
    while (std::getline(iss, arg, ' ')) {
        if (arg.empty()) { continue; }
        args.push_back(arg);
    }

    if (args.size() > 4) {
        DictClient::PrintHelp();
        return;
    }

    std::string search_term = args.front();
    args.pop_front();

    auto itr = Dictionary::entries.find(search_term);
    if (itr == Dictionary::entries.end()) {
        DictClient::PrintResults();
        return;
    }

    std::vector<DictEntry> query_res = std::vector<DictEntry>(itr->second);
    std::sort(query_res.begin(), query_res.end());
    unsigned int arg_index = 0;

    for (const std::string &arg : args) {
        arg_index++;

        bool parsing_failed = true;
        while (!args_to_check.empty()) {
            QueryArg query_arg = args_to_check.front();
            args_to_check.pop_front();

            if (!query_arg.is_valid(arg)) {
                continue;
            }

            parsing_failed = false;
            switch (query_arg.arg_type) {
                case QueryArg::ArgType::PART_OF_SPEECH:
                    std::cout << query_arg.display_name << std::endl;
                    query_res.erase(
                        std::remove_if(
                            query_res.begin(),
                            query_res.end(),
                            [arg](const DictEntry &e) { return e.part_of_speech != arg; }),
                        query_res.end()
                    );
                    break;
                case QueryArg::ArgType::DISTINCT:
                    std::cout << query_arg.display_name << std::endl;
                    query_res.erase(
                        std::unique(query_res.begin(), query_res.end()),
                        query_res.end()
                    );
                    break;
                case QueryArg::ArgType::REVERSE:
                    std::cout << query_arg.display_name << std::endl;
                    std::reverse(query_res.begin(), query_res.end());
                    break;
            }
            break;
        }

        if (parsing_failed) {
            DictClient::PrintParsingError(arg_index, arg);
        }

    }

    DictClient::PrintResults(search_term, query_res);
}
