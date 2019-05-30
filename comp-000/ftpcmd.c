
/*  A Bison parser, made from ftpcmd.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	A	258
#define	B	259
#define	C	260
#define	E	261
#define	F	262
#define	I	263
#define	L	264
#define	N	265
#define	P	266
#define	R	267
#define	S	268
#define	T	269
#define	SP	270
#define	CRLF	271
#define	COMMA	272
#define	STRING	273
#define	NUMBER	274
#define	USER	275
#define	PASS	276
#define	ACCT	277
#define	REIN	278
#define	QUIT	279
#define	PORT	280
#define	PASV	281
#define	TYPE	282
#define	STRU	283
#define	MODE	284
#define	RETR	285
#define	STOR	286
#define	APPE	287
#define	MLFL	288
#define	MAIL	289
#define	MSND	290
#define	MSOM	291
#define	MSAM	292
#define	MRSQ	293
#define	MRCP	294
#define	ALLO	295
#define	REST	296
#define	RNFR	297
#define	RNTO	298
#define	ABOR	299
#define	DELE	300
#define	CWD	301
#define	LIST	302
#define	NLST	303
#define	SITE	304
#define	STAT	305
#define	HELP	306
#define	NOOP	307
#define	MKD	308
#define	RMD	309
#define	PWD	310
#define	CDUP	311
#define	STOU	312
#define	SMNT	313
#define	SYST	314
#define	SIZE	315
#define	MDTM	316
#define	UMASK	317
#define	IDLE	318
#define	CHMOD	319
#define	LEXERR	320

#line 41 "ftpcmd.y"


#ifndef lint
/*static char sccsid[] = "from: @(#)ftpcmd.y	5.24 (Berkeley) 2/25/91";*/
static char rcsid[] = "$Id: ftpcmd.y,v 1.1 1997/12/27 12:52:15 root Exp $";
#endif /* not lint */

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/ftp.h>
#include <signal.h>
#include <setjmp.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

extern	struct sockaddr_in data_dest;
extern	int logged_in;
extern	struct passwd *pw;
extern	int guest;
extern	int logging;
extern	int type;
extern	int form;
extern	int debug;
extern	int timeout;
extern	int maxtimeout;
extern  int pdata;
extern	char hostname[], remotehost[];
extern	char proctitle[];
extern	char *globerr;
extern	int usedefault;
extern  int transflag;
extern  char tmpline[];
char	**ftpglob();

off_t	restart_point;

static	int cmd_type;
static	int cmd_form;
static	int cmd_bytesz;
char	cbuf[512];
char	*fromname;

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		205
#define	YYFLAG		-32768
#define	YYNTBASE	66

#define YYTRANSLATE(x) ((unsigned)(x) <= 320 ? yytranslate[x] : 81)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     7,    12,    17,    22,    25,    30,    35,
    40,    45,    54,    60,    66,    72,    76,    82,    86,    92,
    98,   101,   107,   112,   115,   119,   125,   128,   133,   136,
   142,   148,   152,   156,   161,   168,   174,   182,   192,   197,
   204,   210,   213,   219,   225,   228,   231,   237,   242,   244,
   245,   247,   249,   261,   263,   265,   267,   269,   273,   275,
   279,   281,   283,   287,   290,   292,   294,   296,   298,   300,
   302,   304,   306,   308
};

static const short yyrhs[] = {    -1,
    66,    67,     0,    66,    68,     0,    20,    15,    69,    16,
     0,    21,    15,    70,    16,     0,    25,    15,    72,    16,
     0,    26,    16,     0,    27,    15,    74,    16,     0,    28,
    15,    75,    16,     0,    29,    15,    76,    16,     0,    40,
    15,    19,    16,     0,    40,    15,    19,    15,    12,    15,
    19,    16,     0,    30,    80,    15,    77,    16,     0,    31,
    80,    15,    77,    16,     0,    32,    80,    15,    77,    16,
     0,    48,    80,    16,     0,    48,    80,    15,    18,    16,
     0,    47,    80,    16,     0,    47,    80,    15,    77,    16,
     0,    50,    80,    15,    77,    16,     0,    50,    16,     0,
    45,    80,    15,    77,    16,     0,    43,    15,    77,    16,
     0,    44,    16,     0,    46,    80,    16,     0,    46,    80,
    15,    77,    16,     0,    51,    16,     0,    51,    15,    18,
    16,     0,    52,    16,     0,    53,    80,    15,    77,    16,
     0,    54,    80,    15,    77,    16,     0,    55,    80,    16,
     0,    56,    80,    16,     0,    49,    15,    51,    16,     0,
    49,    15,    51,    15,    18,    16,     0,    49,    15,    62,
    80,    16,     0,    49,    15,    62,    80,    15,    79,    16,
     0,    49,    15,    64,    80,    15,    79,    15,    77,    16,
     0,    49,    15,    63,    16,     0,    49,    15,    63,    15,
    19,    16,     0,    57,    80,    15,    77,    16,     0,    59,
    16,     0,    60,    80,    15,    77,    16,     0,    61,    80,
    15,    77,    16,     0,    24,    16,     0,     1,    16,     0,
    42,    80,    15,    77,    16,     0,    41,    15,    71,    16,
     0,    18,     0,     0,    18,     0,    19,     0,    19,    17,
    19,    17,    19,    17,    19,    17,    19,    17,    19,     0,
    10,     0,    14,     0,     5,     0,     3,     0,     3,    15,
    73,     0,     6,     0,     6,    15,    73,     0,     8,     0,
     9,     0,     9,    15,    71,     0,     9,    71,     0,     7,
     0,    12,     0,    11,     0,    13,     0,     4,     0,     5,
     0,    78,     0,    18,     0,    19,     0,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   116,   117,   122,   125,   130,   135,   144,   148,   183,   195,
   207,   211,   215,   222,   229,   236,   241,   248,   281,   288,
   295,   299,   306,   317,   321,   326,   333,   337,   352,   356,
   364,   371,   376,   381,   385,   389,   399,   414,   428,   434,
   448,   455,   476,   493,   515,   522,   527,   539,   550,   553,
   557,   560,   563,   576,   580,   584,   590,   595,   600,   605,
   610,   614,   619,   625,   632,   636,   640,   646,   650,   654,
   660,   679,   682,   707
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","A","B",
"C","E","F","I","L","N","P","R","S","T","SP","CRLF","COMMA","STRING","NUMBER",
"USER","PASS","ACCT","REIN","QUIT","PORT","PASV","TYPE","STRU","MODE","RETR",
"STOR","APPE","MLFL","MAIL","MSND","MSOM","MSAM","MRSQ","MRCP","ALLO","REST",
"RNFR","RNTO","ABOR","DELE","CWD","LIST","NLST","SITE","STAT","HELP","NOOP",
"MKD","RMD","PWD","CDUP","STOU","SMNT","SYST","SIZE","MDTM","UMASK","IDLE","CHMOD",
"LEXERR","cmd_list","cmd","rcmd","username","password","byte_size","host_port",
"form_code","type_code","struct_code","mode_code","pathname","pathstring","octal_number",
"check_login", NULL
};
#endif

