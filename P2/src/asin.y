%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
%}

%union {
       char *ident; /* Nombre del identificador */
       int cent; /* Valor de la cte num´erica entera */
       DOSV dosv;
       TIPO tipo;
}

%token OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPAND_ OPDECREASE_ OPIGUAL_ OPINCREASE_ OPNOT_ OPOR_
%token COMPDIF_ COMPIGUAL_ COMPMAYOR_ COMPMAYORIG_ COMPMENOR_ COMPMENORIG_
%token OPENCORCH_ OPENLLAVE_ OPENPAR_ CLOSECORCH_ CLOSELLAVE_ CLOSEPAR_ SEMICOLON_ COMA_ PUNTO_
%token FOR_ IF_ ELSE_ WHILE_ STRUCT_
%token READ_ RETURN_ PRINT_
%token TRUE_ FALSE_ BOOL_
%token <cent> CTE_ INT_ 
%token <ident> ID_
%type <cent> tipoSimp declaFunc opIncre opUna opMul opAd opRel opIgual opLogic decla listDecla
%type <dosv> listCamp listParamForm paramForm
%type <tipo> const expreSufi expre
%%

programa
       : { dvar = 0; niv = 0; cargaContexto(niv); } listDecla
              {
                     if($2 >= 0){
                            yyerror("No hay una función main");
                     } else if ($2 < -1) {
                            yyerror("Hay más de una función main");
                     }
              }
       ;

listDecla
       : decla
       | listDecla decla {$$ = $1 + $2;}
       ;

decla
       : declaVar {$$ = 0;}
       | declaFunc {$$ = $1;}
       ;

