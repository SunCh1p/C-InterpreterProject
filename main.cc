#include "./headers/parser.h"

int main(){
  std::string input = "";
  do{
    std::cout << ">>> ";
    std::getline(std::cin, input);
    if(input != "exit"){
      std::vector<Token> tokens = Tokenizer::getInstance().tokenize(input, 0);
      //Builder* builder = new ASTBuilder();
      //Parser p(builder, tokens);
    }
  }while(input != "exit");
  return 0;
}