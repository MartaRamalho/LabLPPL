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
%type <cent> tipoSimp declaFunc listDecla decla opIncre opUna opMul opAd opRel opIgual opLogic listParamAct paramAct
%type <dosv> listCamp listParamForm paramForm
%type <tipo> const expreSufi expre expreLogic expreAd expreIgual expreMul expreRel expreUna

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
			yyerror("Identificador de variable repetido.");
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
                	yyerror ("Identificador del array repetido.");
		} else {
			dvar += numelem * TALLA_TIPO_SIMPLE;
		}
       }
       | STRUCT_ OPENLLAVE_ listCamp CLOSELLAVE_ ID_ SEMICOLON_ {
		if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.ref1)) {
			yyerror("Identificador de struct repetido.");
		} else {
			dvar += $3.ref2;
		}
       }
       ;

tipoSimp
       : INT_ { $$ = T_ENTERO; }
       | BOOL_ { $$ = T_LOGICO; }
       ;

listCamp
       : listCamp tipoSimp ID_ SEMICOLON_ {
        $$.ref1 = insTdR($1.ref1, $3, $2, $$.ref2);
        $$.ref2 = $1.ref2;
		if($$.ref1 == -1) {
            $$.ref1 = $1.ref1;
			yyerror("Identificador de campo repetido.");
		} else {
              $$.ref2 = $1.ref2 + TALLA_TIPO_SIMPLE;
		}
	}
       | tipoSimp ID_ SEMICOLON_ {
		$$.ref1 = insTdR(-1, $2, $1, 0);
		$$.ref2 = TALLA_TIPO_SIMPLE;
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
              if(!insTdS($2, FUNCION, $1, niv-1, -1, $5.ref1)){
                     yyerror("Identificador de la función repetido.");
              }
         }
         OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_
         {
              if(strcmp($2, "main") == 0){
                     //printf("Main detectado");
                     $$ = -1;
              } else {
                     //printf("Funcion que no es main");
                     $$ = 0;
              }

              if($12.t != $1){
                     yyerror("Tipo de return distinto al de la declaración de la función");
              }

              if(verTdS) {
                      mostrarTdS();
              }
              descargaContexto(niv);
              niv--;
              dvar = $<cent>3;
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
              yyerror("Parámetro de la función repetido.");
		}
	}
       | tipoSimp ID_ COMA_ listParamForm {
		$$.ref1 = insTdD($4.ref1, $1);
		$$.ref2 = $4.ref2 + TALLA_TIPO_SIMPLE;
		if(!insTdS($2, PARAMETRO, $1, niv, -$$.ref2, $$.ref1)){
              yyerror("Parámetro de la función repetido.");
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
       : READ_ OPENPAR_ ID_ CLOSEPAR_ SEMICOLON_ {
              SIMB sim = obtTdS($3);
              if(sim.t == T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if(sim.t != T_ENTERO){
                     yyerror("El objeto a leer no es de tipo entero.");
              }
       }
       | PRINT_ OPENPAR_ expre CLOSEPAR_ SEMICOLON_{

              if( $3.t != T_ERROR && $3.t != T_ENTERO){
                      yyerror("El argumento del 'print' no es de tipo entero.");
              }
       }
       ;
instSelec
       : IF_ OPENPAR_ expre CLOSEPAR_ inst ELSE_ inst {
              if($3.t!=T_ERROR && $3.t!=T_LOGICO){
                     yyerror("La expresión del 'if' debe ser de tipo lógico.");
              }
       }
       ;
instIter
       : WHILE_ OPENPAR_ expre {
                     if($3.t!=T_ERROR && $3.t!=T_LOGICO){
                            yyerror("La expresión del 'while' debe ser de tipo lógico.");
                     }
              }
       CLOSEPAR_ inst
       ;
expre
       : expreLogic {$$.t=$1.t;}
       | ID_ OPIGUAL_ expre {
              SIMB sim = obtTdS($1);
              $$.t = T_ERROR;
              if(sim.t == T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if($3.t!=T_ERROR){
                     if($3.t!=sim.t){
                            yyerror("Incompatibilidad de tipos en la asignación.");
                     }
                     else {
                            $$.t=sim.t;
                     }
              }
       }
       | ID_ OPENCORCH_ expre CLOSECORCH_ OPIGUAL_ expre {
              SIMB sim = obtTdS($1);
              $$.t = T_ERROR;
              if(sim.t==T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if(sim.t!=T_ARRAY){
                     yyerror("La variable debe ser de tipo array.");
              } else if($6.t!=T_ERROR){
                     DIM dim = obtTdA(sim.ref);
                     if($3.t != T_ENTERO){
                            yyerror("El índice del array debe ser un número entero.");
                     }
                     else if(dim.telem!=$6.t){
                            yyerror("Incompatibilidad de tipos en la asignación.");
                     } else{
                            $$.t = dim.telem;
                     }
              }
       }
       | ID_ PUNTO_ ID_ OPIGUAL_ expre {
              SIMB sim = obtTdS($1);
              $$.t = T_ERROR;
              CAMP camp = obtTdR(sim.ref,$3);
              if(sim.t==T_ERROR || camp.t==T_ERROR){
                     yyerror("Objeto no declarado.");
              } else if(sim.t!=T_RECORD){
                     yyerror("La variable no es de tipo struct.");
              }
              else if($5.t!=T_ERROR){
                     if(camp.t!=$5.t){
                            yyerror("Incompatibilidad de tipos en la asignación.");
                     } else{
                            $$.t = $5.t;
                     }
              }
       }
       ;
expreLogic
       : expreIgual {$$.t=$1.t;}
       | expreLogic opLogic expreIgual {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=T_LOGICO || $3.t!=T_LOGICO){
                            yyerror("Error en expresión lógica. Las variables no son de tipo lógico.");
                     }
                     else{
                            $$.t = T_LOGICO;
                     }
              }
       }
       ;
expreIgual
       : expreRel {$$.t=$1.t;}
       | expreIgual opIgual expreRel {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=$3.t){
                            yyerror("Error en expresión de igualdad. Las variables no tienen el mismo tipo.");
                     }
                     else{
                            $$.t = T_LOGICO;
                     }
              }
       }
       ;
expreRel
       : expreAd {$$.t=$1.t;}
       | expreRel opRel expreAd {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=T_ENTERO || $3.t!=T_ENTERO){
                            yyerror("Error en expresión relacional. Las variables no son enteras.");
                     }
                     else{
                            $$.t = T_LOGICO;
                     }
              }
       }
       ;
