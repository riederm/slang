#include "irgen.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

Value* IRGenerator::visitProgram(Program* program) {
    module = std::make_unique<Module>(program->name, context);

    auto funType = FunctionType::(Type::getVoidTy(context));
    auto fun = Function::Create(funType, Function::)

    for(auto const& b : declarationBlocks){
        
    }
};

Value* IRGenerator::visitCallStatement(CallStatement* ) {


};
Value* IRGenerator::visitLogicExpression(LogicExpression* ) {};
Value* IRGenerator::visitNotExpression(NotExpression* ) {};
Value* IRGenerator::visitSumExpression(SumExpression* ) {};
Value* IRGenerator::visitAssignment(Assignment* ) {};
Value* IRGenerator::visitReference(Reference* ) {};


Value* IRGenerator::visitVarBlock(VarBlock* ) {};
Value* IRGenerator::visitVariableDeclaration(VariableDeclaration*) {};
Value* IRGenerator::visitBlock(Block*) {};
Value* IRGenerator::visitBoolConstant(BoolConstant*) {};
Value* IRGenerator::visitIntConstant(IntConstant*) {


};