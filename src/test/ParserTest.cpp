#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"
#include "gtest/gtest.h"
#include "StringParser.h"
#include <vector>
#include "ast/pou.h"

using namespace slang_parser;
using namespace antlr4;
using namespace std;


int main(int argc, char *argv[])
{

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    
    return 0;
}
