
#include "antlr4-runtime.h"
#include "gtest/gtest.h"
#include "../StringParser.h"
#include <vector>
#include "../ast/pou.h"
#include "../ast/parseResult.h"
#include <algorithm>


using namespace std;

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

TEST(PouParserTests, theParserReportsErrors){
    string program =
        "PROGRAM "
        "   VAR END_VAR   "
        "END_PROGRAM";

        auto parseResult = StringParser::parse_from_string(program);
        ASSERT_NE(nullptr, parseResult->syntaxErrors);
        ASSERT_EQ(1, parseResult->syntaxErrors->size());

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
        
        auto parseResult = StringParser::parse_from_string(program);
        ASSERT_EQ(pouNames.at(i), parseResult->pou->name);
    
    }
}

TEST(PouParserTests, aPouCanHaveMultipleVARBlocks){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR END_VAR                 "
        "   VAR END_VAR                 "
        "   VAR END_VAR                 "
        "END_PROGRAM";

        auto parseResult = StringParser::parse_from_string(program);
        ASSERT_EQ(3, parseResult->pou->declarationBlocks.size());
}

TEST(PouParserTests, aVarBlockCanHoldAVariable){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR                         "
        "       x : INT;                "
        "   END_VAR                     "
        "END_PROGRAM                    ";

        auto parseResult = StringParser::parse_from_string(program);       
        auto& declaration = parseResult->pou->declarationBlocks.at(0)->declarations.at(0);

        ASSERT_EQ("x", declaration->name);
        ASSERT_EQ("INT", declaration->dataType);
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

        unique_ptr<ParseResult> parseResult = StringParser::parse_from_string(program);
        auto pou = parseResult->pou.get();
        {
            auto& declaration = pou->declarationBlocks.at(0)->declarations.at(0);
            ASSERT_EQ("x", declaration->name);
            ASSERT_EQ("INT", declaration->dataType);
        }
        {
            auto& declaration = pou->declarationBlocks.at(0)->declarations.at(1);
            ASSERT_EQ("y", declaration->name);
            ASSERT_EQ("LONG", declaration->dataType);
        }
        {
            auto& declaration = pou->declarationBlocks.at(0)->declarations.at(2);
            ASSERT_EQ("z", declaration->name);
            ASSERT_EQ("BOOL", declaration->dataType);
        }
}

TEST(PouParserTests, simpleAssignmentsWork){
    string program =
        "PROGRAM MyPRG                  "
        "   VAR                         "
        "       x : INT;                "
        "       y : INT;                "
        "   END_VAR                     "
        "   x := y;                     "
        "END_PROGRAM                    ";

        unique_ptr<ParseResult> parseResult = StringParser::parse_from_string(program);
        //THEN I assume no error
        ASSERT_EQ(0, parseResult->syntaxErrors->size());
        ASSERT_NE(nullptr, parseResult->pou->body);
        ASSERT_EQ(1, parseResult->pou->body->expressions.size());

        Expression* stmt = parseResult->pou->body->expressions.at(0).get();
        auto assignment = static_cast<Assignment*>(stmt);
        ASSERT_NE(nullptr,assignment);

        auto left = static_cast<Reference*>(assignment->left.get());
         ASSERT_NE(nullptr, left);
        ASSERT_EQ(left->identifier, "x");

        auto right = static_cast<Reference*>(assignment->right.get());
         ASSERT_NE(nullptr, right);
        ASSERT_EQ(right->identifier, "y");
        

}

