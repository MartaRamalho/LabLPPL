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
       NT nt;
}

%token OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPAND_ OPDECREASE_ OPIGUAL_ OPINCREASE_ OPNOT_ OPOR_
%token COMPDIF_ COMPIGUAL_ COMPMAYOR_ COMPMAYORIG_ COMPMENOR_ COMPMENORIG_
%token OPENCORCH_ OPENLLAVE_ OPENPAR_ CLOSECORCH_ CLOSELLAVE_ CLOSEPAR_ SEMICOLON_ COMA_ PUNTO_
%token FOR_ IF_ ELSE_ WHILE_ STRUCT_
%token READ_ RETURN_ PRINT_
%token TRUE_ FALSE_ BOOL_
%token <cent> CTE_ INT_
%token <ident> ID_
%type <cent> tipoSimp declaFunc
%type <dosv> listCamp listParamForm paramForm
%type <nt> declaVar
%%

programa
       : listDecla { dvar = 0; niv = 0; cargaContexto(niv); }
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
       : tipoSimp ID_ SEMICOLON_ {
		if(!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += TALLA_TIPO_SIMPLE;
			$$.nom = $2;
			$$.tipo = $1;
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
			$$.nom = $2;
			$$.tipo = $1;
		}
       }
       | STRUCT_ OPENLLAVE_ listCamp CLOSELLAVE_ ID_ SEMICOLON_ {
		if(!insTdS($5, VARIABLE, $3.ref1, niv, dvar, $3.ref1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += $3.ref2 + TALLA_TIPO_SIMPLE;
			$$.nom = $5;
			$$.tipo = $3.ref1;
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
		$$.ref2 = $1.ref2 + TALLA_TIPO_SIMPLE;
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
              insTdS($2, FUNCION, $1, niv-1, dvar, -1); //FALTA POR PONER EL TIPO, EL DESPLAZAMIENTO Y EL REF
         }
         OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_
         {
              if(verTdS) {
                      mostrarTdS();
              }
              descargaContexto(niv);
              niv--;
              dvar = $<cent>$;
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
		insTdS($2, PARAMETRO, $1, niv, -$$.ref2, $$.ref1);
	}
       | tipoSimp ID_ COMA_ listParamForm {
		$$.ref1 = insTdD($4.ref1, $1);
		$$.ref2 = $4.ref2 + TALLA_TIPO_SIMPLE;
		insTdS($2, PARAMETRO, $1, niv, -$$.ref2, $$.ref1);
	}
       ;

declaVarLocal
       :
       | declaVarLocal declaVar {
		insTdS($2.nom, VARIABLE, $2.tipo, niv, dvar, -1);
		dvar += TALLA_SEGENLACES;
       }
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
       : const
       | OPENPAR_ expre CLOSEPAR_
       | ID_
       | ID_ opIncre
       | ID_ PUNTO_ ID_
       | ID_ OPENCORCH_ expre CLOSECORCH_
       | ID_ OPENPAR_ paramAct CLOSEPAR_
       ;
const
       : CTE_
       | TRUE_
       | FALSE_
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
       : OPAND_
       | OPOR_
       ;
opIgual
       : COMPIGUAL_
       | COMPDIF_
       ;
opRel
       : COMPMENOR_
       | COMPMENORIG_
       | COMPMAYOR_
       | COMPMAYORIG_
       ;
opAd 
       : OPSUMA_
       | OPRESTA_
       ;
opMul
       : OPMULT_
       | OPDIV_
       ;
opUna
       : OPSUMA_
       | OPRESTA_
       | OPNOT_
       ;
opIncre
       : OPINCREASE_
       | OPDECREASE_
       ;


%%
