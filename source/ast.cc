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