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



class DeclarationBlock : VariableDeclarationAcceptor{
    private:   
        vector< unique_ptr<VariableDeclaration> > declarations;

    public:
        DeclarationBlock(){
            cout << "new DeclarationBlock()" <<endl;
        };
        ~DeclarationBlock(){};

        VariableDeclaration* addNewVariableDeclaration(string& name, string& dataType);
        int numberOfDeclarations();
        VariableDeclaration* getVariableDeclaration(const int index);

    
};

class VariableDeclaration : VariableAcceptor {
    private:
         string name;
         string dataType;

    public:
         VariableDeclaration(string& name, string& dataType): 
             name(name), dataType(dataType){
             };
        ~VariableDeclaration(){};
        string getName();
        string getDataType();

};

class Pou : DeclarationsAcceptor
{
    private:
        string name;
        vector< unique_ptr<DeclarationBlock> > declarationBlocks;

    public:
        Pou(string& name) :
            name(name) {};
            
        ~Pou(){};

        string& getName();
        DeclarationBlock* addNewDeclarationBlock();


        int numberOfDeclarationBlocks();
        DeclarationBlock* getDeclarationBlock(const int index);
        vector< unique_ptr<DeclarationBlock> >::iterator begin();
};