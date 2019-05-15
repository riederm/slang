#pragma once

#include "pou.h"
#include "ast.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"


class IRGenerator{

    private:
        std::unique_ptr<LLVMContext> context;
        std::unique_ptr<IRBuilder<>> irBuilder;
        std::unique_ptr<Module> module;

    public:
        IRGenerator(){
            context = std::make_unique<LLVMContext>();
            irBuilder = unique_ptr<IRBuilder<>>(new IRBuilder<>(*context));
        }

    protected: 
        virtual void initializeIrBuilder();

        virtual Value* visitCallStatement(CallStatement* );
        virtual Value* visitLogicExpression(LogicExpression* );
        virtual Value* visitNotExpression(NotExpression* );
        virtual Value* visitSumExpression(SumExpression* );
        virtual Value* visitAssignment(Assignment* );
        virtual Value* visitReference(Reference* );
        virtual Value* visitProgram(Program* );
        virtual Value* visitVarBlock(VarBlock* );
        virtual Value* visitVariableDeclaration(VariableDeclaration*);
        virtual Value* visitBlock(Block*);
        virtual Value* visitBoolConstant(BoolConstant*);
        virtual Value* visitIntConstant(IntConstant*);

};