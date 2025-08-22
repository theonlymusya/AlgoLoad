
// Generated from small_c_grammar.g4 by ANTLR 4.13.2


#include "small_c_grammarListener.h"
#include "small_c_grammarVisitor.h"

#include "small_c_grammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Small_c_grammarParserStaticData final {
  Small_c_grammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Small_c_grammarParserStaticData(const Small_c_grammarParserStaticData&) = delete;
  Small_c_grammarParserStaticData(Small_c_grammarParserStaticData&&) = delete;
  Small_c_grammarParserStaticData& operator=(const Small_c_grammarParserStaticData&) = delete;
  Small_c_grammarParserStaticData& operator=(Small_c_grammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag small_c_grammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Small_c_grammarParserStaticData> small_c_grammarParserStaticData = nullptr;

void small_c_grammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (small_c_grammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(small_c_grammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Small_c_grammarParserStaticData>(
    std::vector<std::string>{
      "program", "function", "statement", "block", "ifStatement", "elifChain", 
      "elseBranch", "forStatement", "forStart", "forStartExpr", "forStop", 
      "forStep", "forStepExpr", "assignmentOp", "declaration", "varName", 
      "arrayDecl", "mathExpr", "logicalOrExpr", "logicalAndExpr", "equalityExpr", 
      "relationalExpr", "additiveExpr", "multiplicativeExpr", "unaryExpr", 
      "primaryExpr", "funcCall", "funcName"
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
  	4,1,33,273,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,1,
  	0,5,0,59,8,0,10,0,12,0,62,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,72,
  	8,1,10,1,12,1,75,9,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,85,8,2,1,3,1,
  	3,5,3,89,8,3,10,3,12,3,92,9,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,102,
  	8,4,1,4,3,4,105,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,4,5,114,8,5,11,5,12,5,
  	115,1,6,1,6,1,6,1,7,1,7,1,7,3,7,124,8,7,1,7,1,7,3,7,128,8,7,1,7,1,7,3,
  	7,132,8,7,1,7,1,7,1,7,1,8,1,8,1,8,5,8,140,8,8,10,8,12,8,143,9,8,1,9,1,
  	9,1,10,1,10,1,11,1,11,1,11,5,11,152,8,11,10,11,12,11,155,9,11,1,12,1,
  	12,1,12,1,12,1,13,3,13,162,8,13,1,13,1,13,1,13,3,13,167,8,13,1,14,1,14,
  	1,15,1,15,3,15,173,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,182,8,
  	16,10,16,12,16,185,9,16,1,17,1,17,1,18,1,18,1,18,5,18,192,8,18,10,18,
  	12,18,195,9,18,1,19,1,19,1,19,5,19,200,8,19,10,19,12,19,203,9,19,1,20,
  	1,20,1,20,5,20,208,8,20,10,20,12,20,211,9,20,1,21,1,21,1,21,5,21,216,
  	8,21,10,21,12,21,219,9,21,1,22,1,22,1,22,5,22,224,8,22,10,22,12,22,227,
  	9,22,1,23,1,23,1,23,5,23,232,8,23,10,23,12,23,235,9,23,1,24,1,24,1,24,
  	3,24,240,8,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,249,8,25,1,26,1,
  	26,1,26,1,26,1,26,5,26,256,8,26,10,26,12,26,259,9,26,3,26,261,8,26,1,
  	26,1,26,1,27,1,27,1,27,5,27,268,8,27,10,27,12,27,271,9,27,1,27,0,0,28,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,0,6,2,0,1,1,13,13,1,0,18,19,1,0,20,23,1,0,24,25,1,0,26,28,2,
  	0,24,25,29,29,276,0,60,1,0,0,0,2,65,1,0,0,0,4,84,1,0,0,0,6,86,1,0,0,0,
  	8,95,1,0,0,0,10,113,1,0,0,0,12,117,1,0,0,0,14,120,1,0,0,0,16,136,1,0,
  	0,0,18,144,1,0,0,0,20,146,1,0,0,0,22,148,1,0,0,0,24,156,1,0,0,0,26,161,
  	1,0,0,0,28,168,1,0,0,0,30,170,1,0,0,0,32,174,1,0,0,0,34,186,1,0,0,0,36,
  	188,1,0,0,0,38,196,1,0,0,0,40,204,1,0,0,0,42,212,1,0,0,0,44,220,1,0,0,
  	0,46,228,1,0,0,0,48,239,1,0,0,0,50,248,1,0,0,0,52,250,1,0,0,0,54,264,
  	1,0,0,0,56,59,3,2,1,0,57,59,3,4,2,0,58,56,1,0,0,0,58,57,1,0,0,0,59,62,
  	1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,61,63,1,0,0,0,62,60,1,0,0,0,63,64,
  	5,0,0,1,64,1,1,0,0,0,65,66,5,1,0,0,66,67,5,2,0,0,67,68,5,3,0,0,68,69,
  	5,4,0,0,69,73,5,5,0,0,70,72,3,4,2,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,
  	1,0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,73,1,0,0,0,76,77,5,6,0,0,77,3,
  	1,0,0,0,78,85,3,8,4,0,79,85,3,14,7,0,80,81,3,26,13,0,81,82,5,7,0,0,82,
  	85,1,0,0,0,83,85,3,6,3,0,84,78,1,0,0,0,84,79,1,0,0,0,84,80,1,0,0,0,84,
  	83,1,0,0,0,85,5,1,0,0,0,86,90,5,5,0,0,87,89,3,4,2,0,88,87,1,0,0,0,89,
  	92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,90,1,0,0,0,93,
  	94,5,6,0,0,94,7,1,0,0,0,95,96,5,8,0,0,96,97,5,3,0,0,97,98,3,34,17,0,98,
  	99,5,4,0,0,99,101,3,4,2,0,100,102,3,10,5,0,101,100,1,0,0,0,101,102,1,
  	0,0,0,102,104,1,0,0,0,103,105,3,12,6,0,104,103,1,0,0,0,104,105,1,0,0,
  	0,105,9,1,0,0,0,106,107,5,9,0,0,107,108,5,8,0,0,108,109,5,3,0,0,109,110,
  	3,34,17,0,110,111,5,4,0,0,111,112,3,4,2,0,112,114,1,0,0,0,113,106,1,0,
  	0,0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,11,1,0,0,0,117,
  	118,5,9,0,0,118,119,3,4,2,0,119,13,1,0,0,0,120,121,5,10,0,0,121,123,5,
  	3,0,0,122,124,3,16,8,0,123,122,1,0,0,0,123,124,1,0,0,0,124,125,1,0,0,
  	0,125,127,5,7,0,0,126,128,3,20,10,0,127,126,1,0,0,0,127,128,1,0,0,0,128,
  	129,1,0,0,0,129,131,5,7,0,0,130,132,3,22,11,0,131,130,1,0,0,0,131,132,
  	1,0,0,0,132,133,1,0,0,0,133,134,5,4,0,0,134,135,3,4,2,0,135,15,1,0,0,
  	0,136,141,3,18,9,0,137,138,5,11,0,0,138,140,3,18,9,0,139,137,1,0,0,0,
  	140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,17,1,0,0,0,143,141,
  	1,0,0,0,144,145,3,26,13,0,145,19,1,0,0,0,146,147,3,34,17,0,147,21,1,0,
  	0,0,148,153,3,24,12,0,149,150,5,11,0,0,150,152,3,24,12,0,151,149,1,0,
  	0,0,152,155,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,23,1,0,0,0,155,
  	153,1,0,0,0,156,157,3,30,15,0,157,158,5,12,0,0,158,159,3,34,17,0,159,
  	25,1,0,0,0,160,162,3,28,14,0,161,160,1,0,0,0,161,162,1,0,0,0,162,163,
  	1,0,0,0,163,166,3,30,15,0,164,165,5,12,0,0,165,167,3,34,17,0,166,164,
  	1,0,0,0,166,167,1,0,0,0,167,27,1,0,0,0,168,169,7,0,0,0,169,29,1,0,0,0,
  	170,172,5,31,0,0,171,173,3,32,16,0,172,171,1,0,0,0,172,173,1,0,0,0,173,
  	31,1,0,0,0,174,175,5,14,0,0,175,176,3,34,17,0,176,183,5,15,0,0,177,178,
  	5,14,0,0,178,179,3,34,17,0,179,180,5,15,0,0,180,182,1,0,0,0,181,177,1,
  	0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,33,1,0,0,0,
  	185,183,1,0,0,0,186,187,3,36,18,0,187,35,1,0,0,0,188,193,3,38,19,0,189,
  	190,5,16,0,0,190,192,3,38,19,0,191,189,1,0,0,0,192,195,1,0,0,0,193,191,
  	1,0,0,0,193,194,1,0,0,0,194,37,1,0,0,0,195,193,1,0,0,0,196,201,3,40,20,
  	0,197,198,5,17,0,0,198,200,3,40,20,0,199,197,1,0,0,0,200,203,1,0,0,0,
  	201,199,1,0,0,0,201,202,1,0,0,0,202,39,1,0,0,0,203,201,1,0,0,0,204,209,
  	3,42,21,0,205,206,7,1,0,0,206,208,3,42,21,0,207,205,1,0,0,0,208,211,1,
  	0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,41,1,0,0,0,211,209,1,0,0,0,
  	212,217,3,44,22,0,213,214,7,2,0,0,214,216,3,44,22,0,215,213,1,0,0,0,216,
  	219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,43,1,0,0,0,219,217,1,
  	0,0,0,220,225,3,46,23,0,221,222,7,3,0,0,222,224,3,46,23,0,223,221,1,0,
  	0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,45,1,0,0,0,227,
  	225,1,0,0,0,228,233,3,48,24,0,229,230,7,4,0,0,230,232,3,48,24,0,231,229,
  	1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,47,1,0,0,
  	0,235,233,1,0,0,0,236,237,7,5,0,0,237,240,3,48,24,0,238,240,3,50,25,0,
  	239,236,1,0,0,0,239,238,1,0,0,0,240,49,1,0,0,0,241,249,3,52,26,0,242,
  	243,5,3,0,0,243,244,3,34,17,0,244,245,5,4,0,0,245,249,1,0,0,0,246,249,
  	3,30,15,0,247,249,5,32,0,0,248,241,1,0,0,0,248,242,1,0,0,0,248,246,1,
  	0,0,0,248,247,1,0,0,0,249,51,1,0,0,0,250,251,3,54,27,0,251,260,5,3,0,
  	0,252,257,3,34,17,0,253,254,5,11,0,0,254,256,3,34,17,0,255,253,1,0,0,
  	0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,261,1,0,0,0,259,
  	257,1,0,0,0,260,252,1,0,0,0,260,261,1,0,0,0,261,262,1,0,0,0,262,263,5,
  	4,0,0,263,53,1,0,0,0,264,269,5,31,0,0,265,266,5,30,0,0,266,268,5,31,0,
  	0,267,265,1,0,0,0,268,271,1,0,0,0,269,267,1,0,0,0,269,270,1,0,0,0,270,
  	55,1,0,0,0,271,269,1,0,0,0,28,58,60,73,84,90,101,104,115,123,127,131,
  	141,153,161,166,172,183,193,201,209,217,225,233,239,248,257,260,269
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  small_c_grammarParserStaticData = std::move(staticData);
}

}

small_c_grammarParser::small_c_grammarParser(TokenStream *input) : small_c_grammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

small_c_grammarParser::small_c_grammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  small_c_grammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *small_c_grammarParserStaticData->atn, small_c_grammarParserStaticData->decisionToDFA, small_c_grammarParserStaticData->sharedContextCache, options);
}

small_c_grammarParser::~small_c_grammarParser() {
  delete _interpreter;
}

const atn::ATN& small_c_grammarParser::getATN() const {
  return *small_c_grammarParserStaticData->atn;
}

std::string small_c_grammarParser::getGrammarFileName() const {
  return "small_c_grammar.g4";
}

const std::vector<std::string>& small_c_grammarParser::getRuleNames() const {
  return small_c_grammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& small_c_grammarParser::getVocabulary() const {
  return small_c_grammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView small_c_grammarParser::getSerializedATN() const {
  return small_c_grammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

small_c_grammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* small_c_grammarParser::ProgramContext::EOF() {
  return getToken(small_c_grammarParser::EOF, 0);
}

std::vector<small_c_grammarParser::FunctionContext *> small_c_grammarParser::ProgramContext::function() {
  return getRuleContexts<small_c_grammarParser::FunctionContext>();
}

small_c_grammarParser::FunctionContext* small_c_grammarParser::ProgramContext::function(size_t i) {
  return getRuleContext<small_c_grammarParser::FunctionContext>(i);
}

std::vector<small_c_grammarParser::StatementContext *> small_c_grammarParser::ProgramContext::statement() {
  return getRuleContexts<small_c_grammarParser::StatementContext>();
}

small_c_grammarParser::StatementContext* small_c_grammarParser::ProgramContext::statement(size_t i) {
  return getRuleContext<small_c_grammarParser::StatementContext>(i);
}


size_t small_c_grammarParser::ProgramContext::getRuleIndex() const {
  return small_c_grammarParser::RuleProgram;
}

void small_c_grammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void small_c_grammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any small_c_grammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ProgramContext* small_c_grammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, small_c_grammarParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147493154) != 0)) {
      setState(58);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(56);
        function();
        break;
      }

      case 2: {
        setState(57);
        statement();
        break;
      }

      default:
        break;
      }
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(small_c_grammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

small_c_grammarParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::StatementContext *> small_c_grammarParser::FunctionContext::statement() {
  return getRuleContexts<small_c_grammarParser::StatementContext>();
}

small_c_grammarParser::StatementContext* small_c_grammarParser::FunctionContext::statement(size_t i) {
  return getRuleContext<small_c_grammarParser::StatementContext>(i);
}


size_t small_c_grammarParser::FunctionContext::getRuleIndex() const {
  return small_c_grammarParser::RuleFunction;
}

void small_c_grammarParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void small_c_grammarParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any small_c_grammarParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::FunctionContext* small_c_grammarParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, small_c_grammarParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(small_c_grammarParser::T__0);
    setState(66);
    match(small_c_grammarParser::T__1);
    setState(67);
    match(small_c_grammarParser::T__2);
    setState(68);
    match(small_c_grammarParser::T__3);
    setState(69);
    match(small_c_grammarParser::T__4);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147493154) != 0)) {
      setState(70);
      statement();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(small_c_grammarParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

small_c_grammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::IfStatementContext* small_c_grammarParser::StatementContext::ifStatement() {
  return getRuleContext<small_c_grammarParser::IfStatementContext>(0);
}

small_c_grammarParser::ForStatementContext* small_c_grammarParser::StatementContext::forStatement() {
  return getRuleContext<small_c_grammarParser::ForStatementContext>(0);
}

small_c_grammarParser::AssignmentOpContext* small_c_grammarParser::StatementContext::assignmentOp() {
  return getRuleContext<small_c_grammarParser::AssignmentOpContext>(0);
}

small_c_grammarParser::BlockContext* small_c_grammarParser::StatementContext::block() {
  return getRuleContext<small_c_grammarParser::BlockContext>(0);
}


size_t small_c_grammarParser::StatementContext::getRuleIndex() const {
  return small_c_grammarParser::RuleStatement;
}

void small_c_grammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void small_c_grammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any small_c_grammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::StatementContext* small_c_grammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, small_c_grammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case small_c_grammarParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        ifStatement();
        break;
      }

      case small_c_grammarParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        forStatement();
        break;
      }

      case small_c_grammarParser::T__0:
      case small_c_grammarParser::T__12:
      case small_c_grammarParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(80);
        assignmentOp();
        setState(81);
        match(small_c_grammarParser::T__6);
        break;
      }

      case small_c_grammarParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(83);
        block();
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