static const short yyr1[] = {     0,
    66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    68,    68,    69,    70,
    70,    71,    72,    73,    73,    73,    74,    74,    74,    74,
    74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
    77,    78,    79,    80
};

static const short yyr2[] = {     0,
     0,     2,     2,     4,     4,     4,     2,     4,     4,     4,
     4,     8,     5,     5,     5,     3,     5,     3,     5,     5,
     2,     5,     4,     2,     3,     5,     2,     4,     2,     5,
     5,     3,     3,     4,     6,     5,     7,     9,     4,     6,
     5,     2,     5,     5,     2,     2,     5,     4,     1,     0,
     1,     1,    11,     1,     1,     1,     1,     3,     1,     3,
     1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     0
};

static const short yydefact[] = {     1,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    74,    74,    74,     0,     0,    74,     0,     0,    74,    74,
    74,    74,     0,    74,     0,     0,    74,    74,    74,    74,
    74,     0,    74,    74,     2,     3,    46,     0,    50,    45,
     0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    24,     0,     0,     0,     0,     0,    21,     0,
     0,    27,    29,     0,     0,     0,     0,     0,    42,     0,
     0,    49,     0,    51,     0,     0,     0,    57,    59,    61,
    62,     0,    65,    67,    66,     0,    69,    70,    68,     0,
     0,     0,     0,     0,    52,     0,     0,    72,     0,    71,
     0,     0,    25,     0,    18,     0,    16,     0,    74,     0,
    74,     0,     0,     0,     0,    32,    33,     0,     0,     0,
     4,     5,     0,     6,     0,     0,     0,    64,     8,     9,
    10,     0,     0,     0,     0,    11,    48,     0,    23,     0,
     0,     0,     0,     0,    34,     0,     0,    39,     0,     0,
    28,     0,     0,     0,     0,     0,     0,    56,    54,    55,
    58,    60,    63,    13,    14,    15,     0,    47,    22,    26,
    19,    17,     0,     0,    36,     0,     0,    20,    30,    31,
    41,    43,    44,     0,     0,    35,    73,     0,    40,     0,
     0,     0,    37,     0,     0,    12,     0,     0,    38,     0,
     0,     0,    53,     0,     0
};

static const short yydefgoto[] = {     1,
    35,    36,    73,    75,    96,    77,   161,    82,    86,    90,
    99,   100,   188,    46
};

static const short yypact[] = {-32768,
    35,   -11,    -8,    -3,    25,     5,    38,    57,    82,    86,
-32768,-32768,-32768,    95,    96,-32768,    97,    98,-32768,-32768,
-32768,-32768,   100,   101,    10,   102,-32768,-32768,-32768,-32768,
-32768,   103,-32768,-32768,-32768,-32768,-32768,     1,   104,-32768,
    94,-32768,    65,    46,     4,   105,   106,   108,   107,   109,
   110,   112,-32768,   116,    17,    28,    54,   -48,-32768,   117,
   115,-32768,-32768,   119,   120,   121,   122,   124,-32768,   125,
   126,-32768,   127,-32768,   128,    99,   129,   131,   132,-32768,
     3,   133,-32768,-32768,-32768,   134,-32768,-32768,-32768,   135,
   112,   112,   112,    84,-32768,   136,   112,-32768,   137,-32768,
   112,   112,-32768,   112,-32768,   118,-32768,    89,-32768,    91,
-32768,   112,   138,   112,   112,-32768,-32768,   112,   112,   112,
-32768,-32768,   123,-32768,    88,    88,   109,-32768,-32768,-32768,
-32768,   139,   140,   141,   146,-32768,-32768,   143,-32768,   144,
   145,   147,   148,   130,-32768,    93,   149,-32768,   150,   151,
-32768,   153,   154,   155,   156,   157,   158,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   159,-32768,-32768,-32768,
-32768,-32768,   160,   161,-32768,   162,   161,-32768,-32768,-32768,
-32768,-32768,-32768,   163,   164,-32768,-32768,   165,-32768,   169,
   168,   170,-32768,   112,   171,-32768,   172,   174,-32768,   173,
   176,   175,-32768,   166,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,   -77,-32768,    -2,-32768,-32768,-32768,
   -91,-32768,   -15,    18
};


