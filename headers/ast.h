#ifndef AST_H
#define AST_H

#include <exception>
#include <stdexcept>

/*
  EBNF
    1<expression> ::= <term> {("+" | "-") <term>}
    2<term> ::= <factor> {("*" | "/") <factor>}
    3<factor> ::= <number> | "(" <expression> ")"
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
    virtual std::string pAccept(class Visitor* visitor) const = 0;
    virtual ~ASTNode() = default;
};

//composite
class Expression: public ASTNode{
  public:
    Expression(ASTNode* left, char o, ASTNode* right):
      m_left(left), m_op(o), m_right(right){};
    ~Expression(){delete m_left, delete m_right;}
    ASTNode* getLeft() const{return m_left;}
    ASTNode* getRight() const{return m_right;}
    char getOp() const{return m_op;}
    int accept(class Visitor* visitor) const override;
    std::string pAccept(class Visitor* visitor) const override;
  private:
    char m_op;
    ASTNode* m_left;
    ASTNode* m_right;
};

class Term: public ASTNode{
  public:
    Term(ASTNode* left, char o, ASTNode* right):
      m_left(left), m_op(o), m_right(right){};
    ~Term(){delete m_left, delete m_right;};
    int accept(class Visitor* visitor) const override;
    std::string pAccept(class Visitor* visitor) const override;
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
    ~Factor(){delete m_node;}

    int accept(class Visitor* visitor) const override;
    std::string pAccept(class Visitor* visitor) const override;
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
    std::string pAccept(class Visitor* visitor) const override;
  private:
    int m_val;
};

/*
  Evaluator
*/
//abstract visitor
class Visitor{
  public:
    //evaluation
    virtual int visit(const Expression* expression)=0;
    virtual int visit(const Term* term) = 0;
    virtual int visit(const Factor* factor) = 0;
    virtual int visit(const IntLiteral* IntLiteral) = 0;
    //printing
    virtual std::string pVisit(const Expression* expression)=0;
    virtual std::string pVisit(const Term* term) = 0;
    virtual std::string pVisit(const Factor* factor) = 0;
    virtual std::string pVisit(const IntLiteral* IntLiteral) = 0;

};

class Evaluator: public Visitor{
  public:
    //evaluation
    int visit(const Expression* expression) override;
    int visit(const Term* term) override;
    int visit(const Factor* factor) override;
    int visit(const IntLiteral* IntLiteral) override;

    //printing
    std::string pVisit(const Expression* expression) override;
    std::string pVisit(const Term* term)override;
    std::string pVisit(const Factor* factor)override;
    std::string pVisit(const IntLiteral* IntLiteral)override;
};


#endif

