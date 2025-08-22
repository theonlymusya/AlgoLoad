
// Generated from small_c_grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "small_c_grammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by small_c_grammarParser.
 */
class  small_c_grammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(small_c_grammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(small_c_grammarParser::ProgramContext *ctx) = 0;

  virtual void enterFunction(small_c_grammarParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(small_c_grammarParser::FunctionContext *ctx) = 0;

  virtual void enterStatement(small_c_grammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(small_c_grammarParser::StatementContext *ctx) = 0;

  virtual void enterBlock(small_c_grammarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(small_c_grammarParser::BlockContext *ctx) = 0;

  virtual void enterIfStatement(small_c_grammarParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(small_c_grammarParser::IfStatementContext *ctx) = 0;

  virtual void enterElifChain(small_c_grammarParser::ElifChainContext *ctx) = 0;
  virtual void exitElifChain(small_c_grammarParser::ElifChainContext *ctx) = 0;

  virtual void enterElseBranch(small_c_grammarParser::ElseBranchContext *ctx) = 0;
  virtual void exitElseBranch(small_c_grammarParser::ElseBranchContext *ctx) = 0;

  virtual void enterForStatement(small_c_grammarParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(small_c_grammarParser::ForStatementContext *ctx) = 0;

  virtual void enterForStart(small_c_grammarParser::ForStartContext *ctx) = 0;
  virtual void exitForStart(small_c_grammarParser::ForStartContext *ctx) = 0;

  virtual void enterForStartExpr(small_c_grammarParser::ForStartExprContext *ctx) = 0;
  virtual void exitForStartExpr(small_c_grammarParser::ForStartExprContext *ctx) = 0;

  virtual void enterForStop(small_c_grammarParser::ForStopContext *ctx) = 0;
  virtual void exitForStop(small_c_grammarParser::ForStopContext *ctx) = 0;

  virtual void enterForStep(small_c_grammarParser::ForStepContext *ctx) = 0;
  virtual void exitForStep(small_c_grammarParser::ForStepContext *ctx) = 0;

  virtual void enterForStepExpr(small_c_grammarParser::ForStepExprContext *ctx) = 0;
  virtual void exitForStepExpr(small_c_grammarParser::ForStepExprContext *ctx) = 0;

  virtual void enterAssignmentOp(small_c_grammarParser::AssignmentOpContext *ctx) = 0;
  virtual void exitAssignmentOp(small_c_grammarParser::AssignmentOpContext *ctx) = 0;

  virtual void enterDeclaration(small_c_grammarParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(small_c_grammarParser::DeclarationContext *ctx) = 0;

  virtual void enterVarName(small_c_grammarParser::VarNameContext *ctx) = 0;
  virtual void exitVarName(small_c_grammarParser::VarNameContext *ctx) = 0;

  virtual void enterArrayDecl(small_c_grammarParser::ArrayDeclContext *ctx) = 0;
  virtual void exitArrayDecl(small_c_grammarParser::ArrayDeclContext *ctx) = 0;

  virtual void enterMathExpr(small_c_grammarParser::MathExprContext *ctx) = 0;
  virtual void exitMathExpr(small_c_grammarParser::MathExprContext *ctx) = 0;

  virtual void enterLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext *ctx) = 0;
  virtual void exitLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext *ctx) = 0;

  virtual void enterLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext *ctx) = 0;
  virtual void exitLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext *ctx) = 0;

  virtual void enterEqualityExpr(small_c_grammarParser::EqualityExprContext *ctx) = 0;
  virtual void exitEqualityExpr(small_c_grammarParser::EqualityExprContext *ctx) = 0;

  virtual void enterRelationalExpr(small_c_grammarParser::RelationalExprContext *ctx) = 0;
  virtual void exitRelationalExpr(small_c_grammarParser::RelationalExprContext *ctx) = 0;

  virtual void enterAdditiveExpr(small_c_grammarParser::AdditiveExprContext *ctx) = 0;
  virtual void exitAdditiveExpr(small_c_grammarParser::AdditiveExprContext *ctx) = 0;

  virtual void enterMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext *ctx) = 0;
  virtual void exitMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext *ctx) = 0;

  virtual void enterUnaryExpr(small_c_grammarParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(small_c_grammarParser::UnaryExprContext *ctx) = 0;

  virtual void enterPrimaryExpr(small_c_grammarParser::PrimaryExprContext *ctx) = 0;
  virtual void exitPrimaryExpr(small_c_grammarParser::PrimaryExprContext *ctx) = 0;

  virtual void enterFuncCall(small_c_grammarParser::FuncCallContext *ctx) = 0;
  virtual void exitFuncCall(small_c_grammarParser::FuncCallContext *ctx) = 0;

  virtual void enterFuncName(small_c_grammarParser::FuncNameContext *ctx) = 0;
  virtual void exitFuncName(small_c_grammarParser::FuncNameContext *ctx) = 0;


};

