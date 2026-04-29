/**
 ******************************************************************************
 *
 * @file rwnx_compat.h
 *
 * Minimal compatibility shims for kernel 6.1+
 *
 * Copyright (C) RivieraWaves 2018
 *
 ******************************************************************************
 */
#ifndef _RWNX_COMPAT_H_
#define _RWNX_COMPAT_H_
#include <linux/version.h>
#include <linux/bitfield.h>

/* CFG80211 */
/* CCFS0/CCFS1: kernel >= 4.12 field names (center_freq_seg0/1_idx) */
#define CCFS0(vht) vht->center_freq_seg0_idx
#define CCFS1(vht) vht->center_freq_seg1_idx

/* Survey time fields: kernel >= 4.0 names */
#define SURVEY_TIME(s) s->time
#define SURVEY_TIME_BUSY(s) s->time_busy

/* REGULATORY_IGNORE_STALE_KICKOFF was removed in kernel 6.1; define as 0 if absent */
#ifndef REGULATORY_IGNORE_STALE_KICKOFF
#define REGULATORY_IGNORE_STALE_KICKOFF 0
#endif

#endif /* _RWNX_COMPAT_H_ */
