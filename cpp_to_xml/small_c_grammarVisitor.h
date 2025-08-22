
// Generated from small_c_grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "small_c_grammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by small_c_grammarParser.
 */
class  small_c_grammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by small_c_grammarParser.
   */
    virtual std::any visitProgram(small_c_grammarParser::ProgramContext *context) = 0;

    virtual std::any visitFunction(small_c_grammarParser::FunctionContext *context) = 0;

    virtual std::any visitStatement(small_c_grammarParser::StatementContext *context) = 0;

    virtual std::any visitBlock(small_c_grammarParser::BlockContext *context) = 0;

    virtual std::any visitIfStatement(small_c_grammarParser::IfStatementContext *context) = 0;

    virtual std::any visitElifChain(small_c_grammarParser::ElifChainContext *context) = 0;

    virtual std::any visitElseBranch(small_c_grammarParser::ElseBranchContext *context) = 0;

    virtual std::any visitForStatement(small_c_grammarParser::ForStatementContext *context) = 0;

    virtual std::any visitForStart(small_c_grammarParser::ForStartContext *context) = 0;

    virtual std::any visitForStartExpr(small_c_grammarParser::ForStartExprContext *context) = 0;

    virtual std::any visitForStop(small_c_grammarParser::ForStopContext *context) = 0;

    virtual std::any visitForStep(small_c_grammarParser::ForStepContext *context) = 0;

    virtual std::any visitForStepExpr(small_c_grammarParser::ForStepExprContext *context) = 0;

    virtual std::any visitAssignmentOp(small_c_grammarParser::AssignmentOpContext *context) = 0;

    virtual std::any visitDeclaration(small_c_grammarParser::DeclarationContext *context) = 0;

    virtual std::any visitVarName(small_c_grammarParser::VarNameContext *context) = 0;

    virtual std::any visitArrayDecl(small_c_grammarParser::ArrayDeclContext *context) = 0;

    virtual std::any visitMathExpr(small_c_grammarParser::MathExprContext *context) = 0;

    virtual std::any visitLogicalOrExpr(small_c_grammarParser::LogicalOrExprContext *context) = 0;

    virtual std::any visitLogicalAndExpr(small_c_grammarParser::LogicalAndExprContext *context) = 0;

    virtual std::any visitEqualityExpr(small_c_grammarParser::EqualityExprContext *context) = 0;

    virtual std::any visitRelationalExpr(small_c_grammarParser::RelationalExprContext *context) = 0;

    virtual std::any visitAdditiveExpr(small_c_grammarParser::AdditiveExprContext *context) = 0;

    virtual std::any visitMultiplicativeExpr(small_c_grammarParser::MultiplicativeExprContext *context) = 0;

    virtual std::any visitUnaryExpr(small_c_grammarParser::UnaryExprContext *context) = 0;

    virtual std::any visitPrimaryExpr(small_c_grammarParser::PrimaryExprContext *context) = 0;

    virtual std::any visitFuncCall(small_c_grammarParser::FuncCallContext *context) = 0;

    virtual std::any visitFuncName(small_c_grammarParser::FuncNameContext *context) = 0;


};

