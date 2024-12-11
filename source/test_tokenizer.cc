#include <iostream>
#include <vector>
#include <cassert>
#include "../headers/token.h"
#include "../headers/tokenizer.h"

 //Token(TokenType type, std::string val, int row, int col): 
void testTokenizeComment(){
  std::cout << "Running testTokenizeComment()" << std::endl;
  Token testToken(TokenType::COMMENT, "#", 0, 0);
  auto s = Tokenizer::getInstance().tokenize("#",0);
  assert(testToken == s[0]);
  testToken = Token(TokenType::COMMENT, "#asdfa asdf hi asd",0,0);
  s = Tokenizer::getInstance().tokenize("#asdfa asdf hi asd",0);
  assert(testToken == s[0]);
}

void testTokenizeWhiteSpace(){
  std::cout << "Running testTokenizerWhiteSpace()" << std::endl;
  Token testToken(TokenType::WHITESPACE, " ", 0, 0);
  auto s = Tokenizer::getInstance().tokenize(" ",0);
  assert(testToken == s[0]);
}

void testTokenizeString(){
  std::cout << "Running testTokenizeString()" << std::endl;
  Token testToken(TokenType::STRING, "\"asdf\"", 0,0);
  auto s = Tokenizer::getInstance().tokenize("\"asdf\"",0);
  assert(testToken == s[0]);
}

void testTokenizeBoolean(){
  std::cout << "Running testTokenizeBoolean()" << std::endl;
  Token testToken1(TokenType::BOOLEAN, "true", 0,0);
  Token testToken2(TokenType::BOOLEAN, "false", 0,5);
  auto s = Tokenizer::getInstance().tokenize("true false", 0);
  assert(testToken1 == s[0]);
  assert(testToken2 == s[2]);
}

void testTokenizerNullLiteral(){
  std::cout << "Running testTokenizerNullLiteral" << std::endl;
  Token testToken(TokenType::NULL_LITERAL, "null", 0,0);
  auto s = Tokenizer::getInstance().tokenize("null",0);
  assert(testToken == s[0]);
}

void testTokenizerFunction(){
  std::cout << "Running testTokenizerFunction()" << std::endl;
  Token testToken(TokenType::FUNCTION, "function",0,1);
  auto s = Tokenizer::getInstance().tokenize(" function asdf",0);
  assert(testToken == s[1]);
}

void testTokenizerReturn(){
  std::cout << "Running testTokenizerReturn()" << std::endl;
  Token testToken(TokenType::RETURN, "return",0,11);
  auto s = Tokenizer::getInstance().tokenize("asdfas asd return asdf",0);
  assert(testToken == s[4]);
}

void testTokenizerIf(){
  std::cout << "Running testTokenizerIf()" << std::endl;
  Token testToken(TokenType::IF, "if",0,0);
  auto s = Tokenizer::getInstance().tokenize("if",0);
  assert(testToken == s[0]);
}

void testTokenizerElse(){
  std::cout << "Running testTokenizerElse()" << std::endl;
  Token testToken(TokenType::ELSE, "else",0,0);
  auto s = Tokenizer::getInstance().tokenize("else",0);
  assert(testToken == s[0]);
}

void testTokenizerWhile(){
  std::cout << "Running testTokenizerWhile()" << std::endl;
  Token testToken(TokenType::WHILE, "while",0,0);
  auto s = Tokenizer::getInstance().tokenize("while",0);
  assert(testToken == s[0]);
}

void testTokenizerFor(){
  std::cout << "Running testTokenizerFor()" << std::endl;
  Token testToken(TokenType::FOR, "for",0,0);
  auto s = Tokenizer::getInstance().tokenize("for",0);
  assert(testToken == s[0]);
}

void testTokenizerBreak(){
  std::cout << "Running testTokenizerBreak()" << std::endl;
  Token testToken(TokenType::BREAK, "break",0,0);
  auto s = Tokenizer::getInstance().tokenize("break",0);
  assert(testToken == s[0]);
}

