#include "QueryArg.h"
#include "Dictionary.h"

const std::deque<QueryArg> QueryArg::VALID_ARGS = {
    QueryArg{ArgType::PART_OF_SPEECH, "a part of speech",
             {"adjective", "adverb", "conjunction", "interjection", "noun", "preposition", "pronoun", "verb"}},
    QueryArg{ArgType::DISTINCT, "'distinct'", {"distinct"}},
    QueryArg{ArgType::REVERSE, "'reverse'", {"reverse"}}
};

bool QueryArg::is_valid(const std::string &s) const {
    return this->valid_tokens.contains(s);
}
