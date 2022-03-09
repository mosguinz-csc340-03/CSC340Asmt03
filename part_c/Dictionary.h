#ifndef CSC340ASMT03_DICTIONARY_H
#define CSC340ASMT03_DICTIONARY_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Definition.h"

class Dictionary {

    /** Path to the file that contains the dictionary data. */
    static const std::string DEFAULT_SOURCE_PATH;

    std::unordered_map<std::string, std::vector<Definition>> entries;

 public:
    Dictionary();

    void LoadDictionary();

    static Definition ParseDefinition(const std::string &s);
};

#endif //CSC340ASMT03_DICTIONARY_H
