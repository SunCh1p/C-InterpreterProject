#include "../headers/token.h"

void Token::print() const {
    switch(getType()){
        case TokenType::NUMBER:
            std::cout << "Number ";
            break;
        case TokenType::ADD:
            std::cout << "Add ";
            break;
        case TokenType::SUBTRACT:
            std::cout << "Subtract ";
            break;
        case TokenType::MULTIPLY:
            std::cout << "Multiply ";
            break;
        case TokenType::DIVIDE:
            std::cout << "Divide ";
            break;
        case TokenType::NOTEQUAL:
            std::cout << "NotEqual ";
            break;
        case TokenType::LESSEQUAL:
            std::cout << "LessEqual ";
            break;
        case TokenType::GREATEREQUAL:
            std::cout << "GreaterEqual ";
            break;
        case TokenType::LESS:
            std::cout << "Less ";
            break;
        case TokenType::GREATER:
            std::cout << "Greater ";
            break;
        case TokenType::ASSIGN:
            std::cout << "Assign ";
            break;
        case TokenType::AND:
            std::cout << "And ";
            break;
        case TokenType::OR:
            std::cout << "Or ";
            break;
        case TokenType::NOT:
            std::cout << "Not ";
            break;
        default:
            break;
    }
    std::cout << getVal();
    std::cout << " Row: " << getRow();
    std::cout << " Col: " << getCol() << std::endl;
}