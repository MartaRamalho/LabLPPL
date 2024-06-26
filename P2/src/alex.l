%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"




#define  retornar(x) {if (verbosidad) ECHO; return(x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput
%option nounput
%option yylineno

delimitador    [ \t]+
digito         [0-9]
letra          [A-Za-z]
constante    {digito}*("."{digito}+)?|{digito}+"."{digito}*
id             {letra}({letra}|{digito}|"_")*
comentario     "//".*

%%

"\n" {if (verbosidad) fprintf(stdout,"\n%3d.- ", yylineno);}

{delimitador} { if (verbosidad) ECHO; }
{comentario} { if (verbosidad) ECHO; }

"+" { retornar (OPSUMA_); }
"-" { retornar (OPRESTA_); }
"*" { retornar (OPMULT_); }
"/" { retornar (OPDIV_); }
"!" { retornar (OPNOT_);}
"=" {retornar (OPIGUAL_)}
"&&" {retornar (OPAND_);}
"||" {retornar (OPOR_);}
"++" {retornar (OPINCREASE_);}
"--" {retornar (OPDECREASE_);}

"<" { retornar (COMPMENOR_);}
">" { retornar (COMPMAYOR_);}
"<=" { retornar (COMPMENORIG_);}
">=" { retornar (COMPMAYORIG_);}
"==" {retornar (COMPIGUAL_);}
"!=" {retornar (COMPDIF_);}

"if"	{ retornar(IF_); }
"else" { retornar(ELSE_); }
"struct" {retornar (STRUCT_);}
"while" {retornar (WHILE_)}

"int"	{ retornar(INT_); }
"bool" { retornar(BOOL_); }

"read"				{ retornar(READ_); }
"print"				{ retornar(PRINT_); }
"return"			{ retornar(RETURN_); }

"true"				{ retornar(TRUE_); }
"false"				{ retornar(FALSE_); }

"("  { retornar (OPENPAR_); }
")"  { retornar (CLOSEPAR_); }
"{" { retornar (OPENLLAVE_);}
"}" { retornar (CLOSELLAVE_);}
"[" {retornar (OPENCORCH_);}
"]" {retornar (CLOSECORCH_);}
";" {retornar (SEMICOLON_);}
"," {retornar (COMA_);}
"." {retornar (PUNTO_)}

{id} {yylval.ident = strdup(yytext); retornar (ID_);}
{constante}      {yylval.cent = atoi(yytext); retornar (CTE_); }

.	       { yyerror("Caracter desconocido"); }

%%

/*****************************************************************************/
