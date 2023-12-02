%{
#include <stdio.h>
#include <string.h>
#include "header.h"
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
%token <cent> CTE_
%token <ident> ID_
%type <cent> tipoSimp
%type <dosv> listCamp listParamForm declaFunc
%type <nt> declaVar
%%

programa
       : listDecla { dvar=0; niv = 0; cargaContexto(niv); }
       ;
listDecla
       : decla
       | listDecla decla {$$ = $1 + $2;}
       ;
decla
       : declaVar {$$ = 0;}
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
		if(!insTdS($5, VARIABLE, $1, niv, dvar, $3.ref1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += $3.ref2 + TALLA_TIPO_SIMPLE;
			$$.nom = $2;
			$$.tipo = $1;
		}
       }
       ;
tipoSimp
       : INT_ {$$ = T_ENTERO;}
       | BOOL_ {$$ = T_LOGICO;}
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
       : tipoSimp ID_ OPENPAR_ paramForm CLOSEPAR_ OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_ {
              niv++; 
              cargaContexto(n); 
              $$.ref1 = dvar; 
              dvar = 0;
              insTdS($2, FUNCION, insTdD( $4.ref1, $1 ), n-1, dvar, -1); //FALTA POR PONER EL TIPO, EL DESPLAZAMIENTO Y EL REF
              if($1 != $10.t) { 
                     yyerror ("Se devuelve un tipo distinto al declarado en la funcion"); 
              }
              if(verTdS) {
                      mostrarTdS(); 
              } 
              descargaContexto(n);
              niv--;
              dvar = $$ref1;
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
       {
              SIMB sim = obtTdS($3);
              if(sim.t == T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if(sim.t != T_ENTERO){
                     yyerror("El objeto a leer no es de tipo entero.");
              }
       }
       | PRINT_ OPENPAR_ expre CLOSEPAR_ SEMICOLON_
       {
              else if($3.t != T_ERROR && $3.t != T_ENTERO){
                     yyerror("El objeto a leer no es de tipo entero.");
              }
       }
       ;
instSelec
       : IF_ OPENPAR_ expre CLOSEPAR_ inst ELSE_ inst
       {
              if($3.t != T_ERROR && $3.t != T_LOGICO){
                     yyerror("La expresión debe ser de tipo lógico.");
              }
       }
       ;
instIter
       : WHILE_ OPENPAR_ expre CLOSEPAR_ inst
       {
              if($3.t != T_ERROR && $3.t!=T_LOGICO){
                     yyerror("La expresión debe ser de tipo lógico.");
              }
       }
       ;
expre
       : expreLogic {$$.t=$1.t;}
       | ID_ OPIGUAL_ expre
              {      
                     SIMB sim = obtTdS($1);
                     if (sim.t == T_ERROR) yyerror("Objeto no declarado");
                     else if (! (((sim.t == T_ENTERO) && ($3.t == T_ENTERO)) || ((sim.t == T_LOGICO) && ($3.t == T_LOGICO))) &&
                                   ($3.t != T_ERROR))
                            yyerror("Error de tipos en la ‘instrucción de asignación’");
              }

       | ID_ OPENCORCH_ expre CLOSECORCH_ OPIGUAL_ expre
              {      
                     SIMB sim = obtTdS($1);
                     DIM dim;
                     if(sim.t != T_ARRAY){
                            yyerror("La variable no es un array, no se puede acceder mediante índices.");
                     }
                     else{
                            dim = obtTdA(sim.ref);
                     }

                     if($3.t != T_ERROR && $6.t != T_ERROR){
                            if(sim.t==T_ERROR){
                                   yyerror("Objeto no declarado");
                            }
                            else if($3.t != T_ENTERO){
                                   yyerror("No se puede acceder al índice puesto que no es un entero 0 o positivo");
                            }
                            else if($6.t != dim.telem){
                                   yyerror("Tipos incompatibles");
                            }
                     }
              }
       | ID_ PUNTO_ ID_ OPIGUAL_ expre
              {
                     SIMB sim = obtTdS($1);
                     CAMP reg;
                     if(sim.t != T_RECORD){
                            yyerror("La variable no es un registro.");
                     }
                     else{
                            reg = obtTdR(sim.ref);
                     }

              }
       ;
expreLogic 
       : expreIgual {$$.t=$1.t;}
       | expreLogic opLogic expreIgual
              {
                     $$.t = T_ERROR;
                     if ($1.t != T_ERROR && $3.t != T_ERROR) {
                            if($1.t != T_LOGICO && $3.t != T_LOGICO){
                                   yyerror("Incompatibilidad de tipos. Ambos deben de ser expresiones lógicas.");
                            }
                            else{
                                   $$.t=T_LOGICO;
                            }
                     }
              }
       ;
expreIgual
       : expreRel {$$.t=$1.t;}
       | expreIgual opIgual expreRel
              {
                     $$.t = T_ERROR;
                     if ($1.t != T_ERROR && $3.t != T_ERROR) {
                            if($1.t != $3.t){
                                   yyerror("Incompatibilidad de tipos. Ambas expresiones deben ser del mismo tipo");
                            }
                            else if($1.t != T_LOGICO && $1.t != T_ENTERO){
                                   yyerror("Incompatibilidad de tipos. Deben ser expresiones lógicas o de enteros.");
                            } else{
                                   $$.t = T_LOGICO;
                            }
                     }
              }
       ;
expreRel
       : expreAd {$$.t=$1.t;}
       | expreRel opRel expreAd
              {
                     $$.t = T_ERROR;
                     if ($1.t != T_ERROR && $3.t != T_ERROR) {
                            if($1.t != T_ENTERO && $3.t != T_ENTERO){
                                   yyerror("Incompatibilidad de tipos. Ambos deben de ser expresiones de enteros.");
                            }
                            else{
                                   $$.t=T_LOGICO;
                            }
                     }
              }
       ;
expreAd
       : expreMul {$$.t=$1.t;}
       | expreAd opAd expreMul
              {
                     $$.t = T_ERROR;
                     if ($1.t != T_ERROR && $3.t != T_ERROR) {
                            if($1.t != T_ENTERO && $3.t != T_ENTERO){
                                   yyerror("Incompatibilidad de tipos. Ambos deben de ser expresiones de enteros.");
                            }
                            else{
                                   $$.t=T_ENTERO;
                            }
                     }
              }
       ;
expreMul
       : expreUna {$$.t=$1.t;}
       | expreMul opMul expreUna
              {
                     $$.t = T_ERROR;
                     if ($1.t != T_ERROR && $3.t != T_ERROR) {
                            if($1.t != T_ENTERO && $3.t != T_ENTERO){
                                   yyerror("Incompatibilidad de tipos. Ambos deben de ser expresiones de enteros.");
                            }
                            else{
                                   $$.t=T_ENTERO;
                            }
                     }
              }
       ;
expreUna 
       : expreSufi {$$.t=$1.t;}
       | opUna expreUna 
              {
                     $$.t = T_ERROR;
                     if ($2.t != T_ERROR) {
                            if($2.t == T_ENTERO){
                                   if($1 == OP_NOT){
                                          yyerror("Incompatibilidad de tipos. No se puede negar un entero.");
                                   }
                                   else{
                                          $$.t = T_ENTERO;
                                   }
                            }
                            else if($2.t == T_LOGICO){
                                   if($1 != OP_NOT){
                                          yyerror("Incompatibilidad de tipos.");
                                   }
                                   else{
                                          $$.t = T_LOGICO;
                                   }
                            }
                            else{
                                   yyerror("Incompatibilidad de tipos. La expresión debe ser lógica o un entero.");
                            }
                     }
              }
       | opIncre ID_
              {
                     SIMB sim = obtTdS($2);
                     $$.t = T_ERROR;
                     if(sim.t==T_ERROR){
                            yyerror("Objeto no declarado");
                     }
                     else if (sim.t != T_ENTERO) {
			       yyerror("Incompatibilidad de tipos, la expresión debe ser entera.");
                     }
                     else {
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
			INF inf = obtTdD(sim.ref);

			if (sim.t == T_ERROR) { 
				yyerror("No existe ninguna variable con ese identificador."); 
			} else if (inf.t == T_ERROR) { 
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
