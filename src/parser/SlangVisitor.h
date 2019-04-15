
// Generated from Slang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SlangParser.h"


namespace slang_parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SlangParser.
 */
class  SlangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SlangParser.
   */
    virtual antlrcpp::Any visitPou(SlangParser::PouContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(SlangParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(SlangParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDefinition(SlangParser::VariableDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitTypeRef(SlangParser::TypeRefContext *context) = 0;


};

}  // namespace slang_parser
