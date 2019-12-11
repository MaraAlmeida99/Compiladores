#include "ast.h"
#include "printAbsTree.h"
#include <string.h>
#include "parser.h"


void identar(int v){
	for(int i=0; i<v; i++)
		printf(" ");
}


void printExpr(Expr* exp, int tabs){
	identar(tabs);
	if(exp->kind==E_INTEGER){
		printf("%d \n", exp->attr.value);
		return;
	}
	else{ 
		switch(exp->attr.op.operator){
			case PLUS: 
		        printf("+ \n");
		        break;
		    case MINUS:
		        printf("- \n");
		        break;
		    case MOD:
		        printf("%% \n");
		        break;
		    case TIMES:
		        printf("* \n");
		        break;
		    case DIV:
		        printf("/ \n");
		        break;
		    //default:  yyerror("Unknown operator!");
		}
		tabs+=2;
		printExpr(exp->attr.op.left, tabs);
		printExpr(exp->attr.op.right, tabs);
	}
}

void printBool(BoolExpr* b, int tabs){

	for(int i=0; i<tabs; i++){
		printf(" ");
	}

	if(b->kind==E_BOOL){
		if(b->attr.value==1)
			printf("true \n");
		else
			printf("false \n");
		return;
	}
	else{
		switch(b->attr.op.operator){
			case PLUS: 
		        printf("+ \n");
		        break;
		    case MINUS:
		        printf("- \n");
		        break;
		    case MOD:
		        printf("%% \n");
		        break;
		    case TIMES:
		        printf("* \n");
		        break;
		    case DIV:
		        printf("/ \n");
		        break;
		    case GT:
		    	printf("> \n");
		    	break;
		    case LT:
		    	printf("< \n");
		    	break;
		    case GTE:
		    	printf(">= \n");
		    	break;
		    case LTE:
		    	printf("<= \n");
		    	break;
		    case EQ:
		    	printf("== \n");
		    	break;
		    case DIF:
		    	printf("!= \n");
		    	break; 
		 //   default: yyerror("Unknown operator!");
		}
		tabs+=2;
		printExpr(b->attr.op.left, tabs);
		printExpr(b->attr.op.right, tabs);
	}
}

void print(Cmd* exp, int tabs){
	switch(exp->kind){
		case LET:
			identar(tabs);
			printf("=\n");
			identar(2+tabs);
			char* p;
			p = strtok(exp->attr.let.var, " ");
			printf("%s \n",p);
			printExpr(exp->attr.let.value, 2+tabs);
			break;
		case IF:
			identar(tabs);
			printf("if\n");
			printBool(exp->attr.ifType.cond, 2+tabs);
			//identar(2+tabs);
			print(exp->attr.ifType.cmd,4+tabs);
			if(exp->attr.ifType.list != NULL) {
				while(exp->attr.ifType.list != NULL) {
					print(exp->attr.ifType.list->cmd, 4+tabs);
					exp-> attr.ifType.list = exp->attr.ifType.list -> next;
				}
			}
			break;
		case IFELSE:
			identar(tabs);
			printf("if\n");
			printBool(exp->attr.elseType.cond,2+tabs);
			print(exp->attr.elseType.cmd,4+tabs);
			if(exp->attr.elseType.flist != NULL) {
				while(exp->attr.elseType.flist != NULL) {
					print(exp->attr.elseType.flist->cmd, 4+tabs);
					exp-> attr.elseType.flist = exp->attr.elseType.flist -> next;
				}
			}
			identar(tabs);
			printf("else \n");
			print(exp->attr.elseType.cmdelse,2+tabs);
			if(exp->attr.elseType.slist != NULL){
				while(exp->attr.elseType.slist != NULL) {
					print(exp->attr.elseType.slist->cmd, 2+tabs);
					exp-> attr.elseType.slist = exp->attr.elseType.slist -> next;
				}
			}
			break;
		case WHILE:
			identar(tabs);
			printf("while \n");
			printBool(exp->attr.whileType.cond,2+tabs);
			//identar(2+tabs);
			print(exp->attr.whileType.cmd,4+tabs);
			if(exp->attr.whileType.list != NULL) {
				while(exp->attr.whileType.list != NULL) {
					print(exp->attr.whileType.list->cmd, 4+tabs);
					exp-> attr.whileType.list = exp->attr.whileType.list -> next;
				}
			}	
			break;
		case PRINT:
			identar(tabs);
			printf("println!\n");
			identar(4+tabs);
			printf("%s\n",exp->attr.printType.string);
			break;
		case PRINTT:
			identar(tabs);
			printf("println!\n");
			identar(2+tabs);
			printf("%s \n", exp->attr.printVType.string);
			identar(4+tabs);
			char* k;
			k = strtok(exp->attr.printVType.var, ")");
			printf("%s\n", k);
			break;
		case READ:
			identar(tabs);
			printf("read_line()\n");
			identar(tabs+2);
			char* v;
			v = strtok(exp->attr.readType.var, ")");
			printf("&%s\n",v);
			break;
//		default: yyerror("Unknown operator!");
	}
	return;
}