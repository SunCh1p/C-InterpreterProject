#ifndef PARSER_H
#define PARSER_H
#include "ast.h"
#include "tokenizer.h"
/***
  Parser is being built by utilizing the Builder design pattern to construct an ast
***/
//abstract builder
class Builder{
  public:
    virtual ~Builder(){};
    virtual ASTNode* buildExpression() = 0;
    virtual ASTNode* buildTerm() = 0;
    virtual ASTNode* buildFactor() = 0;
    virtual ASTNode* buildIntLiteral() = 0;
};

//concrete builder
class ASTBuilder: Builder{
  public:
    ASTBuilder(class Parser* parser): m_parser(parser){}

    //<expression> ::= <term> {("+" | "-") <term>}
    ASTNode* buildExpression() override;

    //<term> ::= <factor> {("*" | "/") <factor>}
    ASTNode* buildTerm() override;

    //<factor> ::= <number> | "(" <expression> ")"
    ASTNode* buildFactor() override;

    //Int Literal
    ASTNode* buildIntLiteral() override;

  private:
    class Parser* m_parser;
};
//Parser-Director
class Parser{
  public:
    Parser(Builder* builder, std::vector<Token> tokens);

    //destructor
    ~Parser(){delete m_root;}

    //increment index
    void increment(){m_index++;}
    //get token
    Token getToken(){return m_tokens[m_index];}
    //check if remaining tokens
    bool allTokens(){return !(m_index >= m_tokens.size());}
    //parse tokens and turn into AST
    ASTNode* parse();
    //reset 
    void reset(std::vector<Token> tokens);
  private:
    int m_index;
    Builder* m_builder;
    std::vector<Token> m_tokens;
    ASTNode* m_root;

};


#endif