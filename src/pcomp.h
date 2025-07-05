
/* =====[ pcomp.h ]=========================================================


      REV     DATE     	    BY             DESCRIPTION
      ----  --------  	     ----------    --------------------------------------
      0.00  Sun 15.Nov.2020  Peter Glen    Initial

   ======================================================================= */

// Scratch pad for temp name / all names

#define MAX_VARLEN      256
#define MAX_PATHLEN     1024

// Flags for operation. Some referenced in other files.

typedef struct _configx {
    int   	testflex ;
    int   	testyacc ;
    int   	testpreflex ;
    int   	testpreyacc ;
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
extern int num_lines, num_chars, backslash, prog;

extern char ppfile2[];
extern char outfile[];
extern char usetmp[];

typedef struct timespec Ts;

void    calc_usec_diff(Ts *ts, Ts *ts2, int *pdts, int *pdtu);
int     str2int(char *ptr);

// EOF
