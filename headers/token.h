#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

enum class TokenType{
  NUMBER=0,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  EQUAL,
  NOTEQUAL,
  LESSEQUAL,
  GREATEREQUAL,
  LESS,
  GREATER,
  ASSIGN,
  AND,
  OR,
  NOT
};

class Token{
  public:

    Token(TokenType type, std::string val, int row, int col): 
        m_Type(type), m_Val(val), m_Row(row), m_Col(col){}

    //accessor functions
    TokenType getType() const{return m_Type;}
    std::string getVal() const{return m_Val;}
    int getRow() const{return m_Row;}
    int getCol() const{return m_Col;}

    //print
    void print() const;

  private:
    TokenType m_Type;
    std::string m_Val;
    int m_Row;
    int m_Col;
};


#endif