
#include "StringParser.h"
#include "SlangAstBuilder.h"
#include "ast/pou.h"

unique_ptr<Pou> StringParser::parse_from_string(const string& src){
    StringParser parser;
    return parser.parse(src);
}

unique_ptr<Pou> StringParser::parse(const string& src){
    
    cleanUp();

    stream = new ANTLRInputStream(src);
    lexer = new SlangLexer(stream);
    tokenStream = new CommonTokenStream(lexer);   
    parser = new SlangParser(tokenStream);
    
    auto pouContext = parser->pou();
    SlangAstBuilder astBuilder;
    auto pou = astBuilder.transform(pouContext);
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
