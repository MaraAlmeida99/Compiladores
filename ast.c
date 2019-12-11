// AST constructor functions

#include <stdlib.h> // for malloc
#include "ast.h" // AST header



BoolExpr* ast_boolean(int v){
  BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
  node-> kind = E_BOOL;
  node-> attr.value = v;
  return node;
}

BoolExpr* ast_boolOp(int operator, Expr* left, Expr* right){
  BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
  node-> kind = E_BOOLOP;
  node-> attr.op.operator = operator;
  node-> attr.op.left = left;
  node-> attr.op.right = right;
  return node;
}

Cmd* print_declaration(char* print){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind = PRINT;
  node->attr.printType.string = print;
  return node;
}
Cmd* print_variable(char* string, char* var){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node-> kind = PRINTT;
  node -> attr.printVType.string = string;
  node -> attr.printVType.var = var;
  return node;
}

Cmd* read_line(char* var){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node-> kind = READ;
  node-> attr.readType.var = var;
  return node;
}

CommandList* ast_commandList(Cmd* cmd, CommandList* next){
  CommandList* node = (CommandList*) malloc(sizeof(CommandList));
  node-> cmd = cmd;
  node -> next = next;
  return node;
}



Cmd* variable_declaration(char* v, Expr* value){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node -> kind = LET;
  node -> attr.let.var = v;
  node -> attr.let.value = value;
  return node;
}

Cmd* if_declaration(BoolExpr* cond, Cmd* next,CommandList* list){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node -> kind = IF;
  node -> attr.ifType.cond = cond;
  node -> attr.ifType.cmd = next;
  node -> attr.ifType.list = list;
  return node;
}

Cmd* else_declaration(BoolExpr* cond, Cmd* ifL, CommandList* flist,Cmd* elseL,CommandList* slist){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node -> kind = IFELSE;
  node -> attr.elseType.cond = cond;
  node -> attr.elseType.cmd = ifL;
  node -> attr.elseType.cmdelse= elseL;
  node-> attr.elseType.flist = flist;
  node-> attr.elseType.slist = slist;
  return node; 
}


Cmd* while_declaration(BoolExpr* cond, Cmd* cmd, CommandList* list){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node -> kind = WHILE;
  node -> attr.whileType.cond = cond;
  node -> attr.whileType.cmd = cmd;
  node -> attr.whileType.list = list;
  return node;
}


Expr* ast_integer(int v) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_INTEGER;
  node->attr.value = v;
  return node;
}

Expr* ast_operation(int operator, Expr* left, Expr* right) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_OPERATION;
  node->attr.op.operator = operator;
  node->attr.op.left = left;
  node->attr.op.right = right;
  return node;
}
