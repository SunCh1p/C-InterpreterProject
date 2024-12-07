#include "./headers/parser.h"

void test_tokenizer();
int main(){
  std::string input = "";
  do{
    std::cout << ">>> ";
    std::getline(std::cin, input);
    if(input != "exit"){
      std::vector<Token> tokens = Tokenizer::getInstance().tokenize(input, 0);
      ASTBuilder builder;
      Parser p(&builder, tokens);
      builder.addParser(&p);
      ASTNode* ast = p.parse();
      Evaluator evaluator;
      std::cout << ast->accept(&evaluator) << std::endl;
      std::cout << ast->pAccept(&evaluator) << std::endl;
      //std::cout << ast->pAccept(evaluator) << std::endl;
      //add an environment
      //add the ability to add functions
      //conditional logic
      //data types
    }
  }while(input != "exit");
  return 0;
}