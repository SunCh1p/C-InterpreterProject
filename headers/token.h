#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType{
    Number,
    Operator,
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

    private:
        TokenType m_Type;
        std::string m_Val;
        int m_Row;
        int m_Col; 

};


#endif