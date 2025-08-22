
// Generated from small_c_grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "small_c_grammarListener.h"


/**
 * This class provides an empty implementation of small_c_grammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  small_c_grammarBaseListener : public small_c_grammarListener {
public:

  virtual void enterProgram(small_c_grammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(small_c_grammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunction(small_c_grammarParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(small_c_grammarParser::FunctionContext * /*ctx*/) override { }

  virtual void enterStatement(small_c_grammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(small_c_grammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterBlock(small_c_grammarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(small_c_grammarParser::BlockContext * /*ctx*/) override { }

  virtual void enterIfStatement(small_c_grammarParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(small_c_grammarParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterElifChain(small_c_grammarParser::ElifChainContext * /*ctx*/) override { }
  virtual void exitElifChain(small_c_grammarParser::ElifChainContext * /*ctx*/) override { }

  virtual void enterElseBranch(small_c_grammarParser::ElseBranchContext * /*ctx*/) override { }
  virtual void exitElseBranch(small_c_grammarParser::ElseBranchContext * /*ctx*/) override { }

  virtual void enterForStatement(small_c_grammarParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(small_c_grammarParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForStart(small_c_grammarParser::ForStartContext * /*ctx*/) override { }
  virtual void exitForStart(small_c_grammarParser::ForStartContext * /*ctx*/) override { }

  virtual void enterForStartExpr(small_c_grammarParser::ForStartExprContext * /*ctx*/) override { }
  virtual void exitForStartExpr(small_c_grammarParser::ForStartExprContext * /*ctx*/) override { }

  virtual void enterForStop(small_c_grammarParser::ForStopContext * /*ctx*/) override { }
  virtual void exitForStop(small_c_grammarParser::ForStopContext * /*ctx*/) override { }

  virtual void enterForStep(small_c_grammarParser::ForStepContext * /*ctx*/) override { }
  virtual void exitForStep(small_c_grammarParser::ForStepContext * /*ctx*/) override { }

  virtual void enterForStepExpr(small_c_grammarParser::ForStepExprContext * /*ctx*/) override { }
  virtual void exitForStepExpr(small_c_grammarParser::ForStepExprContext * /*ctx*/) override { }

  virtual void enterAssignmentOp(small_c_grammarParser::AssignmentOpContext * /*ctx*/) override { }
  virtual void exitAssignmentOp(small_c_grammarParser::AssignmentOpContext * /*ctx*/) override { }

  virtual void enterDeclaration(small_c_grammarParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(small_c_grammarParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVarName(small_c_grammarParser::VarNameContext * /*ctx*/) override { }
  virtual void exitVarName(small_c_grammarParser::VarNameContext * /*ctx*/) override { }

  virtual void enterArrayDecl(small_c_grammarParser::ArrayDeclContext * /*ctx*/) override { }
  virtual void exitArrayDecl(small_c_grammarParser::ArrayDeclContext * /*ctx*/) override { }

  virtual void enterMathExpr(small_c_grammarParser::MathExprContext * /*ctx*/) override { }
  virtual void exitMathExpr(small_c_grammarParser::MathExprContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext * /*ctx*/) override { }

  virtual void enterEqualityExpr(small_c_grammarParser::EqualityExprContext * /*ctx*/) override { }
  virtual void exitEqualityExpr(small_c_grammarParser::EqualityExprContext * /*ctx*/) override { }

  virtual void enterRelationalExpr(small_c_grammarParser::RelationalExprContext * /*ctx*/) override { }
  virtual void exitRelationalExpr(small_c_grammarParser::RelationalExprContext * /*ctx*/) override { }

  virtual void enterAdditiveExpr(small_c_grammarParser::AdditiveExprContext * /*ctx*/) override { }
  virtual void exitAdditiveExpr(small_c_grammarParser::AdditiveExprContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(small_c_grammarParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(small_c_grammarParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterPrimaryExpr(small_c_grammarParser::PrimaryExprContext * /*ctx*/) override { }
  virtual void exitPrimaryExpr(small_c_grammarParser::PrimaryExprContext * /*ctx*/) override { }

  virtual void enterFuncCall(small_c_grammarParser::FuncCallContext * /*ctx*/) override { }
  virtual void exitFuncCall(small_c_grammarParser::FuncCallContext * /*ctx*/) override { }

  virtual void enterFuncName(small_c_grammarParser::FuncNameContext * /*ctx*/) override { }
  virtual void exitFuncName(small_c_grammarParser::FuncNameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

