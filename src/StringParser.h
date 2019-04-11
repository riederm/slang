#pragma once

#include <cstring>
#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"

#include <stdio.h>

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

    SlangParser::PouContext* parse(string src);
};

SlangParser::PouContext* StringParser::parse(string src){
    
    cleanUp();

    stream = new ANTLRInputStream(src);
    lexer = new SlangLexer(stream);
    tokenStream = new CommonTokenStream(lexer);   
    parser = new SlangParser(tokenStream);
    
    auto pou = parser->pou();
    return pou;
}

void StringParser::cleanUp(){
    if (tokenStream != NULL) {
        delete tokenStream;
        tokenStream = NULL;
    }

    if (lexer != NULL) {
        delete lexer;
        lexer = NULL;
    }

    if (stream != NULL) {
        delete stream;
        stream = NULL;
    }

    if (parser != NULL){
        delete parser;
        parser = NULL;
    }
        
}

StringParser::StringParser(/* args */)
{

}

StringParser::~StringParser()
{
    cleanUp();
}
