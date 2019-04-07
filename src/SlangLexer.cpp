
// Generated from Slang.g4 by ANTLR 4.7.2


#include "SlangLexer.h"


using namespace antlr4;

using namespace antlrcpptest;

SlangLexer::SlangLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SlangLexer::~SlangLexer() {
  delete _interpreter;
}

std::string SlangLexer::getGrammarFileName() const {
  return "Slang.g4";
}

const std::vector<std::string>& SlangLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& SlangLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& SlangLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& SlangLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& SlangLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> SlangLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& SlangLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> SlangLexer::_decisionToDFA;
atn::PredictionContextCache SlangLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SlangLexer::_atn;
std::vector<uint16_t> SlangLexer::_serializedATN;

std::vector<std::string> SlangLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"WS", u8"CHAR", u8"DIGIT", u8"IDENTIFIER"
};

std::vector<std::string> SlangLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> SlangLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> SlangLexer::_literalNames = {
  "", u8"'PROGRAM'", u8"'END_PROGRAM'"
};

std::vector<std::string> SlangLexer::_symbolicNames = {
  "", "", "", u8"WS", u8"CHAR", u8"DIGIT", u8"IDENTIFIER"
};

dfa::Vocabulary SlangLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SlangLexer::_tokenNames;

SlangLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x8, 0x34, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
    0x7, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x30, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x33, 0xb, 0x7, 0x2, 0x2, 0x8, 0x3, 0x3, 0x5, 0x4, 
    0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0x3, 0x2, 0x4, 0x5, 0x2, 0xb, 
    0xc, 0xf, 0xf, 0x22, 0x22, 0x4, 0x2, 0x43, 0x5c, 0x63, 0x7c, 0x2, 0x36, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x5, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7, 0x23, 0x3, 0x2, 0x2, 0x2, 0x9, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xb, 0x29, 0x3, 0x2, 0x2, 0x2, 0xd, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0xf, 0x10, 0x7, 0x52, 0x2, 0x2, 0x10, 0x11, 0x7, 0x54, 0x2, 
    0x2, 0x11, 0x12, 0x7, 0x51, 0x2, 0x2, 0x12, 0x13, 0x7, 0x49, 0x2, 0x2, 
    0x13, 0x14, 0x7, 0x54, 0x2, 0x2, 0x14, 0x15, 0x7, 0x43, 0x2, 0x2, 0x15, 
    0x16, 0x7, 0x4f, 0x2, 0x2, 0x16, 0x4, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 
    0x7, 0x47, 0x2, 0x2, 0x18, 0x19, 0x7, 0x50, 0x2, 0x2, 0x19, 0x1a, 0x7, 
    0x46, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x61, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x52, 
    0x2, 0x2, 0x1c, 0x1d, 0x7, 0x54, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x51, 0x2, 
    0x2, 0x1e, 0x1f, 0x7, 0x49, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x54, 0x2, 0x2, 
    0x20, 0x21, 0x7, 0x43, 0x2, 0x2, 0x21, 0x22, 0x7, 0x4f, 0x2, 0x2, 0x22, 
    0x6, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x9, 0x2, 0x2, 0x2, 0x24, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x8, 0x4, 0x2, 0x2, 0x26, 0x8, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x28, 0x9, 0x3, 0x2, 0x2, 0x28, 0xa, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x4, 0x32, 0x3b, 0x2, 0x2a, 0xc, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x31, 0x5, 0x9, 0x5, 0x2, 0x2c, 0x30, 0x5, 0x9, 0x5, 0x2, 
    0x2d, 0x30, 0x5, 0xb, 0x6, 0x2, 0x2e, 0x30, 0x7, 0x61, 0x2, 0x2, 0x2f, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0xe, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x5, 0x2, 0x2f, 0x31, 0x3, 
    0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SlangLexer::Initializer SlangLexer::_init;
