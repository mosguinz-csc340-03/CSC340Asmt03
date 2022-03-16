#ifndef CSC340ASMT03_DICTIONARY_H
#define CSC340ASMT03_DICTIONARY_H

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

#include "DictEntry.h"

class Dictionary {

    /** Path to the file that contains the dictionary data. */
    static const std::string DEFAULT_SOURCE_PATH;
    std::unordered_map<std::string, std::vector<DictEntry>> entries;

 public:
    Dictionary();

    static DictEntry ParseEntry(const std::string &s);
    void LoadDictionary();
    void QueryDict(std::string q);
};

#endif //CSC340ASMT03_DICTIONARY_H
