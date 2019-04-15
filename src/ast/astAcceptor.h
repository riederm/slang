#pragma once

#include <string>

using namespace std;

class DeclarationBlock;
class VariableDeclaration;

class DeclarationsAcceptor
{
    public:
        virtual void acceptDeclarationBlock(DeclarationBlock* declarationBlock){
        };
};

class VariableDeclarationAcceptor
{
    public:
        virtual void acceptVariableDeclaration(VariableDeclaration* variableDeclaration){
        };
};

class VariableAcceptor
{
    public:
        virtual void acceptVariable(const string& variable){
        };
};