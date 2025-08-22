grammar small_c_grammar;

program 
    : (function | statement)* EOF
    ;

function 
    : 'int' 'main' '(' ')' '{' statement* '}'
    ;

statement
    : ifStatement
    | forStatement
    | assignmentOp ';'
    | block
    ;

block 
    : '{' statement* '}'
    ;

ifStatement
    : 'if' '(' cond = mathExpr ')' statement elifChain? elseBranch?
    ;

elifChain
    : ('else' 'if' '(' elifCond += mathExpr ')' statement)+
    ;

elseBranch
    : 'else' statement
    ;

forStatement 
    : 'for' '(' forStart? ';' forStop? ';' forStep? ')' statement
    ;

forStart 
    : forStartExpr (',' forStartExpr)*
    ;

forStartExpr
    : assignmentOp
    ;

forStop 
    : mathExpr
    ;

forStep
    : forStepExpr (',' forStepExpr)*
    ;

forStepExpr
    : varName '=' mathExpr
    ;

assignmentOp
    : declaration? varName ('=' mathExpr)?
    ;

declaration
    : ('int' | 'double')
    ;

varName
    : ID arrayDecl?
    ;

arrayDecl 
    : '[' mathExpr ']' ('[' mathExpr ']' )*
    ;

mathExpr
    : logicalOrExpr
    ;

logicalOrExpr
    : logicalAndExpr ( '||' logicalAndExpr )*
    ;

logicalAndExpr
    : equalityExpr ( '&&' equalityExpr )*
    ;

equalityExpr
    : relationalExpr ( ( '==' | '!=' ) relationalExpr )*
    ;

relationalExpr
    : additiveExpr ( ( '<' | '>' | '<=' | '>=' ) additiveExpr )*
    ;

additiveExpr
    : multiplicativeExpr ( ( '+' | '-' ) multiplicativeExpr )*
    ;

multiplicativeExpr
    : unaryExpr ( ( '*' | '/' | '%' ) unaryExpr )*
    ;

unaryExpr
    : ( '!' | '+' | '-' ) unaryExpr
    | primaryExpr
    ;

primaryExpr
    : funcCall
    | '(' mathExpr ')'
    | varName
    | NUMBER
    ;

funcCall
    : funcName '(' ( mathExpr (',' mathExpr)* )? ')'
    ;

funcName
    : ID ( '::' ID )*
    ;

ID : [a-zA-Z_][a-zA-Z0-9_]* ;
NUMBER : [0-9]+ ('.' [0-9]+)? ;
WS : [ \t\r\n]+ -> skip ;
