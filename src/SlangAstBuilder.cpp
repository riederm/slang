#include "SlangAstBuilder.h"
#include "ast/pou.h"
#include "ast/constants.h"
#include <iostream>

using namespace std;
using namespace antlrcpp;

SlangAstBuilder::SlangAstBuilder(/* args */)
{
}

SlangAstBuilder::~SlangAstBuilder()
{
}

Expression* getExpression(const Any& any){
    if (any.is<Reference*>()){
        return any.as<Reference*>();
    
    }else if (any.is<IntConstant*>()){
        return any.as<IntConstant*>();

    }else if (any.is<Assignment*>()){
        return any.as<Assignment*>();
    }

    return nullptr;
}

Any SlangAstBuilder::aggregateResult(antlrcpp::Any exisitingResult, const antlrcpp::Any &nextResult){
    if (nextResult.isNull()){
        return exisitingResult;
    }
    return nextResult;
};

Any SlangAstBuilder::visitProgram(SlangParser::ProgramContext *pouContext) {
    string name = pouContext->pouName->getText();
    
    auto declarations = pouContext->declarations();
    Pou* p = new Program();
    p->name = name;
    
    for_each(declarations.begin(), declarations.end(), [p, this](SlangParser::DeclarationsContext* d){
        auto block = visitDeclarations(d);
        if (block.is<VarBlock*>()){
            p->declarationBlocks.push_back(unique_ptr<DeclarationBlock>(block.as<VarBlock*>()));
        }
    });

    auto body = visitBlock(pouContext->body);
    if (body.is<Block*>()){
        p->body = unique_ptr<Block>(body.as<Block*>());
    }

    return Any(p);
};
 
Any SlangAstBuilder::visitVarDeclarations(SlangParser::VarDeclarationsContext *ctx){  
    auto varBlock = new VarBlock();

    for(auto &varDeclr : ctx->variableDeclarations){
        
        auto declaration = visitVariableDeclaration(varDeclr);
        
        if (declaration.is<VariableDeclaration*>()){
            varBlock->declarations.push_back(
                    std::unique_ptr<VariableDeclaration>(
                        declaration.as<VariableDeclaration*>()));
        }
    }

    return Any(varBlock);
};

Any SlangAstBuilder::visitVariableDeclaration(SlangParser::VariableDeclarationContext *ctx){
    auto name = ctx->variableName->getText();
    auto dataType = ctx->type->scalarTypeRef()->typeName->getText();

    return Any(new VariableDeclaration(name, dataType));
};

Any SlangAstBuilder::visitBlock(SlangParser::BlockContext *ctx){
    auto block = new Block();
    
    for (SlangParser::StatementContext* stmtContext : ctx->statements){
        auto expression = getExpression(visitStatement(stmtContext));
        if (expression != nullptr){
            block->expressions.push_back(unique_ptr<Expression>(expression));
        }
    }

    return Any(block);
};


Any SlangAstBuilder::visitReference(SlangParser::ReferenceContext *ctx){
    auto reference = new Reference();
    reference->identifier = ctx->IDENTIFIER()->getText();
    reference->eval();

    auto e1 = dynamic_cast<Expression*>(reference);

    return Any(reference);
};

Any SlangAstBuilder::visitAssignmentStatement(SlangParser::AssignmentStatementContext *ctx){
    auto left = getExpression(visitExpression(ctx->left));
    auto right = getExpression(visitExpression(ctx->right));


    auto assignment = new Assignment();
    if (left != nullptr){
        assignment->left = unique_ptr<Expression>(left);
    }
    if (right != nullptr){
        assignment->right = unique_ptr<Expression>(right);
    }
    return Any(assignment);
};

Any SlangAstBuilder::visitUnsignedInteger(SlangParser::UnsignedIntegerContext *ctx){
    auto constant = new IntConstant();
    constant->value = atoi(ctx->value->getText().c_str());
    return Any(constant);
};