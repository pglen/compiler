/*--------------------------------------------------------------------------
**  Math functions
*/

#include <math.h>

int errcheck(int aa, char *str) { return 0; };

double Log( double x)

{
   return errcheck( log(x), "log") ;
}

double Log10( double x)
{
   return errcheck( log10(x), "log10") ;
}

double Exp( double x)
{
   return errcheck( exp(x), "exp") ;
}

double Pow( double x, double y)
{
   return errcheck( pow(x, y), "exponentiation") ;
}

double integer( double x)
{
   return (double)(long) x ;
}

double Sqrt( double x)
{
   return errcheck( sqrt(x), "sqrt") ;
}

int main()

{
}


