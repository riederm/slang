#include <string>
#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"
#include "ast/pou.h"

#include <stdio.h>

#pragma once

using namespace slang_parser;
using namespace antlr4;
using namespace std;


class StringParser
{
private:

    SlangParser* parser = NULL;
    ANTLRInputStream* stream = NULL;
    SlangLexer* lexer = NULL;
    CommonTokenStream* tokenStream = NULL;

    void cleanUp();
    /* data */
public:
    StringParser();
    ~StringParser();

    static unique_ptr<Pou> parse_from_string(const string& src);

    unique_ptr<Pou> parse(const string& src);
};
