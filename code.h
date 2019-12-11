#include "ast.h"
#include "parser.h"
#include<stdlib.h>
#include<string.h>

typedef enum {I_LABEL, I_GOTO, I_ATRIB, I_PLUS, I_MINUS, I_MULT, I_DIV, I_IFG, I_IFL, I_IFGE, I_IFLE, I_IFEQ, I_IFNEQ, I_PRINT, I_PRINTT} I_Kind;
typedef enum {A_STRING, A_INT, A_EMPTY} AtomKind;

typedef struct{
		AtomKind kind;
		union{
			int value;
			char *name;
		     }elem;                                                     
		}Atom;

typedef struct{
  I_Kind ikind;
  union{
    struct{
      int operator;   
      Atom* a1;
      Atom* a2;
      char* label1;
      char* label2;
    } i_if;
    struct{
      char* label1;
    } label;
    struct{
      Atom* a1; // variavel
      Atom* a2; // valor
    } atrib;
    struct{
      char* label1;
    } i_goto;
    struct{
      int operator;
      Atom* a1;
      Atom* a2;
      Atom* a3;
    } op;
    struct{
      Atom* a1;   
    } print;
    struct {
      Atom* a1;
      Atom* a2;
    }printt;   
  } attr;
} Instr;


typedef struct list{
	Instr* instr;
	struct list* next;
} LIST;


Atom* atom_String(char* c);
Atom* atom_Int(int v);
Atom* atom_Empty();
Instr* instr_if_Ifg(int op, Atom* a, Atom* b, char* l1, char* l2);   //
Instr* instr_if_IfL(int op, Atom* a, Atom* b, char* l1, char* l2);
Instr* instr_if_Ifge(int op, Atom* a, Atom* b, char* l1, char* l2);
Instr* instr_if_Ifle(int op, Atom* a, Atom* b, char* l1, char* l2);
Instr* instr_if_Ifeq(int op, Atom* a, Atom* b, char* l1, char* l2);
Instr* instr_if_Ifneq(int op, Atom* a, Atom* b, char* l1, char* l2);
Instr* instr_label(char* l);
Instr* intr_op_print(Atom* a);
Instr* intr_op_printt(Atom* a, Atom* b);

Instr* instr_atrib(Atom* a, Atom* b);
Instr* instr_goto(char* l);
Instr* instr_op_plus(int op, Atom* a, Atom* b, Atom* c);
Instr* instr_op_minus(int op, Atom* a, Atom* b, Atom* c);
Instr* instr_op_div(int op, Atom* a, Atom* b, Atom* c);
Instr* instr_op_mult(int op, Atom* a, Atom* b, Atom* c);

void printAtom(Atom* atom);
void printInstr(Instr* instr);
void printListIntrs(LIST* l);


Instr* getFirst(LIST* l);
LIST* append(LIST* l1, LIST* l2);
//void printList(LIST* l);
//int length(LIST* l);
LIST* mkInstrList(Instr* i, LIST* l);               


char* newVar();
LIST* compileCmdList(CommandList* l);  //passar a lista do trab1 para uma lista de instruçoes
LIST* compileCmd(Cmd* command);
Instr* mkInstrOp(int operator, Atom* a1, Atom* a2, Atom* a3);
Instr* makeInstrIf(int op, Atom* a1, Atom* a2, char* label1, char* label2);
LIST* compileExpr(Expr* e, char *r);
LIST* compileBool(BoolExpr* e, char *labelTrue, char *labelFalse); 

