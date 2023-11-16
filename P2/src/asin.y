%{
#include <stdio.h>
#include <string.h>
#include "header.h"
%}

%union {
       char *ident; /* Nombre del identificador */
       int cent; /* Valor de la cte num´erica entera */
}

%token OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPAND_ OPDECREASE_ OPIGUAL_ OPINCREASE_ OPNOT_ OPOR_ 
%token COMPDIF_ COMPIGUAL_ COMPMAYOR_ COMPMAYORIG_ COMPMENOR_ COMPMENORIG_
%token OPENCORCH_ OPENLLAVE_ OPENPAR_ CLOSECORCH_ CLOSELLAVE_ CLOSEPAR_ SEMICOLON_ COMA_ PUNTO_
%token FOR_ IF_ ELSE_ WHILE_ STRUCT_
%token READ_ RETURN_ PRINT_ 
%token TRUE_ FALSE_ BOOL_
%token <cent> CTE_
%token <ident> ID_
%type <cent> tipoSimp

%%

programa
       : listDecla
       ;
listDecla
       : decla
       | listDecla decla
       ;
decla
       : declaVar
       | declaFunc
       ;
declaVar
       : tipoSimp ID_ SEMICOLON_
       | tipoSimp ID_ OPENCORCH_ CTE_ CLOSECORCH_ SEMICOLON_
       | STRUCT_ OPENLLAVE_ listCamp CLOSELLAVE_ ID_ SEMICOLON_
       ;
tipoSimp
       : INT_ {$$ = T_ENTERO;}
       | BOOL_ {$$ = T_LOGICO;}
       ;
listCamp
       : tipoSimp ID_ SEMICOLON_ 
       | listCamp tipoSimp ID_ SEMICOLON_
       ;
declaFunc
       : tipoSimp ID_ OPENPAR_ paramForm CLOSEPAR_ OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_
       ;
paramForm
       : 
       | listParamForm
       ;
listParamForm
       : tipoSimp ID_
       | tipoSimp ID_ COMA_ listParamForm
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
			/* Falta hacer el resto de este */
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
			}
			if (inf.t == T_ERROR) { 
				yyerror("No existe ninguna funcion con ese identificador."); 
			} else {
				$$.t = inf.t;
			}
		}
       ;
const
       : CTE_               {$$.t = T_ENTERO} 
       | TRUE_              {$$.t = T_LOGICO}  
       | FALSE_             {$$.t = T_LOGICO}  
       ;
paramAct
       :
       | listParamAct      
       ;
listParamAct			/* Comprobar el tema de los guiones */
       : expre           
		// {
		// 		$$.ref = insTdD(-1, $1);
		// 		$$.t = TALLA_TIPO_SIMPLE;
		// }
       | expre COMA_ listParamAct       
		// {
		// 	INF inf = obtTdD($3) 
		// 	if(inf.t == T_ERROR){
		// 		yyerror("Error en los parámetros actuales");
		// 	}
		// 	else{
		// 		$$.ref = $3.ref;
		// 		$$.t = $3.t + TALLA_TIPO_SIMPLE;
		// 	}
		// }
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
