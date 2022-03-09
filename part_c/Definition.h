#ifndef CSC340ASMT03_PART_C_DEFINITION_H_
#define CSC340ASMT03_PART_C_DEFINITION_H_

#include <string>

struct Definition {

    const std::string part_of_speech;
    const std::string definition;

    Definition(const std::string &part_of_speech, const std::string &definition) :
        part_of_speech(part_of_speech), definition(definition) {}

    bool operator<(Definition &other) const {
        return this->part_of_speech == other.part_of_speech ?
               this->definition < other.definition :
               this->part_of_speech < other.part_of_speech;
    }

    bool operator==(Definition &other) const {
        return this->part_of_speech == other.part_of_speech &&
            this->definition == other.definition;
    }

};

#endif //CSC340ASMT03_PART_C_DEFINITION_H_
