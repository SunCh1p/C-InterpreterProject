#include "../headers/ast.h"

//ast element functions
int Expression::accept(Visitor* visitor) const{
  return visitor->visit(this);
}

int Term::accept(Visitor* visitor) const{
  return visitor->visit(this);
}

int Factor::accept(Visitor* visitor) const{
  return visitor->visit(this);
}

int IntLiteral::accept(Visitor* visitor) const{
  return visitor->visit(this);
}

std::string Expression::pAccept(Visitor* visitor) const{
  return visitor->pVisit(this);
}

std::string Term::pAccept(Visitor* visitor) const{
  return visitor->pVisit(this);
}

std::string Factor::pAccept(Visitor* visitor) const{
  return visitor->pVisit(this);
}

std::string IntLiteral::pAccept(Visitor* visitor) const{
  return visitor->pVisit(this);
}
//evaluator visitor functions
int Evaluator::visit(const Expression* expression){
  int left = expression->getLeft()->accept(this);
  int right = expression->getRight()->accept(this);
  if(expression->getOp() == '+'){
    return left+right;
  } else{
    return left-right;
  }
}

int Evaluator::visit(const Term* term){
  int left = term->getLeft()->accept(this);
  int right = term->getRight()->accept(this);
  if(term->getOp() == '*'){
    return left*right;
  } else{
    if(right == 0){
      throw std::runtime_error("Division by zero");
    }
    return left/right;
  }
}

int Evaluator::visit(const Factor* factor){
  int res = factor->getNode()->accept(this);
  return res;
}

int Evaluator::visit(const IntLiteral* intLiteral){
  return intLiteral->getVal();
}   

//evaluator print functions
std::string Evaluator::pVisit(const Expression* expression){
  std::string left = expression->getLeft()->pAccept(this);
  std::string right = expression->getRight()->pAccept(this);
  if(expression->getOp() == '+'){
    return '('+left+'+'+right+')';
  } else{
    return '('+left+'-'+right+')';
  }
}
std::string Evaluator::pVisit(const Term* term){
  std::string left = term->getLeft()->pAccept(this);
  std::string right = term->getRight()->pAccept(this);
  if(term->getOp() == '*'){
    return '('+left+'*'+right+')';
  } else{
    return '('+left+'/'+right+')';
  }
}
std::string Evaluator::pVisit(const Factor* factor){
  std::string res = factor->getNode()->pAccept(this);
  return '('+res+')';
}
std::string Evaluator::pVisit(const IntLiteral* IntLiteral){
  return std::to_string(IntLiteral->getVal());
}