
// Generated from Slang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SlangVisitor.h"


namespace slang_parser {

/**
 * This class provides an empty implementation of SlangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SlangBaseVisitor : public SlangVisitor {
public:

  virtual antlrcpp::Any visitPou(SlangParser::PouContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarations(SlangParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(SlangParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDefinition(SlangParser::VariableDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeRef(SlangParser::TypeRefContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace slang_parser