#define	YYLAST		194


static const short yytable[] = {   132,
   133,   134,   108,   128,    37,   138,    38,    87,    88,   140,
   141,    39,   142,   109,   110,   111,    89,   127,    72,    41,
   150,    95,   152,   153,    61,    62,   154,   155,   156,    47,
    48,   102,   103,    51,   204,     2,    54,    55,    56,    57,
    40,    60,   104,   105,    64,    65,    66,    67,    68,   163,
    70,    71,    83,    42,     3,     4,    84,    85,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    78,   106,   107,
    79,    43,    80,    81,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    30,    31,   158,    32,    33,    34,    44,   159,   135,   136,
    45,   160,   197,   144,   145,   147,   148,   174,   175,    49,
    50,    52,    76,    53,    58,   123,    59,    63,    69,    91,
    92,    74,    93,   162,    97,    94,   146,    95,   149,    98,
   101,   112,   113,   114,   115,   143,   116,   117,   118,   119,
   120,   157,   121,   122,   124,   125,   126,   173,   129,   130,
   131,   137,   139,   151,   164,   165,   166,   167,   168,   169,
   170,   190,   171,   172,   177,   205,   178,   176,   179,   180,
   181,   182,   183,   185,   184,   186,     0,   189,     0,   187,
   193,   191,   192,   194,   195,   196,     0,   199,     0,   198,
   200,   201,   202,   203
};

