
#include "antlr4-runtime.h"
#include "gtest/gtest.h"
#include "../StringParser.h"
#include <vector>
#include "../ast/pou.h"
#include <algorithm>

using namespace std;

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

TEST(PouParserTests, aPouCanBeParsed){

    vector<string> pouNames;
    pouNames.push_back("myProgram");
    pouNames.push_back("a");
    pouNames.push_back("B");
    pouNames.push_back("A123");

    for (size_t i = 0; i < pouNames.size(); i++)
    {
        string program =    "   PROGRAM <NAME>                      "
                            "                                       "
                            "   END_PROGRAM                         ";

        replace(program, "<NAME>", pouNames.at(i));
        
        auto pou = StringParser::parse_from_string(program);       
        ASSERT_EQ(pouNames.at(i), pou->getName());
    
    }
}

TEST(PouParserTests, aPouCanHaveMultipleVARBlocks){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR END_VAR                 "
        "   VAR END_VAR                 "
        "   VAR END_VAR                 "
        "END_PROGRAM";

        auto pou = StringParser::parse_from_string(program);
        ASSERT_EQ(3, pou->numberOfDeclarationBlocks());
}

TEST(PouParserTests, aVarBlockCanHoldAVariable){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR                         "
        "       x : INT;                "
        "   END_VAR                     "
        "END_PROGRAM                    ";

        auto pou = StringParser::parse_from_string(program);
        VariableDeclaration* declaration = pou->getDeclarationBlock(0)->getVariableDeclaration(0);
        ASSERT_EQ("x", declaration->getName());
        ASSERT_EQ("INT", declaration->getDataType());
}

TEST(PouParserTests, aVarBlockCanHoldSeveralVariables){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR                         "
        "       x : INT;                "
        "       y : LONG;                "
        "       z : BOOL;                "
        "   END_VAR                     "
        "END_PROGRAM                    ";

        auto pou = StringParser::parse_from_string(program);
        {
            VariableDeclaration* declaration = pou->getDeclarationBlock(0)->getVariableDeclaration(0);
            ASSERT_EQ("x", declaration->getName());
            ASSERT_EQ("INT", declaration->getDataType());
        }
        {
            VariableDeclaration* declaration = pou->getDeclarationBlock(1)->getVariableDeclaration(0);
            ASSERT_EQ("y", declaration->getName());
            ASSERT_EQ("LONG", declaration->getDataType());
        }
        {
            VariableDeclaration* declaration = pou->getDeclarationBlock(2)->getVariableDeclaration(0);
            ASSERT_EQ("z", declaration->getName());
            ASSERT_EQ("BOOL", declaration->getDataType());
        }
}



