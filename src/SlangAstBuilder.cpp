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

    if (any.is<Expression*>()){
        return any.as<Expression*>();

    }else if (any.is<BoolConstant*>()){
        return any.as<BoolConstant*>();

    }else if (any.is<Reference*>()){
        return any.as<Reference*>();
    
    }else if (any.is<IntConstant*>()){
        return any.as<IntConstant*>();

    }else if (any.is<Assignment*>()){
        return any.as<Assignment*>();
    
    }else if (any.is<SumExpression*>()){
        return any.as<SumExpression*>();
    
    }else if (any.is<LogicExpression*>()){
        return any.as<LogicExpression*>();
    
    }else if (any.is<CallStatement*>()){
        return any.as<CallStatement*>();

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
            p->declarationBlocks.push_back(unique_ptr<VarBlock>(block.as<VarBlock*>()));
        }
    });

    auto body = visitBlock(pouContext->body);
    if (body.is<Block*>()){
        p->body = unique_ptr<Block>(body.as<Block*>());
    }

    return p;
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

    return varBlock;
};

Any SlangAstBuilder::visitVariableDeclaration(SlangParser::VariableDeclarationContext *ctx){
    auto name = ctx->variableName->getText();
    auto dataType = ctx->type->scalarTypeRef()->typeName->getText();

    return new VariableDeclaration(name, dataType);
};

Any SlangAstBuilder::visitBlock(SlangParser::BlockContext *ctx){
    auto block = new Block();
    
    for (SlangParser::StatementContext* stmtContext : ctx->statements){
        auto expression = getExpression(visitStatement(stmtContext));
        if (expression != nullptr){
            block->expressions.push_back(unique_ptr<Expression>(expression));
        }
    }

    return block;
};


Any SlangAstBuilder::visitReference(SlangParser::ReferenceContext *ctx){
    auto reference = new Reference();
    reference->identifier = ctx->IDENTIFIER()->getText();
    return reference;
};

Any SlangAstBuilder::visitAssignmentStatement(SlangParser::AssignmentStatementContext *ctx){
    if (ctx->right != nullptr){
        auto left = getExpression(visit(ctx->left));
        auto right = getExpression(visit(ctx->right));

        auto assignment = new Assignment();
        if (left != nullptr){
            assignment->left = unique_ptr<Expression>(left);
        }
        if (right != nullptr){
            assignment->right = unique_ptr<Expression>(right);
        }
        return assignment;
    }else{
        return SlangBaseVisitor::visitAssignmentStatement(ctx);
    }
};

void fillDualOperatorExpression(DualOperatorExpression* dualExpr, Expression* left, Expression* right){
    if (left != nullptr){
        dualExpr->left = unique_ptr<Expression>(left);
    }
    if (right != nullptr){
        dualExpr->right = unique_ptr<Expression>(right);
    }
}

Any SlangAstBuilder::visitSimpleExpression(SlangParser::SimpleExpressionContext *ctx){
    if (ctx->additiveOperator != nullptr){
        auto left = getExpression(visit(ctx->left));
        auto right = getExpression(visit(ctx->right));
        if (ctx->additiveOperator->getText() == "OR"){
            auto logicExpr = new LogicExpression();
            logicExpr->op = LogicOperator::OR;
            fillDualOperatorExpression(logicExpr, left, right);
            return logicExpr;
        }else{
            auto sum = new SumExpression();
            if (ctx->additiveOperator->getText() == "-"){
                sum->op = SumOperator::MINUS;
            }
            fillDualOperatorExpression(sum, left, right);
            return sum;
        }
    }else{
        return SlangBaseVisitor::visitSimpleExpression(ctx);
    }
};

Any SlangAstBuilder::visitBoolLiteral(SlangParser::BoolLiteralContext *ctx){
    auto bc = new BoolConstant();
    bc->value = (ctx->value->getText() == "TRUE");
    return bc;
}

Any SlangAstBuilder::visitUnsignedInteger(SlangParser::UnsignedIntegerContext *ctx){
    auto constant = new IntConstant();
    constant->value = atoi(ctx->value->getText().c_str());
    return constant;
};

Any SlangAstBuilder::visitNotFactor(SlangParser::NotFactorContext *ctx){
    auto notExpr = new NotExpression();
    if (ctx->op != nullptr){
        notExpr->op = unique_ptr<Expression>(getExpression(visit(ctx->op)));
    }
    return notExpr;
};

Any SlangAstBuilder::visitCallExpression(SlangParser::CallExpressionContext *ctx){
    if (ctx->parameters != nullptr){
        auto callStatement = new CallStatement();
        callStatement->op = unique_ptr<Reference>(visitReference(ctx->op).as<Reference*>());
        return callStatement;
    }else{
        return SlangBaseVisitor::visitCallExpression(ctx);
    }
}