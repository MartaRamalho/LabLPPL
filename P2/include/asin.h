/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OPSUMA_ = 258,                 /* OPSUMA_  */
    OPRESTA_ = 259,                /* OPRESTA_  */
    OPMULT_ = 260,                 /* OPMULT_  */
    OPDIV_ = 261,                  /* OPDIV_  */
    OPAND_ = 262,                  /* OPAND_  */
    OPDECREASE_ = 263,             /* OPDECREASE_  */
    OPIGUAL_ = 264,                /* OPIGUAL_  */
    OPINCREASE_ = 265,             /* OPINCREASE_  */
    OPNOT_ = 266,                  /* OPNOT_  */
    OPOR_ = 267,                   /* OPOR_  */
    COMPDIF_ = 268,                /* COMPDIF_  */
    COMPIGUAL_ = 269,              /* COMPIGUAL_  */
    COMPMAYOR_ = 270,              /* COMPMAYOR_  */
    COMPMAYORIG_ = 271,            /* COMPMAYORIG_  */
    COMPMENOR_ = 272,              /* COMPMENOR_  */
    COMPMENORIG_ = 273,            /* COMPMENORIG_  */
    OPENCORCH_ = 274,              /* OPENCORCH_  */
    OPENLLAVE_ = 275,              /* OPENLLAVE_  */
    OPENPAR_ = 276,                /* OPENPAR_  */
    CLOSECORCH_ = 277,             /* CLOSECORCH_  */
    CLOSELLAVE_ = 278,             /* CLOSELLAVE_  */
    CLOSEPAR_ = 279,               /* CLOSEPAR_  */
    SEMICOLON_ = 280,              /* SEMICOLON_  */
    COMA_ = 281,                   /* COMA_  */
    PUNTO_ = 282,                  /* PUNTO_  */
    FOR_ = 283,                    /* FOR_  */
    IF_ = 284,                     /* IF_  */
    ELSE_ = 285,                   /* ELSE_  */
    WHILE_ = 286,                  /* WHILE_  */
    STRUCT_ = 287,                 /* STRUCT_  */
    READ_ = 288,                   /* READ_  */
    RETURN_ = 289,                 /* RETURN_  */
    PRINT_ = 290,                  /* PRINT_  */
    TRUE_ = 291,                   /* TRUE_  */
    FALSE_ = 292,                  /* FALSE_  */
    BOOL_ = 293,                   /* BOOL_  */
    CTE_ = 294,                    /* CTE_  */
    INT_ = 295,                    /* INT_  */
    ID_ = 296                      /* ID_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "src/asin.y"

       char *ident; /* Nombre del identificador */
       int cent; /* Valor de la cte num´erica entera */
       DOSV dosv;
       TIPO tipo;

#line 112 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
