
  /* =====[ PCOMP ]=========================================================

     Description: PCOMP parallel compiler. See README and SYNTAX.

     Revisions:

     REV    DATE            BY             DESCRIPTION
     ----   --------        ----------     ----------------------------
     0.00   Thu 03.Jul.2025 Peter Glen     Initial

     ======================================================================= */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>

#include "symtab.h"
#include "pcomp.h"
#include "utils.h"
#include "xmalloc.h"

char    currline[1024];
int     currprog = 0;
char    prevline[1024];

// Time diff

void    calc_usec_diff(Ts *ts, Ts *ts2, int *pdts, int *pdtu)

{
	#define CALC_NANO  1000000000
	#define CALC_MICRO 1000000

	// Wrapping nanoseconds
	// --------^------^-----|---------------------|---------------------
	// --------^------------|-----^---------------|----------------------
	// --------^------------|---------------------|-----^----------------
    //            NANO - nsec                       nsec2

	int	dtn, dts = ts2->tv_sec - ts->tv_sec;
	if(dts == 0)    // same sec
		dtn = (ts2->tv_nsec - ts->tv_nsec) / 1000;
	else           // jump sec
		dtn = (ts2->tv_nsec + (CALC_NANO - ts->tv_nsec)) / 1000, dts--;

	if(dtn > CALC_MICRO)	// over a sec
		dtn -= CALC_MICRO, dts++;

	*pdts = dts;
	*pdtu = dtn;

	#undef CALC_NANO 	// Make sure define stays local
	#undef CALC_MICRO
}

// Copy with limits. Make sure we got terminator.

char    *strpcpy(char *dest, const char *src, size_t nn)

{
    int cnt = 0;
    char chh, *ret = dest;
    while(1)
        {
        if(cnt >= nn - 1)
            {
            *dest = '\0';
            break;
            }
        chh = *src;
        *dest = chh;
        if(chh == '\0')
            break;
        src++; dest++;
        cnt++;
        }
    return ret;
}

char    *addstrs(char *str1, char *str2)

{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *sum =  xmalloc(len1 + len2 + 2);
    memcpy(sum, str1, len1);
    memcpy(sum + len1, str2, len2);
    sum[len1 + len2] = '\0';

    return sum;
}

// Convert string to integer

int     str2int(char *ptr)

{
    int ret = 0, base = 10, sign = 0;

    if(ptr[0] && ptr[1])    // If string is big enough
        {
        // Determine base
        char base1 = ptr[0], base2 = ptr[1];

        if(base1 == '0' && (base2 == 'x' || base2 == 'X'))
            base = 16, ptr += 2;

        if(base1 == '0' && (base2 == 'y' || base2 == 'Y'))
            base = 8, ptr += 2;

        if(base1 == '0' && (base2 == 'z' || base2 == 'Z'))
            base = 2, ptr += 2;
        }

    if(ptr[0])    // If string is big enough
        {
        // Determine sign
        char sign1 = ptr[0];
        if(sign1 == '-')
            sign = 1, ptr++;
        else if(sign1 == '+')
            ptr++;  // skip plus
        }

    //printf(" str2int(%s) ", ptr);

    while(1)
        {
        char digit = *ptr++;

        if(digit == '\0')      // End of str
            break;

        if(base > 10)
            {
            // See if it is a valid digit
            if(digit >= '0' && digit < '0' + base)
                {
                ret *= base;
                ret += digit - '0';
                }
            else if(digit >= 'A' && digit < ('A' + base - 10))
                {
                ret *= base;
                ret += digit - 'A' + 10;
                }
            else if(digit >= 'a' && digit < ('a' + base - 10))
                {
                ret *= base;
                ret += digit - 'a' + 10;
                }
            else
                {
                break;
                }
            }
        else
            {
            // See if it is a valid digit
            if(digit >= '0' && digit < '0' + base)
                {
                ret *= base;
                ret += digit - '0';
                }
            else
                {
                break;
                }
            }
        }
    if(sign)
        ret = - ret;

    //printf("base=%d  ret=%d\n", base, ret);
    return ret;
}

//define TEST


void    hd(char *ptr, int len)
{
    for(int aa = 0; aa < len; aa++)
        {
        printf("%02x ", ptr[aa] & 0xff);
        }
    printf("\n");
}

#ifdef TEST

char    test[12], test2[4], test3[4];

int     main (int argc, char **argv)

{
    //printf("%d\n",      str2int("-2345"));
    //printf("%d\n",      str2int("1234"));
    //printf("0x%x\n",    str2int("0xab2cdef"));
    //printf("0y%o\n",    str2int("0y765"));
    //printf("%d\n",      str2int("0z1102"));

    memset(test, 'b', sizeof(test));
    memset(test2, 'c', sizeof(test2));
    memset(test3, 'd', sizeof(test3));
    test3[sizeof(test3)-1] = '\0';

    hd(test, 24);

    strpcpy(test, test3, sizeof(test));
    hd(test, 24);

    return 0;
}

