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
    SyntaxError(int line, const string& message)
        : line(line), message(message){};

    int getLine();
    const string& getMessage();
};


class VectorErrorListener : public BaseErrorListener
{

    public:
        VectorErrorListener(vector<unique_ptr<SyntaxError>>* v) : syntaxErrors(v){
        };

        vector<unique_ptr<SyntaxError>>* syntaxErrors;
        virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
        const std::string &msg, std::exception_ptr e) override;
        
};
