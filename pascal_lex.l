%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "y.tab.h"
#include "table.h"

/* 行号 */
int line_no = 1;
char str_lex[20];
int yylex(void);

%}

/* 语言不区分大小写 */
A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]	
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

letter		[_A-Za-z]
letternum	[_A-Za-z0-9]
num			[0-9]

%%

{P}{R}{O}{G}{R}{A}{M} 	{ return(Program); }
{V}{A}{R} 				{ return(Var); }
{R}{E}{A}{L}			{ return(Real); }
{I}{N}{T}{E}{G}{E}{R} 	{ return(Integer); }
{B}{E}{G}{I}{N}		 	{ return(Begin); }
{E}{N}{D}			 	{ return(End); }
{W}{H}{I}{L}{E}			{ return(While); }
{D}{O}					{ return(Do); }
{I}{F}					{ return(If); }
{T}{H}{E}{N}			{ return(Then); }
{E}{L}{S}{E}			{ return(Else); }
{O}{F}					{ return(Of); }
{A}{R}{R}{A}{Y}			{ return(Array); }
{A}{N}{D}				{ return(And); }
{O}{R}					{ return(Or); }
{N}{O}{T}				{ return(Not); }

":="   	{ return(AssignOp); }
"\.\."	{ return(DotDot); }
"."    	{ return('.'); }
","    	{ return(','); }
";"    	{ return(';'); }
":"    	{ return(':'); }
"+"    	{ return('+'); }
"*"    	{ return('*'); }
"("    	{ return('('); }
")"    	{ return(')'); }
">"	   	{ return('>'); }
"<"	   	{ return('<'); }
"="		{ return('='); }
">="	{ return(GE); }
"<="	{ return(LE); }
"<>"	{ return(NE); }
"-"		{ return('-'); }
"/"		{ return('/'); }
"["		{ return('['); }
"]"		{ return(']'); }


[0-9]+  { strcpy(yylval.str, yytext); strcpy(str_lex, yytext); return(UnsignedIntNo); }

[0-9]+"."[0-9]+ 	{ strcpy(yylval.str, yytext); printf("lex %s\n",yytext); return(UnsignedRealNo); }

{letter}{letternum}* { strcpy(yylval.str, yytext); return Iden; }

\n    { line_no++; }

[ \t\f]  { ; }

.	{ strcpy(str_lex, yytext); printf("Invalid char %s\n",yytext); return ErrorChar; }

%%

#ifndef yywrap
int yywrap()
{
	return 1;
}

#endif
