#include "../headers/tokenizer.h"

Tokenizer& Tokenizer::getInstance(){
    static Tokenizer singleton;
    return singleton;
}

std::vector<Token> Tokenizer::tokenize(std::string input){
    //check if it matches the patterns
    for(const auto& pattern: patterns){

    }
}