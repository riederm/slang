
#pragma once

#include "ast/pou.h"
#include "parser/SlangParser.h"

using namespace std;
using namespace slang_parser;

class SlangAstBuilder
{
private:
    /* data */
public:
    SlangAstBuilder(/* args */);
    ~SlangAstBuilder();

    unique_ptr<Pou> transform(SlangParser::PouContext* pouContext);
    
};