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
// void TestTokens(){
//     Token testToken(TokenType::STRING, "absdefghijklmnpqrstuvwxyz",1,2);
//     assert(testToken.getVal() == "absdefghijklmnpqrstuvwxyz");
    
// }

void test_tokenizer(){
    testTokenizeComment();
    testTokenizeWhiteSpace();
    testTokenizeString();
    testTokenizeBoolean();
    testTokenizerNullLiteral();
    testTokenizerFunction();
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
