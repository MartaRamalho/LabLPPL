/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras donde situar las           **/
/** definiciones de constantes, variables y estructuras para MenosC. Los    **/
/** alumnos deberan adaptarlo al desarrollo de su propio compilador.    **/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define TALLA_TIPO_SIMPLE 1
#define TALLA_SEGENLACES 2

#define OP_NOT 0
#define OP_MAS 1
#define OP_MENOS 2
#define OP_MULT 3
#define OP_DIV 4
#define OP_INCR 5
#define OP_DECR 6
#define OP_MAYOR 7
#define OP_MENOR 8
#define OP_MAYORIG 9
#define OP_MENORIG 10
#define OP_IGUAL 11
#define OP_NOTIGUAL 12
#define OP_OR 13
#define OP_AND 14
/****************************************************** Structuras */

typedef struct dosv  /* Estructura para las referencias prima */
{
  int   ref1;                                      /*  */
  int   ref2;                                      /*  */
} DOSV;
typedef struct tipo  /* Estructura para las funciones                         */
{
  int   t;                            /* Tipo del rango de la funcion     */
  int   d;
}TIPO;

typedef struct aux  /* Estructura para las funciones                         */
{
  int   r1;                            /* Tipo del rango de la funcion     */
  int   r2;
  int   r3;
}AUX;



/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */
extern int verTdS;

#endif  /* _HEADER_H */
/*****************************************************************************/
