#include"code.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int registo=0;
int label=1;

Atom* atom_String(char* c){
	Atom* node = (Atom*)malloc(sizeof(Atom));
	node->kind = A_STRING;
	node->elem.name = c;
	return node;
}

Atom* atom_Int(int v){
	Atom* node = (Atom*)malloc(sizeof(Atom));
	node->kind = A_INT;
	node->elem.value = v;
	return node;

}

Atom* atom_Empty(){
	Atom* node = (Atom*)malloc(sizeof(Atom));
	node->kind = A_EMPTY;
	return node;
}

Instr* instr_if_Ifg(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFG;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}

Instr* instr_if_IfL(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFL;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}

Instr* instr_if_Ifge(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFGE;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}
Instr* instr_if_Ifle(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFLE;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}

Instr* instr_if_Ifeq(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFEQ;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}

Instr* instr_if_Ifneq(int op, Atom* a, Atom* b, char* l1, char* l2){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind =  I_IFNEQ;
	node->attr.i_if.operator = op;
	node->attr.i_if.a1 = a;
	node->attr.i_if.a2 = b;
	node->attr.i_if.label1 = l1;
	node->attr.i_if.label2 = l2;
	return node;
}

Instr* instr_label(char* l){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind = I_LABEL;
	node->attr.label.label1 = l;
	return node;
}

Instr* instr_atrib(Atom* a, Atom* b){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind = I_ATRIB;
	node->attr.atrib.a1 = a;
	node->attr.atrib.a2 = b;
	return node;
}

Instr* instr_goto(char* l){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind = I_GOTO;
	node->attr.i_goto.label1=l;
	return node;
}

Instr* instr_op_plus(int op, Atom* a, Atom* b, Atom* c){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind=I_PLUS;
	node->attr.op.operator=op;
	node->attr.op.a1 = a;
	node->attr.op.a2 = b;
	node->attr.op.a3 = c;
	return node;
}

Instr* instr_op_minus(int op, Atom* a, Atom* b, Atom* c){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind=I_MINUS;
	node->attr.op.operator=op;
	node->attr.op.a1 = a;
	node->attr.op.a2 = b;
	node->attr.op.a3 = c;
	return node;
}

Instr* instr_op_mult(int op, Atom* a, Atom* b, Atom* c){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind=I_MULT;
	node->attr.op.operator=op;
	node->attr.op.a1 = a;
	node->attr.op.a2 = b;
	node->attr.op.a3 = c;
	return node;
}

Instr* instr_op_div(int op, Atom* a, Atom* b, Atom* c){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind=I_DIV;
	node->attr.op.operator=op;
	node->attr.op.a1 = a;
	node->attr.op.a2 = b;
	node->attr.op.a3 = c;
	return node;
}

Instr* intr_op_print(Atom* a){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind = I_PRINT;
	node->attr.print.a1 = a;
	return node;
}

Instr* intr_op_printt(Atom* a, Atom* b){
	Instr* node = (Instr*)malloc(sizeof(Instr));
	node->ikind = I_PRINTT;
	node->attr.printt.a1 = a;
	node->attr.printt.a2 = b;

	return node;

}

Instr* getFirst(LIST* l){

	if(l->instr == NULL) return NULL;
	else
		return l->instr;
}

LIST* nextInstrs(LIST* l){
	return l->next;
}

LIST* append(LIST* l1, LIST* l2){
	LIST* p= l1;

	if(l1==NULL) return l2;

	else
		while(l1->next == NULL)
			l1==l1->next;
		l1->next=l2;
			

			return p;
}
 
LIST* mkInstrList(Instr* i, LIST* l){                        //criar lista
  LIST* list = (LIST*)malloc(sizeof(LIST));
  list->instr = i;
  list->next = l;

  return list;
}

