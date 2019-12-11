
// AST definitions
#ifndef __ast_h__
#define __ast_h__


// AST for expressions
struct _Expr {
  enum { 
    E_INTEGER,
    E_OPERATION
  } kind;
  union {
    int value; // for integer values
    struct { 
      int operator; // PLUS, MINUS, etc 
      struct _Expr* left;
      struct _Expr* right;
    } op; // for binary expressions
  } attr;
};



struct _BoolExpr {
  enum {
    E_BOOL,
    E_BOOLOP
  }kind;
  union{
    int value; // for boolean values
    struct {
      int operator;
      struct _Expr* left;
      struct _Expr* right;
    }op;
  }attr;
};

//SEPARAR AS ESTRUTURAS DOS CMDS

struct _CommandList {
      struct _Cmd* cmd;
      struct _CommandList* next;
};

struct _Cmd {
  enum {
    LET,
    IF,
    IFELSE,
    WHILE,
    PRINT,
    PRINTT,
    READ,
  }kind;
  union{
    struct {
      char* var;
      struct _Expr* value;
    }let;
    struct{
      struct _BoolExpr* cond;
      struct _Cmd* cmd;
      struct _CommandList* list;
    }ifType;
    struct{
      struct _BoolExpr* cond;
      struct   _Cmd* cmd;
      struct _Cmd* cmdelse;
      struct _CommandList* flist;
      struct _CommandList* slist;
    }elseType;
    struct{
      struct _BoolExpr* cond;
      struct _Cmd* cmd;
      struct _CommandList* list;
    }whileType;
      struct {
        char* string;
      }printType;
      struct{
        char* string;
        char* var;
      }printVType;
      struct{
        char* var;
      }readType;
  }attr;
};




typedef struct _CommandList CommandList;
typedef struct _Cmd Cmd;
typedef struct _BoolExpr BoolExpr;
typedef struct _Expr Expr; // Convenience typedef


// Constructor functions (see implementation in ast.c)


//COMMAND LIST

CommandList* ast_commandList(Cmd* cmd, CommandList* next);
Cmd* variable_declaration(char* v,Expr* value);
Cmd* if_declaration(BoolExpr* cond, Cmd* next,CommandList* list);
Cmd* else_declaration(BoolExpr* cond, Cmd* ifL, CommandList* flist,Cmd* elseL, CommandList* slist);
Cmd* print_declaration(char* print);
Cmd* print_variable(char* string, char* var);
Cmd* read_line(char* var);
Cmd* while_declaration(BoolExpr* cond, Cmd* cmd,CommandList* list);

BoolExpr* ast_boolean(int v);
BoolExpr* ast_boolOp(int operator, Expr* left, Expr* right);
Expr* ast_integer(int v);
Expr* ast_operation(int operator, Expr* left, Expr* right);

#endif
