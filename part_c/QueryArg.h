#include <string>
#include <vector>
#include <set>

#ifndef CSC340ASMT03_PART_C_QUERYARG_H_
#define CSC340ASMT03_PART_C_QUERYARG_H_

struct QueryArg {
    std::string arg_type;
    std::string display_name;
    std::set<std::string> valid_tokens;

    bool is_valid(const std::string &s) const;
};

#endif //CSC340ASMT03_PART_C_QUERYARG_H_
