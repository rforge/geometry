/*<html><pre>  -<a                             href="qh-user_r.htm"
  >-------------------------------</a><a name="TOP">-</a>

   usermem_r.c
   qh_exit(), qh_free(), and qh_malloc()

   See README.txt.

   If you redefine one of these functions you must redefine all of them.
   If you recompile and load this file, then usermem.o will not be loaded
   from qhull.a or qhull.lib

   See libqhull_r.h for data structures, macros, and user-callable functions.
   See user_r.c for qhull-related, redefinable functions
   see user_r.h for user-definable constants
   See userprintf_r.c for qh_fprintf and userprintf_rbox_r.c for qh_fprintf_rbox

   Please report any errors that you fix to qhull@qhull.org
*/

#include "libqhull_r.h"

#include <stdlib.h>

/*-<a                             href="qh-user_r.htm#TOC"
  >-------------------------------</a><a name="qh_exit">-</a>

  qh_exit( exitcode )
    exit program

  notes:
    qh_exit() is called when qh_errexit() and longjmp() are not available.
    same as exit()
*/
void qh_exit(int exitcode) {
    /* CHANGE TO SOURCE: The commented line below is the original. It
     needs to be replaced to fix warnings about exit being called. --
     David Sterratt 3/4/12. */
    /* exit(exitcode); */
    error("Qhull exit, code $i", exitcode);
} /* exit */

/*-<a                             href="qh-user_r.htm#TOC"
>-------------------------------</a><a name="qh_free">-</a>

  qh_free(qhT *qh, mem )
    free memory

  notes:
    same as free()
    No calls to qh_errexit() 
*/
void qh_free(void *mem) {
    free(mem);
} /* free */

/*-<a                             href="qh-user_r.htm#TOC"
    >-------------------------------</a><a name="qh_malloc">-</a>

    qh_malloc( mem )
      allocate memory

    notes:
      same as malloc()
*/
void *qh_malloc(size_t size) {
    return malloc(size);
} /* malloc */


