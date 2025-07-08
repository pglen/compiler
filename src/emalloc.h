
/* =====[ emalloc.h ]=========================================================


      REV     DATE     	BY             DESCRIPTION
      ----  --------  	 ----------    --------------------------------------
      0.00  dec/23/2013  Peter Glen    Progress.

   ======================================================================= */

typedef struct _meminf {
		int 	magic;
		int	 	line;
		void 	*ptr;
		char 	file[24];
  		struct  _meminf *next ;
} meminf;

#define MNULL  (meminf*)0
#define CNULL  (char*)0

char    *emalloc(unsigned nn);
char    *emalloc2(unsigned nn, int line, char *file);
void	efree(void *ptr);
void	efreeall();

int 	print_emalloc();
char 	*estrdup(char *str);
char 	*estrdup2(char *str, int line, char *file);
int 	print_estrdup();

// EOF
