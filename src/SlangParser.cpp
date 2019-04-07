
// Generated from Slang.g4 by ANTLR 4.7.2



#include "SlangParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;
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
    setState(2);
    match(SlangParser::T__0);
    setState(3);
    match(SlangParser::IDENTIFIER);
    setState(4);
    match(SlangParser::T__1);
   
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
  "pou"
};

std::vector<std::string> SlangParser::_literalNames = {
  "", "'PROGRAM'", "'END_PROGRAM'"
};

std::vector<std::string> SlangParser::_symbolicNames = {
  "", "", "", "WS", "CHAR", "DIGIT", "IDENTIFIER"
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
    0x3, 0x8, 0x9, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 0x2, 0x4, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x5, 0x7, 0x3, 0x2, 0x2, 0x5, 0x6, 0x7, 0x8, 0x2, 
    0x2, 0x6, 0x7, 0x7, 0x4, 0x2, 0x2, 0x7, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 
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
