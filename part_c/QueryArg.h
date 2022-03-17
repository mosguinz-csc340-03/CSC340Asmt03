#include <string>
#include <deque>
#include <set>

#ifndef CSC340ASMT03_PART_C_QUERYARG_H_
#define CSC340ASMT03_PART_C_QUERYARG_H_

struct QueryArg {
    enum ArgType { PART_OF_SPEECH, DISTINCT, REVERSE };

    ArgType arg_type;
    std::string display_name;
    std::set<std::string> valid_tokens;

    bool IsValid(const std::string &s) const;
    static const std::deque<QueryArg> VALID_ARGS;
};

#endif //CSC340ASMT03_PART_C_QUERYARG_H_