//----------------- BlockContext ------------------------------------------------------------------

small_c_grammarParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::StatementContext *> small_c_grammarParser::BlockContext::statement() {
  return getRuleContexts<small_c_grammarParser::StatementContext>();
}

small_c_grammarParser::StatementContext* small_c_grammarParser::BlockContext::statement(size_t i) {
  return getRuleContext<small_c_grammarParser::StatementContext>(i);
}


size_t small_c_grammarParser::BlockContext::getRuleIndex() const {
  return small_c_grammarParser::RuleBlock;
}

void small_c_grammarParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void small_c_grammarParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any small_c_grammarParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::BlockContext* small_c_grammarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, small_c_grammarParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(small_c_grammarParser::T__4);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147493154) != 0)) {
      setState(87);
      statement();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(small_c_grammarParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

small_c_grammarParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::StatementContext* small_c_grammarParser::IfStatementContext::statement() {
  return getRuleContext<small_c_grammarParser::StatementContext>(0);
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::IfStatementContext::mathExpr() {
  return getRuleContext<small_c_grammarParser::MathExprContext>(0);
}

small_c_grammarParser::ElifChainContext* small_c_grammarParser::IfStatementContext::elifChain() {
  return getRuleContext<small_c_grammarParser::ElifChainContext>(0);
}

small_c_grammarParser::ElseBranchContext* small_c_grammarParser::IfStatementContext::elseBranch() {
  return getRuleContext<small_c_grammarParser::ElseBranchContext>(0);
}


size_t small_c_grammarParser::IfStatementContext::getRuleIndex() const {
  return small_c_grammarParser::RuleIfStatement;
}

void small_c_grammarParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void small_c_grammarParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any small_c_grammarParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::IfStatementContext* small_c_grammarParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, small_c_grammarParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(small_c_grammarParser::T__7);
    setState(96);
    match(small_c_grammarParser::T__2);
    setState(97);
    antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = mathExpr();
    setState(98);
    match(small_c_grammarParser::T__3);
    setState(99);
    statement();
    setState(101);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(100);
      elifChain();
      break;
    }

    default:
      break;
    }
    setState(104);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(103);
      elseBranch();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElifChainContext ------------------------------------------------------------------

small_c_grammarParser::ElifChainContext::ElifChainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::StatementContext *> small_c_grammarParser::ElifChainContext::statement() {
  return getRuleContexts<small_c_grammarParser::StatementContext>();
}

small_c_grammarParser::StatementContext* small_c_grammarParser::ElifChainContext::statement(size_t i) {
  return getRuleContext<small_c_grammarParser::StatementContext>(i);
}

std::vector<small_c_grammarParser::MathExprContext *> small_c_grammarParser::ElifChainContext::mathExpr() {
  return getRuleContexts<small_c_grammarParser::MathExprContext>();
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::ElifChainContext::mathExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::MathExprContext>(i);
}


size_t small_c_grammarParser::ElifChainContext::getRuleIndex() const {
  return small_c_grammarParser::RuleElifChain;
}

void small_c_grammarParser::ElifChainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElifChain(this);
}

