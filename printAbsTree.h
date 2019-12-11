#pragma once
#include "ast.h"

void identar(int v);
void printExpr(Expr* exp, int tabs);
void printBool(BoolExpr* b, int tabs);
void print(Cmd* exp, int tabs);


