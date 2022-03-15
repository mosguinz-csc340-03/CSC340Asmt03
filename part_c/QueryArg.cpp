#include "QueryArg.h"
#include "Dictionary.h"

const std::vector<QueryArg> QueryArg::VALID_ARGS = {
    QueryArg{"part_of_speech", "a part of speech",
             {"adjective", "adverb", "conjunction", "interjection", "noun", "preposition", "pronoun", "verb"}},
    QueryArg{"distinct", "'distinct'", {"distinct"}},
    QueryArg{"reverse", "'reverse'", {"distinct"}}
};

bool QueryArg::is_valid(const std::string &s) const {
    return this->valid_tokens.contains(s);
}
