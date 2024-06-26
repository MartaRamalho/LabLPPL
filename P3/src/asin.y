%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"
%}

%union {
       char *ident; /* Nombre del identificador */
       int cent; /* Valor de la cte num´erica entera */
       DOSV dosv;
       TIPO tipo;
       AUX aux;
}

%token OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPAND_ OPDECREASE_ OPIGUAL_ OPINCREASE_ OPNOT_ OPOR_
%token COMPDIF_ COMPIGUAL_ COMPMAYOR_ COMPMAYORIG_ COMPMENOR_ COMPMENORIG_
%token OPENCORCH_ OPENLLAVE_ OPENPAR_ CLOSECORCH_ CLOSELLAVE_ CLOSEPAR_ SEMICOLON_ COMA_ PUNTO_
%token FOR_ IF_ ELSE_ WHILE_ STRUCT_
%token READ_ RETURN_ PRINT_
%token TRUE_ FALSE_ BOOL_
%token <cent> CTE_ INT_
%token <ident> ID_
%type <cent> tipoSimp declaFunc listDecla decla opIncre opUna opMul opAd opRel opIgual opLogic listParamAct paramAct instSelec instIter
%type <dosv> listCamp listParamForm paramForm
%type <tipo> const expreSufi expre expreLogic expreAd expreIgual expreMul expreRel expreUna

%%

programa
       : {
              dvar = 0; niv = 0; si=0;
              cargaContexto(niv);
              $<aux>$.r1 = creaLans(si);
              emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
              $<aux>$.r2 = creaLans(si);
              emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));

       } listDecla
       {
              if($2 >= 0){
                     yyerror("No hay una función main");
              } else if ($2 < -1) {
                     yyerror("Hay más de una función main");
              }

              completaLans($<aux>1.r1, crArgEnt(dvar));

              SIMB sim = obtTdS("main");
              $<aux>$.r3 = sim.d;

              completaLans($<aux>1.r2, crArgEtq($<aux>$.r3));
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
              if(!insTdS($2, FUNCION, $1, niv-1, si, $5.ref1)){
                     yyerror("Identificador de la función repetido.");
              }
              emite(PUSHFP,crArgNul(),crArgNul(),crArgNul());
              emite(FPTOP,crArgNul(),crArgNul(),crArgNul());
              $<cent>$=creaLans(si);
              emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1));
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
              SIMB sim = obtTdS($2);
              INF inf = obtTdD(sim.ref);
              int dvr=TALLA_SEGENLACES+inf.tsp+TALLA_TIPO_SIMPLE;
              emite(EASIG, crArgPos(niv, $12.d), crArgNul(), crArgPos(niv, -dvr));
              completaLans($<cent>7,crArgEnt(dvar));
              emite(TOPFP,crArgNul(),crArgNul(),crArgNul());
              emite(FPPOP,crArgNul(),crArgNul(),crArgNul());

              if ($$ == -1) { emite(FIN, crArgNul(), crArgNul(), crArgNul()); }
              else { emite(RET, crArgNul(), crArgNul(), crArgNul()); }

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
		//emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv,$$.ref2)); esto estaba muy mal, es en paramAct, no form
       }
       | tipoSimp ID_ COMA_{
              //emite(EPUSH,crArgNul(),crArgNul(),crArgEnt(TALLA_TIPO_SIMPLE));
       }listParamForm {
		$$.ref1 = insTdD($5.ref1, $1);
		$$.ref2 = $5.ref2 + TALLA_TIPO_SIMPLE;
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
              emite(EREAD, crArgNul(), crArgNul(),crArgPos(sim.n , sim.d));
       }
       | PRINT_ OPENPAR_ expre CLOSEPAR_ SEMICOLON_{

              if( $3.t != T_ERROR && $3.t != T_ENTERO){
                      yyerror("El argumento del 'print' no es de tipo entero.");
              }
              emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.d));
       }
       ;
instSelec
       : IF_ OPENPAR_ expre CLOSEPAR_
       {
              if($3.t!=T_ERROR && $3.t!=T_LOGICO){
                     yyerror("La expresión del 'if' debe ser de tipo lógico.");
              }
              $<cent>$=creaLans(si); //lf
              emite(EIGUAL,crArgPos(niv, $3.d),crArgEnt(0), crArgEtq(-1));
       }
       inst {
              $<cent>$=creaLans(si); //fin
              emite(GOTOS,crArgNul(),crArgNul(), crArgEtq(-1));
              completaLans($<cent>5,crArgEnt(si));
       }
       ELSE_ inst {
              completaLans($<cent>7,crArgEnt(si));
       }
       ;
