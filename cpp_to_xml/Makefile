EXECUTABLE = parser

CXX = g++
CXXFLAGS = -std=c++17

# пути к ANTLR runtime
INCLUDES = -Iexternal/antlr4-runtime -Iexternal/antlr4-runtime/src

# файлы проекта
SRC = main.cpp \
      small_c_grammarLexer.cpp \
      small_c_grammarParser.cpp \
      small_c_grammarVisitor.cpp \
      small_c_grammarBaseVisitor.cpp \
	CPreprocess.cpp \
      ASTBuilder.cpp \
      InstrPrinter.cpp \
      ASTContext.cpp \
      CalcExpr.cpp \
      external/tinyExpr/tinyexpr.cpp \
      Tables.cpp \
      AlgoGenerator.cpp\
      AlgoInfoPrinter.cpp

RUNTIME_SRC := $(shell find external/antlr4-runtime/src -name '*.cpp')

ALL_SRC = $(SRC) $(RUNTIME_SRC)

OBJ = $(ALL_SRC:.cpp=.o)

# сборка проекта
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
