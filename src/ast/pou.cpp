#include "pou.h"
#include <iostream>

DeclarationBlock* Pou::addNewDeclarationBlock(){
    auto block = new DeclarationBlock();   
    auto b = std::unique_ptr<DeclarationBlock>(block);
    declarationBlocks.push_back(std::move(b));
    return block;
}

DeclarationBlock* Pou::getDeclarationBlock(int index){
    return declarationBlocks.at(index).get();
}

int Pou::numberOfDeclarationBlocks(){
    return declarationBlocks.size();
}

string& Pou::getName(){
    return name;
}

//   DeclarationBlock


int DeclarationBlock::numberOfDeclarations(){
    return declarations.size();
}

VariableDeclaration* DeclarationBlock::getVariableDeclaration(const int index){
    return declarations.at(index).get();
}

VariableDeclaration* DeclarationBlock::addNewVariableDeclaration(string& name, string& dataType){
    auto declaration = new VariableDeclaration(name, dataType);
    auto d = std::unique_ptr<VariableDeclaration>(declaration);
    declarations.push_back(std::move(d));
    return declaration;
}

// VariableDeclaration


string VariableDeclaration::getName(){
    return name;
}

string VariableDeclaration::getDataType(){
    return dataType;
}