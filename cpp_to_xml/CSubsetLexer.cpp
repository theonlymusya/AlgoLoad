
// Generated from small_c_grammar.g4 by ANTLR 4.13.2


#include "CSubsetLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CSubsetLexerStaticData final {
  CSubsetLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetLexerStaticData(const CSubsetLexerStaticData&) = delete;
  CSubsetLexerStaticData(CSubsetLexerStaticData&&) = delete;
  CSubsetLexerStaticData& operator=(const CSubsetLexerStaticData&) = delete;
  CSubsetLexerStaticData& operator=(CSubsetLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetLexerStaticData> csubsetlexerLexerStaticData = nullptr;

void csubsetlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "ID", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'if'", "'('", "')'", "'else'", "'for'", "';'", "'while'", "'return'", 
      "'int'", "'='", "'+'", "'-'", "'*'", "'/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", 
      "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,17,99,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,
  	1,13,1,14,1,14,5,14,83,8,14,10,14,12,14,86,9,14,1,15,4,15,89,8,15,11,
  	15,12,15,90,1,16,4,16,94,8,16,11,16,12,16,95,1,16,1,16,0,0,17,1,1,3,2,
  	5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,1,0,4,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,
  	0,48,57,3,0,9,10,13,13,32,32,101,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,
  	0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,
  	0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,
  	0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,1,35,1,0,0,0,3,38,1,0,0,0,5,
  	40,1,0,0,0,7,42,1,0,0,0,9,47,1,0,0,0,11,51,1,0,0,0,13,53,1,0,0,0,15,59,
  	1,0,0,0,17,66,1,0,0,0,19,70,1,0,0,0,21,72,1,0,0,0,23,74,1,0,0,0,25,76,
  	1,0,0,0,27,78,1,0,0,0,29,80,1,0,0,0,31,88,1,0,0,0,33,93,1,0,0,0,35,36,
  	5,105,0,0,36,37,5,102,0,0,37,2,1,0,0,0,38,39,5,40,0,0,39,4,1,0,0,0,40,
  	41,5,41,0,0,41,6,1,0,0,0,42,43,5,101,0,0,43,44,5,108,0,0,44,45,5,115,
  	0,0,45,46,5,101,0,0,46,8,1,0,0,0,47,48,5,102,0,0,48,49,5,111,0,0,49,50,
  	5,114,0,0,50,10,1,0,0,0,51,52,5,59,0,0,52,12,1,0,0,0,53,54,5,119,0,0,
  	54,55,5,104,0,0,55,56,5,105,0,0,56,57,5,108,0,0,57,58,5,101,0,0,58,14,
  	1,0,0,0,59,60,5,114,0,0,60,61,5,101,0,0,61,62,5,116,0,0,62,63,5,117,0,
  	0,63,64,5,114,0,0,64,65,5,110,0,0,65,16,1,0,0,0,66,67,5,105,0,0,67,68,
  	5,110,0,0,68,69,5,116,0,0,69,18,1,0,0,0,70,71,5,61,0,0,71,20,1,0,0,0,
  	72,73,5,43,0,0,73,22,1,0,0,0,74,75,5,45,0,0,75,24,1,0,0,0,76,77,5,42,
  	0,0,77,26,1,0,0,0,78,79,5,47,0,0,79,28,1,0,0,0,80,84,7,0,0,0,81,83,7,
  	1,0,0,82,81,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,30,1,
  	0,0,0,86,84,1,0,0,0,87,89,7,2,0,0,88,87,1,0,0,0,89,90,1,0,0,0,90,88,1,
  	0,0,0,90,91,1,0,0,0,91,32,1,0,0,0,92,94,7,3,0,0,93,92,1,0,0,0,94,95,1,
  	0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,98,6,16,0,0,98,34,
  	1,0,0,0,4,0,84,90,95,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetlexerLexerStaticData = std::move(staticData);
}

}

CSubsetLexer::CSubsetLexer(CharStream *input) : Lexer(input) {
  CSubsetLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *csubsetlexerLexerStaticData->atn, csubsetlexerLexerStaticData->decisionToDFA, csubsetlexerLexerStaticData->sharedContextCache);
}

CSubsetLexer::~CSubsetLexer() {
  delete _interpreter;
}

std::string CSubsetLexer::getGrammarFileName() const {
  return "small_c_grammar.g4";
}

const std::vector<std::string>& CSubsetLexer::getRuleNames() const {
  return csubsetlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CSubsetLexer::getChannelNames() const {
  return csubsetlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CSubsetLexer::getModeNames() const {
  return csubsetlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CSubsetLexer::getVocabulary() const {
  return csubsetlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetLexer::getSerializedATN() const {
  return csubsetlexerLexerStaticData->serializedATN;
}

const atn::ATN& CSubsetLexer::getATN() const {
  return *csubsetlexerLexerStaticData->atn;
}




void CSubsetLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(csubsetlexerLexerOnceFlag, csubsetlexerLexerInitialize);
#endif
}