declaVar
       : tipoSimp ID_ SEMICOLON_ {
		if(!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += TALLA_TIPO_SIMPLE;
		}
       }
       | tipoSimp ID_ OPENCORCH_ CTE_ CLOSECORCH_ SEMICOLON_ {
		int numelem = $4;
		if($4<=0) {
                	yyerror("Talla inapropiada del array");
			numelem = 0;
		}
		int refe = insTdA($1, numelem);
		if ( ! insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe) ) {
                	yyerror ("Identificador repetido");
		} else {
			dvar += numelem * TALLA_TIPO_SIMPLE;
		}
       }
       | STRUCT_ OPENLLAVE_ listCamp CLOSELLAVE_ ID_ SEMICOLON_ {
		if(!insTdS($5, VARIABLE, $3.ref1, niv, dvar, $3.ref1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += TALLA_TIPO_SIMPLE;
		}
       }
       ;

tipoSimp
       : INT_ { $$ = T_ENTERO; }
       | BOOL_ { $$ = T_LOGICO; }
       ;

listCamp
       : listCamp tipoSimp ID_ SEMICOLON_ {
		$$.ref1 = insTdR($1.ref1, $3, $2, $1.ref2);
		if(!insTdS($3, VARIABLE, $2, niv, dvar, $$.ref1)) {
			yyerror("Identificador repetido");
		} else {
              dvar += TALLA_TIPO_SIMPLE;
		}
	}
       | tipoSimp ID_ SEMICOLON_ {
		$$.ref1 = insTdR(-1, $2, $1, 0);
		if(!insTdS($2, VARIABLE, $1, niv, dvar, $$.ref1)) {
			yyerror("Identificador repetido");
		} else {
              dvar += TALLA_TIPO_SIMPLE;
		}
       	}
       ;

declaFunc
       : tipoSimp ID_
         {
              niv++;
              cargaContexto(niv);
              $<cent>$ = dvar;
              dvar = 0;
         }
         OPENPAR_ paramForm CLOSEPAR_
         {
              if(!insTdS($2, FUNCION, $1, niv-1, dvar, $5.ref1)){
                     yyerror("Identificador repetido");
              }
         }
         OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_
         {
              if(verTdS) {
                      mostrarTdS();
              }
              descargaContexto(niv);
              niv--;
              dvar = $<cent>$;

              if(strcmp($2, "main") == 0){
                     //printf("Main detectado");
                     $<cent>$ = -1;
              } else {
                     //printf("Funcion que no es main");
                     $<cent>$ = 0;
              }

              if($12.t != $1){
                     yyerror("Tipo de return distinto al de la función");
              }
         }
       ;

paramForm
       : {
		$$.ref1 = insTdD(-1, T_VACIO);
		$$.ref2 = 0;
       }
       | listParamForm {
		$$.ref1 = $1.ref1;
		$$.ref2 = $1.ref2 - TALLA_SEGENLACES;
       }
       ;

listParamForm
       : tipoSimp ID_ {
		$$.ref1 = insTdD(-1, $1);
		$$.ref2 = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;

		if(!insTdS($2, PARAMETRO, $1, niv, -$$.ref2, $$.ref1)){
              yyerror("Identificador repetido");
		}
	}
       | tipoSimp ID_ COMA_ listParamForm {
		$$.ref1 = insTdD($4.ref1, $1);
		$$.ref2 = $4.ref2 + TALLA_TIPO_SIMPLE;
		if(!insTdS($2, PARAMETRO, $1, niv, -$$.ref2, $$.ref1)){
              yyerror("Identificador repetido");
		}
	}
       ;

declaVarLocal
       :
       | declaVarLocal declaVar
       ;

listInst
       :
       | listInst inst
       ;
inst
       : OPENLLAVE_ listInst CLOSELLAVE_
       | instExpre
       | instEntSal
       | instSelec
       | instIter
       ;
instExpre
       : expre SEMICOLON_
       | SEMICOLON_
       ;
instEntSal
       : READ_ OPENPAR_ ID_ CLOSEPAR_ SEMICOLON_
       | PRINT_ OPENPAR_ expre CLOSEPAR_ SEMICOLON_
       ;
instSelec
       : IF_ OPENPAR_ expre CLOSEPAR_ inst ELSE_ inst
       ;
instIter
       : WHILE_ OPENPAR_ expre CLOSEPAR_ inst
       ;
expre
       : expreLogic
       | ID_ OPIGUAL_ expre
       | ID_ OPENCORCH_ expre CLOSECORCH_ OPIGUAL_ expre
       | ID_ PUNTO_ ID_ OPIGUAL_ expre
       ;
expreLogic
       : expreIgual
       | expreLogic opLogic expreIgual
       ;
expreIgual
       : expreRel
       | expreIgual opIgual expreRel
       ;
expreRel
       : expreAd
       | expreRel opRel expreAd
       ;
expreAd
       : expreMul
       | expreAd opAd expreMul
       ;
expreMul
       : expreUna
       | expreMul opMul expreUna
       ;
expreUna
       : expreSufi
       | opUna expreUna
       | opIncre ID_
       ;

expreSufi
       : const                    {$$.t = $1.t;}
       | OPENPAR_ expre CLOSEPAR_ {$$.t = $2.t;}
       | ID_
              {
			$$.t = T_ERROR;
			SIMB sim = obtTdS($1);
		 	if (sim.t == T_ERROR) {
				 yyerror("No existe ninguna variable con ese identificador.");
			 } else {
				 $$.t = sim.t;
			 }
		}
       | ID_ opIncre
              {
			$$.t = T_ERROR;
			SIMB sim = obtTdS($1);
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.t == T_ENTERO) {
				$$.t = sim.t;
			} else {
				yyerror("Incompatibilidad de tipos, solo se puede aplicar el operador \"++\" o \"--\" a una expresion entera.");
			}
		}
       | ID_ PUNTO_ ID_
		{
			$$.t = T_ERROR;
			SIMB sim = obtTdS($1);
			CAMP cam = obtTDR(sim.ref, $3)
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.t != T_RECORD) {
				yyerror("La variable no es del tipo apropiado.");
			} else if (cam.t == T_ERROR) {	/* Falta hacer el resto de este */
				yyerror("No existe ninguna variable con ese identificador en ese campo.")
			} else {
				$$.t = cam.t
			}

		}
       | ID_ OPENCORCH_ expre CLOSECORCH_
		{
			$$.t = T_ERROR;
			SIMB sim = obtTdS($1);
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if ($3.t != T_ENTERO) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else {
				DIM dim = obtTdA(sim.ref);
				$$.t = dim.telem;
			}
		}
       | ID_ OPENPAR_ paramAct CLOSEPAR_
		{
			$$.t = T_ERROR;
			SIMB sim = obtTdS($1);
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (inf.t == T_ERROR) {
				yyerror("No existe ninguna funcion con ese identificador.");
			} else {
                INF inf = obtTdD(sim.ref);
				$$.t = inf.t;
			}
		}
       ;
const
       : CTE_               {$$.t = T_ENTERO;}
       | TRUE_              {$$.t = T_LOGICO;}
       | FALSE_             {$$.t = T_LOGICO;}
       ;
paramAct
       :
       | listParamAct      
       ;
listParamAct			
       : expre           
       | expre COMA_ listParamAct       
       ;
opLogic
       : OPAND_              {$$ = OP_AND;}
       | OPOR_               {$$ = OP_OR;}
       ;
opIgual
       : COMPIGUAL_          {$$ = OP_IGUAL;}
       | COMPDIF_            {$$ = OP_NOTIGUAL;}
       ;
opRel
       : COMPMENOR_          {$$ = OP_MENOR;}
       | COMPMENORIG_        {$$ = OP_MENORIG;}
       | COMPMAYOR_          {$$ = OP_MAYOR;}
       | COMPMAYORIG_        {$$ = OP_MAYORIG;}
       ;
opAd
       : OPSUMA_             {$$ = OP_SUMA;}
       | OPRESTA_            {$$ = OP_RESTA;}
       ;
opMul
       : OPMULT_             {$$ = OP_MULT;}
       | OPDIV_              {$$ = OP_DIV;}
       ;
opUna
       : OPSUMA_             {$$ = OP_SUMA;}
       | OPRESTA_            {$$ = OP_RESTA;}
       | OPNOT_              {$$ = OP_NOT;}
       ;
opIncre
       : OPINCREASE_         {$$ = OP_INCR;}
       | OPDECREASE_         {$$ = OP_DECR;}
       ;
%%