void small_c_grammarParser::ElifChainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElifChain(this);
}


std::any small_c_grammarParser::ElifChainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitElifChain(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ElifChainContext* small_c_grammarParser::elifChain() {
  ElifChainContext *_localctx = _tracker.createInstance<ElifChainContext>(_ctx, getState());
  enterRule(_localctx, 10, small_c_grammarParser::RuleElifChain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(113); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(106);
              match(small_c_grammarParser::T__8);
              setState(107);
              match(small_c_grammarParser::T__7);
              setState(108);
              match(small_c_grammarParser::T__2);
              setState(109);
              antlrcpp::downCast<ElifChainContext *>(_localctx)->mathExprContext = mathExpr();
              antlrcpp::downCast<ElifChainContext *>(_localctx)->elifCond.push_back(antlrcpp::downCast<ElifChainContext *>(_localctx)->mathExprContext);
              setState(110);
              match(small_c_grammarParser::T__3);
              setState(111);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(115); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseBranchContext ------------------------------------------------------------------

small_c_grammarParser::ElseBranchContext::ElseBranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::StatementContext* small_c_grammarParser::ElseBranchContext::statement() {
  return getRuleContext<small_c_grammarParser::StatementContext>(0);
}


size_t small_c_grammarParser::ElseBranchContext::getRuleIndex() const {
  return small_c_grammarParser::RuleElseBranch;
}

void small_c_grammarParser::ElseBranchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseBranch(this);
}

void small_c_grammarParser::ElseBranchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseBranch(this);
}


std::any small_c_grammarParser::ElseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitElseBranch(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ElseBranchContext* small_c_grammarParser::elseBranch() {
  ElseBranchContext *_localctx = _tracker.createInstance<ElseBranchContext>(_ctx, getState());
  enterRule(_localctx, 12, small_c_grammarParser::RuleElseBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(small_c_grammarParser::T__8);
    setState(118);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

small_c_grammarParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::StatementContext* small_c_grammarParser::ForStatementContext::statement() {
  return getRuleContext<small_c_grammarParser::StatementContext>(0);
}

small_c_grammarParser::ForStartContext* small_c_grammarParser::ForStatementContext::forStart() {
  return getRuleContext<small_c_grammarParser::ForStartContext>(0);
}

small_c_grammarParser::ForStopContext* small_c_grammarParser::ForStatementContext::forStop() {
  return getRuleContext<small_c_grammarParser::ForStopContext>(0);
}

small_c_grammarParser::ForStepContext* small_c_grammarParser::ForStatementContext::forStep() {
  return getRuleContext<small_c_grammarParser::ForStepContext>(0);
}


size_t small_c_grammarParser::ForStatementContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStatement;
}

void small_c_grammarParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void small_c_grammarParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any small_c_grammarParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStatementContext* small_c_grammarParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, small_c_grammarParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(small_c_grammarParser::T__9);
    setState(121);
    match(small_c_grammarParser::T__2);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147491842) != 0)) {
      setState(122);
      forStart();
    }
    setState(125);
    match(small_c_grammarParser::T__6);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7029653512) != 0)) {
      setState(126);
      forStop();
    }
    setState(129);
    match(small_c_grammarParser::T__6);
    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == small_c_grammarParser::ID) {
      setState(130);
      forStep();
    }
    setState(133);
    match(small_c_grammarParser::T__3);
    setState(134);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStartContext ------------------------------------------------------------------

