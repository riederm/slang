
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

    virtual antlrcpp::Any visitProgram(SlangParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(SlangParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclarations(SlangParser::VarDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(SlangParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDefinition(SlangParser::VariableDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitTypeRef(SlangParser::TypeRefContext *context) = 0;

    virtual antlrcpp::Any visitScalarTypeRef(SlangParser::ScalarTypeRefContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SlangParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement(SlangParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitStructuredStatement(SlangParser::StructuredStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(SlangParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(SlangParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(SlangParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitSignedFactor(SlangParser::SignedFactorContext *context) = 0;

    virtual antlrcpp::Any visitFactor(SlangParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(SlangParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedInteger(SlangParser::UnsignedIntegerContext *context) = 0;

    virtual antlrcpp::Any visitBoolLiteral(SlangParser::BoolLiteralContext *context) = 0;

    virtual antlrcpp::Any visitRelationaloperator(SlangParser::RelationaloperatorContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStatement(SlangParser::SimpleStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(SlangParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitReference(SlangParser::ReferenceContext *context) = 0;


};

}  // namespace slang_parser
