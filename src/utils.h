#ifndef TIMESCALEDB_UTILS_H
#define TIMESCALEDB_UTILS_H

#include <postgres.h>
#include <fmgr.h>
#include <nodes/primnodes.h>
#include <catalog/pg_proc.h>
#include <utils/datetime.h>

/*
 * Convert a column value into the internal time representation.
 */
extern int64 time_value_to_internal(Datum time_val, Oid type, bool failure_ok);

/*
 * Return the period in microseconds of the first argument to date_trunc.
 * This is approximate -- to be used for planning;
 */
extern int64 date_trunc_interval_period_approx(text *units);

/*
 * Return the interval period in microseconds.
 * This is approximate -- to be used for planning;
 */
extern int64 get_interval_period_approx(Interval *interval);

extern FmgrInfo *create_fmgr(char *schema, char *function_name, int num_args);
extern RangeVar *makeRangeVarFromRelid(Oid relid);
extern int	int_cmp(const void *a, const void *b);

#define DATUM_GET(values, attno) \
	values[attno-1]

#endif							/* TIMESCALEDB_UTILS_H */