small_c_grammarParser::ForStartContext::ForStartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::ForStartExprContext *> small_c_grammarParser::ForStartContext::forStartExpr() {
  return getRuleContexts<small_c_grammarParser::ForStartExprContext>();
}

small_c_grammarParser::ForStartExprContext* small_c_grammarParser::ForStartContext::forStartExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::ForStartExprContext>(i);
}


size_t small_c_grammarParser::ForStartContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStart;
}

void small_c_grammarParser::ForStartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStart(this);
}

void small_c_grammarParser::ForStartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStart(this);
}


std::any small_c_grammarParser::ForStartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStart(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStartContext* small_c_grammarParser::forStart() {
  ForStartContext *_localctx = _tracker.createInstance<ForStartContext>(_ctx, getState());
  enterRule(_localctx, 16, small_c_grammarParser::RuleForStart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    forStartExpr();
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__10) {
      setState(137);
      match(small_c_grammarParser::T__10);
      setState(138);
      forStartExpr();
      setState(143);
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

//----------------- ForStartExprContext ------------------------------------------------------------------

small_c_grammarParser::ForStartExprContext::ForStartExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::AssignmentOpContext* small_c_grammarParser::ForStartExprContext::assignmentOp() {
  return getRuleContext<small_c_grammarParser::AssignmentOpContext>(0);
}


size_t small_c_grammarParser::ForStartExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStartExpr;
}

void small_c_grammarParser::ForStartExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStartExpr(this);
}

void small_c_grammarParser::ForStartExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStartExpr(this);
}


