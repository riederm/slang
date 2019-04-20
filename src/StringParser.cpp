
#include "StringParser.h"
#include "SlangAstBuilder.h"
#include "ast/pou.h"
#include "SyntaxError.h"

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
    
    auto errorListener = unique_ptr<VectorErrorListener>(new VectorErrorListener());
    parser->addErrorListener(errorListener.get());
    SlangAstBuilder astBuilder;
    
    Pou* pou = astBuilder.visit(parser->pou()).as<Pou*>();
    return std::unique_ptr<Pou>(pou);
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
