
// Generated from Slang.g4 by ANTLR 4.7.2


#include "SlangVisitor.h"

#include "SlangParser.h"


using namespace antlrcpp;
using namespace slang_parser;
using namespace antlr4;

SlangParser::SlangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SlangParser::~SlangParser() {
  delete _interpreter;
}

std::string SlangParser::getGrammarFileName() const {
  return "Slang.g4";
}

const std::vector<std::string>& SlangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SlangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PouContext ------------------------------------------------------------------

SlangParser::PouContext::PouContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::ProgramContext* SlangParser::PouContext::program() {
  return getRuleContext<SlangParser::ProgramContext>(0);
}


size_t SlangParser::PouContext::getRuleIndex() const {
  return SlangParser::RulePou;
}


antlrcpp::Any SlangParser::PouContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitPou(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::PouContext* SlangParser::pou() {
  PouContext *_localctx = _tracker.createInstance<PouContext>(_ctx, getState());
  enterRule(_localctx, 0, SlangParser::RulePou);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    program();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

SlangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SlangParser::ProgramContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
}

SlangParser::BlockContext* SlangParser::ProgramContext::block() {
  return getRuleContext<SlangParser::BlockContext>(0);
}

std::vector<SlangParser::DeclarationsContext *> SlangParser::ProgramContext::declarations() {
  return getRuleContexts<SlangParser::DeclarationsContext>();
}

SlangParser::DeclarationsContext* SlangParser::ProgramContext::declarations(size_t i) {
  return getRuleContext<SlangParser::DeclarationsContext>(i);
}


size_t SlangParser::ProgramContext::getRuleIndex() const {
  return SlangParser::RuleProgram;
}


antlrcpp::Any SlangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::ProgramContext* SlangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, SlangParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(SlangParser::T__0);
    setState(45);
    dynamic_cast<ProgramContext *>(_localctx)->pouName = match(SlangParser::IDENTIFIER);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SlangParser::T__2) {
      setState(46);
      dynamic_cast<ProgramContext *>(_localctx)->declarationsContext = declarations();
      dynamic_cast<ProgramContext *>(_localctx)->declarationContainers.push_back(dynamic_cast<ProgramContext *>(_localctx)->declarationsContext);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    dynamic_cast<ProgramContext *>(_localctx)->body = block();
    setState(53);
    match(SlangParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

SlangParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::VarDeclarationsContext* SlangParser::DeclarationsContext::varDeclarations() {
  return getRuleContext<SlangParser::VarDeclarationsContext>(0);
}


size_t SlangParser::DeclarationsContext::getRuleIndex() const {
  return SlangParser::RuleDeclarations;
}


antlrcpp::Any SlangParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::DeclarationsContext* SlangParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, SlangParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    varDeclarations();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationsContext ------------------------------------------------------------------

SlangParser::VarDeclarationsContext::VarDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SlangParser::VariableDeclarationContext *> SlangParser::VarDeclarationsContext::variableDeclaration() {
  return getRuleContexts<SlangParser::VariableDeclarationContext>();
}

SlangParser::VariableDeclarationContext* SlangParser::VarDeclarationsContext::variableDeclaration(size_t i) {
  return getRuleContext<SlangParser::VariableDeclarationContext>(i);
}


size_t SlangParser::VarDeclarationsContext::getRuleIndex() const {
  return SlangParser::RuleVarDeclarations;
}


antlrcpp::Any SlangParser::VarDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitVarDeclarations(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::VarDeclarationsContext* SlangParser::varDeclarations() {
  VarDeclarationsContext *_localctx = _tracker.createInstance<VarDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 6, SlangParser::RuleVarDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(SlangParser::T__2);
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SlangParser::IDENTIFIER) {
      setState(58);
      dynamic_cast<VarDeclarationsContext *>(_localctx)->variableDeclarationContext = variableDeclaration();
      dynamic_cast<VarDeclarationsContext *>(_localctx)->variableDeclarations.push_back(dynamic_cast<VarDeclarationsContext *>(_localctx)->variableDeclarationContext);
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(SlangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

SlangParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SlangParser::VariableDeclarationContext::SEMI() {
  return getToken(SlangParser::SEMI, 0);
}

tree::TerminalNode* SlangParser::VariableDeclarationContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
}

SlangParser::TypeRefContext* SlangParser::VariableDeclarationContext::typeRef() {
  return getRuleContext<SlangParser::TypeRefContext>(0);
}

SlangParser::VariableDefinitionContext* SlangParser::VariableDeclarationContext::variableDefinition() {
  return getRuleContext<SlangParser::VariableDefinitionContext>(0);
}


size_t SlangParser::VariableDeclarationContext::getRuleIndex() const {
  return SlangParser::RuleVariableDeclaration;
}


antlrcpp::Any SlangParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::VariableDeclarationContext* SlangParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, SlangParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    dynamic_cast<VariableDeclarationContext *>(_localctx)->variableName = match(SlangParser::IDENTIFIER);
    setState(67);
    match(SlangParser::T__4);
    setState(68);
    dynamic_cast<VariableDeclarationContext *>(_localctx)->type = typeRef();
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SlangParser::T__5) {
      setState(69);
      variableDefinition();
    }
    setState(72);
    match(SlangParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDefinitionContext ------------------------------------------------------------------

SlangParser::VariableDefinitionContext::VariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::VariableDefinitionContext* SlangParser::VariableDefinitionContext::variableDefinition() {
  return getRuleContext<SlangParser::VariableDefinitionContext>(0);
}


size_t SlangParser::VariableDefinitionContext::getRuleIndex() const {
  return SlangParser::RuleVariableDefinition;
}


antlrcpp::Any SlangParser::VariableDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitVariableDefinition(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::VariableDefinitionContext* SlangParser::variableDefinition() {
  VariableDefinitionContext *_localctx = _tracker.createInstance<VariableDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 10, SlangParser::RuleVariableDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(SlangParser::T__5);
    setState(75);
    variableDefinition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeRefContext ------------------------------------------------------------------

SlangParser::TypeRefContext::TypeRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::ScalarTypeRefContext* SlangParser::TypeRefContext::scalarTypeRef() {
  return getRuleContext<SlangParser::ScalarTypeRefContext>(0);
}


size_t SlangParser::TypeRefContext::getRuleIndex() const {
  return SlangParser::RuleTypeRef;
}


antlrcpp::Any SlangParser::TypeRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitTypeRef(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::TypeRefContext* SlangParser::typeRef() {
  TypeRefContext *_localctx = _tracker.createInstance<TypeRefContext>(_ctx, getState());
  enterRule(_localctx, 12, SlangParser::RuleTypeRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    scalarTypeRef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeRefContext ------------------------------------------------------------------

SlangParser::ScalarTypeRefContext::ScalarTypeRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SlangParser::ScalarTypeRefContext::getRuleIndex() const {
  return SlangParser::RuleScalarTypeRef;
}


antlrcpp::Any SlangParser::ScalarTypeRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitScalarTypeRef(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::ScalarTypeRefContext* SlangParser::scalarTypeRef() {
  ScalarTypeRefContext *_localctx = _tracker.createInstance<ScalarTypeRefContext>(_ctx, getState());
  enterRule(_localctx, 14, SlangParser::RuleScalarTypeRef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    dynamic_cast<ScalarTypeRefContext *>(_localctx)->typeName = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::T__6)
      | (1ULL << SlangParser::T__7)
      | (1ULL << SlangParser::T__8))) != 0))) {
      dynamic_cast<ScalarTypeRefContext *>(_localctx)->typeName = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SlangParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SlangParser::StatementContext *> SlangParser::BlockContext::statement() {
  return getRuleContexts<SlangParser::StatementContext>();
}

SlangParser::StatementContext* SlangParser::BlockContext::statement(size_t i) {
  return getRuleContext<SlangParser::StatementContext>(i);
}


size_t SlangParser::BlockContext::getRuleIndex() const {
  return SlangParser::RuleBlock;
}


antlrcpp::Any SlangParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::BlockContext* SlangParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, SlangParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::T__9)
      | (1ULL << SlangParser::T__10)
      | (1ULL << SlangParser::T__11)
      | (1ULL << SlangParser::T__17)
      | (1ULL << SlangParser::IDENTIFIER)
      | (1ULL << SlangParser::NUM_INT))) != 0)) {
      setState(81);
      dynamic_cast<BlockContext *>(_localctx)->statementContext = statement();
      dynamic_cast<BlockContext *>(_localctx)->statements.push_back(dynamic_cast<BlockContext *>(_localctx)->statementContext);
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SlangParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::SimpleStatementContext* SlangParser::StatementContext::simpleStatement() {
  return getRuleContext<SlangParser::SimpleStatementContext>(0);
}

SlangParser::StructuredStatementContext* SlangParser::StatementContext::structuredStatement() {
  return getRuleContext<SlangParser::StructuredStatementContext>(0);
}


size_t SlangParser::StatementContext::getRuleIndex() const {
  return SlangParser::RuleStatement;
}


antlrcpp::Any SlangParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::StatementContext* SlangParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, SlangParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SlangParser::T__10:
      case SlangParser::T__11:
      case SlangParser::T__17:
      case SlangParser::IDENTIFIER:
      case SlangParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(87);
        simpleStatement();
        break;
      }

      case SlangParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(88);
        structuredStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructuredStatementContext ------------------------------------------------------------------

SlangParser::StructuredStatementContext::StructuredStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SlangParser::StructuredStatementContext::getRuleIndex() const {
  return SlangParser::RuleStructuredStatement;
}


antlrcpp::Any SlangParser::StructuredStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitStructuredStatement(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::StructuredStatementContext* SlangParser::structuredStatement() {
  StructuredStatementContext *_localctx = _tracker.createInstance<StructuredStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, SlangParser::RuleStructuredStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(SlangParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SlangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::SimpleExpressionContext* SlangParser::ExpressionContext::simpleExpression() {
  return getRuleContext<SlangParser::SimpleExpressionContext>(0);
}

SlangParser::ExpressionContext* SlangParser::ExpressionContext::expression() {
  return getRuleContext<SlangParser::ExpressionContext>(0);
}

tree::TerminalNode* SlangParser::ExpressionContext::EQUAL() {
  return getToken(SlangParser::EQUAL, 0);
}

tree::TerminalNode* SlangParser::ExpressionContext::NOT_EQUAL() {
  return getToken(SlangParser::NOT_EQUAL, 0);
}

tree::TerminalNode* SlangParser::ExpressionContext::LT() {
  return getToken(SlangParser::LT, 0);
}

tree::TerminalNode* SlangParser::ExpressionContext::GT() {
  return getToken(SlangParser::GT, 0);
}

tree::TerminalNode* SlangParser::ExpressionContext::LE() {
  return getToken(SlangParser::LE, 0);
}

tree::TerminalNode* SlangParser::ExpressionContext::GE() {
  return getToken(SlangParser::GE, 0);
}


size_t SlangParser::ExpressionContext::getRuleIndex() const {
  return SlangParser::RuleExpression;
}


antlrcpp::Any SlangParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::ExpressionContext* SlangParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 22, SlangParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    simpleExpression();
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::EQUAL)
      | (1ULL << SlangParser::NOT_EQUAL)
      | (1ULL << SlangParser::LT)
      | (1ULL << SlangParser::LE)
      | (1ULL << SlangParser::GE)
      | (1ULL << SlangParser::GT))) != 0)) {
      setState(94);
      dynamic_cast<ExpressionContext *>(_localctx)->relationalOperator = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SlangParser::EQUAL)
        | (1ULL << SlangParser::NOT_EQUAL)
        | (1ULL << SlangParser::LT)
        | (1ULL << SlangParser::LE)
        | (1ULL << SlangParser::GE)
        | (1ULL << SlangParser::GT))) != 0))) {
        dynamic_cast<ExpressionContext *>(_localctx)->relationalOperator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(95);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

SlangParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::TermContext* SlangParser::SimpleExpressionContext::term() {
  return getRuleContext<SlangParser::TermContext>(0);
}

SlangParser::SimpleExpressionContext* SlangParser::SimpleExpressionContext::simpleExpression() {
  return getRuleContext<SlangParser::SimpleExpressionContext>(0);
}


size_t SlangParser::SimpleExpressionContext::getRuleIndex() const {
  return SlangParser::RuleSimpleExpression;
}


antlrcpp::Any SlangParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::SimpleExpressionContext* SlangParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 24, SlangParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    term();
    setState(101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::T__10)
      | (1ULL << SlangParser::T__11)
      | (1ULL << SlangParser::T__12))) != 0)) {
      setState(99);
      dynamic_cast<SimpleExpressionContext *>(_localctx)->additiveOperator = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SlangParser::T__10)
        | (1ULL << SlangParser::T__11)
        | (1ULL << SlangParser::T__12))) != 0))) {
        dynamic_cast<SimpleExpressionContext *>(_localctx)->additiveOperator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(100);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

SlangParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::SignedFactorContext* SlangParser::TermContext::signedFactor() {
  return getRuleContext<SlangParser::SignedFactorContext>(0);
}

SlangParser::TermContext* SlangParser::TermContext::term() {
  return getRuleContext<SlangParser::TermContext>(0);
}


size_t SlangParser::TermContext::getRuleIndex() const {
  return SlangParser::RuleTerm;
}


antlrcpp::Any SlangParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::TermContext* SlangParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 26, SlangParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    signedFactor();
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::T__13)
      | (1ULL << SlangParser::T__14)
      | (1ULL << SlangParser::T__15)
      | (1ULL << SlangParser::T__16))) != 0)) {
      setState(104);
      dynamic_cast<TermContext *>(_localctx)->multiplicativeOperator = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SlangParser::T__13)
        | (1ULL << SlangParser::T__14)
        | (1ULL << SlangParser::T__15)
        | (1ULL << SlangParser::T__16))) != 0))) {
        dynamic_cast<TermContext *>(_localctx)->multiplicativeOperator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(105);
      term();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedFactorContext ------------------------------------------------------------------

SlangParser::SignedFactorContext::SignedFactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::FactorContext* SlangParser::SignedFactorContext::factor() {
  return getRuleContext<SlangParser::FactorContext>(0);
}


size_t SlangParser::SignedFactorContext::getRuleIndex() const {
  return SlangParser::RuleSignedFactor;
}


antlrcpp::Any SlangParser::SignedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitSignedFactor(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::SignedFactorContext* SlangParser::signedFactor() {
  SignedFactorContext *_localctx = _tracker.createInstance<SignedFactorContext>(_ctx, getState());
  enterRule(_localctx, 28, SlangParser::RuleSignedFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SlangParser::T__10

    || _la == SlangParser::T__11) {
      setState(108);
      dynamic_cast<SignedFactorContext *>(_localctx)->prefix = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == SlangParser::T__10

      || _la == SlangParser::T__11)) {
        dynamic_cast<SignedFactorContext *>(_localctx)->prefix = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(111);
    factor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

SlangParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::ReferenceContext* SlangParser::FactorContext::reference() {
  return getRuleContext<SlangParser::ReferenceContext>(0);
}

SlangParser::FactorContext* SlangParser::FactorContext::factor() {
  return getRuleContext<SlangParser::FactorContext>(0);
}

SlangParser::UnsignedIntegerContext* SlangParser::FactorContext::unsignedInteger() {
  return getRuleContext<SlangParser::UnsignedIntegerContext>(0);
}


size_t SlangParser::FactorContext::getRuleIndex() const {
  return SlangParser::RuleFactor;
}


antlrcpp::Any SlangParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::FactorContext* SlangParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 30, SlangParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SlangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        reference();
        break;
      }

      case SlangParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(SlangParser::T__17);
        setState(115);
        factor();
        break;
      }

      case SlangParser::NUM_INT: {
        enterOuterAlt(_localctx, 3);
        setState(116);
        unsignedInteger();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedIntegerContext ------------------------------------------------------------------

SlangParser::UnsignedIntegerContext::UnsignedIntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SlangParser::UnsignedIntegerContext::NUM_INT() {
  return getToken(SlangParser::NUM_INT, 0);
}


size_t SlangParser::UnsignedIntegerContext::getRuleIndex() const {
  return SlangParser::RuleUnsignedInteger;
}


antlrcpp::Any SlangParser::UnsignedIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitUnsignedInteger(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::UnsignedIntegerContext* SlangParser::unsignedInteger() {
  UnsignedIntegerContext *_localctx = _tracker.createInstance<UnsignedIntegerContext>(_ctx, getState());
  enterRule(_localctx, 32, SlangParser::RuleUnsignedInteger);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    dynamic_cast<UnsignedIntegerContext *>(_localctx)->value = match(SlangParser::NUM_INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationaloperatorContext ------------------------------------------------------------------

SlangParser::RelationaloperatorContext::RelationaloperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::EQUAL() {
  return getToken(SlangParser::EQUAL, 0);
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::NOT_EQUAL() {
  return getToken(SlangParser::NOT_EQUAL, 0);
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::LT() {
  return getToken(SlangParser::LT, 0);
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::LE() {
  return getToken(SlangParser::LE, 0);
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::GE() {
  return getToken(SlangParser::GE, 0);
}

tree::TerminalNode* SlangParser::RelationaloperatorContext::GT() {
  return getToken(SlangParser::GT, 0);
}


size_t SlangParser::RelationaloperatorContext::getRuleIndex() const {
  return SlangParser::RuleRelationaloperator;
}


antlrcpp::Any SlangParser::RelationaloperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitRelationaloperator(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::RelationaloperatorContext* SlangParser::relationaloperator() {
  RelationaloperatorContext *_localctx = _tracker.createInstance<RelationaloperatorContext>(_ctx, getState());
  enterRule(_localctx, 34, SlangParser::RuleRelationaloperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SlangParser::EQUAL)
      | (1ULL << SlangParser::NOT_EQUAL)
      | (1ULL << SlangParser::LT)
      | (1ULL << SlangParser::LE)
      | (1ULL << SlangParser::GE)
      | (1ULL << SlangParser::GT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStatementContext ------------------------------------------------------------------

SlangParser::SimpleStatementContext::SimpleStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SlangParser::AssignmentStatementContext* SlangParser::SimpleStatementContext::assignmentStatement() {
  return getRuleContext<SlangParser::AssignmentStatementContext>(0);
}

tree::TerminalNode* SlangParser::SimpleStatementContext::SEMI() {
  return getToken(SlangParser::SEMI, 0);
}


size_t SlangParser::SimpleStatementContext::getRuleIndex() const {
  return SlangParser::RuleSimpleStatement;
}


antlrcpp::Any SlangParser::SimpleStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitSimpleStatement(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::SimpleStatementContext* SlangParser::simpleStatement() {
  SimpleStatementContext *_localctx = _tracker.createInstance<SimpleStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, SlangParser::RuleSimpleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    assignmentStatement();
    setState(124);
    match(SlangParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

SlangParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SlangParser::ExpressionContext *> SlangParser::AssignmentStatementContext::expression() {
  return getRuleContexts<SlangParser::ExpressionContext>();
}

SlangParser::ExpressionContext* SlangParser::AssignmentStatementContext::expression(size_t i) {
  return getRuleContext<SlangParser::ExpressionContext>(i);
}


size_t SlangParser::AssignmentStatementContext::getRuleIndex() const {
  return SlangParser::RuleAssignmentStatement;
}


antlrcpp::Any SlangParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::AssignmentStatementContext* SlangParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, SlangParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    dynamic_cast<AssignmentStatementContext *>(_localctx)->left = expression();
    setState(127);
    match(SlangParser::T__5);
    setState(128);
    dynamic_cast<AssignmentStatementContext *>(_localctx)->right = expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReferenceContext ------------------------------------------------------------------

SlangParser::ReferenceContext::ReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SlangParser::ReferenceContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
}


size_t SlangParser::ReferenceContext::getRuleIndex() const {
  return SlangParser::RuleReference;
}


antlrcpp::Any SlangParser::ReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SlangVisitor*>(visitor))
    return parserVisitor->visitReference(this);
  else
    return visitor->visitChildren(this);
}

SlangParser::ReferenceContext* SlangParser::reference() {
  ReferenceContext *_localctx = _tracker.createInstance<ReferenceContext>(_ctx, getState());
  enterRule(_localctx, 40, SlangParser::RuleReference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(SlangParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SlangParser::_decisionToDFA;
atn::PredictionContextCache SlangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SlangParser::_atn;
std::vector<uint16_t> SlangParser::_serializedATN;

std::vector<std::string> SlangParser::_ruleNames = {
  "pou", "program", "declarations", "varDeclarations", "variableDeclaration", 
  "variableDefinition", "typeRef", "scalarTypeRef", "block", "statement", 
  "structuredStatement", "expression", "simpleExpression", "term", "signedFactor", 
  "factor", "unsignedInteger", "relationaloperator", "simpleStatement", 
  "assignmentStatement", "reference"
};

std::vector<std::string> SlangParser::_literalNames = {
  "", "'PROGRAM'", "'END_PROGRAM'", "'VAR'", "'END_VAR'", "':'", "':='", 
  "'INT'", "'BOOL'", "'LONG'", "'STRUCTURED_STATEMENT'", "'+'", "'-'", "'OR'", 
  "'*'", "'/'", "'MOD'", "'AND'", "'NOT'", "", "", "", "'='", "'<>'", "'<'", 
  "'<='", "'>='", "'>'", "';'"
};

std::vector<std::string> SlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "WS", "IDENTIFIER", "NUM_INT", "EQUAL", "NOT_EQUAL", "LT", "LE", "GE", 
  "GT", "SEMI"
};

dfa::Vocabulary SlangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SlangParser::_tokenNames;

SlangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1e, 0x87, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x32, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x35, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x3e, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x41, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x49, 0xa, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x7, 0xa, 0x55, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0x58, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x5c, 0xa, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x63, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x68, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x6d, 0xa, 0xf, 0x3, 0x10, 0x5, 0x10, 
    0x70, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x78, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x2, 0x17, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2, 0x7, 0x3, 0x2, 0x9, 0xb, 
    0x3, 0x2, 0x18, 0x1d, 0x3, 0x2, 0xd, 0xf, 0x3, 0x2, 0x10, 0x13, 0x3, 
    0x2, 0xd, 0xe, 0x2, 0x7c, 0x2, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x44, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x51, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x77, 0x3, 0x2, 0x2, 0x2, 0x22, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x80, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2d, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x7, 0x3, 0x2, 0x2, 0x2f, 0x33, 0x7, 0x16, 0x2, 0x2, 0x30, 0x32, 0x5, 
    0x6, 0x4, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x37, 0x5, 0x12, 0xa, 0x2, 0x37, 0x38, 0x7, 0x4, 0x2, 0x2, 0x38, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3f, 0x7, 0x5, 0x2, 0x2, 0x3c, 0x3e, 0x5, 
    0xa, 0x6, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x7, 0x6, 0x2, 0x2, 0x43, 0x9, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x45, 0x7, 0x16, 0x2, 0x2, 0x45, 0x46, 0x7, 0x7, 0x2, 0x2, 0x46, 0x48, 
    0x5, 0xe, 0x8, 0x2, 0x47, 0x49, 0x5, 0xc, 0x7, 0x2, 0x48, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4b, 0x7, 0x1e, 0x2, 0x2, 0x4b, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x7, 0x8, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xc, 0x7, 0x2, 
    0x4e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x10, 0x9, 0x2, 0x50, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x9, 0x2, 0x2, 0x2, 0x52, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x5, 0x14, 0xb, 0x2, 0x54, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x5, 0x26, 0x14, 0x2, 
    0x5a, 0x5c, 0x5, 0x16, 0xc, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x15, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
    0x7, 0xc, 0x2, 0x2, 0x5e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x5, 
    0x1a, 0xe, 0x2, 0x60, 0x61, 0x9, 0x3, 0x2, 0x2, 0x61, 0x63, 0x5, 0x18, 
    0xd, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x19, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x5, 0x1c, 0xf, 0x2, 
    0x65, 0x66, 0x9, 0x4, 0x2, 0x2, 0x66, 0x68, 0x5, 0x1a, 0xe, 0x2, 0x67, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x5, 0x1e, 0x10, 0x2, 0x6a, 0x6b, 0x9, 
    0x5, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x1c, 0xf, 0x2, 0x6c, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x70, 0x9, 0x6, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x5, 0x20, 0x11, 0x2, 0x72, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x73, 0x78, 
    0x5, 0x2a, 0x16, 0x2, 0x74, 0x75, 0x7, 0x14, 0x2, 0x2, 0x75, 0x78, 0x5, 
    0x20, 0x11, 0x2, 0x76, 0x78, 0x5, 0x22, 0x12, 0x2, 0x77, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x21, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x17, 0x2, 
    0x2, 0x7a, 0x23, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x9, 0x3, 0x2, 0x2, 
    0x7c, 0x25, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x28, 0x15, 0x2, 0x7e, 
    0x7f, 0x7, 0x1e, 0x2, 0x2, 0x7f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x5, 0x18, 0xd, 0x2, 0x81, 0x82, 0x7, 0x8, 0x2, 0x2, 0x82, 0x83, 0x5, 
    0x18, 0xd, 0x2, 0x83, 0x29, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x16, 
    0x2, 0x2, 0x85, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x33, 0x3f, 0x48, 0x56, 
    0x5b, 0x62, 0x67, 0x6c, 0x6f, 0x77, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SlangParser::Initializer SlangParser::_init;
