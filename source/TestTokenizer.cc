#include <iostream>
#include <cassert>
#include "../headers/tokenizer.h"

// function to display test results
void printTestResult(const std::string& testName, bool result) {
    if (result) {
        std::cout << "[PASSED] " << testName << "\n";
    } else {
        std::cout << "[FAILED] " << testName << "\n";
    }
}

// function to compare expected tokens with actual tokens
void testTokenizer(const std::string& testName, const std::string& input, int row,
                   const std::vector<Token>& expectedTokens) {
    Tokenizer& tokenizer = Tokenizer::getInstance();
    std::vector<Token> actualTokens = tokenizer.tokenize(input, row);

    bool result = actualTokens.size() == expectedTokens.size();
    if (result) {
        for (size_t i = 0; i < actualTokens.size(); ++i) {
            if (actualTokens[i].getType() != expectedTokens[i].getType() ||
                actualTokens[i].getVal() != expectedTokens[i].getVal() ||
                actualTokens[i].getRow() != expectedTokens[i].getRow()) {
                result = false;
                break;
            }
        }
    }
    printTestResult(testName, result);
}

// Main function to execute all tests
int main() {
    // Test 1: Tokenizing a simple arithmetic expression
    testTokenizer(
        "Simple Arithmetic Expression",
        "3 + 5 * 10",
        1,
        {
            Token(TokenType::NUMBER, "3", 1, 0),
            Token(TokenType::ADD, "+", 1, 2),
            Token(TokenType::NUMBER, "5", 1, 4),
            Token(TokenType::MULTIPLY, "*", 1, 6),
            Token(TokenType::NUMBER, "10", 1, 8),
        });

    // Test 2: Tokenizing relational operators
    testTokenizer(
        "Relational Operators",
        "5 >= 3 && 10 < 20",
        2,
        {
            Token(TokenType::NUMBER, "5", 2, 0),
            Token(TokenType::GREATEREQUAL, ">=", 2, 2),
            Token(TokenType::NUMBER, "3", 2, 5),
            Token(TokenType::AND, "&&", 2, 7),
            Token(TokenType::NUMBER, "10", 2, 10),
            Token(TokenType::LESS, "<", 2, 13),
            Token(TokenType::NUMBER, "20", 2, 15),
        });

    // Test 3: Tokenizing with parentheses
    testTokenizer(
        "Parentheses and Logical Operators",
        "(1 + 2) || (3 - 4)",
        3,
        {
            Token(TokenType::LPAREN, "(", 3, 0),
            Token(TokenType::NUMBER, "1", 3, 1),
            Token(TokenType::ADD, "+", 3, 3),
            Token(TokenType::NUMBER, "2", 3, 5),
            Token(TokenType::RPAREN, ")", 3, 6),
            Token(TokenType::OR, "||", 3, 8),
            Token(TokenType::LPAREN, "(", 3, 11),
            Token(TokenType::NUMBER, "3", 3, 12),
            Token(TokenType::SUBTRACT, "-", 3, 14),
            Token(TokenType::NUMBER, "4", 3, 16),
            Token(TokenType::RPAREN, ")", 3, 17),
        });

    // Test 4: Tokenizing invalid input (unrecognized tokens)
    try {
        Tokenizer& tokenizer = Tokenizer::getInstance();
        tokenizer.tokenize("3 + @", 4); // Invalid '@' character
        printTestResult("Invalid Input", false);
    } catch (const std::exception& e) {
        printTestResult("Invalid Input", true);
    }

    // Test 5: Tokenizing an empty string
    testTokenizer(
        "Empty Input",
        "",
        5,
        {}
    );

    // Test 6: Tokenizing floating-point numbers
    testTokenizer(
        "Floating Point Numbers",
        "3.14 + 0.5 * .75",
        6,
        {
            Token(TokenType::NUMBER, "3.14", 6, 0),
            Token(TokenType::ADD, "+", 6, 5),
            Token(TokenType::NUMBER, "0.5", 6, 7),
            Token(TokenType::MULTIPLY, "*", 6, 11),
            Token(TokenType::NUMBER, ".75", 6, 13),
        });

    // Summary
    std::cout << "All tests executed.\n";

    return 0;
}