std::any small_c_grammarParser::ForStartExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStartExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStartExprContext* small_c_grammarParser::forStartExpr() {
  ForStartExprContext *_localctx = _tracker.createInstance<ForStartExprContext>(_ctx, getState());
  enterRule(_localctx, 18, small_c_grammarParser::RuleForStartExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    assignmentOp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStopContext ------------------------------------------------------------------

small_c_grammarParser::ForStopContext::ForStopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::ForStopContext::mathExpr() {
  return getRuleContext<small_c_grammarParser::MathExprContext>(0);
}


size_t small_c_grammarParser::ForStopContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStop;
}

void small_c_grammarParser::ForStopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStop(this);
}

void small_c_grammarParser::ForStopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStop(this);
}


std::any small_c_grammarParser::ForStopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStop(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStopContext* small_c_grammarParser::forStop() {
  ForStopContext *_localctx = _tracker.createInstance<ForStopContext>(_ctx, getState());
  enterRule(_localctx, 20, small_c_grammarParser::RuleForStop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    mathExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStepContext ------------------------------------------------------------------

small_c_grammarParser::ForStepContext::ForStepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::ForStepExprContext *> small_c_grammarParser::ForStepContext::forStepExpr() {
  return getRuleContexts<small_c_grammarParser::ForStepExprContext>();
}

small_c_grammarParser::ForStepExprContext* small_c_grammarParser::ForStepContext::forStepExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::ForStepExprContext>(i);
}


size_t small_c_grammarParser::ForStepContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStep;
}

void small_c_grammarParser::ForStepContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStep(this);
}

void small_c_grammarParser::ForStepContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStep(this);
}


std::any small_c_grammarParser::ForStepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStep(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStepContext* small_c_grammarParser::forStep() {
  ForStepContext *_localctx = _tracker.createInstance<ForStepContext>(_ctx, getState());
  enterRule(_localctx, 22, small_c_grammarParser::RuleForStep);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    forStepExpr();
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__10) {
      setState(149);
      match(small_c_grammarParser::T__10);
      setState(150);
      forStepExpr();
      setState(155);
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

//----------------- ForStepExprContext ------------------------------------------------------------------

small_c_grammarParser::ForStepExprContext::ForStepExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::VarNameContext* small_c_grammarParser::ForStepExprContext::varName() {
  return getRuleContext<small_c_grammarParser::VarNameContext>(0);
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::ForStepExprContext::mathExpr() {
  return getRuleContext<small_c_grammarParser::MathExprContext>(0);
}


size_t small_c_grammarParser::ForStepExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleForStepExpr;
}

void small_c_grammarParser::ForStepExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStepExpr(this);
}

void small_c_grammarParser::ForStepExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStepExpr(this);
}