void testTokenizerContinue(){
  std::cout << "Running testTokenizerContinue()" << std::endl;
  Token testToken(TokenType::CONTINUE, "continue",0,0);
  auto s = Tokenizer::getInstance().tokenize("continue",0);
  assert(testToken == s[0]);
}

void testTokenizerPrint(){
  std::cout << "Running testTokenizerPrint()" << std::endl;
  Token testToken(TokenType::PRINT, "print",0,0);
  auto s = Tokenizer::getInstance().tokenize("print",0);
  assert(testToken == s[0]);
}

void testTokenizerImport(){
  std::cout << "Running testTokenizerImport()" << std::endl;
  Token testToken(TokenType::IMPORT, "import",0,0);
  auto s = Tokenizer::getInstance().tokenize("import",0);
  assert(testToken == s[0]);
}

void testTokenizerExternal(){
  std::cout << "Running testTokenizerExternal()" << std::endl;
  Token testToken(TokenType::EXTERNAL, "external",0,0);
  auto s = Tokenizer::getInstance().tokenize("external",0);
  assert(testToken == s[0]);
}

void testTokenizerInput(){
  std::cout << "Running testTokenizerInput()" << std::endl;
  Token testToken(TokenType::INPUT, "input",0,0);
  auto s = Tokenizer::getInstance().tokenize("input",0);
  assert(testToken == s[0]);
}

void testTokenizerExit(){
  std::cout << "Running testTokenizerExit()" << std::endl;
  Token testToken(TokenType::EXIT, "exit",0,0);
  auto s = Tokenizer::getInstance().tokenize("exit",0);
  assert(testToken == s[0]);
}
//there is problem in L and R paren need to be fixed 
void testTokenizerLParen() {
  std::cout << "Running testTokenizerLParen()" << std::endl;
  Token testToken(TokenType::LPAREN, "(", 0, 0);
  auto s = Tokenizer::getInstance().tokenize("(", 0);
  assert(testToken == s[0]);
}

void testTokenizerRParen() {
  std::cout << "Running testTokenizerRParen()" << std::endl;
  Token testToken(TokenType::RPAREN, ")", 0, 0);
  auto s = Tokenizer::getInstance().tokenize(")", 0);
  assert(testToken == s[0]);
}

void testTokenizerAdd(){
  std::cout << "Running testTokenizerAdd()" << std::endl;
  Token testToken(TokenType::ADD, "+", 0,6);
  auto s = Tokenizer::getInstance().tokenize(" a2 2 +",0);
  assert(testToken == s[5]);
}

void testTokenizerSubtract(){
  std::cout << "Running testTokenizerSubtract()" << std::endl;
  Token testToken(TokenType::SUBTRACT, "-", 0,2);
  auto s = Tokenizer::getInstance().tokenize("+/-",0);
  assert(testToken == s[2]);
}

void testTokenizerMultiply(){
  std::cout << "Running testTokenizerMultiply()" << std::endl;
  Token testToken(TokenType::MULTIPLY, "*", 0,3);
  auto s = Tokenizer::getInstance().tokenize("a+/*a ",0);
  assert(testToken == s[3]);
}

void testTokenizerIdentifier(){
  std::cout << "Running testTokenizerIdentifier()" << std::endl;
  Token testToken(TokenType::IDENTIFIER, "a",0,5);
  auto s = Tokenizer::getInstance().tokenize("asdf a \"asdf\" yay",0);
  assert(testToken == s[2]);
}

void testTokenizerDivide(){
  std::cout << "Running testTokenizerDivide()" << std::endl;
  Token testToken(TokenType::DIVIDE, "/", 0, 1);
  auto s = Tokenizer::getInstance().tokenize(" /", 0);
  assert(testToken == s[1]);
}

