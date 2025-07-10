
  /* =====[ PCOMP ]=========================================================

     Description: PCOMP parallel compiler. See README and SYNTAX.

     Revisions:

     REV    DATE            BY             DESCRIPTION
     ----   --------        ----------     ----------------------------
     0.00   Thu 03.Jul.2025 Peter Glen     Initial

     ======================================================================= */

void    calc_usec_diff(Ts *ts, Ts *ts2, int *pdts, int *pdtu);
char    *strpcpy(char *dest, const char *src, size_t nn);
char    *addstrs(char *str1, char *str2);
int     str2int(char *ptr);
void    hd(char *ptr, int len);
double  errcheck( double d, char *s);
void    execerror(char * str, char *str2);
int     addemit(char chh);
int     addemitstr(char *str);
int     inputx(char *buf, int max_size, FILE *ppfp3);
void    preerror(const char *str);
void    safe_printf(char *fmt, ...);
void    inf(int lev, char *fmt, ...);
void    inff(int lev, char *fmt, ...);

extern  int     emitprog;
extern  char    emitline[1024];

extern  char    currline[1024];
extern  int     currprog ;
extern  char    prevline[1024];

// EOF
