%{
#include <stdio.h>
#include <string.h>
#include "header.h"

#define  retornar(x) {if (verbosidad) ECHO; return(x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput       
%option nounput       
%option yylineno  

delimitador    [ \t\n]+
digito         [0-9]
letra          [A-Za-z]
entero         {digito}+
real           {entero}("."{digito}*)
id             {letra}(letra|digito|"_")*
comentario     "\\".*\n

%%
{delimitador} { if (verbosidad) ECHO; }
{comentario} { retornar (COMENT_); }

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

{entero}      { retornar (CTE_); }
{real} { retornar (CTE_);}
{id} {retornar (ID_);}

"("  { retornar (OPENPAR_); }
")"  { retornar (CLOSEPAR_); }
"{" { retornar (OPENLLAVE_);}
"}" { retornar (CLOSELLAVE_);}
"[" {retornar (OPENCORCH_);}
"]" {retornar (CLOSECORCH_);}
";" {retornar (SEMICOLON_);}
"," {retornar (COMA_);}
"." {retornar (PUNTO_)}

.	       { yyerror("Caracter desconocido"); }

%%
/*****************************************************************************/
