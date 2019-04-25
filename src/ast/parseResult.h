
#pragma once

#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "ANTLRErrorListener.h"
#include "pou.h"
#include "syntaxError.h"


typedef unique_ptr<SyntaxError> pSyntaxError;

class ParseResult
{
private:
public:
    unique_ptr<Pou> pou;
    unique_ptr<vector<pSyntaxError>> syntaxErrors;
    ParseResult(unique_ptr<Pou> pou, unique_ptr<vector<pSyntaxError>> syntaxErrors):
        pou(std::move(pou)), syntaxErrors(std::move(syntaxErrors)){};

    
    
};

