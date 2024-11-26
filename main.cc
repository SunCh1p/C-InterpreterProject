#include "./headers/tokenizer.h"

int main(){
  std::string dave = "1+2+3342+4/5||";
  std::vector<Token> res = Tokenizer::getInstance().tokenize(dave,0);
  for(auto item: res){
      item.print();
  }
  return 0;
}