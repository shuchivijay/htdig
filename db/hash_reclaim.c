/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1996, 1997, 1998, 1999, 2000
 *	Sleepycat Software.  All rights reserved.
 */

#include "config.h"

#ifndef lint
static const char revid[] = "$Id: hash_reclaim.c,v 1.1.2.2 2000/09/14 03:13:21 ghutchis Exp $";
#endif /* not lint */

#ifndef NO_SYSTEM_INCLUDES
#include <sys/types.h>

#include <errno.h>
#include <string.h>
#endif

#include "db_int.h"
#include "db_page.h"
#include "db_shash.h"
#include "hash.h"
#include "lock.h"

/*
 * CDB___ham_reclaim --
 *	Reclaim the pages from a subdatabase and return them to the
 * parent free list.  For now, we link each freed page on the list
 * separately.  If people really store hash databases in subdatabases
 * and do a lot of creates and deletes, this is going to be a problem,
 * because hash needs chunks of contiguous storage.  We may eventually
 * need to go to a model where we maintain the free list with chunks of
 * contiguous pages as well.
 *
 * PUBLIC: int CDB___ham_reclaim __P((DB *, DB_TXN *txn));
 */
int
CDB___ham_reclaim(dbp, txn)
	DB *dbp;
	DB_TXN *txn;
{
	DBC *dbc;
	HASH_CURSOR *hcp;
	int ret;

	/* Open up a cursor that we'll use for traversing. */
	if ((ret = dbp->cursor(dbp, txn, &dbc, 0)) != 0)
		return (ret);
	hcp = (HASH_CURSOR *)dbc->internal;

	if ((ret = CDB___ham_get_meta(dbc)) != 0)
		goto err;

	if ((ret = CDB___ham_traverse(dbp,
	    dbc, DB_LOCK_WRITE, CDB___db_reclaim_callback, dbc)) != 0)
		goto err;
	if ((ret = dbc->c_close(dbc)) != 0)
		goto err;
	if ((ret = CDB___ham_release_meta(dbc)) != 0)
		goto err;
	return (0);

err:	if (hcp->hdr != NULL)
		(void)CDB___ham_release_meta(dbc);
	(void)dbc->c_close(dbc);
	return (ret);
}
