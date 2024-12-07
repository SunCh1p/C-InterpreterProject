#include "../headers/token.h"

void Token::print() const {
    switch(getType()){
        case TokenType::COMMENT:
            std::cout << "Comment ";
            break;
        case TokenType::WHITESPACE:
            std::cout << "Whitespace ";
            break;
        case TokenType::NUMBER:
            std::cout << "Number ";
            break;
        case TokenType::STRING:
            std::cout << "String ";
            break;
        case TokenType::FUNCTION:
            std::cout << "Function ";
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

bool Token::operator==(const Token& other) const{
    bool res = true;
    if(m_Type != other.getType()){
        res = false;
    } else if(m_Val != other.getVal()){
        res = false;
    } else if(m_Col != other.getCol()){
        res = false;
    } else if(m_Row != other.getRow()){
        res = false;
    }
    return res;
}