instIter
       : WHILE_{
              $<cent>$=si;
       }
       OPENPAR_ expre CLOSEPAR_ {
              if($4.t!=T_ERROR && $4.t!=T_LOGICO){
                     yyerror("La expresión del 'while' debe ser de tipo lógico.");
              }
              $<cent>$=creaLans(si); //lf
              emite(EIGUAL,crArgPos(niv, $4.d),crArgEnt(0), crArgEtq(-1));
              }
       inst {
              emite(GOTOS,crArgNul(),crArgNul(), crArgEtq($<cent>2));
              completaLans($<cent>6,crArgEnt(si));
       }
       ;
expre
       : expreLogic {$$.t=$1.t;$$.d=$1.d;}
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
       $$.d = creaVarTemp();
       emite(EASIG,crArgPos(niv, $3.d),crArgNul(), crArgPos(sim.n,sim.d));
       emite(EASIG, crArgPos(sim.n,sim.d), crArgNul(), crArgPos(niv, $$.d));

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
                            $$.d = creaVarTemp();
                            emite(EVA,crArgPos(sim.n,sim.d), crArgPos(niv,$3.d),  crArgPos(niv,$6.d));
                            emite(EASIG, crArgPos(niv, $6.d), crArgNul(), crArgPos(niv, $$.d));
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
                            $$.d = creaVarTemp();
                            emite(EASIG,crArgPos(niv, $5.d),crArgNul(), crArgPos(sim.n,sim.d + camp.d));
                            emite(EASIG, crArgPos(sim.n,sim.d + camp.d), crArgNul(), crArgPos(niv, $$.d));
                     }
              }
       }
       ;
expreLogic
       : expreIgual {$$.t=$1.t;$$.d=$1.d;}
       | expreLogic opLogic expreIgual {
              $$.t = T_ERROR;
              if($1.t!=T_ERROR && $3.t!=T_ERROR){
                     if($1.t!=T_LOGICO || $3.t!=T_LOGICO){
                            yyerror("Error en expresión lógica. Las variables no son de tipo lógico.");
                     }
                     else{
                            $$.t = T_LOGICO;
                            $$.d = creaVarTemp();
                            emite($2,crArgPos(niv,$1.d),crArgPos(niv,$3.d), crArgPos(niv,$$.d));
                            emite(EMENEQ,crArgPos(niv,$$.d),crArgEnt(1), crArgEtq(si+2));
                            emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv,$$.d));
                     }
              }
       }
       ;
expreIgual
       : expreRel {$$.t=$1.t;$$.d=$1.d;}
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
		$$.d = creaVarTemp();
		emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv,$$.d));
		emite($2,crArgPos(niv,$1.d),crArgPos(niv,$3.d), crArgEtq(si+2));
		emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv,$$.d));
       }
       ;
expreRel
       : expreAd {$$.t=$1.t;$$.d=$1.d;}
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
		$$.d = creaVarTemp();
		emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv,$$.d));
		emite($2,crArgPos(niv,$1.d),crArgPos(niv,$3.d), crArgEtq(si+2));
		emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv,$$.d));
       }
       ;
expreAd
       : expreMul {$$.t=$1.t; $$.d=$1.d;}
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
		$$.d = creaVarTemp();
		emite($2,crArgPos(niv,$1.d),crArgPos(niv,$3.d), crArgPos(niv,$$.d));
       }
       ;
expreMul
       : expreUna {$$.t=$1.t; $$.d=$1.d;}
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
		$$.d = creaVarTemp();
		emite($2,crArgPos(niv,$1.d),crArgPos(niv,$3.d), crArgPos(niv,$$.d));
       }
       ;
expreUna
       : expreSufi {$$.t=$1.t; $$.d=$1.d;}
       | opUna expreUna {
              $$.t=$2.t;
              if($1==OP_NOT && $2.t!=T_LOGICO){
                     yyerror("Error en expresión unaria. La variable no es de tipo lógico.");
                     $$.t=T_ERROR;
              } else if(($1 == OP_MAS || $1 == OP_MENOS) && $2.t != T_ENTERO){
                     yyerror("Error en expresión unaria. La variable no es de tipo entero.");
                     $$.t=T_ERROR;
              }
              $$.d = creaVarTemp();
              if ($1==OP_NOT){
                     emite(EDIF,crArgEnt(1),crArgPos(niv,$2.d), crArgPos(niv,$$.d));
              } else if ($1 == OP_MENOS) {
                     emite(ESIG,crArgPos(niv,$2.d),crArgNul(), crArgPos(niv,$$.d));
              } else {
                     $$.d = $2.d;
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
		$$.d = creaVarTemp();
		emite($1,crArgPos(sim.n,sim.d),crArgEnt(1), crArgPos(sim.n,sim.d));
		emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, $$.d));
       }
       ;
