
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
int     main (int argc, char **argv);

// EOF
