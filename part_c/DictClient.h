#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "DictEntry.h"

#ifndef CSC340ASMT03_PART_C_DICTCLIENT_H_
#define CSC340ASMT03_PART_C_DICTCLIENT_H_

class DictClient {
 public:
    static void PrintToConsole(const std::vector<std::string> &messages) {
        std::cout << std::setw(8) << '|' << '\n';
        for (const std::string &message : messages) {
            std::cout << std::setw(8) << "" << message << '\n';
        }
        std::cout << std::setw(8) << '|' << '\n';
    }

    static void PrintHelp() {
        PrintToConsole(
            {"PARAMETER HOW-TO,  please enter:",
             "1. A search key -then 2. An optional part of speech -then",
             "3. An optional 'distinct' -then 4. An optional 'reverse'"
            }
        );
    }

    static void PrintResults(std::string term, const std::vector<DictEntry> &entries) {
        if (entries.empty()) {
            PrintToConsole({"<NOT FOUND> To be considered for the next release. Thank you."});
            PrintHelp();
            return;
        }

        // "You should account for these [capitalization] typos.
        // Similarly with the capitalization of CSC220 and CSC340."
        if (term.starts_with("csc")) {
            std::transform(term.begin(), term.end(), term.begin(), ::toupper);
        } else {
            term[0] = std::toupper(term[0], std::locale());
        }

        std::vector<std::string> res;
        res.reserve(entries.size());
        for (const DictEntry &entry : entries) {
            std::string formatted = term;
            std::string definition = (char) toupper(entry.definition[0]) + entry.definition.substr(1);
            res.push_back(
                formatted.append(" [").append(entry.part_of_speech).append("] : ").append(definition)
            );
        }
        PrintToConsole(res);
    }
};

#endif //CSC340ASMT03_PART_C_DICTCLIENT_H_
