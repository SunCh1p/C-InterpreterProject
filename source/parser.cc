#include "../headers/parser.h"

/*
  Builder Implementation
*/
//<expression> ::= <term> {("+" | "-") <term>}
ASTNode* ASTBuilder::buildExpression(){
  //get term 1
  ASTNode* left_term = buildTerm();
  //continue to parse tokens if they exist
  while(m_parser->tokensLeft()){
    Token token = m_parser->getToken();
    if(token.getType() == TokenType::ADD || token.getType() == TokenType::SUBTRACT){
        m_parser->increment(); //consume token
        ASTNode* right_term = buildTerm();
        char op = '+';
        if(token.getType() == TokenType::SUBTRACT){
          op = '-';
        }
        left_term = new Expression(left_term, op, right_term);
    } else {
      break;
    }
  }
  return left_term;
}

//<term> ::= <factor> {("*" | "/") <factor>}
ASTNode* ASTBuilder::buildTerm(){
  ASTNode* left_term = buildFactor();
  while(m_parser->tokensLeft()){
    Token token = m_parser->getToken();
    if(token.getType() == TokenType::MULTIPLY || token.getType() == TokenType::DIVIDE){
        m_parser->increment(); //consume token
        ASTNode* right_term = buildTerm();
        char op = '*';
        if(token.getType() == TokenType::DIVIDE){
          op = '/';
        }
        left_term = new Term(left_term, op, right_term);
    } else {
      break;
    }
  }
  return left_term;
}

//<factor> ::= <number> | "(" <expression> ")"
//this is the old code you had 
ASTNode* ASTBuilder::buildFactor(){
  Token token = m_parser->getToken();
  if(token.getType() == TokenType::NUMBER){
    ASTNode* node = buildIntLiteral();
    return node;
  } else if(token.getType() == TokenType::LPAREN){
    //consume left parenthesis token
    m_parser->increment();

    ASTNode* node = buildExpression(); //parse inner expression
    Token token = m_parser->getToken();
    if(token.getType() != TokenType::RPAREN){
      throw std::runtime_error("Expected closing parenthesis");
    }
    m_parser->increment();
    return new Factor(node);
  } else {
    throw std::runtime_error("Unexpected Token");
  }
}

// ASTNode* ASTBuilder::buildFactor() {
//     Token token = m_parser->getToken();
//     if (token.getType() == TokenType::NUMBER) {
//         return buildIntLiteral();
//     } else if (token.getType() == TokenType::LPAREN) {
//         m_parser->increment();  // Consume '('
//         ASTNode* node = buildExpression();
//         Token closingToken = m_parser->getToken();
//         if (closingToken.getType() != TokenType::RPAREN) {
//             throw std::runtime_error("Expected closing parenthesis, but got: " + closingToken.getVal());
//         }
//         m_parser->increment();  // Consume ')'
//         return new Factor(node);
//     } else {
//         throw std::runtime_error("Unexpected token in factor: " + token.getVal());
//     }
// }


//Int Literal

// this is the old code  you had 

ASTNode* ASTBuilder::buildIntLiteral(){
  Token token = m_parser->getToken();
  ASTNode* node = new IntLiteral(std::stoi(token.getVal()));
  m_parser->increment();
  return node;
}

// ASTNode* ASTBuilder::buildIntLiteral() {
//     Token token = m_parser->getToken();
//     try {
//         int value = std::stoi(token.getVal());
//         ASTNode* node = new IntLiteral(value);
//         m_parser->increment();
//         return node;
//     } catch (const std::invalid_argument& e) {
//         throw std::runtime_error("Invalid integer literal: " + token.getVal());
//     } catch (const std::out_of_range& e) {
//         throw std::runtime_error("Integer literal out of range: " + token.getVal());
//     }
// }


/*
  Director
*/
Parser::Parser(Builder* builder, std::vector<Token> tokens): m_builder(builder){
  m_tokens = tokens;
  m_root = nullptr;
  m_index = 0;
}

ASTNode* Parser::parse(){
  if(m_builder == nullptr){
    return nullptr;
  }
  if(m_root != nullptr){
    delete m_root;
  }
  m_root = m_builder->buildExpression();
  return m_root;
}

void Parser::reset(std::vector<Token> tokens){
  m_tokens.clear();
  m_tokens = tokens;
  m_index = 0;
  delete m_root;
}