#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "token.h"
#include <regex>
#include <vector>
#include <sstream>
#include <utility>

//implemented as a meyers singleton for not reason but the lols
class Tokenizer{
  public:
    static Tokenizer& getInstance();

    //tokenize a string a return a stream of tokens
    std::vector<Token> tokenize(std::string input, int row);

  private:
    Tokenizer() = default;
    Tokenizer(const Tokenizer&) = delete;
    Tokenizer& operator=(const Tokenizer&) = delete;
};

#endif