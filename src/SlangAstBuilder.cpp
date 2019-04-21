#include "SlangAstBuilder.h"
#include "ast/pou.h"


#include <iostream>


using namespace std;
using namespace antlrcpp;

SlangAstBuilder::SlangAstBuilder(/* args */)
{
}

SlangAstBuilder::~SlangAstBuilder()
{
}

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
    auto block = unique_ptr<Block>(new Block());
    
    for (SlangParser::StatementContext* stmtContext : ctx->statements){
        auto anyStatement = visitStatement(stmtContext);
        if (anyStatement.is<Expression>()){
            block->expressions.push_back(unique_ptr<Expression>(anyStatement.as<Expression*>()));
        }
    }

    return Any(move(block));
};


Any SlangAstBuilder::visitReference(SlangParser::ReferenceContext *ctx){
    auto reference = new Reference();
    reference->identifier = ctx->IDENTIFIER()->getText();
    return Any(reference);
};

Any SlangAstBuilder::visitAssignmentStatement(SlangParser::AssignmentStatementContext *ctx){
    return nullptr;
};


