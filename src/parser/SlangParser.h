
// Generated from Slang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace slang_parser {


class  SlangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    WS = 8, CHAR = 9, DIGIT = 10, IDENTIFIER_NONDIGIT = 11, IDENTIFIER = 12
  };

  enum {
    RulePou = 0, RuleDeclarations = 1, RuleVariableDeclaration = 2, RuleVariableDefinition = 3, 
    RuleTypeRef = 4
  };

  SlangParser(antlr4::TokenStream *input);
  ~SlangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class PouContext;
  class DeclarationsContext;
  class VariableDeclarationContext;
  class VariableDefinitionContext;
  class TypeRefContext; 

  class  PouContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *pouName = nullptr;;
    PouContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationsContext *declarations();
    antlr4::tree::TerminalNode *IDENTIFIER();

   
  };

  PouContext* pou();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableDeclarationContext *> variableDeclaration();
    VariableDeclarationContext* variableDeclaration(size_t i);

   
  };

  DeclarationsContext* declarations();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeRefContext *typeRef();
    VariableDefinitionContext *variableDefinition();

   
  };

  VariableDeclarationContext* variableDeclaration();

  class  VariableDefinitionContext : public antlr4::ParserRuleContext {
  public:
    VariableDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDefinitionContext *variableDefinition();

   
  };

  VariableDefinitionContext* variableDefinition();

  class  TypeRefContext : public antlr4::ParserRuleContext {
  public:
    TypeRefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

   
  };

  TypeRefContext* typeRef();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace slang_parser
