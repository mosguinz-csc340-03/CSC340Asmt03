//
// Created by Kullathon Sitthisarnwattanachai on 3/7/22.
//

#ifndef CSC340ASMT03_PART_C_DEFINITION_H_
#define CSC340ASMT03_PART_C_DEFINITION_H_

#include <string>

struct Definition {

    std::string part_of_speech;
    std::string definition;

    Definition(const std::string &part_of_speech, const std::string &definition);

};

#endif //CSC340ASMT03_PART_C_DEFINITION_H_