std::any small_c_grammarParser::ForStepExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitForStepExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ForStepExprContext* small_c_grammarParser::forStepExpr() {
  ForStepExprContext *_localctx = _tracker.createInstance<ForStepExprContext>(_ctx, getState());
  enterRule(_localctx, 24, small_c_grammarParser::RuleForStepExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    varName();
    setState(157);
    match(small_c_grammarParser::T__11);
    setState(158);
    mathExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOpContext ------------------------------------------------------------------

small_c_grammarParser::AssignmentOpContext::AssignmentOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::VarNameContext* small_c_grammarParser::AssignmentOpContext::varName() {
  return getRuleContext<small_c_grammarParser::VarNameContext>(0);
}

small_c_grammarParser::DeclarationContext* small_c_grammarParser::AssignmentOpContext::declaration() {
  return getRuleContext<small_c_grammarParser::DeclarationContext>(0);
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::AssignmentOpContext::mathExpr() {
  return getRuleContext<small_c_grammarParser::MathExprContext>(0);
}


size_t small_c_grammarParser::AssignmentOpContext::getRuleIndex() const {
  return small_c_grammarParser::RuleAssignmentOp;
}

void small_c_grammarParser::AssignmentOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOp(this);
}

void small_c_grammarParser::AssignmentOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOp(this);
}


std::any small_c_grammarParser::AssignmentOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitAssignmentOp(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::AssignmentOpContext* small_c_grammarParser::assignmentOp() {
  AssignmentOpContext *_localctx = _tracker.createInstance<AssignmentOpContext>(_ctx, getState());
  enterRule(_localctx, 26, small_c_grammarParser::RuleAssignmentOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == small_c_grammarParser::T__0

    || _la == small_c_grammarParser::T__12) {
      setState(160);
      declaration();
    }
    setState(163);
    varName();
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == small_c_grammarParser::T__11) {
      setState(164);
      match(small_c_grammarParser::T__11);
      setState(165);
      mathExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

small_c_grammarParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t small_c_grammarParser::DeclarationContext::getRuleIndex() const {
  return small_c_grammarParser::RuleDeclaration;
}

void small_c_grammarParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void small_c_grammarParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any small_c_grammarParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::DeclarationContext* small_c_grammarParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 28, small_c_grammarParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    _la = _input->LA(1);
    if (!(_la == small_c_grammarParser::T__0

    || _la == small_c_grammarParser::T__12)) {
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

//----------------- VarNameContext ------------------------------------------------------------------

small_c_grammarParser::VarNameContext::VarNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* small_c_grammarParser::VarNameContext::ID() {
  return getToken(small_c_grammarParser::ID, 0);
}

small_c_grammarParser::ArrayDeclContext* small_c_grammarParser::VarNameContext::arrayDecl() {
  return getRuleContext<small_c_grammarParser::ArrayDeclContext>(0);
}


size_t small_c_grammarParser::VarNameContext::getRuleIndex() const {
  return small_c_grammarParser::RuleVarName;
}

void small_c_grammarParser::VarNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarName(this);
}

void small_c_grammarParser::VarNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarName(this);
}


std::any small_c_grammarParser::VarNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitVarName(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::VarNameContext* small_c_grammarParser::varName() {
  VarNameContext *_localctx = _tracker.createInstance<VarNameContext>(_ctx, getState());
  enterRule(_localctx, 30, small_c_grammarParser::RuleVarName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(small_c_grammarParser::ID);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == small_c_grammarParser::T__13) {
      setState(171);
      arrayDecl();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclContext ------------------------------------------------------------------

small_c_grammarParser::ArrayDeclContext::ArrayDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::MathExprContext *> small_c_grammarParser::ArrayDeclContext::mathExpr() {
  return getRuleContexts<small_c_grammarParser::MathExprContext>();
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::ArrayDeclContext::mathExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::MathExprContext>(i);
}


size_t small_c_grammarParser::ArrayDeclContext::getRuleIndex() const {
  return small_c_grammarParser::RuleArrayDecl;
}

void small_c_grammarParser::ArrayDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDecl(this);
}

void small_c_grammarParser::ArrayDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDecl(this);
}


std::any small_c_grammarParser::ArrayDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitArrayDecl(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::ArrayDeclContext* small_c_grammarParser::arrayDecl() {
  ArrayDeclContext *_localctx = _tracker.createInstance<ArrayDeclContext>(_ctx, getState());
  enterRule(_localctx, 32, small_c_grammarParser::RuleArrayDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(small_c_grammarParser::T__13);
    setState(175);
    mathExpr();
    setState(176);
    match(small_c_grammarParser::T__14);
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__13) {
      setState(177);
      match(small_c_grammarParser::T__13);
      setState(178);
      mathExpr();
      setState(179);
      match(small_c_grammarParser::T__14);
      setState(185);
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

//----------------- MathExprContext ------------------------------------------------------------------

small_c_grammarParser::MathExprContext::MathExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::LogicalOrExprContext* small_c_grammarParser::MathExprContext::logicalOrExpr() {
  return getRuleContext<small_c_grammarParser::LogicalOrExprContext>(0);
}


size_t small_c_grammarParser::MathExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleMathExpr;
}

void small_c_grammarParser::MathExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMathExpr(this);
}

void small_c_grammarParser::MathExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMathExpr(this);
}


std::any small_c_grammarParser::MathExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitMathExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::mathExpr() {
  MathExprContext *_localctx = _tracker.createInstance<MathExprContext>(_ctx, getState());
  enterRule(_localctx, 34, small_c_grammarParser::RuleMathExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    logicalOrExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrExprContext ------------------------------------------------------------------

small_c_grammarParser::LogicalOrExprContext::LogicalOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::LogicalAndExprContext *> small_c_grammarParser::LogicalOrExprContext::logicalAndExpr() {
  return getRuleContexts<small_c_grammarParser::LogicalAndExprContext>();
}

small_c_grammarParser::LogicalAndExprContext* small_c_grammarParser::LogicalOrExprContext::logicalAndExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::LogicalAndExprContext>(i);
}


size_t small_c_grammarParser::LogicalOrExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleLogicalOrExpr;
}

void small_c_grammarParser::LogicalOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpr(this);
}

void small_c_grammarParser::LogicalOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpr(this);
}


std::any small_c_grammarParser::LogicalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::LogicalOrExprContext* small_c_grammarParser::logicalOrExpr() {
  LogicalOrExprContext *_localctx = _tracker.createInstance<LogicalOrExprContext>(_ctx, getState());
  enterRule(_localctx, 36, small_c_grammarParser::RuleLogicalOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    logicalAndExpr();
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__15) {
      setState(189);
      match(small_c_grammarParser::T__15);
      setState(190);
      logicalAndExpr();
      setState(195);
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

//----------------- LogicalAndExprContext ------------------------------------------------------------------

small_c_grammarParser::LogicalAndExprContext::LogicalAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::EqualityExprContext *> small_c_grammarParser::LogicalAndExprContext::equalityExpr() {
  return getRuleContexts<small_c_grammarParser::EqualityExprContext>();
}

small_c_grammarParser::EqualityExprContext* small_c_grammarParser::LogicalAndExprContext::equalityExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::EqualityExprContext>(i);
}


size_t small_c_grammarParser::LogicalAndExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleLogicalAndExpr;
}

void small_c_grammarParser::LogicalAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpr(this);
}