expreAd
       : expreMul {$$.t=$1.t;}
       | expreAd opAd expreMul {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=T_ENTERO || $3.t!=T_ENTERO){
                            yyerror("Error en expresión aditiva. Las variables no son enteras.");
                     }
                     else{
                            $$.t = $1.t;
                     }
              }
       }
       ;
expreMul
       : expreUna {$$.t=$1.t;}
       | expreMul opMul expreUna {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=T_ENTERO || $3.t!=T_ENTERO){
                            yyerror("Las variables a multiplicar/dividir no son enteras.");
                     }
                     else{
                            $$.t = $1.t;
                     }
              }
       }
       ;
expreUna
       : expreSufi {$$.t=$1.t;}
       | opUna expreUna {
              $$.t=$2.t;
              if($1==OP_NOT && $2.t!=T_LOGICO){
                     yyerror("Error en expresión unaria. La variable no es de tipo lógico.");
                     $$.t=T_ERROR;
              }
       }
       | opIncre ID_ {
              SIMB sim = obtTdS($2);
              $$.t = T_ERROR;
              if(sim.t==T_ERROR){
                     yyerror("Objeto no declarado");
              } else if (sim.t != T_ENTERO){
                     yyerror("Error en expresión unaria. La variable no es entera.");
              }else{
                     $$.t = sim.t;
              }
       }
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
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.t != T_RECORD) {
				yyerror("El identificador debe ser de tipo struct.");
			} else{
              CAMP cam = obtTdR(sim.ref, $3);
              if (cam.t == T_ERROR) {
                     yyerror("No existe ningun campo con ese identificador en ese struct.");
              } else {
                     $$.t = cam.t;
              }
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
			INF inf = obtTdD(sim.ref);
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.c != FUNCION) {
				yyerror("No existe ninguna función con ese identificador.");
			} else if (!cmpDom(sim.ref, $3)) {
                yyerror("Parámetros de la función incorrectos");
			} else {
				$$.t = inf.tipo;
			}
		}
       ;
const
       : CTE_               {$$.t = T_ENTERO;}
       | TRUE_              {$$.t = T_LOGICO;}
       | FALSE_             {$$.t = T_LOGICO;}
       ;
paramAct
       : {$$ = insTdD(-1,T_VACIO);}
       | listParamAct {
              $$ = $1;
       }
       ;
listParamAct
       : expre {
              $$=insTdD(-1, $1.t);
       }
       | expre COMA_ listParamAct {
              $$=insTdD($3, $1.t);
       }
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