#endif

/*--------------------------------------------------------------------------
**  Support routines
*/

void    execerror(char * str, char *str2)
{
    printf("%s - %s", str, str2);
    exit(1);
}

double errcheck( double d, char *s)
{
    if (errno == EDOM) {
        errno = 0 ;
        execerror( s, "argument out of domain") ;
    }
    else if (errno == ERANGE) {
        errno = 0 ;
        execerror(s, "result out of range") ;
    }
    return d ;
}

char    emitline[1024]; // = {0,};
int     emitprog = 0;

int     addemit(char chh)

{
    //printf("addemit: '%c'\n", chh);
    emitline[emitprog] = chh;
    if(emitprog < sizeof(emitline))
        emitprog++;
    emitline[emitprog] = '\0';
    return emitprog;
}

int     addemitstr(char *str)

{
    int cnt = 0;
    while(1)
        {
        char chh = str[cnt];
        if(chh == '\0')
            break;
        addemit(chh);
        cnt++;
        }
}

// Tag a new line at the end of sequence

//#define OUTCX

int     addnums(char *num1, char *num2)

{
    //printf("addnums: %s %s\n", num1, num2);
    int n1=atoi(num1); int n2=atoi(num2);
    int ret = n1 + n2;
    return ret;
}

int     inputx(char *buf, int max_size, FILE *ppfp3)

{
    //printf(" inputx ");

    static int end = 0;
    int ret = 1;
    if(end) {
        end = 0; ret = 0;
        //currline[currprog] = '\0';
        return ret;
        }
    int cc = getc(ppfp3);
    if(cc == EOF)  {
        buf[0] = '\n';  end = 1;
        currline[currprog] = '\0';
        #ifdef OUTCX
            printf("c='EOF'"); fflush(stdout);
        #endif
        }
    else {
        buf[0] = cc;
        #ifdef OUTCX
            if(cc <= '\n')
                printf("c=%d ", cc);
            else
                printf("c='%c' ", cc);
            fflush(stdout);
        #endif

        // Restart
        if (cc == '\n')
            {
            //memcpy(prevline, currline, currprog);
            //prevline[currprog] = '\0';
            //strpcpy(prevline, currline, sizeof(prevline));
            strcpy(prevline, currline);
            currprog = 0;
            }
        else
            {
            currline[currprog] = cc;
            if (currprog < sizeof(currline))
                currprog++;
            currline[currprog] = '\0';
            }
        }
    return ret;
}

jmp_buf env;

void segfault_handler(int sig_num, siginfo_t *si, void *context) {
    printf("\n\033[31;1mCaught segmentation fault\033[0m (Signal %d)\n",
                          sig_num);
    //hd(si, 128);
    sigset_t signal_set;
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGSEGV);
    sigprocmask(SIG_UNBLOCK, &signal_set, NULL);
    //signal(SIGSEGV, SIG_DFL);
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = SIG_DFL;
    sigaction(SIGSEGV, &action, NULL);
    longjmp(env, 1);
}

int boom()
{
    // BOOM
    int *aa = NULL;
    *aa = 1;
}

// Macros to use in catching signal for 'C' try.

#define SET_SIG                                     \
    struct sigaction action;                        \
    struct sigaction action2;                       \
    memset(&action, 0, sizeof(struct sigaction));   \
    memset(&action2, 0, sizeof(struct sigaction));  \
    action.sa_flags = SA_SIGINFO;                   \
    action.sa_sigaction = segfault_handler;         \
    sigaction(SIGSEGV, &action, &action2);          \

//#define UNSET_SIG                                   \
//    memset(&action, 0, sizeof(struct sigaction));   \
//    action.sa_flags = SA_SIGINFO;                   \
//    action.sa_sigaction = SIG_DFL;                  \
//    sigaction(SIGSEGV, &action, NULL);

#define UNSET_SIG                                   \
    sigaction(SIGSEGV, &action2, NULL);

void    safe_printf(char *fmt, ...)

{
    SET_SIG

    if(setjmp(env) == 0)  {
        // Put the actual function calls here
        va_list ap;
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
        //boom();
        }
    else
        {
        //printf("Back to safe\n");
        }
    UNSET_SIG

    //printf("End of safe");
    // TEST This should set it off
    //boom();
}

void    inf(int lev, char *fmt, ...)
{
    if(config.testpreyacc > lev)
        {
        va_list ap;
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
        fflush(stdout);
        }
}
void    inff(int lev, char *fmt, ...)
{
    if(config.testpreflex > lev)
        {
        va_list ap;
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
        fflush(stdout);
        }
}

// EOF
