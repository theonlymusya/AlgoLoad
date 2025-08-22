
// Generated from small_c_grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "small_c_grammarVisitor.h"


/**
 * This class provides an empty implementation of small_c_grammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  small_c_grammarBaseVisitor : public small_c_grammarVisitor {
public:

  virtual std::any visitProgram(small_c_grammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(small_c_grammarParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(small_c_grammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(small_c_grammarParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(small_c_grammarParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElifChain(small_c_grammarParser::ElifChainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseBranch(small_c_grammarParser::ElseBranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(small_c_grammarParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStart(small_c_grammarParser::ForStartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStartExpr(small_c_grammarParser::ForStartExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStop(small_c_grammarParser::ForStopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStep(small_c_grammarParser::ForStepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStepExpr(small_c_grammarParser::ForStepExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOp(small_c_grammarParser::AssignmentOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(small_c_grammarParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarName(small_c_grammarParser::VarNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDecl(small_c_grammarParser::ArrayDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMathExpr(small_c_grammarParser::MathExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(small_c_grammarParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpr(small_c_grammarParser::RelationalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpr(small_c_grammarParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(small_c_grammarParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(small_c_grammarParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncCall(small_c_grammarParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncName(small_c_grammarParser::FuncNameContext *ctx) override {
    return visitChildren(ctx);
  }


};

