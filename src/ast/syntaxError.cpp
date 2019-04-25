#include "syntaxError.h"

using namespace std;
using namespace antlr4;

void VectorErrorListener::syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e){
    syntaxErrors->push_back(unique_ptr<SyntaxError>(new SyntaxError(line, msg)));
};

int SyntaxError::getLine(){
      return line;
};

const string& SyntaxError::getMessage(){
      return message;
};