#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "DictEntry.h"
#include "Dictionary.h"
#include "QueryArg.h"

#ifndef CSC340ASMT03_PART_C_DICTCLIENT_H_
#define CSC340ASMT03_PART_C_DICTCLIENT_H_

class DictClient {

 private:
    unsigned int query_count = 0;

 public:
    static void PrintToConsole(const std::vector<std::string> &messages);
    static void PrintHelp();
    static void PrintResults(std::string term, const std::vector<DictEntry> &entries);
    static void PrintParsingError(int arg_index, const std::string &arg);

    void StartSession();
    std::string PromptInput();
};

#endif //CSC340ASMT03_PART_C_DICTCLIENT_H_
