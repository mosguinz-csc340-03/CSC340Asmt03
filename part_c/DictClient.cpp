#include "DictClient.h"

void DictClient::PrintToConsole(const std::vector<std::string> &messages) {
    std::cout << std::setw(8) << '|' << '\n';
    for (const std::string &message : messages) {
        std::cout << std::setw(8) << "" << message << '\n';
    }
    std::cout << std::setw(8) << '|' << '\n';
}

void DictClient::PrintHelp() {
    PrintToConsole(
        {"PARAMETER HOW-TO,  please enter:",
         "1. A search key -then 2. An optional part of speech -then",
         "3. An optional 'distinct' -then 4. An optional 'reverse'"
        }
    );
}

void DictClient::PrintResults(std::string term, const std::vector<DictEntry> &entries) {
    if (entries.empty()) {
        PrintToConsole({"<NOT FOUND> To be considered for the next release. Thank you."});
        PrintHelp();
        return;
    }

    // "You should account for these [capitalization] typos.
    // Similarly with the capitalization of CSC220 and CSC340."
    if (term.starts_with("csc")) {
        std::transform(term.begin(), term.end(), term.begin(), ::toupper);
    } else {
        term[0] = std::toupper(term[0], std::locale());
    }

    std::vector<std::string> res;
    res.reserve(entries.size());
    for (const DictEntry &entry : entries) {
        std::string formatted = term;
        res.push_back(
            formatted.append(" [").append(entry.part_of_speech).append("] : ").append(entry.definition)
        );
    }
    PrintToConsole(res);
}

void DictClient::PrintParsingError(int arg_index, const std::string &arg) {
    std::vector<QueryArg> query_options = std::vector<QueryArg>(
        std::next(QueryArg::VALID_ARGS.begin(), arg_index - 1), QueryArg::VALID_ARGS.end());
    std::vector<std::string> messages;
    messages.reserve(query_options.size() + 2);

    std::string arg_ordinal;
    switch (arg_index) {
        case 0:
            arg_ordinal = "1st";
            break;
        case 1:
            arg_ordinal = "2nd";
            break;
        case 2:
            arg_ordinal = "3rd";
            break;
        default:
            arg_ordinal = std::to_string(arg_index + 1) + "th";
    }

    for (const QueryArg &option : query_options) {
        messages.emplace_back(std::string("<The entered ")
                                  .append(arg_ordinal)
                                  .append(" parameter '")
                                  .append(arg)
                                  .append("' is NOT ")
                                  .append(option.display_name)
                                  .append(".>"));
    };

    messages.emplace_back(std::string("<The entered ")
                              .append(arg_ordinal)
                              .append(" parameter '")
                              .append(arg)
                              .append("' was disregarded.>"));

    std::string arg_list;
    for (const QueryArg &option : query_options) {
        if (!arg_list.empty()) {
            arg_list.append(" or ");
        }
        arg_list.append(option.display_name);
    }
    messages.emplace_back(std::string("<The ")
                              .append(arg_ordinal)
                              .append(" parameter should be ")
                              .append(arg_list)
                              .append(".>"));

    PrintToConsole(messages);
}

void DictClient::StartSession() {
    Dictionary dictionary;

    while (true) {
        const std::string input = PromptInput();

        if (input == "!q") {
            std::cout << "\n-----THANK YOU-----";
            return;
        }

        if (input.empty() || input == "!help") {
            PrintHelp();
            continue;
        }

        dictionary.QueryDict(input);

    }

}

std::string DictClient::PromptInput() {
    std::printf("Search [%d]: ", ++query_count);
    std::string x;
    std::getline(std::cin, x);
    return x;
}