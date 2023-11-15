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
       : INT_
       | BOOL_
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
