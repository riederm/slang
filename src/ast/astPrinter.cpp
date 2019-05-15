#include "astPrinter.h"
#include "stdio.h"

void AstPrinter::printIndentation(){
    for (size_t i = 0; i < getLevel(); i++)
    {
        cout << "\t";
    }
}

void AstPrinter::visitCallStatement(CallStatement* ){
    cout << "CallStatement" << endl;
}

void AstPrinter::visitLogicExpression(LogicExpression* ){
    cout << "LogicExpression" << endl;
}
void AstPrinter::visitNotExpression(NotExpression* ){
    cout << "NotExpression" << endl;
}
void AstPrinter::visitSumExpression(SumExpression* e){
    cout << "SumExpression " << e->op << endl;
}
void AstPrinter::visitAssignment(Assignment* ){
    cout << "Assignment" << endl;
}
void AstPrinter::visitReference(Reference* r){
    cout << "Reference: " << r->identifier << endl;
}
void AstPrinter::visitProgram(Program* p){
    cout << "Program: " << p->name << endl;
}
void AstPrinter::visitVarBlock(VarBlock* ){
    cout << "VarBlock" << endl;
}
void AstPrinter::visitVariableDeclaration(VariableDeclaration* d){
    cout << "Declaration: " << d->name << " : " << d->dataType << endl;
}
void AstPrinter::visitBlock(Block*){
    cout << "Block" << endl;
}
void AstPrinter::visitBoolConstant(BoolConstant* b){
    cout << b->value << endl;
}
void AstPrinter::visitIntConstant(IntConstant* i){
    cout << i->value << endl;
}