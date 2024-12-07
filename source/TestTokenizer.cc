#include <iostream>
#include <vector>
#include <cassert>
#include "../headers/token.h"
#include "../headers/tokenizer.h"

 //Token(TokenType type, std::string val, int row, int col): 

void TestTokens(){
    Token testToken(TokenType::STRING, "absdefghijklmnpqrstuvwxyz",1,2);
    assert(testToken.getVal() == "absdefghijklmnpqrstuvwxyz");
    
}
int main() {
    TestTokens();
    std::cout<<"Error\n";

    
    std::cout<<"fuck you all\n";
  
  
    return 0;

}
