/* DO NOT EDIT: automatically built by dist/distrib. */
#ifndef	_hash_ext_h_
#define	_hash_ext_h_
#if defined(__cplusplus)
extern "C" {
#endif
int CDB___ham_metachk __P((DB *, const char *, HMETA *));
int CDB___ham_open __P((DB *, const char *, db_pgno_t, u_int32_t));
int CDB___ham_c_init __P((DBC *));
int CDB___ham_c_count __P((DBC *, db_recno_t *));
int CDB___ham_c_dup __P((DBC *, DBC *));
u_int32_t CDB___ham_call_hash __P((DBC *, u_int8_t *, int32_t));
int CDB___ham_init_dbt __P((DB_ENV *,
    DBT *, u_int32_t, void **, u_int32_t *));
void CDB___ham_c_update
   __P((DBC *, db_pgno_t, u_int32_t, int, int));
int CDB___ham_get_clist __P((DB *,
    db_pgno_t, u_int32_t, DBC ***));
void CDB___ham_c_chgpg
   __P((DBC *, db_pgno_t, u_int32_t, db_pgno_t, u_int32_t));
int CDB___ham_pgin __P((DB_ENV *, db_pgno_t, void *, DBT *));
int CDB___ham_pgout __P((DB_ENV *, db_pgno_t, void *, DBT *));
int CDB___ham_mswap __P((void *));
int CDB___ham_add_dup __P((DBC *, DBT *, u_int32_t, db_pgno_t *));
int CDB___ham_dup_convert __P((DBC *));
int CDB___ham_make_dup __P((DB_ENV *,
    const DBT *, DBT *d, void **, u_int32_t *));
void CDB___ham_move_offpage __P((DBC *, PAGE *, u_int32_t, db_pgno_t));
void CDB___ham_dsearch __P((DBC *, DBT *, u_int32_t *, int *));
int CDB___ham_cprint __P((DB *));
u_int32_t CDB___ham_func2 __P((const void *, u_int32_t));
u_int32_t CDB___ham_func3 __P((const void *, u_int32_t));
u_int32_t CDB___ham_func4 __P((const void *, u_int32_t));
u_int32_t CDB___ham_func5 __P((const void *, u_int32_t));
int CDB___ham_get_meta __P((DBC *));
int CDB___ham_release_meta __P((DBC *));
int CDB___ham_dirty_meta __P((DBC *));
int CDB___ham_db_create __P((DB *));
int CDB___ham_db_close __P((DB *));
int CDB___ham_item __P((DBC *, db_lockmode_t, db_pgno_t *));
int CDB___ham_item_reset __P((DBC *));
void CDB___ham_item_init __P((DBC *));
int CDB___ham_item_last __P((DBC *, db_lockmode_t, db_pgno_t *));
int CDB___ham_item_first __P((DBC *, db_lockmode_t, db_pgno_t *));
int CDB___ham_item_prev __P((DBC *, db_lockmode_t, db_pgno_t *));
int CDB___ham_item_next __P((DBC *, db_lockmode_t, db_pgno_t *));
void CDB___ham_putitem __P((PAGE *p, const DBT *, int));
void CDB___ham_reputpair
   __P((PAGE *p, u_int32_t, u_int32_t, const DBT *, const DBT *));
int CDB___ham_del_pair __P((DBC *, int));
int CDB___ham_replpair __P((DBC *, DBT *, u_int32_t));
void CDB___ham_onpage_replace __P((PAGE *, size_t, u_int32_t, int32_t,
    int32_t,  DBT *));
int CDB___ham_split_page __P((DBC *, u_int32_t, u_int32_t));
int CDB___ham_add_el __P((DBC *, const DBT *, const DBT *, int));
void CDB___ham_copy_item __P((size_t, PAGE *, u_int32_t, PAGE *));
int CDB___ham_add_ovflpage __P((DBC *, PAGE *, int, PAGE **));
int CDB___ham_put_page __P((DB *, PAGE *, int32_t));
int CDB___ham_dirty_page __P((DB *, PAGE *));
int CDB___ham_get_page __P((DB *, db_pgno_t, PAGE **));
db_pgno_t CDB___bucket_to_page __P((HASH_CURSOR *, db_pgno_t));
int CDB___ham_get_cpage __P((DBC *, db_lockmode_t));
int CDB___ham_next_cpage __P((DBC *, db_pgno_t, int));
int CDB___ham_lock_bucket __P((DBC *, db_lockmode_t));
void CDB___ham_dpair __P((DB *, PAGE *, u_int32_t));
int CDB___ham_insdel_recover
    __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_newpage_recover
    __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_replace_recover
   __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_splitdata_recover
   __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_copypage_recover
  __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_metagroup_recover
  __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_groupalloc_recover
  __P((DB_ENV *, DBT *, DB_LSN *, db_recops, void *));
int CDB___ham_reclaim __P((DB *, DB_TXN *txn));
int CDB___ham_stat __P((DB *, void *, void *(*)(size_t), u_int32_t));
 int CDB___ham_traverse __P((DB *, DBC *, db_lockmode_t,
    int (*)(DB *, PAGE *, void *, int *), void *));
int CDB___ham_30_hashmeta __P((DB *, char *, u_int8_t *));
int CDB___ham_31_hashmeta
     __P((DB *, char *, u_int32_t, DB_FH *, PAGE *, int *));
int CDB___ham_31_hash
     __P((DB *, char *, u_int32_t, DB_FH *, PAGE *, int *));
int CDB___ham_vrfy_meta __P((DB *, VRFY_DBINFO *, HMETA *,
    db_pgno_t, u_int32_t));
int CDB___ham_vrfy __P((DB *, VRFY_DBINFO *, PAGE *, db_pgno_t,
    u_int32_t));
int CDB___ham_vrfy_structure __P((DB *, VRFY_DBINFO *, db_pgno_t,
    u_int32_t));
int CDB___ham_vrfy_hashing __P((DB *,
    u_int32_t, HMETA *, u_int32_t, db_pgno_t, u_int32_t,
    u_int32_t (*) __P((const void *, u_int32_t))));
int CDB___ham_salvage __P((DB *, VRFY_DBINFO *, db_pgno_t, PAGE *,
    void *, int (*)(void *, const void *), u_int32_t));
int CDB___ham_meta2pgset __P((DB *, VRFY_DBINFO *, HMETA *, u_int32_t,
    DB *));
#if defined(__cplusplus)
}
#endif
#endif /* _hash_ext_h_ */
