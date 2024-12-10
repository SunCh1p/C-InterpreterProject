#include <iostream>
#include <vector>
#include <cassert>
#include "../headers/token.h"
#include "../headers/tokenizer.h"

 //Token(TokenType type, std::string val, int row, int col): 
void testTokenizeComment(){
  std::cout << "Running testTokenizeComment" << std::endl;
  Token testToken(TokenType::COMMENT, "//", 0, 0);
  auto s = Tokenizer::getInstance().tokenize("//",0);
  assert(testToken == s[0]);
  testToken = Token(TokenType::COMMENT, "//asdfa asdf hi asd",0,0);
  s = Tokenizer::getInstance().tokenize("//asdfa asdf hi asd",0);
  assert(testToken == s[0]);
}

void testTokenizeWhiteSpace(){
  std::cout << "Running testTokenizerWhiteSpace" << std::endl;
  Token testToken(TokenType::WHITESPACE, " ", 0, 0);
  auto s = Tokenizer::getInstance().tokenize(" ",0);
  assert(testToken == s[0]);
}

void testTokenizeString(){
  std::cout << "Running testTokenizeString" << std::endl;
  Token testToken(TokenType::STRING, "asdf", 0,0);
  auto s = Tokenizer::getInstance().tokenize("asdf",0);
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
  std::cout << "Running testTokenizerFunction" << std::endl;
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
void testTokensBoolean() {
  std::cout << "Running testTokensBoolean()" << std::endl;
  Token testToken(TokenType::BOOLEAN, "true", 0, 0);
  auto s = Tokenizer::getInstance().tokenize("true", 0);
  assert(testToken == s[0]);
  std::cout << "testTokensBoolean passed." << std::endl;
}

void testTokenizerNullLiteral() {
  std::cout << "Running testTokenizerNullLiteral()" << std::endl;
  Token testToken(TokenType::NULL_LITERAL, "null", 0, 0);
  auto s = Tokenizer::getInstance().tokenize("null", 0);
  assert(testToken == s[0]);
  std::cout << "testTokenizerNullLiteral passed." << std::endl;
}
void testTokenizerLParen() {
    std::cout << "Running testTokenizerLParen()" << std::endl;
    Token testToken(TokenType::LPAREN, "(", 0, 0);
    auto s = Tokenizer::getInstance().tokenize("(", 0);
    assert(testToken == s[0]);
    std::cout << "testTokenizerLParen passed." << std::endl;
}

void testTokenizerRParen() {
    std::cout << "Running testTokenizerRParen()" << std::endl;
    Token testToken(TokenType::RPAREN, ")", 0, 0);
    auto s = Tokenizer::getInstance().tokenize(")", 0);
    assert(testToken == s[0]);
    std::cout << "testTokenizerRParen passed." << std::endl;
}
// void TestTokens(){
//     Token testToken(TokenType::STRING, "absdefghijklmnpqrstuvwxyz",1,2);
//     assert(testToken.getVal() == "absdefghijklmnpqrstuvwxyz");
    
// }

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
