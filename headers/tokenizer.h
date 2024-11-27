#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "token.h"
#include <regex>
#include <vector>
#include <sstream>
#include <utility>

//global list of regex patterns for tokenization
const std::vector<std::pair<std::regex, TokenType>> patterns = {
  //numbers = 0
  {std::regex(R"((\d+\.\d*)|(\d*\.\d+)|(\d+))"),TokenType::NUMBER},
  //operators
  {std::regex(R"(\+)"), TokenType::ADD},
  {std::regex(R"(\-)"), TokenType::SUBTRACT},
  {std::regex(R"(\*)"), TokenType::MULTIPLY},
  {std::regex(R"(\/)"), TokenType::DIVIDE},
  {std::regex(R"(==)"), TokenType::EQUAL},
  {std::regex(R"(!=)"), TokenType::NOTEQUAL},
  {std::regex(R"(>=)"), TokenType::GREATEREQUAL},
  {std::regex(R"(<=)"), TokenType::LESSEQUAL},
  {std::regex(R"(>)"), TokenType::GREATER},
  {std::regex(R"(<)"), TokenType::LESS},
  {std::regex(R"(=)"), TokenType::ASSIGN},
  {std::regex(R"(&&)"), TokenType::AND},
  {std::regex(R"(\|\|)"), TokenType::OR},
  {std::regex(R"(!)"), TokenType::NOT},
  {std::regex(R"(\()"), TokenType::LPAREN},
  {std::regex(R"(\))"), TokenType::RPAREN},

};

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