expreSufi
       : const                    {
		$$.t = $1.t;
		$$.d = creaVarTemp();
		emite( EASIG , crArgEnt($1.d) , crArgNul() , crArgPos(niv,$$.d));
	}
       | OPENPAR_ expre CLOSEPAR_ {
              $$.t = $2.t;
              $$.d=$2.d;
       }
       | ID_
              {
              $$.t = T_ERROR;
              SIMB sim = obtTdS($1);
              if (sim.t == T_ERROR) {
                     yyerror("No existe ninguna variable con ese identificador.");
              } else {
                     $$.t = sim.t;
		     $$.d = creaVarTemp();
		     emite( EASIG , crArgPos(sim.n , sim.d) , crArgNul() , crArgPos(niv , $$.d));
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
			$$.d = creaVarTemp();
			emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, $$.d));
			emite($2, crArgPos(sim.n, sim.d), crArgEnt(1), crArgPos(sim.n,sim.d));
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
                                   $$.d = creaVarTemp();
                                   emite(EASIG,crArgPos(sim.n,sim.d + cam.d),crArgPos(niv,cam.d), crArgPos(niv,$$.d));
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
                //emite(EMULT, crArgPos(niv,$3.d),crArgEnt(TALLA_TIPO_SIMPLE), crArgPos(niv,$3.d));

			}
			$$.d = creaVarTemp();
            emite(EAV,crArgPos(sim.n,sim.d), crArgPos(niv,$3.d),  crArgPos(niv,$$.d));
		}
       | ID_ {

              emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(TALLA_TIPO_SIMPLE));
       }
       OPENPAR_ paramAct CLOSEPAR_
       {
              $$.t = T_ERROR;
              SIMB sim = obtTdS($1);
              INF inf = obtTdD(sim.ref);
              if (sim.t == T_ERROR) {
                     yyerror("No existe ninguna variable con ese identificador.");
              } else if (sim.c != FUNCION) {
                     yyerror("No existe ninguna función con ese identificador.");
              }
			 if (!cmpDom(sim.ref, $4)) {
                		yyerror("Parámetros de la función incorrectos");
			} else {
				$$.t = inf.tipo;
			}
			//emite(EPUSH,crArgNul(),crArgNul(),crArgEnt(si+2));
			emite(CALL,crArgNul(),crArgNul(),crArgEnt(sim.d));
			emite(DECTOP,crArgNul(),crArgNul(),crArgEnt(inf.tsp));
			$$.d=creaVarTemp();
			emite(EPOP,crArgNul(),crArgNul(),crArgPos(niv,$$.d));
		}
       ;
const
       : CTE_               {$$.t = T_ENTERO; $$.d = $1;}
       | TRUE_              {$$.t = T_LOGICO; $$.d = 1;}
       | FALSE_             {$$.t = T_LOGICO; $$.d = 0;}
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
              emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv,$1.d));
       }
       | expre COMA_{
              emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv,$1.d));
       } listParamAct {
              $$=insTdD($4, $1.t);
       }
       ;
opLogic
       : OPAND_              {$$ = EMULT;}
       | OPOR_               {$$ = ESUM;}
       ;
opIgual
       : COMPIGUAL_          {$$ = EIGUAL;}
       | COMPDIF_            {$$ = EDIST;}
       ;
opRel
       : COMPMENOR_          {$$ = EMEN;}
       | COMPMENORIG_        {$$ = EMENEQ;}
       | COMPMAYOR_          {$$ = EMAY;}
       | COMPMAYORIG_        {$$ = EMAYEQ;}
       ;
opAd
       : OPSUMA_             {$$ = ESUM;}
       | OPRESTA_            {$$ = EDIF;}
       ;
opMul
       : OPMULT_             {$$ = EMULT;}
       | OPDIV_              {$$ = EDIVI;}
       ;
opUna
       : OPSUMA_             {$$ = OP_MAS;}
       | OPRESTA_            {$$ = OP_MENOS;}
       | OPNOT_              {$$ = OP_NOT;}
       ;
opIncre
       : OPINCREASE_         {$$ = ESUM;}
       | OPDECREASE_         {$$ = EDIF;}
       ;
%%
