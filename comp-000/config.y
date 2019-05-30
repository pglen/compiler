%{

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

#define MAX_ARRAY 4

char **ulist = 0;
char **clist = 0;
char **dlist = 0;
char **flist = 0;
char **xdlist = 0;

int add_array(char ***ulist,  char *ptr);
int add_ptr  (char ***list, char *ptr);
int init_array(char ***list);

/* define this to see indivdual parsing */
//define DEBUGYYY

%}

%token

SP NL NUM ID SEP STR CLASS SSALC DIR RID DBG LOG
DENY YNED FUNC BEG  END
LCUR RCUR PLUS

%%

all2:  |
all2  all1

all1:    class
| dir1
| debug1
| deny1
| func1
| ews

debug1: DBG SP NUM emws
{

#ifdef TEST
  printf("Debug level: \t%s\n", $3);
#endif
}

func1: FUNC ews ID ews LCUR ews add1 ews RCUR
{

#ifdef TEST
  printf("Function=%s ", $3);
#endif
}

add1:  ID ews PLUS ews ID

{
#ifdef TEST
  printf("Add %s + %s\n", $1, $3);
#endif

}

deny1: DENY ews ID ews ids ews YNED emws
{
  int loop;


#ifdef TEST
  printf("Deny  files:\n");
#endif

  add_array(&flist, (char*)$3);

#ifdef TEST
  printf(" '%s' ", (char*)$3);
#endif

 for(loop = 0; loop < (int)ulist[1]; loop++)
    {
     add_array(&flist, ulist[loop+2]);
#ifdef TEST
     printf(" '%s' ", ulist[loop+2]);
#endif
    }

#ifdef TEST
    printf("\n");
#endif

        }
       ;

class: CLASS SP ID ews ids ews SSALC emws
{
  int loop;

#ifdef TEST
  printf("List of Classes: %s\n", (char*)$3);
#endif

  for(loop = 0; loop < (int)ulist[1]; loop++)
    {
     add_array(&clist, ulist[loop+2]);
#ifdef TEST
     printf(" '%s' ", ulist[loop+2]);
#endif
    }

#ifdef TEST
    printf("\n");
#endif

        }
       ;
dir1: DIR SP ID ews ids ews RID emws
        {
        int loop;
        static char ***tmplist;

        if( !(tmplist = malloc(sizeof(char*))))
           {
           printf("Out of memory\n"); exit(0);
           }
        *tmplist = 0;
        add_array(tmplist, (char*)$3);
        for(loop = 0; loop < (int)ulist[1]; loop++)
          {
           add_array(tmplist, ulist[loop+2]);
          }
        /* add a container for this dir list */
        add_array(&xdlist, (char*)*tmplist);
        }
       ;
emws: {
    #ifdef DEBUGYYY
    //printf("empty emws ");
    #endif
       }
      | ews
    {
    #ifdef DEBUGYYY
    printf("emws ");
    #endif
        }
    ;

ews:    SP  {
        #ifdef DEBUGYYY
    printf("'EWS space' ");
        #endif
        }
   |  NL {
        #ifdef DEBUGYYY
    printf("EWS newline' ");
        #endif
    }
   | SP NL {
    #ifdef DEBUGYYY
    printf("EWS SPnewline' ");
        #endif
   }
   | NL SP {
    #ifdef DEBUGYYY
    printf("EWS NLspace' ");
        #endif
    }
   | SP NL SP {
        #ifdef DEBUGYYY
    printf("#EWS NLspace' ");
        #endif
    }
      ;

ids:   ID
     {
       free_array(&ulist);
       add_array(&ulist, (char*)$1);

      #ifdef DEBUGYYY
      printf("ID: '%s' ", $1);
      #endif
     }
       | ids ews ID
      {
      add_array(&ulist, (char*)$3);

        #ifdef DEBUGYYY
        printf("ID list: '%s' ",(char*)$3);
        #endif
      }
    ;


%%


/*
 * Array of pointers.
 * First entry is number of current allocated pointers,
 * second entry next available index.
 *
 * Note:
 *        the first two array entries are used as integers. (noty noty)
 *
 * Input: pointer to root list, pointer to string to add
 *
 * Reading the list:
 *
 *  for(loop = 0; loop < (int)list[1]; loop++)
 *     {
 *     item =  list[loop+2]);
 *     }
 */

int add_array(char ***list, char *ptr)

{
  char *tmp;

      /* init list: */
    if (*list == 0)
        {
        //printf ("add_array(newlist)\n"); fflush(stdout);
        tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

        *list = (char**)tmp;
        (*list)[0] = (char*)MAX_ARRAY;  /* limit */
        (*list)[1] = (char*)0;          /* index */
        }

    //printf ("add_array(list) len = %d idx = %d str= %s\n", (int)(*list)[0], (int)(*list)[1], ptr);

      /*  expand the list if needed */
     if((*list)[1] >= (*list)[0])
        {
        tmp = malloc( ((int)(*list)[0] + MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

      //  printf ("add_array(expandlist)\n"); fflush(stdout);

        memcpy(tmp, *list, ((int)(*list)[1] + 2) * sizeof(char*));

        if(*list) free(*list);
        *list = (char **)tmp;
        (*list)[0] += MAX_ARRAY;
        }
    //printf ("add_array(assignlist)\n"); fflush(stdout);

     (*list)[(int)(*list)[1] + 2] = ptr;
     (*list)[1]++;
}

int free_array(char ***list)

{
  //printf("Free array \n"); fflush(stdout);

  if(*list)
    {
    free(*list);
    *list = 0;
    }
}

int init_array(char ***list)

{
    char *tmp;

    tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
    if(!tmp) printf("Out of memory.\n"), exit(0);

    *list = (char**)tmp;
    (*list)[0] = (char*)MAX_ARRAY;  /* limit */
    (*list)[1] = (char*)0;          /* index */
}


