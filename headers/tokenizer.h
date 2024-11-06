#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "token.h"
#include <regex>
#include <vector>
#include <fstream>

enum class Patterns{
    NUMBER=0,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    PATTERN_COUNT
};
//global list of regex patterns for tokenization
const std::vector<std::regex> patterns = {
    //numbers = 0
    std::regex(R"((\d+\.\d*)|(\d*\.\d+)|(\d+))"),
    //operators
    std::regex(R"(\+)"),
    std::regex(R"(\-)"),
    std::regex(R"(\*)"),
    std::regex(R"(\/)")
};

//implemented as a meyers singleton for not reason but the lols
class Tokenizer{
    public:
        static Tokenizer& getInstance();

        std::vector<Token> tokenize(std::string input);

    private:
        Tokenizer(){}
        Tokenizer(const Tokenizer&){}
        Tokenizer& operator=(const Tokenizer&){}
};

#endif