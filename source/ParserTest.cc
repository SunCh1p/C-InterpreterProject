#include <iostream>
#include "../headers/parser.h"
#include "../headers/tokenizer.h"
#include "../headers/ast.h"

int main() {
    try {
        // Example input: (3 + 5) * 2
        std::vector<Token> tokens = {
            Token(TokenType::LPAREN, "("),
            Token(TokenType::NUMBER, "3"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "5"),
            Token(TokenType::RPAREN, ")"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::NUMBER, "2")
        };

        // Initialize builder and parser
        Parser parser(new ASTBuilder(&parser), tokens);

        // Parse and build the AST
        ASTNode* root = parser.parse();

        // Print or evaluate the AST
        std::cout << "AST successfully built!" << std::endl;

        // Clean up
        delete root;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
