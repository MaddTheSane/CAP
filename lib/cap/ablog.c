static char rcsid[] = "$Author: djh $ $Date: 1995/05/29 10:45:18 $";
static char rcsident[] = "$Header: /mac/src/cap60/lib/cap/RCS/ablog.c,v 2.5 1995/05/29 10:45:18 djh Rel djh $";
static char revision[] = "$Revision: 2.5 $";

/*
 * ablog.c - simple logging facility
 *
 *
 * Copyright (c) 1988 by The Trustees of Columbia University 
 *   in the City of New York.
 *
 * Permission is granted to any individual or institution to use,
 * copy, or redistribute this software so long as it is not sold for
 * profit, provided that this notice and the original copyright
 * notices are retained.  Columbia University nor the author make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * 
 * Edit History:
 *
 *   Aug, 1988 CCKim created
 *
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netat/appletalk.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dispatch/dispatch.h>

# include <stdarg.h>
#ifdef USETIMES
# include <time.h>
#endif //USETIMES

/* current debug level */
static int dlevel;

#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
# define FALSE 0
#endif

/*
 * set debug level
 *
*/
int get_debug_level()
{
  return(dlevel);
}
void set_debug_level(n)
int n;
{
  dlevel = n;
}

/*
 * print message - use vprintf whenever possible (solves the problem
 * of using the varargs macros -- you must interpret the format).
 * This is something all machine should, but don't have :-)
 */

static FILE *lfp;
static char *mytod(void);

static dispatch_once_t lfpInit_once;
static dispatch_block_t lfpInit_block = ^void(void) {
  lfp = stderr;
};

void logit(int level, const char *fmt, ...)
{
  dispatch_once(&lfpInit_once, lfpInit_block);
  va_list args;
  int saveerr;

  if (lfp == NULL)		/* no logging? */
    return;

  saveerr = errno;
  va_start(args, fmt);

  if (dlevel < (level & L_LVL))
    return;

  fprintf(lfp,"%s ",mytod());

  vfprintf(lfp, fmt, args);
  va_end(args);
  if (level & L_UERR) {
    if (saveerr < sys_nerr)
      fprintf(lfp, ": %s", sys_errlist[saveerr]);
    else
      fprintf(lfp, ": error %d\n", saveerr);
  }
  putc('\n', lfp);
  fflush(lfp);
  if (level & L_EXIT)
    exit(1);
}

bool islogitfile()
{
  dispatch_once(&lfpInit_once, lfpInit_block);
  if (lfp == stderr)
    return(FALSE);
  return(lfp != NULL);
}

void logitfileis(const char *filename, const char *mode)
{
  dispatch_once(&lfpInit_once, lfpInit_block);
  FILE *fp;

  if ((fp = fopen(filename, mode)) != NULL) {
    logit(0, "log file name %s", filename);
  } else {
    logit(0|L_UERR, "couldn't open logfile %s", filename);
  }
  lfp = fp;			/* reset */
}

void nologitfile()
{
  dispatch_once(&lfpInit_once, lfpInit_block);
  if (lfp && lfp != stderr)
    fclose(lfp);
  lfp = NULL;
}

/*
 * return pointer to formatted tod in static buffer
 *
*/
static char *
mytod()
{
  long tloc;
  struct tm *tm, *localtime();
  static char buf[100];		/* should be large enough */

  (void)time(&tloc);
  tm = localtime(&tloc);
  if (tm->tm_year > 99)
    sprintf(buf, "%02d:%02d:%02d %02d/%02d/%04d ",
	    tm->tm_hour, tm->tm_min, tm->tm_sec,
	    tm->tm_mon+1, tm->tm_mday, tm->tm_year+1900);
  else
    sprintf(buf, "%02d:%02d:%02d %02d/%02d/%02d ",
	    tm->tm_hour, tm->tm_min, tm->tm_sec,
	    tm->tm_mon+1, tm->tm_mday, tm->tm_year);
  return(buf);
}
