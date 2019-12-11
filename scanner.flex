%{
// HEADERS
#include <stdlib.h>
#include "parser.h"

// variables maintained by the lexical analyser
int yyline = 1;
%}

%option noyywrap

%%
[ \t]+ {  }
#.*\n { yyline++; }
\n { yyline++; }

\-?[0-9]+ { 
   yylval.intValue = atoi(yytext);
   return INT; 
}

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return TIMES; }
"/" { return DIV; }
"%" { return MOD; }
"true" { return T; }
"false" {return F; }
"<" { return LT; }
">" { return GT; }  
"<=" { return LTE; }
">=" { return GTE; }
"==" { return EQ; }
"!=" { return DIF; }
"if" { return TOKEN_IF; }
"else" { return TOKEN_ELSE; }
"while" { return TOKEN_WHILE; }
"let" {return TOKEN_ATRIB; }
"{" { return CHAVETA1; }
"}" { return CHAVETA2; }
";" { return EOL; }
"=" { return TOKEN_EQ; }
"(" { return OPENP; }
")" { return CLOSEP; }
"println!" { return PRINTL; }
"fn main(){" {return MAIN; }
"{}" { return PRINTV; }
"," { return VIRGULA;}
"read_line" { return READLINE;}
"&" { return COMM;}

[a-z][a-zA-Z]* {
	yylval.charValue = yytext;
	return VAR;
}

\".*?[^\\]\" {
    yylval.typesValue = strdup(yytext);
    return STRING;
}
.  { yyerror("unexpected character"); }
%%

