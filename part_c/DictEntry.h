#ifndef CSC340ASMT03_PART_C_DICTENTRY_H_
#define CSC340ASMT03_PART_C_DICTENTRY_H_

#include <string>

struct DictEntry {

    const std::string part_of_speech;
    const std::string definition;

    DictEntry(const std::string &part_of_speech, const std::string &definition) :
        part_of_speech(part_of_speech), definition(definition) {}

    bool operator<(DictEntry &other) const {
        return this->part_of_speech == other.part_of_speech ?
               this->definition < other.definition :
               this->part_of_speech < other.part_of_speech;
    }

    bool operator==(DictEntry &other) const {
        return this->part_of_speech == other.part_of_speech &&
            this->definition == other.definition;
    }

};

#endif //CSC340ASMT03_PART_C_DICTENTRY_H_
