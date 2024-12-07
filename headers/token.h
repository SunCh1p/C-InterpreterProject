#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

enum class TokenType{
  COMMENT = 0,
  WHITESPACE,
  NUMBER,
  STRING,
  BOOLEAN,
  NULL_LITERAL,
  FUNCTION,
  RETURN,
  IF,
  ELSE,
  WHILE,
  FOR,
  BREAK,
  CONTINUE,
  PRINT,
  IMPORT,
  EXTERNAL,
  INPUT,
  EXIT,
  //
  IDENTIFIER,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  LPAREN,
  RPAREN,
  //LBRAC,
  //RBRAC,
  EQUAL,
  NOTEQUAL,
  LESSEQUAL,
  GREATEREQUAL,
  LESS,
  GREATER,
  AND,
  OR,
  NOT,
  ASSIGN,
  //DOT,
  //LSBRAC,
  //RSBRAC,
  //COMMA,
  //COLON,
  //SCOLON,
  //ERROR,
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
    bool operator==(const Token& other) const;

    //print
    void print() const;

  private:
    TokenType m_Type;
    std::string m_Val;
    int m_Row;
    int m_Col;
};


#endif