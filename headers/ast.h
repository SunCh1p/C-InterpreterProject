#ifndef AST_H
#define AST_H

#include <exception>
#include <stdexcept>

/*
  EBNF
    <expression> ::= <term> {("+" | "-") <term>}
    <term> ::= <factor> {("*" | "/") <factor>}
    <factor> ::= <number> | "(" <expression> ")"
*/
//ast can be represented using the composite design pattern
/*
  AST
*/
class Visitor;

//component
class ASTNode{
  public:
    virtual int accept(class Visitor* visitor) const = 0; // for evaluator
    virtual ~ASTNode() = default;
};

//composite
class Expression: public ASTNode{
  public:
    Expression(ASTNode* left, char o, ASTNode* right):
      m_left(left), m_op(o), m_right(right){};
    ASTNode* getLeft() const{return m_left;}
    ASTNode* getRight() const{return m_right;}
    char getOp() const{return m_op;}
    int accept(class Visitor* visitor) const override;
  private:
    char m_op;
    ASTNode* m_left;
    ASTNode* m_right;
};

class Term: public ASTNode{
  public:
    Term(ASTNode* left, char o, ASTNode* right):
      m_left(left), m_op(o), m_right(right){};
    int accept(class Visitor* visitor) const override;
    ASTNode* getLeft() const{return m_left;}
    ASTNode* getRight() const{return m_right;}
    char getOp() const{return m_op;}
  private:
    char m_op;
    ASTNode* m_left;
    ASTNode* m_right;
};

class Factor: public ASTNode{
  public:
    Factor(ASTNode* node): m_node(node){}

    int accept(class Visitor* visitor) const override;
    ASTNode* getNode() const{return m_node;}
  private:
    ASTNode* m_node;
};

//leaf
class IntLiteral: public ASTNode{
  public:
    IntLiteral(int v): m_val(v){}
    int getVal() const {return m_val;}
    int accept(class Visitor* visitor) const override;
  private:
    int m_val;
};

/*
  Evaluator
*/
//abstract visitor
class Visitor{
  public:
    virtual int visit(const Expression* expression)=0;
    virtual int visit(const Term* term) = 0;
    virtual int visit(const Factor* factor) = 0;
    virtual int visit(const IntLiteral* IntLiteral) = 0;

};

class Evaluator: public Visitor{
  int visit(const Expression* expression) override;
  int visit(const Term* term) override;
  int visit(const Factor* factor) override;
  int visit(const IntLiteral* IntLiteral) override;
};

#endif

