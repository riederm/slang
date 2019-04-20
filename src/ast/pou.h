#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ast.h"
#include "ast/astAcceptor.h"

#include <iostream>


using namespace std;

class Pou;
class DeclarationBlock;
class VariableDeclaration;



class DeclarationBlock {
    public:   
        DeclarationBlock(){
        };
        ~DeclarationBlock(){}

    public:
        vector< unique_ptr<VariableDeclaration> > declarations;

};

class VarBlock : public DeclarationBlock{
    public: 
        VarBlock(): DeclarationBlock(){};
        ~VarBlock(){};
};


class VariableDeclaration : public VariableAcceptor {
    private:


    public:
         VariableDeclaration(string& name, string& dataType): 
             name(name), dataType(dataType){
             };
        ~VariableDeclaration(){};

        string name;
        string dataType;
};

class Pou 
{

    public:
        Pou(){};
        ~Pou(){};


    public:
        string name;
        vector< unique_ptr<DeclarationBlock> > declarationBlocks;
};

class Program : public Pou{
    public:
        Program():Pou(){};
        ~Program();
        
};