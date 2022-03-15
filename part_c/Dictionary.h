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

    static const std::set<std::string> PARTS_OF_SPEECH;

    std::unordered_map<std::string, std::vector<DictEntry>> entries;

 public:
    Dictionary();

    void LoadDictionary();

    static DictEntry ParseEntry(const std::string &s);
    std::vector<DictEntry> QueryDict(const std::string &q);

 private:
    std::vector<DictEntry> GetEntry(const std::string &);
};

#endif //CSC340ASMT03_DICTIONARY_H
