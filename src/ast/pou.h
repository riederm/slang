#pragma once

#include <string>
#include <vector>
#include <stack>
#include <memory>
#include "ast.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"

#include <iostream>

using namespace std;

class Pou;
class DeclarationBlock;
class VariableDeclaration;

class Expression;
class Reference;
class Assignment;
class Block;
class CallStatement;
class LogicExpression;
class NotExpression;
class SumExpression;
class Program;
class VarBlock;
class ASTElement;
class BoolConstant;
class IntConstant;
class ASTVisitor;

using namespace llvm;

class ASTElement{
    public: 
        virtual void visit(ASTVisitor& visitor) = 0;
};


class ASTVisitor{
    private:
        int level = 0;

    protected:
        int getLevel(){ return level;};

    public: 
        virtual void visitCallStatement(CallStatement* ){};
        virtual void visitLogicExpression(LogicExpression* ){};
        virtual void visitNotExpression(NotExpression* ){};
        virtual void visitSumExpression(SumExpression* ){};
        virtual void visitAssignment(Assignment* ){};
        virtual void visitReference(Reference* ){};
        virtual void visitProgram(Program* ){};
        virtual void visitVarBlock(VarBlock* ){};
        virtual void visitVariableDeclaration(VariableDeclaration*){};
        virtual void visitBlock(Block*){};
        virtual void visitBoolConstant(BoolConstant*){};
        virtual void visitIntConstant(IntConstant*){};

        virtual void visitChild(ASTElement* ast){
            level++;
            ast->visit(*this);
            level--;
        };
};


class DeclarationBlock : public ASTElement  {
    public:   
        DeclarationBlock(){
        };
        

    public:
        vector< unique_ptr<VariableDeclaration> > declarations;
        

};


class Expression : public ASTElement {
    public:
        int field = 0;
        string type = "";

        virtual void visit(ASTVisitor& visitor) {};

};


class VariableDeclaration : public ASTElement {

    public:
         VariableDeclaration(string& name, string& dataType): 
             name(name), dataType(dataType){
             };
        

        
        virtual void visit(ASTVisitor& visitor) {
            visitor.visitVariableDeclaration(this);
        };

        string name;
        string dataType;
};

class VarBlock : public DeclarationBlock {
    public: 
        VarBlock(): DeclarationBlock(){};
        
        virtual void visit(ASTVisitor& visitor) {
            visitor.visitVarBlock(this);
            for (auto const& d: declarations) {
                visitor.visitChild(d.get());
            }
        };
};

class Pou : public ASTElement
{

    public:
        Pou(){};
        


    public:
        string name;
        vector< unique_ptr<VarBlock> > declarationBlocks;
        unique_ptr<Block> body;
        virtual void visit(ASTVisitor& visitor) {};
};

class Block : public ASTElement{
    public:
        Block(){};
        vector <unique_ptr<Expression> > expressions;
        virtual void visit(ASTVisitor& visitor) {
            visitor.visitBlock(this);
             for (auto const& e: expressions) {
                visitor.visitChild(e.get());
             }
        };
};

class Program : public Pou{
    public:
        Program():Pou(){};
        
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitProgram(this);
            for(auto const& b : declarationBlocks){
                visitor.visitChild(b.get());
            }
            visitor.visitChild(body.get());
        };
};

class Reference : public Expression {
    public:
        Reference(): Expression(){
            type="Reference";
        }
        string identifier;

        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitReference(this);
        };
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
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitAssignment(this);
            if (left != nullptr){
                visitor.visitChild(left.get());
            }
            if (right != nullptr){
                visitor.visitChild(right.get());
            }
        }
};

enum SumOperator{ PLUS, MINUS };

class SumExpression : public DualOperatorExpression {
    public:
        SumOperator op = PLUS;
        SumExpression(): DualOperatorExpression(){
            type="SumExpression";
        }
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitSumExpression(this);
            if (left != nullptr){
                visitor.visitChild(left.get());
            }
            if (right != nullptr){
                visitor.visitChild(right.get());
            }
        }
};

class NotExpression : public Expression{
    public:
        NotExpression():Expression(){
            type="NotExpression";
        }
        unique_ptr<Expression> op = unique_ptr<Expression>();
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitNotExpression(this);
            visitor.visitChild(op.get());
        }
};

enum LogicOperator{AND, OR, XOR};

class LogicExpression : public DualOperatorExpression {
    public:
        LogicOperator op;
        LogicExpression(): DualOperatorExpression(){
            type="LogicExpression";
        }
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitLogicExpression(this);
            if (left != nullptr){
                visitor.visitChild(left.get());
            }
            if (right != nullptr){
                visitor.visitChild(right.get());
            }
        }

};



class CallStatement : public Expression{
    public:
        CallStatement(): Expression(){
            type="CallStatement";
        }
        unique_ptr<Reference> op;
        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitCallStatement(this);
            visitor.visitChild(op.get());
        }
};


class IntConstant : public Expression{
    public: 
        int value;
        IntConstant(): Expression(){
            type="IntConstant";
        }

        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitIntConstant(this);
        }
};

class BoolConstant : public Expression{
    public:
        bool value;
        BoolConstant() : Expression(){
            type="BoolConstant";
        }

        virtual void visit(ASTVisitor& visitor) override{
            visitor.visitBoolConstant(this);
        }
};


