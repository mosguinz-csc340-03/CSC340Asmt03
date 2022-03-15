#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "DictEntry.h"

#ifndef CSC340ASMT03_PART_C_DICTCLIENT_H_
#define CSC340ASMT03_PART_C_DICTCLIENT_H_

class DictClient {

 private:
    unsigned int query_count = 0;

 public:

    static const std::vector<std::string> QUERY_ARGS;

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

    static void PrintParsingError(int arg_index, const std::string &arg) {
        std::vector<std::string> query_options = QUERY_ARGS;
        std::vector<std::string> messages;
        messages.reserve(query_options.size() + 2);

        std::string arg_ordinal;
        switch (arg_index) {
            case 0: arg_ordinal = "1st";
                break;
            case 1: arg_ordinal = "2nd";
                break;
            case 2: arg_ordinal = "3rd";
                break;
            default: arg_ordinal = std::to_string(arg_index + 1) + "th";
        }

        for (const std::string &option : query_options) {
            messages.emplace_back(std::string("<The entered ")
                                      .append(arg_ordinal)
                                      .append(" parameter is NOT ")
                                      .append(option)
                                      .append(".>"));
        };

        messages.emplace_back(std::string("<The entered ")
                                  .append(arg_ordinal)
                                  .append(" parameter '")
                                  .append(arg)
                                  .append("' was disregarded.>"));

        std::string arg_list;
        for (const std::string &option : query_options) {
            if (!arg_list.empty()) {
                arg_list.append(" or ");
            }
            arg_list.append(option);
        }
        messages.emplace_back(std::string("<The ")
                                  .append(arg_ordinal)
                                  .append(" parameter should be ")
                                  .append(arg_list)
                                  .append(".>"));

        PrintToConsole(messages);
    }

    std::string PromptInput() {
        std::printf("Search [%d]: ", ++query_count);
        std::string x;
        std::cin >> x;
        return x;
    }
};

#endif //CSC340ASMT03_PART_C_DICTCLIENT_H_
