#include "../headers/tokenizer.h"
//global list of regex patterns for tokenization
const std::vector<std::pair<std::regex, TokenType>> patterns = {
  //numbers = 0
  {std::regex(R"(\#[^\n]*)"), TokenType::COMMENT},
  {std::regex(R"(\s+)"), TokenType::WHITESPACE},
  {std::regex(R"(true|false)"), TokenType::BOOLEAN},
  {std::regex(R"(null)"), TokenType::NULL_LITERAL},
  {std::regex(R"(function)"), TokenType::FUNCTION},
  {std::regex(R"(return)"), TokenType::RETURN},
  {std::regex(R"(if)"), TokenType::IF},
  {std::regex(R"(else)"), TokenType::ELSE},
  {std::regex(R"(while)"), TokenType::WHILE},
  {std::regex(R"(for)"), TokenType::FOR},
  {std::regex(R"(break)"), TokenType::BREAK},
  {std::regex(R"(continue)"), TokenType::CONTINUE},
  {std::regex(R"(print)"), TokenType::PRINT},
  {std::regex(R"(import)"), TokenType::IMPORT},
  {std::regex(R"(external)"), TokenType::EXTERNAL},
  {std::regex(R"(input)"), TokenType::INPUT},
  {std::regex(R"(exit)"), TokenType::EXIT},

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
  {std::regex(R"(\[)"), TokenType::LBRAC},
  {std::regex(R"(\])"), TokenType::RBRAC},
  {std::regex(R"(\{)"), TokenType::LSBRAC},
  {std::regex(R"(\})"), TokenType::RSBRAC},
  {std::regex(R"(\.)"), TokenType::DOT},
  {std::regex(R"(\,)"), TokenType::COMMA},
  {std::regex(R"(\:)"), TokenType::COLON},
  {std::regex(R"(\;)"), TokenType::SCOLON},
  {std::regex(R"([a-zA-Z_][a-zA-Z0-9_]*)"), TokenType::IDENTIFIER},
  {std::regex(R"(".*?")"), TokenType::STRING},
  {std::regex(R"(.)"), TokenType::ERROR},
};

Tokenizer& Tokenizer::getInstance(){
  static Tokenizer singleton;
  return singleton;
}

std::vector<Token> Tokenizer::tokenize(std::string input, int row){
  //initialize token stream
  std::vector<Token> tokenStream;

  //check if it matches the patterns
  std::stringstream s(input);

  //initialize position
  size_t position = 0;


  while(position < input.length()){
    bool matched = false;
    std::smatch match;
    std::string subStr = input.substr(position);

    for(const auto& pattern: patterns){
      if(std::regex_search(subStr, match, pattern.first) && match.position() == 0){
          tokenStream.push_back(Token(pattern.second, match.str(), row, position));
          position += match.str().length();
          matched = true;
          break;
      }
    }

    if(matched == false){
      position++;
    }
  }

  return tokenStream;
}