// Tokens
%token 
  INT  
  PLUS
  MINUS
  TIMES
  DIV
  MOD
  EQ
  DIF
  LT
  GT
  LTE
  GTE
  T
  F
  CHAVETA1
  CHAVETA2
  EOL
  TOKEN_EQ
  VAR
  TOKEN_ATRIB
  TOKEN_IF
  TOKEN_ELSE
  TOKEN_WHILE
  OPENP
  CLOSEP
  PRINTL
  MAIN
  STRING
  ASPAS
  PRINTV
  VIRGULA
  READLINE
  COMM


// Operator associativity & precedence
%left F T
%left GT LT GTE LTE EQ DIF
%left PLUS MINUS
%left TIMES DIV
%left MOD

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
  int intValue;
  Expr* exprValue;
  char* typesValue;
  BoolExpr* BoolValue;
  char* charValue;
  Cmd* cmdValue;
  char* string;
  CommandList* list;
}
%type <string> STRING
%type <intValue> INT
%type <exprValue> expr
%type <cmdValue> cmd
%type <BoolValue> bool_expr
%type <list> cmdlist
%type <charValue> VAR

// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
CommandList* root;
}

%%

program: MAIN cmdlist CHAVETA2 {root = $2;}


cmdlist:
  cmd cmdlist {
     $$ = ast_commandList($1,$2);
  }
  | 
  cmd {
    $$ = ast_commandList($1,NULL);
  }
  |
  {
   $$ = ast_commandList(NULL, NULL);
  }
  ;
      
expr: 
  INT { 
    $$ = ast_integer($1); 
  } 
  | 
  expr PLUS expr { 
    $$ = ast_operation(PLUS, $1, $3); 
  } 
  |
  expr MINUS expr {
    $$ = ast_operation(MINUS, $1, $3);
  }
  |
  expr DIV expr {
    $$ = ast_operation(DIV, $1, $3);
  }
  |
  expr TIMES expr {
    $$ = ast_operation(TIMES, $1, $3);
  }
  ;


bool_expr:
  F {
    $$ = ast_boolean(0);
  }
  |T {
    $$ = ast_boolean(1);
  }
  |expr EQ expr {
    $$ = ast_boolOp(EQ, $1, $3);
  }
  |expr DIF expr {
    $$ = ast_boolOp(DIF, $1, $3);
  }
  |expr LT expr {
    $$ = ast_boolOp(LT, $1, $3);
  }
  |expr GT expr {
    $$ = ast_boolOp(GT, $1, $3);
  }
  |expr LTE expr {
    $$ = ast_boolOp(LTE, $1, $3);
  }
  |expr GTE expr {
   $$ = ast_boolOp(GTE, $1, $3);
  }
  ;



cmd:
  TOKEN_IF bool_expr CHAVETA1 cmd cmdlist CHAVETA2 {
    $$ = if_declaration($2, $4, $5);
  }
  |
  TOKEN_IF bool_expr CHAVETA1 cmd CHAVETA2{
    $$ = if_declaration($2, $4, NULL);
  }
  |
  TOKEN_IF bool_expr CHAVETA1 cmd cmdlist CHAVETA2 TOKEN_ELSE CHAVETA1 cmd cmdlist CHAVETA2 {
    $$ = else_declaration($2,$4,$5,$9,$10);
  }
  |
  TOKEN_IF bool_expr CHAVETA1 cmd CHAVETA2 TOKEN_ELSE CHAVETA1 cmd CHAVETA2 {
    $$ = else_declaration($2,$4,NULL,$8,NULL);
  }
  |
  TOKEN_IF bool_expr CHAVETA1 cmd cmdlist CHAVETA2 TOKEN_ELSE CHAVETA1 cmd CHAVETA2 {
    $$ = else_declaration($2,$4,$5,$9,NULL);
  }
  |
  TOKEN_IF bool_expr CHAVETA1 cmd CHAVETA2 TOKEN_ELSE CHAVETA1 cmd cmdlist CHAVETA2 {
    $$ = else_declaration($2,$4,NULL,$8,$9);
  }
  |
  TOKEN_WHILE bool_expr CHAVETA1 cmd cmdlist CHAVETA2 {
    $$ = while_declaration($2,$4,$5);
  }
  |
  TOKEN_WHILE bool_expr CHAVETA1 cmd CHAVETA2 {
    $$ = while_declaration($2,$4,NULL);
  }
  |
  TOKEN_ATRIB VAR TOKEN_EQ expr EOL{
    $$ = variable_declaration($2,$4);
  }
  |
  PRINTL OPENP STRING CLOSEP EOL{
    $$ = print_declaration($3);
  }
  |
  PRINTL OPENP STRING VIRGULA VAR CLOSEP EOL{
    $$ = print_variable($3,$5);
  } 
  |
  READLINE OPENP COMM VAR CLOSEP EOL{
    $$ = read_line($4);
  }
  ;




%%

void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}

