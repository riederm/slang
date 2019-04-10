#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"
#include "gtest/gtest.h"

using namespace slang_parser;
using namespace antlr4;
using namespace std;

TEST(ParserTestSuite, ParseAnEmptyProgram){
    string program =    "   PROGRAM myProgram   "
                        "      VAR              "
                        "          xx : INT;    "
                        "      END_VAR          "
                        "   END_PROGRAM         ";

    unique_ptr<SlangParser> parser(
        new SlangParser(
            new CommonTokenStream(
                new SlangLexer(
                    new ANTLRInputStream(program)))));

    SlangParser::PouContext* pou = parser->pou();

    ASSERT_EQ("myProgramX", pou->IDENTIFIER()->getSymbol()->getText());
}


int main(int argc, char *argv[])
{

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    
    return 0;
}
