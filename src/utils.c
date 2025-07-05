
  /* =====[ PCOMP ]=========================================================

     Description: PCOMP parallel compiler. See README and SYNTAX.

     Revisions:

     REV    DATE            BY             DESCRIPTION
     ----   --------        ----------     ----------------------------
     0.00   Thu 03.Jul.2025 Peter Glen     Initial

     ======================================================================= */

#include <time.h>
#include <stdio.h>
#include <string.h>

#include "symtab.h"
#include "pcomp.h"

// Time diff
//

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

#ifdef TEST

void    hd(char *ptr, int len)
{
    for(int aa = 0; aa < len; aa++)
        {
        printf("%02x ", ptr[aa] & 0xff);
        }
    printf("\n");
}

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


// EOF
