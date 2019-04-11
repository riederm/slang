
#include <iostream>

#include "parser/SlangParser.h"
#include "parser/SlangLexer.h"
#include "antlr4-runtime.h"
#include "StringParser.h"

using namespace slang_parser;
using namespace antlr4;
using namespace std;

int main(int argc, char const *argv[])
{
    string program =    "PROGRAM myProgram "
                        "   VAR "
                        "       x : INT;"
                        "   END_VAR "
                        "END_PROGRAM";

    cout << "parsing ... " << endl;
    StringParser p;
    auto pou = p.parse(program);


    /*unique_ptr<SlangParser> parser(
        new SlangParser(
            new CommonTokenStream(
                new SlangLexer(
                    new ANTLRInputStream(program)))));
*/

    //SlangParser::PouContext* pou = parser->pou();
    cout << "parsed successfully" << endl;
    printf("%p \n", pou);
    
    cout << pou->IDENTIFIER()->getSymbol()->getText() << endl;
    cout << "number of variables: " << pou->declarations(0)->variableDeclaration().size() << endl;
    cout << "variable name: " << pou->declarations(0)->variableDeclaration(0)->IDENTIFIER()->getSymbol()->getText() << endl;
    return 0;
}
