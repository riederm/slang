
// Generated from Slang.g4 by ANTLR 4.7.2



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

SlangParser::DeclarationsContext* SlangParser::PouContext::declarations() {
  return getRuleContext<SlangParser::DeclarationsContext>(0);
}

tree::TerminalNode* SlangParser::PouContext::IDENTIFIER() {
  return getToken(SlangParser::IDENTIFIER, 0);
}


size_t SlangParser::PouContext::getRuleIndex() const {
  return SlangParser::RulePou;
}


SlangParser::PouContext* SlangParser::pou() {
  PouContext *_localctx = _tracker.createInstance<PouContext>(_ctx, getState());
  enterRule(_localctx, 0, SlangParser::RulePou);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    match(SlangParser::T__0);
    setState(11);
    dynamic_cast<PouContext *>(_localctx)->pouName = match(SlangParser::IDENTIFIER);
    setState(12);
    declarations();
    setState(13);
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


SlangParser::DeclarationsContext* SlangParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 2, SlangParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    match(SlangParser::T__2);
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SlangParser::IDENTIFIER) {
      setState(16);
      variableDeclaration();
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(22);
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


SlangParser::VariableDeclarationContext* SlangParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, SlangParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    match(SlangParser::IDENTIFIER);
    setState(25);
    match(SlangParser::T__4);
    setState(26);
    typeRef();
    setState(28);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SlangParser::T__6) {
      setState(27);
      variableDefinition();
    }
    setState(30);
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


SlangParser::VariableDefinitionContext* SlangParser::variableDefinition() {
  VariableDefinitionContext *_localctx = _tracker.createInstance<VariableDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 6, SlangParser::RuleVariableDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(SlangParser::T__6);
    setState(33);
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


SlangParser::TypeRefContext* SlangParser::typeRef() {
  TypeRefContext *_localctx = _tracker.createInstance<TypeRefContext>(_ctx, getState());
  enterRule(_localctx, 8, SlangParser::RuleTypeRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
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
  "", "", "", "", "", "", "", "", "WS", "CHAR", "DIGIT", "IDENTIFIER_NONDIGIT", 
  "IDENTIFIER"
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
    0x3, 0xe, 0x28, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x14, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x17, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1f, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x2, 0x2, 
    0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x2, 0x2, 0x24, 0x2, 0xc, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1a, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x22, 0x3, 0x2, 0x2, 0x2, 0xa, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 
    0x7, 0x3, 0x2, 0x2, 0xd, 0xe, 0x7, 0xe, 0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 
    0x3, 0x2, 0xf, 0x10, 0x7, 0x4, 0x2, 0x2, 0x10, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x11, 0x15, 0x7, 0x5, 0x2, 0x2, 0x12, 0x14, 0x5, 0x6, 0x4, 0x2, 0x13, 
    0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x7, 0x6, 
    0x2, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0xe, 0x2, 
    0x2, 0x1b, 0x1c, 0x7, 0x7, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0xa, 0x6, 0x2, 
    0x1d, 0x1f, 0x5, 0x8, 0x5, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x7, 0x8, 0x2, 0x2, 0x21, 0x7, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 
    0x9, 0x2, 0x2, 0x23, 0x24, 0x5, 0x8, 0x5, 0x2, 0x24, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x26, 0x7, 0xe, 0x2, 0x2, 0x26, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x15, 0x1e, 
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