void small_c_grammarParser::LogicalAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpr(this);
}


std::any small_c_grammarParser::LogicalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::LogicalAndExprContext* small_c_grammarParser::logicalAndExpr() {
  LogicalAndExprContext *_localctx = _tracker.createInstance<LogicalAndExprContext>(_ctx, getState());
  enterRule(_localctx, 38, small_c_grammarParser::RuleLogicalAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    equalityExpr();
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__16) {
      setState(197);
      match(small_c_grammarParser::T__16);
      setState(198);
      equalityExpr();
      setState(203);
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

//----------------- EqualityExprContext ------------------------------------------------------------------

small_c_grammarParser::EqualityExprContext::EqualityExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::RelationalExprContext *> small_c_grammarParser::EqualityExprContext::relationalExpr() {
  return getRuleContexts<small_c_grammarParser::RelationalExprContext>();
}

small_c_grammarParser::RelationalExprContext* small_c_grammarParser::EqualityExprContext::relationalExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::RelationalExprContext>(i);
}


size_t small_c_grammarParser::EqualityExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleEqualityExpr;
}

void small_c_grammarParser::EqualityExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpr(this);
}

void small_c_grammarParser::EqualityExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpr(this);
}


std::any small_c_grammarParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::EqualityExprContext* small_c_grammarParser::equalityExpr() {
  EqualityExprContext *_localctx = _tracker.createInstance<EqualityExprContext>(_ctx, getState());
  enterRule(_localctx, 40, small_c_grammarParser::RuleEqualityExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    relationalExpr();
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__17

    || _la == small_c_grammarParser::T__18) {
      setState(205);
      _la = _input->LA(1);
      if (!(_la == small_c_grammarParser::T__17

      || _la == small_c_grammarParser::T__18)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(206);
      relationalExpr();
      setState(211);
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

//----------------- RelationalExprContext ------------------------------------------------------------------

small_c_grammarParser::RelationalExprContext::RelationalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::AdditiveExprContext *> small_c_grammarParser::RelationalExprContext::additiveExpr() {
  return getRuleContexts<small_c_grammarParser::AdditiveExprContext>();
}

small_c_grammarParser::AdditiveExprContext* small_c_grammarParser::RelationalExprContext::additiveExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::AdditiveExprContext>(i);
}


size_t small_c_grammarParser::RelationalExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleRelationalExpr;
}

void small_c_grammarParser::RelationalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpr(this);
}

void small_c_grammarParser::RelationalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpr(this);
}


std::any small_c_grammarParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::RelationalExprContext* small_c_grammarParser::relationalExpr() {
  RelationalExprContext *_localctx = _tracker.createInstance<RelationalExprContext>(_ctx, getState());
  enterRule(_localctx, 42, small_c_grammarParser::RuleRelationalExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    additiveExpr();
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15728640) != 0)) {
      setState(213);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 15728640) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(214);
      additiveExpr();
      setState(219);
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

//----------------- AdditiveExprContext ------------------------------------------------------------------

small_c_grammarParser::AdditiveExprContext::AdditiveExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::MultiplicativeExprContext *> small_c_grammarParser::AdditiveExprContext::multiplicativeExpr() {
  return getRuleContexts<small_c_grammarParser::MultiplicativeExprContext>();
}

small_c_grammarParser::MultiplicativeExprContext* small_c_grammarParser::AdditiveExprContext::multiplicativeExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::MultiplicativeExprContext>(i);
}


size_t small_c_grammarParser::AdditiveExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleAdditiveExpr;
}

void small_c_grammarParser::AdditiveExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpr(this);
}

void small_c_grammarParser::AdditiveExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpr(this);
}


std::any small_c_grammarParser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::AdditiveExprContext* small_c_grammarParser::additiveExpr() {
  AdditiveExprContext *_localctx = _tracker.createInstance<AdditiveExprContext>(_ctx, getState());
  enterRule(_localctx, 44, small_c_grammarParser::RuleAdditiveExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    multiplicativeExpr();
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__23

    || _la == small_c_grammarParser::T__24) {
      setState(221);
      _la = _input->LA(1);
      if (!(_la == small_c_grammarParser::T__23

      || _la == small_c_grammarParser::T__24)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(222);
      multiplicativeExpr();
      setState(227);
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

//----------------- MultiplicativeExprContext ------------------------------------------------------------------

small_c_grammarParser::MultiplicativeExprContext::MultiplicativeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<small_c_grammarParser::UnaryExprContext *> small_c_grammarParser::MultiplicativeExprContext::unaryExpr() {
  return getRuleContexts<small_c_grammarParser::UnaryExprContext>();
}

small_c_grammarParser::UnaryExprContext* small_c_grammarParser::MultiplicativeExprContext::unaryExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::UnaryExprContext>(i);
}


size_t small_c_grammarParser::MultiplicativeExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleMultiplicativeExpr;
}

void small_c_grammarParser::MultiplicativeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpr(this);
}

void small_c_grammarParser::MultiplicativeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpr(this);
}


std::any small_c_grammarParser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::MultiplicativeExprContext* small_c_grammarParser::multiplicativeExpr() {
  MultiplicativeExprContext *_localctx = _tracker.createInstance<MultiplicativeExprContext>(_ctx, getState());
  enterRule(_localctx, 46, small_c_grammarParser::RuleMultiplicativeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    unaryExpr();
    setState(233);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 469762048) != 0)) {
      setState(229);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 469762048) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(230);
      unaryExpr();
      setState(235);
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

