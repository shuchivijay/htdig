/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1996, 1997, 1998, 1999, 2000
 *	Sleepycat Software.  All rights reserved.
 */

#include "config.h"

#ifndef lint
static const char revid[] = "$Id: db_getlong.c,v 1.1.2.2 2000/09/14 03:13:19 ghutchis Exp $";
#endif /* not lint */

#ifndef NO_SYSTEM_INCLUDES
#include <sys/types.h>

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "db_int.h"

/*
 * CDB___db_getlong --
 *	Return a long value inside of basic parameters.
 *
 * PUBLIC: int CDB___db_getlong
 * PUBLIC:     __P((DB *, const char *, char *, long, long, long *));
 */
int
CDB___db_getlong(dbp, CDB_progname, p, min, max, storep)
	DB *dbp;
	const char *CDB_progname;
	char *p;
	long min, max, *storep;
{
	long val;
	char *end;

	CDB___os_set_errno(0);
	val = strtol(p, &end, 10);
	if ((val == LONG_MIN || val == LONG_MAX) &&
	    CDB___os_get_errno() == ERANGE) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: %s\n", CDB_progname, p, strerror(ERANGE));
			exit(1);
		}
		dbp->err(dbp, ERANGE, "%s", p);
		return (1);
	}
	if (p[0] == '\0' || (end[0] != '\0' && end[0] != '\n')) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Invalid numeric argument\n", CDB_progname, p);
			exit(1);
		}
		dbp->errx(dbp, "%s: Invalid numeric argument", p);
		return (1);
	}
	if (val < min) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Less than minimum value (%ld)\n",
			    CDB_progname, p, min);
			exit(1);
		}
		dbp->errx(dbp, "%s: Less than minimum value (%ld)", p, min);
		return (1);
	}
	if (val > max) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Greater than maximum value (%ld)\n",
			    CDB_progname, p, max);
			exit(1);
		}
		dbp->errx(dbp, "%s: Greater than maximum value (%ld)", p, max);
		exit(1);
	}
	*storep = val;
	return (0);
}

/*
 * CDB___db_getulong --
 *	Return an unsigned long value inside of basic parameters.
 *
 * PUBLIC: int CDB___db_getulong
 * PUBLIC:     __P((DB *, const char *, char *, u_long, u_long, u_long *));
 */
int
CDB___db_getulong(dbp, CDB_progname, p, min, max, storep)
	DB *dbp;
	const char *CDB_progname;
	char *p;
	u_long min, max, *storep;
{
#if !defined(HAVE_STRTOUL)
	COMPQUIET(min, 0);

	return (CDB___db_getlong(dbp, CDB_progname, p, 0, max, storep));
#else

	u_long val;
	char *end;

	CDB___os_set_errno(0);
	val = strtoul(p, &end, 10);
	if (val == ULONG_MAX && CDB___os_get_errno() == ERANGE) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: %s\n", CDB_progname, p, strerror(ERANGE));
			exit(1);
		}
		dbp->err(dbp, ERANGE, "%s", p);
		return (1);
	}
	if (p[0] == '\0' || (end[0] != '\0' && end[0] != '\n')) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Invalid numeric argument\n", CDB_progname, p);
			exit(1);
		}
		dbp->errx(dbp, "%s: Invalid numeric argument", p);
		return (1);
	}
	if (val < min) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Less than minimum value (%ld)\n",
			    CDB_progname, p, min);
			exit(1);
		}
		dbp->errx(dbp, "%s: Less than minimum value (%ld)", p, min);
		return (1);
	}

	/*
	 * We allow a 0 to substitute as a max value for ULONG_MAX because
	 * 1) accepting only a 0 value is unlikely to be necessary, and 2)
	 * we don't want callers to have to use ULONG_MAX explicitly, as it
	 * may not exist on all platforms.
	 */
	if (max != 0 && val > max) {
		if (dbp == NULL) {
			fprintf(stderr,
			    "%s: %s: Greater than maximum value (%ld)\n",
			    CDB_progname, p, max);
			exit(1);
		}
		dbp->errx(dbp, "%s: Greater than maximum value (%ld)", p, max);
		exit(1);
	}
	*storep = val;
	return (0);
#endif	/* !defined(HAVE_STRTOUL) */
}
