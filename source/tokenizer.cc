#include "../headers/tokenizer.h"

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