
// Generated from small_c_grammar.g4 by ANTLR 4.13.2


#include "small_c_grammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct Small_c_grammarLexerStaticData final {
  Small_c_grammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Small_c_grammarLexerStaticData(const Small_c_grammarLexerStaticData&) = delete;
  Small_c_grammarLexerStaticData(Small_c_grammarLexerStaticData&&) = delete;
  Small_c_grammarLexerStaticData& operator=(const Small_c_grammarLexerStaticData&) = delete;
  Small_c_grammarLexerStaticData& operator=(Small_c_grammarLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag small_c_grammarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Small_c_grammarLexerStaticData> small_c_grammarlexerLexerStaticData = nullptr;

void small_c_grammarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (small_c_grammarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(small_c_grammarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Small_c_grammarLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "ID", "NUMBER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'if'", 
      "'else'", "'for'", "','", "'='", "'double'", "'['", "']'", "'||'", 
      "'&&'", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'+'", "'-'", 
      "'*'", "'/'", "'%'", "'!'", "'::'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "NUMBER", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,33,177,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,8,1,
  	8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,
  	1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,21,1,22,1,22,
  	1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,
  	1,29,1,29,1,30,1,30,5,30,153,8,30,10,30,12,30,156,9,30,1,31,4,31,159,
  	8,31,11,31,12,31,160,1,31,1,31,4,31,165,8,31,11,31,12,31,166,3,31,169,
  	8,31,1,32,4,32,172,8,32,11,32,12,32,173,1,32,1,32,0,0,33,1,1,3,2,5,3,
  	7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,
  	33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,
  	28,57,29,59,30,61,31,63,32,65,33,1,0,4,3,0,65,90,95,95,97,122,4,0,48,
  	57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,181,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,
  	0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,
  	0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,1,67,
  	1,0,0,0,3,71,1,0,0,0,5,76,1,0,0,0,7,78,1,0,0,0,9,80,1,0,0,0,11,82,1,0,
  	0,0,13,84,1,0,0,0,15,86,1,0,0,0,17,89,1,0,0,0,19,94,1,0,0,0,21,98,1,0,
  	0,0,23,100,1,0,0,0,25,102,1,0,0,0,27,109,1,0,0,0,29,111,1,0,0,0,31,113,
  	1,0,0,0,33,116,1,0,0,0,35,119,1,0,0,0,37,122,1,0,0,0,39,125,1,0,0,0,41,
  	127,1,0,0,0,43,129,1,0,0,0,45,132,1,0,0,0,47,135,1,0,0,0,49,137,1,0,0,
  	0,51,139,1,0,0,0,53,141,1,0,0,0,55,143,1,0,0,0,57,145,1,0,0,0,59,147,
  	1,0,0,0,61,150,1,0,0,0,63,158,1,0,0,0,65,171,1,0,0,0,67,68,5,105,0,0,
  	68,69,5,110,0,0,69,70,5,116,0,0,70,2,1,0,0,0,71,72,5,109,0,0,72,73,5,
  	97,0,0,73,74,5,105,0,0,74,75,5,110,0,0,75,4,1,0,0,0,76,77,5,40,0,0,77,
  	6,1,0,0,0,78,79,5,41,0,0,79,8,1,0,0,0,80,81,5,123,0,0,81,10,1,0,0,0,82,
  	83,5,125,0,0,83,12,1,0,0,0,84,85,5,59,0,0,85,14,1,0,0,0,86,87,5,105,0,
  	0,87,88,5,102,0,0,88,16,1,0,0,0,89,90,5,101,0,0,90,91,5,108,0,0,91,92,
  	5,115,0,0,92,93,5,101,0,0,93,18,1,0,0,0,94,95,5,102,0,0,95,96,5,111,0,
  	0,96,97,5,114,0,0,97,20,1,0,0,0,98,99,5,44,0,0,99,22,1,0,0,0,100,101,
  	5,61,0,0,101,24,1,0,0,0,102,103,5,100,0,0,103,104,5,111,0,0,104,105,5,
  	117,0,0,105,106,5,98,0,0,106,107,5,108,0,0,107,108,5,101,0,0,108,26,1,
  	0,0,0,109,110,5,91,0,0,110,28,1,0,0,0,111,112,5,93,0,0,112,30,1,0,0,0,
  	113,114,5,124,0,0,114,115,5,124,0,0,115,32,1,0,0,0,116,117,5,38,0,0,117,
  	118,5,38,0,0,118,34,1,0,0,0,119,120,5,61,0,0,120,121,5,61,0,0,121,36,
  	1,0,0,0,122,123,5,33,0,0,123,124,5,61,0,0,124,38,1,0,0,0,125,126,5,60,
  	0,0,126,40,1,0,0,0,127,128,5,62,0,0,128,42,1,0,0,0,129,130,5,60,0,0,130,
  	131,5,61,0,0,131,44,1,0,0,0,132,133,5,62,0,0,133,134,5,61,0,0,134,46,
  	1,0,0,0,135,136,5,43,0,0,136,48,1,0,0,0,137,138,5,45,0,0,138,50,1,0,0,
  	0,139,140,5,42,0,0,140,52,1,0,0,0,141,142,5,47,0,0,142,54,1,0,0,0,143,
  	144,5,37,0,0,144,56,1,0,0,0,145,146,5,33,0,0,146,58,1,0,0,0,147,148,5,
  	58,0,0,148,149,5,58,0,0,149,60,1,0,0,0,150,154,7,0,0,0,151,153,7,1,0,
  	0,152,151,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,
  	62,1,0,0,0,156,154,1,0,0,0,157,159,7,2,0,0,158,157,1,0,0,0,159,160,1,
  	0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,168,1,0,0,0,162,164,5,46,0,
  	0,163,165,7,2,0,0,164,163,1,0,0,0,165,166,1,0,0,0,166,164,1,0,0,0,166,
  	167,1,0,0,0,167,169,1,0,0,0,168,162,1,0,0,0,168,169,1,0,0,0,169,64,1,
  	0,0,0,170,172,7,3,0,0,171,170,1,0,0,0,172,173,1,0,0,0,173,171,1,0,0,0,
  	173,174,1,0,0,0,174,175,1,0,0,0,175,176,6,32,0,0,176,66,1,0,0,0,6,0,154,
  	160,166,168,173,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  small_c_grammarlexerLexerStaticData = std::move(staticData);
}

}

small_c_grammarLexer::small_c_grammarLexer(CharStream *input) : Lexer(input) {
  small_c_grammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *small_c_grammarlexerLexerStaticData->atn, small_c_grammarlexerLexerStaticData->decisionToDFA, small_c_grammarlexerLexerStaticData->sharedContextCache);
}

small_c_grammarLexer::~small_c_grammarLexer() {
  delete _interpreter;
}

std::string small_c_grammarLexer::getGrammarFileName() const {
  return "small_c_grammar.g4";
}

const std::vector<std::string>& small_c_grammarLexer::getRuleNames() const {
  return small_c_grammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& small_c_grammarLexer::getChannelNames() const {
  return small_c_grammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& small_c_grammarLexer::getModeNames() const {
  return small_c_grammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& small_c_grammarLexer::getVocabulary() const {
  return small_c_grammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView small_c_grammarLexer::getSerializedATN() const {
  return small_c_grammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& small_c_grammarLexer::getATN() const {
  return *small_c_grammarlexerLexerStaticData->atn;
}




void small_c_grammarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  small_c_grammarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(small_c_grammarlexerLexerOnceFlag, small_c_grammarlexerLexerInitialize);
#endif
}