static const short yycheck[] = {    91,
    92,    93,    51,    81,    16,    97,    15,     4,     5,   101,
   102,    15,   104,    62,    63,    64,    13,    15,    18,    15,
   112,    19,   114,   115,    15,    16,   118,   119,   120,    12,
    13,    15,    16,    16,     0,     1,    19,    20,    21,    22,
    16,    24,    15,    16,    27,    28,    29,    30,    31,   127,
    33,    34,     7,    16,    20,    21,    11,    12,    24,    25,
    26,    27,    28,    29,    30,    31,    32,     3,    15,    16,
     6,    15,     8,     9,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,     5,    59,    60,    61,    15,    10,    15,    16,
    15,    14,   194,    15,    16,    15,    16,    15,    16,    15,
    15,    15,    19,    16,    15,    17,    16,    16,    16,    15,
    15,    18,    15,   126,    15,    19,   109,    19,   111,    18,
    15,    15,    18,    15,    15,    18,    16,    16,    15,    15,
    15,    19,    16,    16,    16,    15,    15,    18,    16,    16,
    16,    16,    16,    16,    16,    16,    16,    12,    16,    16,
    16,   177,    16,    16,    15,     0,    16,    19,    16,    16,
    16,    16,    16,    15,    17,    16,    -1,    16,    -1,    19,
    16,    19,    19,    15,    17,    16,    -1,    16,    -1,    19,
    17,    19,    17,    19
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 118 "ftpcmd.y"
{
			fromname = (char *) 0;
			restart_point = (off_t) 0;
		;
    break;}
case 4:
#line 126 "ftpcmd.y"
{
			user((char *) yyvsp[-1]);
			free((char *) yyvsp[-1]);
		;
    break;}
case 5:
#line 131 "ftpcmd.y"
{
			pass((char *) yyvsp[-1]);
			free((char *) yyvsp[-1]);
		;
    break;}
case 6:
#line 136 "ftpcmd.y"
{
			usedefault = 0;
			if (pdata >= 0) {
				(void) close(pdata);
				pdata = -1;
			}
			reply(200, "PORT command successful.");
		;
    break;}
case 7:
#line 145 "ftpcmd.y"
{
			passive();
		;
    break;}
case 8:
#line 149 "ftpcmd.y"
{
			switch (cmd_type) {

			case TYPE_A:
				if (cmd_form == FORM_N) {
					reply(200, "Type set to A.");
					type = cmd_type;
					form = cmd_form;
				} else
					reply(504, "Form must be N.");
				break;

			case TYPE_E:
				reply(504, "Type E not implemented.");
				break;

			case TYPE_I:
				reply(200, "Type set to I.");
				type = cmd_type;
				break;

			case TYPE_L:
#if NBBY == 8
				if (cmd_bytesz == 8) {
					reply(200,
					    "Type set to L (byte size 8).");
					type = cmd_type;
				} else
					reply(504, "Byte size must be 8.");
#else /* NBBY == 8 */
				UNIMPLEMENTED for NBBY != 8
#endif /* NBBY == 8 */
			}
		;
    break;}
case 9:
#line 184 "ftpcmd.y"
{
			switch (yyvsp[-1]) {

			case STRU_F:
				reply(200, "STRU F ok.");
				break;

			default:
				reply(504, "Unimplemented STRU type.");
			}
		;
    break;}
case 10:
#line 196 "ftpcmd.y"
{
			switch (yyvsp[-1]) {

			case MODE_S:
				reply(200, "MODE S ok.");
				break;

			default:
				reply(502, "Unimplemented MODE type.");
			}
		;
    break;}
case 11:
#line 208 "ftpcmd.y"
{
			reply(202, "ALLO command ignored.");
		;
    break;}
case 12:
#line 212 "ftpcmd.y"
{
			reply(202, "ALLO command ignored.");
		;
    break;}
case 13:
#line 216 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				retrieve((char *) 0, (char *) yyvsp[-1], 1);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 14:
#line 223 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				_store((char *) yyvsp[-1], "w+", 0);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 15:
#line 230 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				_store((char *) yyvsp[-1], "a", 0);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 16:
#line 237 "ftpcmd.y"
{
			if (yyvsp[-1])
				send_file_list(".");
		;
    break;}
case 17:
#line 242 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL) 
				send_file_list((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 18:
#line 249 "ftpcmd.y"
{
			if (yyvsp[-1])
			{
			  int loop;
			  extern char **dlist;
			  extern char *home;
			  extern char *getwd();
			  
			  char path[MAXPATHLEN + 1];
			  
			  if (getwd(path) == (char *)NULL)
			         path[0]  = '\0';
			  /* are we at home ? */
			  if(strncmp(path, home, strlen(home) ))
			  {
			    /* print normal output */
			    retrieve("/bin/ls -l", "", 1);
			  }
			  else
			  {
			    /* print virtual directories */
			    retrieve("/bin/ls -l", "", 2);
			    do_virtual();
			  }
			  //else
			  //{
			  // Recursive download error
			  // retrieve("/bin/ls -ld %s", home, 3);
			  // }
			 }
			
		;
    break;}
case 19:
#line 282 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				retrieve("/bin/ls -lA %s", (char *) yyvsp[-1], 1);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 20:
#line 289 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				statfilecmd((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 21:
#line 296 "ftpcmd.y"
{
			statcmd();
		;
    break;}
case 22:
#line 300 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				_delete((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 23:
#line 307 "ftpcmd.y"
{
			if (fromname) {
				renamecmd(fromname, (char *) yyvsp[-1]);
				free(fromname);
				fromname = (char *) 0;
			} else {
				reply(503, "Bad sequence of commands.");
			}
			free((char *) yyvsp[-1]);
		;
    break;}
case 24:
#line 318 "ftpcmd.y"
{
			reply(225, "ABOR command successful.");
		;
    break;}
case 25:
#line 322 "ftpcmd.y"
{
			if (yyvsp[-1])
				cwd(pw->pw_dir);
		;
    break;}
case 26:
#line 327 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				cwd((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 27:
#line 334 "ftpcmd.y"
{
			help(cmdtab, (char *) 0);
		;
    break;}
case 28:
#line 338 "ftpcmd.y"
{
			register char *cp = (char *)yyvsp[-1];

			if (strncasecmp(cp, "SITE", 4) == 0) {
				cp = (char *)yyvsp[-1] + 4;
				if (*cp == ' ')
					cp++;
				if (*cp)
					help(sitetab, cp);
				else
					help(sitetab, (char *) 0);
			} else
				help(cmdtab, (char *) yyvsp[-1]);
		;
    break;}
case 29:
#line 353 "ftpcmd.y"
{
			reply(200, "NOOP command successful.");
		;
    break;}
case 30:
#line 357 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				makedir((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
			free((char *) yyvsp[-1]);
		;
    break;}
case 31:
#line 365 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				removedir((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 32:
#line 372 "ftpcmd.y"
{
			if (yyvsp[-1])
				pwd();
		;
    break;}
case 33:
#line 377 "ftpcmd.y"
{
			if (yyvsp[-1])
				cwd("..");
		;
    break;}
case 34:
#line 382 "ftpcmd.y"
{
			help(sitetab, (char *) 0);
		;
    break;}
case 35:
#line 386 "ftpcmd.y"
{
			help(sitetab, (char *) yyvsp[-1]);
		;
    break;}
case 36:
#line 390 "ftpcmd.y"
{
			int oldmask;

			if (yyvsp[-1]) {
				oldmask = umask(0);
				(void) umask(oldmask);
				reply(200, "Current UMASK is %03o", oldmask);
			}
		;
    break;}
case 37:
#line 400 "ftpcmd.y"
{
			int oldmask;

			if (yyvsp[-3]) {
				if ((yyvsp[-1] == -1) || (yyvsp[-1] > 0777)) {
					reply(501, "Bad UMASK value");
				} else {
					oldmask = umask(yyvsp[-1]);
					reply(200,
					    "UMASK set to %03o (was %03o)",
					    yyvsp[-1], oldmask);
				}
			}
		;
    break;}
case 38:
#line 415 "ftpcmd.y"
{
			if (yyvsp[-5] && (yyvsp[-1] != NULL)) {
				if (yyvsp[-3] > 0777)
					reply(501,
				"CHMOD: Mode value must be between 0 and 0777");
				else if (chmod((char *) yyvsp[-1], yyvsp[-3]) < 0)
					perror_reply(550, (char *) yyvsp[-1]);
				else
					reply(200, "CHMOD command successful.");
			}
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 39:
#line 429 "ftpcmd.y"
{
			reply(200,
			    "Current IDLE time limit is %d seconds; max %d",
				timeout, maxtimeout);
		;
    break;}
case 40:
#line 435 "ftpcmd.y"
{
			if (yyvsp[-1] < 30 || yyvsp[-1] > maxtimeout) {
				reply(501,
			"Maximum IDLE time must be between 30 and %d seconds",
				    maxtimeout);
			} else {
				timeout = yyvsp[-1];
				(void) alarm((unsigned) timeout);
				reply(200,
				    "Maximum IDLE time set to %d seconds",
				    timeout);
			}
		;
    break;}
case 41:
#line 449 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				_store((char *) yyvsp[-1], "w", 1);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 42:
#line 456 "ftpcmd.y"
{
#ifdef unix
#ifdef BSD
			reply(215, "UNIX Type: L%d Version: BSD-%d",
				NBBY, BSD);
#else /* BSD */
			reply(215, "UNIX Type: L%d", NBBY);
#endif /* BSD */
#else /* unix */
			reply(215, "UNKNOWN Type: L%d", NBBY);
#endif /* unix */
		;
    break;}
case 43:
#line 477 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL)
				sizecmd((char *) yyvsp[-1]);
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 44:
#line 494 "ftpcmd.y"
{
			if (yyvsp[-3] && yyvsp[-1] != NULL) {
				struct stat stbuf;
				if (stat((char *) yyvsp[-1], &stbuf) < 0)
					perror_reply(550, "%s", (char *) yyvsp[-1]);
				else if ((stbuf.st_mode&S_IFMT) != S_IFREG) {
					reply(550, "%s: not a plain file.",
						(char *) yyvsp[-1]);
				} else {
					register struct tm *t;
					struct tm *gmtime();
					t = gmtime(&stbuf.st_mtime);
					reply(213,
					    "19%02d%02d%02d%02d%02d%02d",
					    t->tm_year, t->tm_mon+1, t->tm_mday,
					    t->tm_hour, t->tm_min, t->tm_sec);
				}
			}
			if (yyvsp[-1] != NULL)
				free((char *) yyvsp[-1]);
		;
    break;}
case 45:
#line 516 "ftpcmd.y"
{
		  syslog(LOG_INFO, "User %s logged off\n", pw->pw_name);
		  
			reply(221, "Goodbye.");
			dologout(0);
		;
    break;}
case 46:
#line 523 "ftpcmd.y"
{
			yyerrok;
		;
    break;}
case 47:
#line 528 "ftpcmd.y"
{
			char *renamefrom();

			restart_point = (off_t) 0;
			if (yyvsp[-3] && yyvsp[-1]) {
				fromname = renamefrom((char *) yyvsp[-1]);
				if (fromname == (char *) 0 && yyvsp[-1]) {
					free((char *) yyvsp[-1]);
				}
			}
		;
    break;}
case 48:
#line 540 "ftpcmd.y"
{
			long atol();

			fromname = (char *) 0;
			restart_point = yyvsp[-1];
			reply(350, "Restarting at %ld. %s", restart_point,
			    "Send STORE or RETRIEVE to initiate transfer.");
		;
    break;}
case 50:
#line 554 "ftpcmd.y"
{
			*(char **)&(yyval) = (char *)calloc(1, sizeof(char));
		;
    break;}
case 53:
#line 565 "ftpcmd.y"
{
			register char *a, *p;

			a = (char *)&data_dest.sin_addr;
			a[0] = yyvsp[-10]; a[1] = yyvsp[-8]; a[2] = yyvsp[-6]; a[3] = yyvsp[-4];
			p = (char *)&data_dest.sin_port;
			p[0] = yyvsp[-2]; p[1] = yyvsp[0];
			data_dest.sin_family = AF_INET;
		;
    break;}
case 54:
#line 577 "ftpcmd.y"
{
		yyval = FORM_N;
	;
    break;}
case 55:
#line 581 "ftpcmd.y"
{
		yyval = FORM_T;
	;
    break;}
case 56:
#line 585 "ftpcmd.y"
{
		yyval = FORM_C;
	;
    break;}
case 57:
#line 591 "ftpcmd.y"
{
		cmd_type = TYPE_A;
		cmd_form = FORM_N;
	;
    break;}
case 58:
#line 596 "ftpcmd.y"
{
		cmd_type = TYPE_A;
		cmd_form = yyvsp[0];
	;
    break;}
case 59:
#line 601 "ftpcmd.y"
{
		cmd_type = TYPE_E;
		cmd_form = FORM_N;
	;
    break;}
case 60:
#line 606 "ftpcmd.y"
{
		cmd_type = TYPE_E;
		cmd_form = yyvsp[0];
	;
    break;}
case 61:
#line 611 "ftpcmd.y"
{
		cmd_type = TYPE_I;
	;
    break;}
case 62:
#line 615 "ftpcmd.y"
{
		cmd_type = TYPE_L;
		cmd_bytesz = NBBY;
	;
    break;}
case 63:
#line 620 "ftpcmd.y"
{
		cmd_type = TYPE_L;
		cmd_bytesz = yyvsp[0];
	;
    break;}
case 64:
#line 626 "ftpcmd.y"
{
		cmd_type = TYPE_L;
		cmd_bytesz = yyvsp[0];
	;
    break;}
case 65:
#line 633 "ftpcmd.y"
{
		yyval = STRU_F;
	;
    break;}
case 66:
#line 637 "ftpcmd.y"
{
		yyval = STRU_R;
	;
    break;}
case 67:
#line 641 "ftpcmd.y"
{
		yyval = STRU_P;
	;
    break;}
case 68:
#line 647 "ftpcmd.y"
{
		yyval = MODE_S;
	;
    break;}
case 69:
#line 651 "ftpcmd.y"
{
		yyval = MODE_B;
	;
    break;}
case 70:
#line 655 "ftpcmd.y"
{
		yyval = MODE_C;
	;
    break;}
case 71:
#line 661 "ftpcmd.y"
{
		/*
		 * Problem: this production is used for all pathname
		 * processing, but only gives a 550 error reply.
		 * This is a valid reply in some cases but not in others.
		 */
		if (logged_in && yyvsp[0] && strncmp((char *) yyvsp[0], "~", 1) == 0) {
			*(char **)&(yyval) = *ftpglob((char *) yyvsp[0]);
			if (globerr != NULL) {
				reply(550, globerr);
				yyval = NULL;
			}
			free((char *) yyvsp[0]);
		} else
			yyval = yyvsp[0];
	;
    break;}
case 73:
#line 683 "ftpcmd.y"
{
		register int ret, dec, multby, digit;

		/*
		 * Convert a number that was read as decimal number
		 * to what it would be if it had been read as octal.
		 */
		dec = yyvsp[0];
		multby = 1;
		ret = 0;
		while (dec) {
			digit = dec%10;
			if (digit > 7) {
				ret = -1;
				break;
			}
			ret += digit * multby;
			multby *= 8;
			dec /= 10;
		}
		yyval = ret;
	;
    break;}
case 74:
#line 708 "ftpcmd.y"
{
		if (logged_in)
			yyval = 1;
		else {
			reply(530, "Please login with USER and PASS.");
			yyval = 0;
		}
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 718 "ftpcmd.y"


extern jmp_buf errcatch;

#define	CMD	0	/* beginning of command */
#define	ARGS	1	/* expect miscellaneous arguments */
#define	STR1	2	/* expect SP followed by STRING */
#define	STR2	3	/* expect STRING */
#define	OSTR	4	/* optional SP then STRING */
#define	ZSTR1	5	/* SP then optional STRING */
#define	ZSTR2	6	/* optional STRING after SP */
#define	SITECMD	7	/* SITE command */
#define	NSTR	8	/* Number followed by a string */

struct tab {
	char	*name;
	short	token;
	short	state;
	short	implemented;	/* 1 if command is implemented */
	char	*help;
};

struct tab cmdtab[] = {		/* In order defined in RFC 765 */
	{ "USER", USER, STR1, 1,	"<sp> username" },
	{ "PASS", PASS, ZSTR1, 1,	"<sp> password" },
	{ "ACCT", ACCT, STR1, 0,	"(specify account)" },
	{ "SMNT", SMNT, ARGS, 0,	"(structure mount)" },
	{ "REIN", REIN, ARGS, 0,	"(reinitialize server state)" },
	{ "QUIT", QUIT, ARGS, 1,	"(terminate service)", },
	{ "PORT", PORT, ARGS, 1,	"<sp> b0, b1, b2, b3, b4" },
	{ "PASV", PASV, ARGS, 1,	"(set server in passive mode)" },
	{ "TYPE", TYPE, ARGS, 1,	"<sp> [ A | E | I | L ]" },
	{ "STRU", STRU, ARGS, 1,	"(specify file structure)" },
	{ "MODE", MODE, ARGS, 1,	"(specify transfer mode)" },
	{ "RETR", RETR, STR1, 1,	"<sp> file-name" },
	{ "STOR", STOR, STR1, 1,	"<sp> file-name" },
	{ "APPE", APPE, STR1, 1,	"<sp> file-name" },
	{ "MLFL", MLFL, OSTR, 0,	"(mail file)" },
	{ "MAIL", MAIL, OSTR, 0,	"(mail to user)" },
	{ "MSND", MSND, OSTR, 0,	"(mail send to terminal)" },
	{ "MSOM", MSOM, OSTR, 0,	"(mail send to terminal or mailbox)" },
	{ "MSAM", MSAM, OSTR, 0,	"(mail send to terminal and mailbox)" },
	{ "MRSQ", MRSQ, OSTR, 0,	"(mail recipient scheme question)" },
	{ "MRCP", MRCP, STR1, 0,	"(mail recipient)" },
	{ "ALLO", ALLO, ARGS, 1,	"allocate storage (vacuously)" },
	{ "REST", REST, ARGS, 1,	"(restart command)" },
	{ "RNFR", RNFR, STR1, 1,	"<sp> file-name" },
	{ "RNTO", RNTO, STR1, 1,	"<sp> file-name" },
	{ "ABOR", ABOR, ARGS, 1,	"(abort operation)" },
	{ "DELE", DELE, STR1, 1,	"<sp> file-name" },
	{ "CWD",  CWD,  OSTR, 1,	"[ <sp> directory-name ]" },
	{ "XCWD", CWD,	OSTR, 1,	"[ <sp> directory-name ]" },
	{ "LIST", LIST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "NLST", NLST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "SITE", SITE, SITECMD, 1,	"site-cmd [ <sp> arguments ]" },
	{ "SYST", SYST, ARGS, 1,	"(get type of operating system)" },
	{ "STAT", STAT, OSTR, 1,	"[ <sp> path-name ]" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ "NOOP", NOOP, ARGS, 1,	"" },
	{ "MKD",  MKD,  STR1, 1,	"<sp> path-name" },
	{ "XMKD", MKD,  STR1, 1,	"<sp> path-name" },
	{ "RMD",  RMD,  STR1, 1,	"<sp> path-name" },
	{ "XRMD", RMD,  STR1, 1,	"<sp> path-name" },
	{ "PWD",  PWD,  ARGS, 1,	"(return current directory)" },
	{ "XPWD", PWD,  ARGS, 1,	"(return current directory)" },
	{ "CDUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "XCUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "STOU", STOU, STR1, 1,	"<sp> file-name" },
	{ "SIZE", SIZE, OSTR, 1,	"<sp> path-name" },
	{ "MDTM", MDTM, OSTR, 1,	"<sp> path-name" },
	{ NULL,   0,    0,    0,	0 }
};

struct tab sitetab[] = {
	{ "UMASK", UMASK, ARGS, 1,	"[ <sp> umask ]" },
	{ "IDLE", IDLE, ARGS, 1,	"[ <sp> maximum-idle-time ]" },
	{ "CHMOD", CHMOD, NSTR, 1,	"<sp> mode <sp> file-name" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ NULL,   0,    0,    0,	0 }
};

struct tab *
lookup(p, cmd)
	register struct tab *p;
	char *cmd;
{

	for (; p->name != NULL; p++)
		if (strcmp(cmd, p->name) == 0)
			return (p);
	return (0);
}

#include <arpa/telnet.h>

/*
 * getline - a hacked up version of fgets to ignore TELNET escape codes.
 */
char *
getline(s, n, iop)
	char *s;
	register FILE *iop;
{
	register c;
	register char *cs;

	cs = s;
/* tmpline may contain saved command from urgent mode interruption */
	for (c = 0; tmpline[c] != '\0' && --n > 0; ++c) {
		*cs++ = tmpline[c];
		if (tmpline[c] == '\n') {
			*cs++ = '\0';
			if (debug)
				syslog(LOG_DEBUG, "command: %s", s);
			tmpline[0] = '\0';
			return(s);
		}
		if (c == 0)
			tmpline[0] = '\0';
	}
	while ((c = getc(iop)) != EOF) {
		c &= 0377;
		if (c == IAC) {
		    if ((c = getc(iop)) != EOF) {
			c &= 0377;
			switch (c) {
			case WILL:
			case WONT:
				c = getc(iop);
				printf("%c%c%c", IAC, DONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case DO:
			case DONT:
				c = getc(iop);
				printf("%c%c%c", IAC, WONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case IAC:
				break;
			default:
				continue;	/* ignore command */
			}
		    }
		}
		*cs++ = c;
		if (--n <= 0 || c == '\n')
			break;
	}
	if (c == EOF && cs == s)
		return (NULL);
	*cs++ = '\0';
	if (debug)
		syslog(LOG_DEBUG, "command: %s", s);
	return (s);
}

static void
toolong()
{
	time_t now;

	reply(421,
	  "Timeout (%d seconds): closing control connection.", timeout);
	(void) time(&now);
	if (logging) {
		syslog(LOG_INFO,
			"User %s timed out after %d seconds at %s",
			(pw ? pw -> pw_name : "unknown"), timeout, ctime(&now));
	}
	dologout(1);
}

yylex()
{
	static int cpos, state;
	register char *cp, *cp2;
	register struct tab *p;
	int n;
	char c, *copy();

	for (;;) {
		switch (state) {

		case CMD:
			(void) signal(SIGALRM, toolong);
			(void) alarm((unsigned) timeout);
			if (getline(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
				reply(221, "You could at least say goodbye.");
				dologout(0);
			}
			(void) alarm(0);
#ifdef SETPROCTITLE
			if (strncasecmp(cbuf, "PASS", 4) != 0)
				setproctitle("%s: %s", proctitle, cbuf);
#endif /* SETPROCTITLE */
			if ((cp = index(cbuf, '\r'))) {
				*cp++ = '\n';
				*cp = '\0';
			}
			if ((cp = strpbrk(cbuf, " \n")))
				cpos = cp - cbuf;
			if (cpos == 0)
				cpos = 4;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cbuf);
			p = lookup(cmdtab, cbuf);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					nack(p->name);
					longjmp(errcatch,0);
					/* NOTREACHED */
				}
				state = p->state;
				*(char **)&yylval = p->name;
				return (p->token);
			}
			break;

		case SITECMD:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			cp = &cbuf[cpos];
			if ((cp2 = strpbrk(cp, " \n")))
				cpos = cp2 - cbuf;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cp);
			p = lookup(sitetab, cp);
			cbuf[cpos] = c;
			if (p != 0) {
				if (p->implemented == 0) {
					state = CMD;
					nack(p->name);
					longjmp(errcatch,0);
					/* NOTREACHED */
				}
				state = p->state;
				*(char **)&yylval = p->name;
				return (p->token);
			}
			state = CMD;
			break;

		case OSTR:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR1:
		case ZSTR1:
		dostr1:
			if (cbuf[cpos] == ' ') {
				cpos++;
				state = state == OSTR ? STR2 : ++state;
				return (SP);
			}
			break;

		case ZSTR2:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR2:
			cp = &cbuf[cpos];
			n = strlen(cp);
			cpos += n - 1;
			/*
			 * Make sure the string is nonempty and \n terminated.
			 */
			if (n > 1 && cbuf[cpos] == '\n') {
				cbuf[cpos] = '\0';
				*(char **)&yylval = copy(cp);
				cbuf[cpos] = '\n';
				state = ARGS;
				return (STRING);
			}
			break;

		case NSTR:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval = atoi(cp);
				cbuf[cpos] = c;
				state = STR1;
				return (NUMBER);
			}
			state = STR1;
			goto dostr1;

		case ARGS:
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval = atoi(cp);
				cbuf[cpos] = c;
				return (NUMBER);
			}
			switch (cbuf[cpos++]) {

			case '\n':
				state = CMD;
				return (CRLF);

			case ' ':
				return (SP);

			case ',':
				return (COMMA);

			case 'A':
			case 'a':
				return (A);

			case 'B':
			case 'b':
				return (B);

			case 'C':
			case 'c':
				return (C);

			case 'E':
			case 'e':
				return (E);

			case 'F':
			case 'f':
				return (F);

			case 'I':
			case 'i':
				return (I);

			case 'L':
			case 'l':
				return (L);

			case 'N':
			case 'n':
				return (N);

			case 'P':
			case 'p':
				return (P);

			case 'R':
			case 'r':
				return (R);

			case 'S':
			case 's':
				return (S);

			case 'T':
			case 't':
				return (T);

			}
			break;

		default:
			fatal("Unknown state in scanner.");
		}
		yyerror((char *) 0);
		state = CMD;
		longjmp(errcatch,0);
	}
}

upper(s)
	register char *s;
{
	while (*s != '\0') {
		if (islower(*s))
			*s = toupper(*s);
		s++;
	}
}

char *
copy(s)
	char *s;
{
	char *p;

	p = malloc((unsigned) strlen(s) + 1);
	if (p == NULL)
		fatal("Ran out of memory.");
	(void) strcpy(p, s);
	return (p);
}

help(ctab, s)
	struct tab *ctab;
	char *s;
{
	register struct tab *c;
	register int width, NCMDS;
	char *type;

	if (ctab == sitetab)
		type = "SITE ";
	else
		type = "";
	width = 0, NCMDS = 0;
	for (c = ctab; c->name != NULL; c++) {
		int len = strlen(c->name);

		if (len > width)
			width = len;
		NCMDS++;
	}
	width = (width + 8) &~ 7;
	if (s == 0) {
		register int i, j, w;
		int columns, lines;

		lreply(214, "The following %scommands are recognized %s.",
		    type, "(* =>'s unimplemented)");
		columns = 76 / width;
		if (columns == 0)
			columns = 1;
		lines = (NCMDS + columns - 1) / columns;
		for (i = 0; i < lines; i++) {
			printf("   ");
			for (j = 0; j < columns; j++) {
				c = ctab + j * lines + i;
				printf("%s%c", c->name,
					c->implemented ? ' ' : '*');
				if (c + lines >= &ctab[NCMDS])
					break;
				w = strlen(c->name) + 1;
				while (w < width) {
					putchar(' ');
					w++;
				}
			}
			printf("\r\n");
		}
		(void) fflush(stdout);
		reply(214, "Direct comments to ftp-bugs@%s.", hostname);
		return;
	}
	upper(s);
	c = lookup(ctab, s);
	if (c == (struct tab *)0) {
		reply(502, "Unknown command %s.", s);
		return;
	}
	if (c->implemented)
		reply(214, "Syntax: %s%s %s", type, c->name, c->help);
	else
		reply(214, "%s%-*s\t%s; unimplemented.", type, width,
		    c->name, c->help);
}

sizecmd(filename)
char *filename;
{
	switch (type) {
	case TYPE_L:
	case TYPE_I: {
		struct stat stbuf;
		if (stat(filename, &stbuf) < 0 ||
		    (stbuf.st_mode&S_IFMT) != S_IFREG)
			reply(550, "%s: not a plain file.", filename);
		else
			reply(213, "%lu", stbuf.st_size);
		break;}
	case TYPE_A: {
		FILE *fin;
		register int c;
		register long count;
		struct stat stbuf;
		fin = fopen(filename, "r");
		if (fin == NULL) {
			perror_reply(550, filename);
			return;
		}
		if (fstat(fileno(fin), &stbuf) < 0 ||
		    (stbuf.st_mode&S_IFMT) != S_IFREG) {
			reply(550, "%s: not a plain file.", filename);
			(void) fclose(fin);
			return;
		}

		count = 0;
		while((c=getc(fin)) != EOF) {
			if (c == '\n')	/* will get expanded to \r\n */
				count++;
			count++;
		}
		(void) fclose(fin);

		reply(213, "%ld", count);
		break;}
	default:
		reply(504, "SIZE not implemented for Type %c.", "?AEIL"[type]);
	}
}

/* EOF */