/*void printList(LIST* l){

	if(l==NULL) printf("Lista Vazia");
	else{
		while(l->next!=NULL){
			printInstr(l->instr);
			l=l->next;
		}
		printInstr(l->instr);
	}
}

int length(LIST* l){
    
	int i = 0;
	while (l-> next!= NULL){
   		l = l->next;
   		i++;
	}
return i;
}
*/
void printAtom(Atom* atom){
	if(atom->kind == A_STRING)
		printf("%s " , atom->elem.name);
	else if(atom->kind == A_INT)
		printf("%d ", atom->elem.value);
	else if(atom->kind == A_EMPTY)
		printf("Atom vazio\n");
}

void printInstr(Instr* instr){
	switch(instr->ikind){
		case I_ATRIB:
			printAtom(instr->attr.atrib.a1);
		 	printf(" := ");
		 	printAtom(instr->attr.atrib.a2);
		 	printf("\n");
		 	break;
		case I_PLUS:
			printAtom(instr->attr.op.a1);
			printf(" := ");
			printAtom(instr->attr.op.a2);
			printf("+");
			printAtom(instr->attr.op.a3);
			printf("\n");
			break;
		case I_MINUS:
			printAtom(instr->attr.op.a1);
			printf(" := ");
			printAtom(instr->attr.op.a2);
			printf("-");
			printAtom(instr->attr.op.a3);
			printf("\n");
			break;
		case I_DIV:
			printAtom(instr->attr.op.a1);
			printf(" := ");
			printAtom(instr->attr.op.a2);
			printf("/");
			printAtom(instr->attr.op.a3);
			printf("\n");
			break;
		case I_MULT:
			printAtom(instr->attr.op.a1);
			printf(" := ");
			printAtom(instr->attr.op.a2);
			printf("*");
			printAtom(instr->attr.op.a3);
			printf("\n");
			break;
		case I_IFGE:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d ", instr->attr.i_if.operator);
			printf(" >= ");
			printAtom(instr->attr.i_if.a2);
			printf("then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
		case I_IFG:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d " ,instr->attr.i_if.operator);
			printf(" >= ");
			printAtom(instr->attr.i_if.a2);
			printf("then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
		case I_IFL:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d " ,instr->attr.i_if.operator);
			printf(" < ");
			printAtom(instr->attr.i_if.a2);
			printf(" then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
		case I_IFLE:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d " ,instr->attr.i_if.operator);
			printf(" <= ");
			printAtom(instr->attr.i_if.a2);
			printf(" then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
			case I_IFEQ:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d ", instr->attr.i_if.operator);
			printf(" <= ");
			printAtom(instr->attr.i_if.a2);
			printf(" then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
		case I_IFNEQ:
			printf("if ");
			printAtom(instr->attr.i_if.a1);
			//printf("%d ", instr->attr.i_if.operator);
			printf(" != ");
			printAtom(instr->attr.i_if.a2);
			printf(" then ");
			printf("%s ",instr->attr.i_if.label1);
			printf(" else ");
			printf("%s " , instr->attr.i_if.label2);
			break;
		default:
			printf("erro no kind\n");
		break;
	}
}

 void printListIntrs(LIST* l){

 	if(l==NULL) printf("Lista Vazia");

	else{
		while(l->next!=NULL){
			printInstr(l->instr);
			l=l->next;
		}

		printInstr(l->instr);
	}
 }

LIST* compileCmdList(CommandList* l){    //passar a lista do trab1 para uma lista de instruçoes
	if(l == NULL) return NULL;
	else{
		LIST* l1 = compileCmd(l->cmd);
		LIST* l2 = compileCmdList(l->next);
		return (append(l1,l2));
	}
}

char* newLabel(){
	char* name ="label";
 	sprintf(name, "%d",label);
 	label++;
 	return name;
}

LIST* compileCmd(Cmd* command){
	LIST* l = (LIST*) malloc(sizeof(LIST));
	LIST* l1 = (LIST*) malloc(sizeof(LIST));
	LIST* l2 = (LIST*) malloc(sizeof(LIST));
	LIST* l3 = (LIST*) malloc(sizeof(LIST));
	LIST* l4 = (LIST*) malloc(sizeof(LIST));
	LIST* l5 = (LIST*) malloc(sizeof(LIST));
	LIST* linicio = (LIST*) malloc(sizeof(LIST));
	LIST* l6= (LIST*) malloc(sizeof(LIST));
	LIST* l7 = (LIST*) malloc(sizeof(LIST));
	LIST* l8 = (LIST*) malloc(sizeof(LIST));
	LIST* l9 = (LIST*) malloc(sizeof(LIST));
	LIST* l10 = (LIST*) malloc(sizeof(LIST));
	LIST* l11 = (LIST*) malloc(sizeof(LIST));
	LIST* l12 = (LIST*) malloc(sizeof(LIST));

	char* reg="";
	char* label1 = "";
	char* label2 = "";
	char* label3 = "";

	switch(command -> kind) {
		case LET:
			reg = newVar();
			l = mkInstrList(instr_atrib(atom_String(command->attr.let.var), atom_String(reg)), NULL);
			l = append(compileExpr(command->attr.let.value, reg), l);
			return l;

		case WHILE:
			label1 = newLabel();
			label2 = newLabel();
			label3 = newLabel();
			linicio = mkInstrList(instr_label(label3), NULL);
			l1 = compileBool(command->attr.whileType.cond , label1, label2);
			l2 = append(linicio, l1); 
			l3 = mkInstrList(instr_label(label1), NULL);
			l4 = append(l2, l3);
			l5 = compileCmdList(command->attr.whileType.list); 
			l6 = append(l4, l5);
			l7 = mkInstrList(instr_goto(label3), NULL);   //voltar para a label do inicio
			l8 = append(l6, l7);
			l9 = mkInstrList(instr_label(label2), NULL);
			l10 = append(l8, l9);     
			return l10;

		case IF:	
			label1 = newLabel();
			label2 = newLabel();
			l = compileBool(command->attr.ifType.cond , label1, label2);
			l1 = mkInstrList(instr_label(label1), NULL);
			l2 = append(l, l1);
			l3 = compileCmdList(command->attr.ifType.list); 
			l4 = append(l2, l3);
			l5 = mkInstrList(instr_label(label2), NULL);
			l6 = append(l4, l5);
			return l6; 

		case IFELSE:
			label1 = newLabel();
			label2 = newLabel();
			label3 = newLabel();
			l = compileBool(command->attr.elseType.cond , label1, label2);
			l1 = mkInstrList(instr_label(label1), NULL);
			l2 = append(l, l1);
			l3 = compileCmdList(command->attr.elseType.flist);
			l4 = append(l2,l3);
			l5 = mkInstrList(instr_goto(label3), NULL);   //voltar para a label do inicio
			l6 = append(l4,l5);
			l7 = mkInstrList(instr_label(label2), NULL);   //voltar para a label do inicio
			l8 = append(l6,l7);
			l9 = compileCmdList(command->attr.elseType.slist); 
			l10 = append(l8, l9);
			l11 = mkInstrList(instr_label(label3), NULL);
			l12 = append(l10, l11);
			return l12;

	/*	case PRINT:
		reg =  newVar();
		l = mkInstrList(instr_print(atom_String(command->attr.let.var), atom_String(reg)), NULL);
		l = append();*/

		break;

		case PRINTT:
		break;

        case READ:
        break;
	}
}

char* newVar(){
 	char* name ="t";
 	sprintf(name, "%d",registo);
 	registo++;
 	return name;
 }

LIST* compileExpr(Expr* e, char* r){

 	LIST* l4 = malloc(sizeof(LIST));
 	if(e->kind ==  E_INTEGER){
 		LIST* l = mkInstrList(instr_atrib(atom_String(r), atom_Int(e->attr.value)), NULL);
 		return l;
 	}
 	else if(e->kind == E_OPERATION){
 		char* r1 = newVar();
		LIST* l1 = compileExpr(e->attr.op.left, r1);
		char* r2 = newVar();
		LIST* l2 = compileExpr(e->attr.op.right, r2);
		LIST* l3 = append(l1, l2);
		l4 = append(l3, mkInstrList(mkInstrOp(e->attr.op.operator, atom_String(r), atom_String(r1), atom_String(r2)), NULL));
	}
	return l4;
}
 
Instr* mkInstrOp(int operator, Atom* a1, Atom* a2, Atom* a3){
	Instr* instr = 	(Instr*) malloc(sizeof(Instr));

	switch(operator){

	case PLUS:
	instr = instr_op_plus(operator,a1,a2,a3);
	instr->ikind = I_PLUS;
	return instr;

	case MINUS:
	instr = instr_op_minus(operator, a1, a2, a3);
	instr->ikind = I_MINUS;
	return instr;

	case DIV:
	instr = instr_op_div(operator,a1, a2, a3);
	instr->ikind = I_DIV;
	return instr;

	case TIMES:
	instr = instr_op_mult(operator, a1, a2, a3);
	instr->ikind = I_MULT;
	return instr;

	default:
		printf("Erro no operador\n");
		break;
	}
}

Instr* makeInstrIf(int operador, Atom* a1, Atom* a2, char* label1, char* label2){
  Instr* instr = (Instr*)malloc(sizeof(Instr));

  switch(operador) {
    case EQ:
    	instr = instr_if_Ifeq(operador, a1, a2, label1, label2);
    	instr->ikind = I_IFEQ;
      break;
    case DIF:
    	instr = instr_if_Ifneq(operador, a1, a2, label1, label2);
    	instr->ikind = I_IFNEQ;
      	break;
    case LT:
    	instr = instr_if_IfL(operador, a1, a2, label1, label2);
      	instr->ikind = I_IFL;
      	break;
    case GT:
    	instr = instr_if_Ifg(operador, a1, a2, label1, label1);  
    	instr->ikind = I_IFG;
      break;
    case LTE:
    	instr = instr_if_Ifle(operador, a1, a2, label1, label2);
      	instr->ikind = I_IFLE;
      break;
    case GTE:
    	instr = instr_if_Ifge(operador, a1, a2, label1, label2);
      instr->ikind = I_IFGE;
      break;
  }
  instr->attr.i_if.operator = operador;
  instr->attr.i_if.a1 = a1;
  instr->attr.i_if.a2 = a2;
  instr->attr.i_if.label1 = strdup(label1);
  instr->attr.i_if.label2 = strdup(label2);
  return instr;
}

LIST* compileBool(BoolExpr* e, char *labelTrue, char *labelFalse){
	LIST* l = (LIST*)malloc(sizeof(LIST));

	if(e->kind == E_BOOL){
		char* r1 = newVar();
		LIST* l1 = mkInstrList(instr_atrib(atom_String(r1), atom_Int(e->attr.value)), NULL);
		return l1;
	}

	else if(e->kind == E_BOOLOP){
		char* temp1 = malloc(1024*sizeof(char));
		char* temp2 = malloc(1024*sizeof(char));
  		int operador;
		LIST* l1 = (LIST*)malloc(sizeof(LIST));
 		LIST* l2 = (LIST*)malloc(sizeof(LIST));
  		LIST* l3 = (LIST*)malloc(sizeof(LIST));
  		LIST* l4 = (LIST*)malloc(sizeof(LIST));
  		LIST* l5 = (LIST*)malloc(sizeof(LIST));
  		temp1 = newVar();
  		temp2 = newVar();
  		l1 = compileExpr(e->attr.op.left, temp1);
  		l2 = compileExpr(e->attr.op.right, temp2);
  		operador = e->attr.op.operator;
  		l3 = append(l1, l2);
  		Atom* a1 = atom_String(temp1);
  		Atom* a2 = atom_String(temp2);
  		l5 = mkInstrList(makeInstrIf(operador, a1, a2, labelTrue, labelFalse), NULL);
  		l4 = append(l3, l5);
  		return l4;
	}   
}

int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //yyin = stdin

  if (yyparse() == 0) {
    //printf("Result = %d\n", evalExpr(root,0));
    //evalCmdList(root,0);
    printListIntrs(compileCmdList(root));
  }
  return 0;
}


