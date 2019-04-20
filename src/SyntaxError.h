#pragma once

#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "ANTLRErrorListener.h"

using namespace std;
using namespace antlr4;

class SyntaxError
{
private:
    int line = -1;
    string message;

public:
    
};


class VectorErrorListener : public BaseErrorListener
{
private:
    vector<unique_ptr<SyntaxError>> syntaxErrors;
public:
    virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e) override;
    
};
