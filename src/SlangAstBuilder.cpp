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

void fillDeclarationBlock(  DeclarationBlock* block, 
                            SlangParser::DeclarationsContext* d){

    for (size_t i = 0; i < d->variableDeclaration().size(); i++)
    {
        auto v = d->variableDeclaration().at(i);
        string name = v->IDENTIFIER()->getText();
        string dataType = v->typeRef()->IDENTIFIER()->getText();

        auto decl = block->addNewVariableDeclaration(
            name,
            dataType
        );
    }
    
}

unique_ptr<Pou> SlangAstBuilder::transform(SlangParser::PouContext* pouContext){
    string name = pouContext->pouName->getText();
    
    auto declarations = pouContext->declarations();
    Pou* p = new Pou(name);
    
    for_each(declarations.begin(), declarations.end(), [p](SlangParser::DeclarationsContext* d){
        DeclarationBlock* block = p->addNewDeclarationBlock();
        fillDeclarationBlock(block, d);
    });

    return unique_ptr<Pou>(p);
}


