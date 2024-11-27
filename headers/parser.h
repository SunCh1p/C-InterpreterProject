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
    virtual ASTNode* buildIntLiteral(int val) = 0;
};

//concrete builder
class ASTBuilder: Builder{
  public:
    ASTBuilder(class Parser* parser): m_parser(parser){}
    //<expression> ::= <term> {("+" | "-") <term>}
    ASTNode* buildExpression() override{

    }
    //<term> ::= <factor> {("*" | "/") <factor>}
    ASTNode* buildTerm() override;
    //<factor> ::= <number> | "(" <expression> ")"
    ASTNode* buildFactor() override;
    ASTNode* buildIntLiteral(int val) override;
  private:
    class Parser* m_parser;
};
//Parser-Director
class Parser{
  public:
    Parser(Builder* builder, std::vector<Token> tokens):
      m_builder(builder), m_tokens(tokens){}

    //increment index
    void increment(){m_index++;}
    //get token
    Token getToken(){return m_tokens[m_index];}
    //parse tokens and turn into AST
    ASTNode* parse(){
      if(m_builder == nullptr){
        return nullptr;
      }
      if(m_root != nullptr){
        delete m_root;
      }
      m_root = m_builder->buildExpression();
      return m_root;
    }
  private:
    int m_index = 0;
    Builder* m_builder = nullptr;
    std::vector<Token> m_tokens;
    ASTNode* m_root = nullptr;

};


#endif