void testTokenizerLBRAC(){
  std::cout << "Running testTokenizerLBRAC()" << std::endl;
  Token testToken(TokenType::LBRAC, "[", 0,0);
  auto s = Tokenizer::getInstance().tokenize("[",0);
  assert(testToken == s[0]);
}

void testTokenizerRBRAC(){
  std::cout << "Running testTokenizerRBRAC()" << std::endl;
  Token testToken(TokenType::RBRAC, "]",0,0);
  auto s = Tokenizer::getInstance().tokenize("]",0);
  assert(testToken == s[0]);
}

void testTokenizerEqual(){
  std::cout << "Running testTokenizerEqual()" << std::endl;
  Token testToken(TokenType::EQUAL, "==",0,2);
  auto s = Tokenizer::getInstance().tokenize("a1==\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerNotEqual(){
  std::cout << "Running testTokenizerNotEqual()" << std::endl;
  Token testToken(TokenType::NOTEQUAL, "!=",0,2);
  auto s = Tokenizer::getInstance().tokenize("a1!=\"asdf\"",0);
  assert(testToken == s[1]);  
}

void testTokenizerLessEqual(){
  std::cout << "Running testTokenizerLessEqual()" << std::endl;
  Token testToken(TokenType::LESSEQUAL, "<=", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1<=\"asdf\"",0);
  assert(testToken == s[1]);  
}

void testTokenizerGreaterEqual(){
  std::cout << "Running testTokenizerGreaterEqual()" << std::endl;
  Token testToken(TokenType::GREATEREQUAL, ">=", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1>=\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerLess(){
  std::cout << "Running testTokenizerLess()" << std::endl;
  Token testToken(TokenType::LESS, "<", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1<\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerGreater(){
  std::cout << "Running testTokenizerGreater()" << std::endl;
  Token testToken(TokenType::GREATER, ">", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1>\"asdf\"",0);
  assert(testToken == s[1]); 
}

void testTokenizerAnd(){
  std::cout << "Running testTokenizerAnd()" << std::endl;
  Token testToken(TokenType::AND, "&&", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1&&\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerOr(){
  std::cout << "Running testTokenizerOr()" << std::endl;
  Token testToken(TokenType::OR, "||", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1||\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerNot(){
  std::cout << "Running testTokenizerNot()" << std::endl;
  Token testToken(TokenType::NOT, "!", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1!\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerAssign(){
  std::cout << "Running testTokenizerAssign()" << std::endl;
  Token testToken(TokenType::ASSIGN, "=", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1=\"asdf\"",0);
  assert(testToken == s[1]);
}

void testTokenizerDot(){
  std::cout << "Running testTokenizerDot()" << std::endl;
  Token testToken(TokenType::DOT, ".", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1.\"asdf\"",0);
  assert(testToken == s[1]); 
}

void testTokenizerLSBRAC(){
  std::cout << "Running testTokenizerLSBRAC()" << std::endl;
  Token testToken(TokenType::LSBRAC, "{", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1{\"asdf\"",0);
  assert(testToken == s[1]);  
}

void testTokenizerRSBRAC(){
  std::cout << "Running testTokenizerRSBRAC()" << std::endl;
  Token testToken(TokenType::RSBRAC, "}", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1}\"asdf\"",0);
  assert(testToken == s[1]);  
}

void testTokenizerComma(){
  std::cout << "Running testTokenizerComma()" << std::endl;
  Token testToken(TokenType::COMMA, ",", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1,\"asdf\"",0);
  assert(testToken == s[1]); 
}

void testTokenizerColon(){
  std::cout << "Running testTokenizerColon()" << std::endl;
  Token testToken(TokenType::COLON, ":", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1:\"asdf\"",0);
  assert(testToken == s[1]); 
}

void testTokenizerSemiColon(){
  std::cout << "Running testTokenizerSemiColon()" << std::endl;
  Token testToken(TokenType::SCOLON, ";", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1;\"asdf\"",0);
  assert(testToken == s[1]); 
}

void testTokenizerError(){
  std::cout << "Running testTokenizerError()" << std::endl;
  Token testToken(TokenType::ERROR, "@", 0,2);
  auto s = Tokenizer::getInstance().tokenize("a1@\"asdf\"~`",0);
  assert(testToken == s[1]); 
  assert(s[4].getType() == TokenType::ERROR);
}



void test_tokenizer(){
  testTokenizeComment();
  testTokenizeWhiteSpace();
  testTokenizeBoolean();
  testTokenizerNullLiteral();
  testTokenizerFunction();
  testTokenizerReturn();
  testTokenizerIf();
  testTokenizerElse();
  testTokenizerWhile();
  testTokenizerFor();
  testTokenizerBreak();
  testTokenizerContinue();
  testTokenizerPrint();
  testTokenizerImport();
  testTokenizerExternal();
  testTokenizerInput();
  testTokenizerExit();
  testTokenizeString();
  testTokenizerRParen();
  testTokenizerLParen();
  testTokenizerAdd();
  testTokenizerSubtract();
  testTokenizerMultiply();
  testTokenizerIdentifier();
  testTokenizerDivide();
  testTokenizerLBRAC();
  testTokenizerRBRAC();
  testTokenizerEqual();
  testTokenizerNotEqual();
  testTokenizerLessEqual();
  testTokenizerGreaterEqual();
  testTokenizerLess();
  testTokenizerGreater();
  testTokenizerAnd();
  testTokenizerOr();
  testTokenizerNot();
  testTokenizerAssign();
  testTokenizerDot();
  testTokenizerLBRAC();
  testTokenizerRBRAC();
  testTokenizerComma();
  testTokenizerColon();
  testTokenizerSemiColon();
  testTokenizerError();
  std::cout << "All Tokenizer tests passed" << std::endl;
}
/*
patterns = [
    [r"//[^\n]*", "comment"],  # Comment
    [r"\s+", "whitespace"],  # Whitespace
    [r"\d*\.\d+|\d+\.\d*|\d+", "number"],  # numeric literals
    [r'"([^"]|"")*"', "string"],  # string literals
    [r"true|false", "boolean"],  # boolean literals
    [r"null", "null"],  # the null literal
    [r"function", "function"],  # function keyword
    [r"return", "return"],  # return keyword
    [r"if", "if"],  # if keyword
    [r"else", "else"],  # else keyword
    [r"while", "while"],  # while keyword
    [r"for", "for"],  # for keyword
    [r"break", "break"],  # for keyword
    [r"continue", "continue"],  # for keyword
    [r"print", "print"],  # print keyword
    [r"import", "import"],  # import keyword
    [r"external", "external"],  # external keyword
    [r"input", "input"],  # function keyword
    [r"exit", "exit"],  # exit keyword
    [r"and", "&&"],  # alternate for &&
    [r"or", "||"],  # alternate for ||
    [r"not", "!"],  # alternate for !
    [r"[a-zA-Z_][a-zA-Z0-9_]*", "identifier"],  # identifiers
    [r"\+", "+"],
    [r"\-", "-"],
    [r"\*", "*"],
    [r"\/", "/"],
    [r"\(", "("],
    [r"\)", ")"],
    [r"\{", "{"],
    [r"\}", "}"],
    [r"\;", ";"],
    [r"==", "=="],
    [r"!=", "!="],
    [r"<=", "<="],
    [r">=", ">="],
    [r"<", "<"],
    [r">", ">"],
    [r"\&\&", "&&"],
    [r"\|\|", "||"],
    [r"\!", "!"],
    [r"\=", "="],
    [r"\.", "."],
    [r"\[", "["],
    [r"\]", "]"],
    [r"\,", ","],
    [r"\:", ":"],
    [r"\;", ";"],
    [r".", "error"],  # unexpected content
]*/
