#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ast.h"

#include <iostream>


using namespace std;

class Pou;
class DeclarationBlock;
class VariableDeclaration;

class Expression;
class Reference;
class Assignment;
class Block;



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


class VariableDeclaration {
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
        unique_ptr<Block> body;
};

class Program : public Pou{
    public:
        Program():Pou(){};
        ~Program();
        
};


class Expression {
    public:
        int field = 0;
        string type = "";

        virtual int eval(){
            return 0;
        };
};

class Reference : public Expression {
    public:
        Reference(): Expression(){
            type="Reference";
        }
        string identifier;
};

class DualOperatorExpression : public Expression{
    public: 
    unique_ptr<Expression> left = unique_ptr<Expression>();
    unique_ptr<Expression> right = unique_ptr<Expression>();
};

class Assignment : public DualOperatorExpression {
    public:
        Assignment(): DualOperatorExpression(){
            type="Assignment";
        }
};

enum SumOperator{ PLUS, MINUS };

class SumExpression : public DualOperatorExpression {
    public:
        SumOperator op = PLUS;
        SumExpression(): DualOperatorExpression(){
            type="SumExpression";
        }
};

class NotExpression : public Expression{
    public:
        NotExpression():Expression(){
            type="NotExpression";
        }
        unique_ptr<Expression> op = unique_ptr<Expression>();
};

enum LogicOperator{AND, OR, XOR};

class LogicExpression : public DualOperatorExpression {
    public:
        LogicOperator op;
        LogicExpression(): DualOperatorExpression(){
            type="LogicExpression";
        }

};

class Block {
    public:
        Block(){};
        vector <unique_ptr<Expression> > expressions;
};

