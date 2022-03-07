#ifndef CSC340ASMT03_DICTIONARY_H
#define CSC340ASMT03_DICTIONARY_H

#include <string>
#include <unordered_map>
#include "Definition.h"

class Dictionary {

    /** Path to the file that contains the dictionary data. */
    static const std::string DEFAULT_SOURCE_PATH;

    const std::unordered_map<std::string, std::vector<Definition>> ENTRIES;

 public:
    Dictionary();

    static void LoadDictionary();

};

#endif //CSC340ASMT03_DICTIONARY_H
