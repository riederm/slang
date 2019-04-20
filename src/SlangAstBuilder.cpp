#include "SlangAstBuilder.h"
#include "ast/pou.h"


#include <iostream>


using namespace std;

SlangAstBuilder::SlangAstBuilder(/* args */)
{
}

SlangAstBuilder::~SlangAstBuilder()
{
}

antlrcpp::Any SlangAstBuilder::visitProgram(SlangParser::ProgramContext *pouContext) {
    string name = pouContext->pouName->getText();
    
    auto declarations = pouContext->declarations();
    Pou* p = new Program();
    p->name = name;
    
    for_each(declarations.begin(), declarations.end(), [p, this](SlangParser::DeclarationsContext* d){
        auto block = visitDeclarations(d);
        if (block.is<VarBlock*>()){
            p->declarationBlocks.push_back(unique_ptr<DeclarationBlock>(block.as<VarBlock*>()));
        }
    });

    return antlrcpp::Any(p);
}

antlrcpp::Any SlangAstBuilder::visitVarDeclarations(SlangParser::VarDeclarationsContext *ctx){  
    auto varBlock = new VarBlock();

    for(auto &varDeclr : ctx->variableDeclarations){
        
        auto declaration = visitVariableDeclaration(varDeclr);
        
        if (declaration.is<VariableDeclaration*>()){
            varBlock->declarations.push_back(
                    std::unique_ptr<VariableDeclaration>(
                        declaration.as<VariableDeclaration*>()));
        }
    }

    return antlrcpp::Any(varBlock);
}

antlrcpp::Any SlangAstBuilder::visitVariableDeclaration(SlangParser::VariableDeclarationContext *ctx){
    auto name = ctx->variableName->getText();
    auto dataType = ctx->type->scalarTypeRef()->typeName->getText();

    return antlrcpp::Any(new VariableDeclaration(name, dataType));
}

// void fillDeclarationBlock(  DeclarationBlock* block, 
//                             SlangParser::DeclarationsContext* d){

//     for (size_t i = 0; i < d->variableDeclaration().size(); i++)
//     {
//         auto v = d->variableDeclaration().at(i);
//         string name = v->IDENTIFIER()->getText();
//         string dataType = v->typeRef()->scalarTypeRef()->getText();
//         auto decl = std::unique_ptr<VariableDeclaration>(new VariableDeclaration(name, dataType));
//         block->declarations.push_back(std::move(decl));
//     }
// }

// unique_ptr<Pou> SlangAstBuilder::transform(SlangParser::PouContext* pouContext){
//     string name = pouContext->pouName->getText();
    
//     auto declarations = pouContext->declarations();
//     Pou* p = new Program();
//     p->name = name;
    
//     for_each(declarations.begin(), declarations.end(), [p](SlangParser::DeclarationsContext* d){
//         auto block = unique_ptr<VarBlock>(new VarBlock());
//         fillDeclarationBlock(block.get(), d);
//         p->declarationBlocks.push_back(std::move(block));
//     });

//     return unique_ptr<Pou>(p);
// }


