
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

tree::TerminalNode* SlangParser::PouContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
}

std::vector<SlangParser::DeclarationsContext *> SlangParser::PouContext::declarations() {
  return getRuleContexts<SlangParser::DeclarationsContext>();
}

SlangParser::DeclarationsContext* SlangParser::PouContext::declarations(size_t i) {
  return getRuleContext<SlangParser::DeclarationsContext>(i);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    match(SlangParser::T__0);
    setState(11);
    dynamic_cast<PouContext *>(_localctx)->pouName = match(SlangParser::IDENTIFIER);
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SlangParser::T__2) {
      setState(12);
      dynamic_cast<PouContext *>(_localctx)->declarationsContext = declarations();
      dynamic_cast<PouContext *>(_localctx)->declarationContainers.push_back(dynamic_cast<PouContext *>(_localctx)->declarationsContext);
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(18);
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

std::vector<SlangParser::VariableDeclarationContext *> SlangParser::DeclarationsContext::variableDeclaration() {
  return getRuleContexts<SlangParser::VariableDeclarationContext>();
}

SlangParser::VariableDeclarationContext* SlangParser::DeclarationsContext::variableDeclaration(size_t i) {
  return getRuleContext<SlangParser::VariableDeclarationContext>(i);
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
  enterRule(_localctx, 2, SlangParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    match(SlangParser::T__2);
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SlangParser::IDENTIFIER) {
      setState(21);
      variableDeclaration();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(27);
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
  enterRule(_localctx, 4, SlangParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(SlangParser::IDENTIFIER);
    setState(30);
    match(SlangParser::T__4);
    setState(31);
    typeRef();
    setState(33);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SlangParser::T__6) {
      setState(32);
      variableDefinition();
    }
    setState(35);
    match(SlangParser::T__5);
   
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
  enterRule(_localctx, 6, SlangParser::RuleVariableDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(SlangParser::T__6);
    setState(38);
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

tree::TerminalNode* SlangParser::TypeRefContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
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
  enterRule(_localctx, 8, SlangParser::RuleTypeRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
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
  "pou", "declarations", "variableDeclaration", "variableDefinition", "typeRef"
};

std::vector<std::string> SlangParser::_literalNames = {
  "", "'PROGRAM'", "'END_PROGRAM'", "'VAR'", "'END_VAR'", "':'", "';'", 
  "':='"
};

std::vector<std::string> SlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "WS", "IDENTIFIER"
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
    0x3, 0xb, 0x2d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x10, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x13, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x19, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x1c, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x24, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0x2, 0x2, 0x2, 0x2a, 0x2, 0xc, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x7, 0x3, 
    0x2, 0x2, 0xd, 0x11, 0x7, 0xb, 0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 
    0xf, 0xe, 0x3, 0x2, 0x2, 0x2, 0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 
    0x4, 0x2, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1a, 0x7, 0x5, 
    0x2, 0x2, 0x17, 0x19, 0x5, 0x6, 0x4, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x6, 0x2, 0x2, 0x1e, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0xb, 0x2, 0x2, 0x20, 0x21, 0x7, 
    0x7, 0x2, 0x2, 0x21, 0x23, 0x5, 0xa, 0x6, 0x2, 0x22, 0x24, 0x5, 0x8, 
    0x5, 0x2, 0x23, 0x22, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x8, 0x2, 0x2, 
    0x26, 0x7, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x9, 0x2, 0x2, 0x28, 
    0x29, 0x5, 0x8, 0x5, 0x2, 0x29, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 
    0x7, 0xb, 0x2, 0x2, 0x2b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5, 0x11, 0x1a, 
    0x23, 
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
