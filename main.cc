/*
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
*/
#include "./headers/parser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void test_tokenizer();

void processInput(const std::string &input) {
    std::vector<Token> tokens = Tokenizer::getInstance().tokenize(input, 0);
    ASTBuilder builder;
    Parser parser(&builder, tokens);
    builder.addParser(&parser);
    ASTNode* ast = parser.parse();

    if (ast) {
        Evaluator evaluator;
        std::cout << ast->accept(&evaluator) << std::endl;
    } else {
        std::cerr << "Error: Parsing failed" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::ifstream inputFile(argv[1]);

        if (!inputFile.is_open()) {
            std::cerr << "Error: Could not open " << argv[1] << std::endl;
            return 1;
        }

        std::string input;
        while (std::getline(inputFile, input)) {
            processInput(input);
        }

        inputFile.close();
    } else {
        std::string input;
        while (true) {
            std::cout << ">>> ";
            std::getline(std::cin, input);
            if (input == "exit") {
                break;
            }
            processInput(input);
        }
    }

    return 0;
}
