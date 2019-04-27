
#pragma once

#include "ast/pou.h"
#include "parser/SlangParser.h"
#include "parser/SlangBaseVisitor.h"

using namespace std;
using namespace slang_parser;

class SlangAstBuilder : public SlangBaseVisitor
{
private:
    /* data */
public:
    SlangAstBuilder(/* args */);
    ~SlangAstBuilder();

    virtual antlrcpp::Any aggregateResult(antlrcpp::Any exisitingResult, const antlrcpp::Any &nextResult) override;

    virtual antlrcpp::Any visitProgram(SlangParser::ProgramContext *ctx) override;
    
    virtual antlrcpp::Any visitVarDeclarations(SlangParser::VarDeclarationsContext *ctx) override;

    virtual antlrcpp::Any visitVariableDeclaration(SlangParser::VariableDeclarationContext *ctx) override;

    virtual antlrcpp::Any visitBlock(SlangParser::BlockContext *ctx) override; 

    virtual antlrcpp::Any visitReference(SlangParser::ReferenceContext *ctx) override;

    virtual antlrcpp::Any visitAssignmentStatement(SlangParser::AssignmentStatementContext *ctx) override;

    virtual antlrcpp::Any visitSimpleExpression(SlangParser::SimpleExpressionContext *ctx) override;
  
    virtual antlrcpp::Any visitUnsignedInteger(SlangParser::UnsignedIntegerContext *ctx) override;

    virtual antlrcpp::Any visitBoolLiteral(SlangParser::BoolLiteralContext *ctx) override;

    virtual antlrcpp::Any visitNotFactor(SlangParser::NotFactorContext *ctx) override;

};