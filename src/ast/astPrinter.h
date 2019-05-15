
#pragma once

#include "pou.h"

class AstPrinter : public ASTVisitor
{
private:
    int lvl = 0;
    /* data */
public:

    virtual void visitCallStatement(CallStatement* );
    virtual void visitLogicExpression(LogicExpression* );
    virtual void visitNotExpression(NotExpression* );
    virtual void visitSumExpression(SumExpression* );
    virtual void visitAssignment(Assignment* );
    virtual void visitReference(Reference* );
    virtual void visitProgram(Program* );
    virtual void visitVarBlock(VarBlock* );
    virtual void visitVariableDeclaration(VariableDeclaration*);
    virtual void visitBlock(Block*);

    virtual void visitBoolConstant(BoolConstant*);
    virtual void visitIntConstant(IntConstant*);

    void printIndentation();

    virtual void visitChild(ASTElement* ast){
        printIndentation();
        ASTVisitor::visitChild(ast);
    }

};
