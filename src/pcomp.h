
/* =====[ pcomp.h ]=========================================================


      REV     DATE     	    BY             DESCRIPTION
      ----  --------  	     ----------    --------------------------------------
      0.00  Sun 15.Nov.2020  Peter Glen    Initial

   ======================================================================= */

// Flags for operation. Some referenced in other files.

typedef struct _configx {
    int   	testflex ;
    int   	testyacc ;
    int	  	showcomm ;
    int	  	dumpsymtab ;
    int 	errorcount ;
    int		debuglevel ;
    int		noprologue ;
    int 	catsrc ;
    int 	catpre ;
    int		interlace_sym ;
    int		noassembly ;
    int		nolink ;
    int		showallocbuff ;
    int		noprog ;
    int		nocompile ;
    int		verbose ;
    int		nopre ;
} Configx;

extern Configx config;
extern char ppfile2[];
extern int num_lines, num_chars, backslash, prog;
extern char outfile[MAX_VARLEN];
extern char outtmp[MAX_VARLEN];

// EOF
