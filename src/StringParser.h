#pragma once

#include <cstring>
#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"

using namespace slang_parser;
using namespace antlr4;
using namespace std;


class StringParser
{
private:
    /* data */
public:
    StringParser();
    ~StringParser();

    SlangParser::PouContext* parse(string src);
};

SlangParser::PouContext* StringParser::parse(string src){
    ANTLRInputStream stream(src);
    SlangLexer lexer(&stream);
    CommonTokenStream tokenStream(&lexer);
    SlangParser parser(&tokenStream);

    return parser.pou();
}

StringParser::StringParser(/* args */)
{

}

StringParser::~StringParser()
{
}
