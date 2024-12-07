// #include <iostream>
// #include "../headers/ast.h"

// int main() {
//     Evaluator evaluator;

//     // Test 1: Simple addition
//     ASTNode* three = new IntLiteral(3);
//     ASTNode* four = new IntLiteral(4);
//     ASTNode* addition = new Expression(three, '+', four); // Represents (3 + 4)
//     std::cout << "Test 1: (3 + 4) = " << addition->accept(&evaluator) << std::endl;

//     // Test 2: Simple multiplication
//     ASTNode* two = new IntLiteral(2);
//     ASTNode* multiplication = new Term(addition, '*', two); // Represents (3 + 4) * 2
//     std::cout << "Test 2: ((3 + 4) * 2) = " << multiplication->accept(&evaluator) << std::endl;

    
//     // Represents: ((3 + 4) * 2) - (5 / 1)
//     ASTNode* five = new IntLiteral(5);
//     ASTNode* one = new IntLiteral(1);
//     ASTNode* division = new Term(five, '/', one); // Represents (5 / 1)
//     ASTNode* subtraction = new Expression(multiplication, '-', division); // Represents ((3 + 4) * 2) - (5 / 1)
//     std::cout << "Test 3: (((3 + 4) * 2) - (5 / 1)) = " << subtraction->accept(&evaluator) << std::endl;

    
//     // Represents: (3 * ((2 + 4) - 1))
//     ASTNode* nestedAddition = new Expression(two, '+', four);  // (2 + 4)
//     ASTNode* nestedSubtraction = new Expression(nestedAddition, '-', one); // ((2 + 4) - 1)
//     ASTNode* nestedMultiplication = new Term(three, '*', nestedSubtraction); // (3 * ((2 + 4) - 1))
//     std::cout << "Test 4: (3 * ((2 + 4) - 1)) = " << nestedMultiplication->accept(&evaluator) << std::endl;

//     // Test 5: 
//     ASTNode* singleNumber = new IntLiteral(42); // Just a number
//     std::cout << "Test 5: 42 = " << singleNumber->accept(&evaluator) << std::endl;

//     delete addition;
//     delete multiplication;
//     delete division;
//     delete subtraction;
//     delete nestedMultiplication;
//     delete singleNumber;

//     return 0;
// }