//----------------- UnaryExprContext ------------------------------------------------------------------

small_c_grammarParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::UnaryExprContext* small_c_grammarParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<small_c_grammarParser::UnaryExprContext>(0);
}

small_c_grammarParser::PrimaryExprContext* small_c_grammarParser::UnaryExprContext::primaryExpr() {
  return getRuleContext<small_c_grammarParser::PrimaryExprContext>(0);
}


size_t small_c_grammarParser::UnaryExprContext::getRuleIndex() const {
  return small_c_grammarParser::RuleUnaryExpr;
}

void small_c_grammarParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}

void small_c_grammarParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}


std::any small_c_grammarParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::UnaryExprContext* small_c_grammarParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 48, small_c_grammarParser::RuleUnaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case small_c_grammarParser::T__23:
      case small_c_grammarParser::T__24:
      case small_c_grammarParser::T__28: {
        enterOuterAlt(_localctx, 1);
        setState(236);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 587202560) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(237);
        unaryExpr();
        break;
      }

      case small_c_grammarParser::T__2:
      case small_c_grammarParser::ID:
      case small_c_grammarParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(238);
        primaryExpr();
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

//----------------- PrimaryExprContext ------------------------------------------------------------------

small_c_grammarParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::FuncCallContext* small_c_grammarParser::PrimaryExprContext::funcCall() {
  return getRuleContext<small_c_grammarParser::FuncCallContext>(0);
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::PrimaryExprContext::mathExpr() {
  return getRuleContext<small_c_grammarParser::MathExprContext>(0);
}

small_c_grammarParser::VarNameContext* small_c_grammarParser::PrimaryExprContext::varName() {
  return getRuleContext<small_c_grammarParser::VarNameContext>(0);
}

tree::TerminalNode* small_c_grammarParser::PrimaryExprContext::NUMBER() {
  return getToken(small_c_grammarParser::NUMBER, 0);
}


size_t small_c_grammarParser::PrimaryExprContext::getRuleIndex() const {
  return small_c_grammarParser::RulePrimaryExpr;
}

void small_c_grammarParser::PrimaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpr(this);
}

void small_c_grammarParser::PrimaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpr(this);
}


std::any small_c_grammarParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::PrimaryExprContext* small_c_grammarParser::primaryExpr() {
  PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, getState());
  enterRule(_localctx, 50, small_c_grammarParser::RulePrimaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      funcCall();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(242);
      match(small_c_grammarParser::T__2);
      setState(243);
      mathExpr();
      setState(244);
      match(small_c_grammarParser::T__3);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(246);
      varName();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(247);
      match(small_c_grammarParser::NUMBER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

small_c_grammarParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

small_c_grammarParser::FuncNameContext* small_c_grammarParser::FuncCallContext::funcName() {
  return getRuleContext<small_c_grammarParser::FuncNameContext>(0);
}

std::vector<small_c_grammarParser::MathExprContext *> small_c_grammarParser::FuncCallContext::mathExpr() {
  return getRuleContexts<small_c_grammarParser::MathExprContext>();
}

small_c_grammarParser::MathExprContext* small_c_grammarParser::FuncCallContext::mathExpr(size_t i) {
  return getRuleContext<small_c_grammarParser::MathExprContext>(i);
}


size_t small_c_grammarParser::FuncCallContext::getRuleIndex() const {
  return small_c_grammarParser::RuleFuncCall;
}

void small_c_grammarParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void small_c_grammarParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}


std::any small_c_grammarParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::FuncCallContext* small_c_grammarParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 52, small_c_grammarParser::RuleFuncCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    funcName();
    setState(251);
    match(small_c_grammarParser::T__2);
    setState(260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7029653512) != 0)) {
      setState(252);
      mathExpr();
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == small_c_grammarParser::T__10) {
        setState(253);
        match(small_c_grammarParser::T__10);
        setState(254);
        mathExpr();
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(262);
    match(small_c_grammarParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncNameContext ------------------------------------------------------------------

small_c_grammarParser::FuncNameContext::FuncNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> small_c_grammarParser::FuncNameContext::ID() {
  return getTokens(small_c_grammarParser::ID);
}

tree::TerminalNode* small_c_grammarParser::FuncNameContext::ID(size_t i) {
  return getToken(small_c_grammarParser::ID, i);
}


size_t small_c_grammarParser::FuncNameContext::getRuleIndex() const {
  return small_c_grammarParser::RuleFuncName;
}

void small_c_grammarParser::FuncNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncName(this);
}

void small_c_grammarParser::FuncNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<small_c_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncName(this);
}


std::any small_c_grammarParser::FuncNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<small_c_grammarVisitor*>(visitor))
    return parserVisitor->visitFuncName(this);
  else
    return visitor->visitChildren(this);
}

small_c_grammarParser::FuncNameContext* small_c_grammarParser::funcName() {
  FuncNameContext *_localctx = _tracker.createInstance<FuncNameContext>(_ctx, getState());
  enterRule(_localctx, 54, small_c_grammarParser::RuleFuncName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(small_c_grammarParser::ID);
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == small_c_grammarParser::T__29) {
      setState(265);
      match(small_c_grammarParser::T__29);
      setState(266);
      match(small_c_grammarParser::ID);
      setState(271);
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

void small_c_grammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  small_c_grammarParserInitialize();
#else
  ::antlr4::internal::call_once(small_c_grammarParserOnceFlag, small_c_grammarParserInitialize);
#endif
}
