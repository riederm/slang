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

TEST(ParserTestSuite, variablesIdentifiers){
    // Pou myPou("lala");

    string program =    "   PROGRAM myProgram                   "
                        "      VAR                              "
                        "          a            : INT;          "   //short identifier
                        "          a_b_c_e_f    : INT;          "   //identifiers with _
                        "          a123         : INT;          "   //identifiers with numbers
                        "          aLongIdentifier : INT;       "   //long text
                        "          a_1_b : INT;                 "   //mix numbers and underscore
                        "      END_VAR                          "
                        "   END_PROGRAM                         ";

    // StringParser parser;
    // auto pou = parser.parse(program);
    // auto declaration =  pou->declarations(0);

    // ASSERT_EQ("myProgram", pou->IDENTIFIER()->getText());
    // ASSERT_EQ("a", declaration->variableDeclaration(0)->IDENTIFIER()->getText()) ;
    // ASSERT_EQ("a_b_c_e_f", declaration->variableDeclaration(1)->IDENTIFIER()->getText()) ;
    // ASSERT_EQ("a123", declaration->variableDeclaration(2)->IDENTIFIER()->getText()) ;
    // ASSERT_EQ("aLongIdentifier", declaration->variableDeclaration(3)->IDENTIFIER()->getText()) ;
    // ASSERT_EQ("a_1_b", declaration->variableDeclaration(4)->IDENTIFIER()->getText()) ;
}


TEST(ParserTestSuite, aPouCanHaveMultipleDeclarationBlocks){
    string program =        "   PROGRAM myProgram                   "
                            "      VAR                              "
                            "          a            : INT;          "
                            "      END_VAR                          "
                            "      VAR                              "
                            "          b            : INT;          "
                            "      END_VAR                          "
                            "      VAR                              "
                            "          c            : INT;          "
                            "      END_VAR                          "
                            "   END_PROGRAM                         ";

    // StringParser parser;
    // auto pou = parser.parse(program);
    
    // ASSERT_EQ(3, pou->declarations().size());
}


int main(int argc, char *argv[])
{

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    
    return 0;
}
