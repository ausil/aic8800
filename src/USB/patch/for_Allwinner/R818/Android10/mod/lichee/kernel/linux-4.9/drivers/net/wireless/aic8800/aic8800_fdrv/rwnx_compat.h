/**
 ******************************************************************************
 *
 * @file rwnx_compat.h
 *
 * Ensure driver compilation for linux 3.16 to 3.19
 *
 * To avoid too many #if LINUX_VERSION_CODE if the code, when prototype change
 * between different kernel version:
 * - For external function, define a macro whose name is the function name with
 *   _compat suffix and prototype (actually the number of parameter) of the
 *   latest version. Then latest version this macro simply call the function
 *   and for older kernel version it call the function adapting the api.
 * - For internal function (e.g. cfg80211_ops) do the same but the macro name
 *   doesn't need to have the _compat suffix when the function is not used
 *   directly by the driver
 *
 * Copyright (C) RivieraWaves 2018
 *
 ******************************************************************************
 */
#ifndef _RWNX_COMPAT_H_
#define _RWNX_COMPAT_H_
#include <linux/version.h>


/* Generic */
#include <linux/bitfield.h>

/* CFG80211 */


#define CCFS0(vht) vht->center_freq_seg0_idx
#define CCFS1(vht) vht->center_freq_seg1_idx







#define SURVEY_TIME(s) s->time
#define SURVEY_TIME_BUSY(s) s->time_busy

#define STA_TDLS_INITIATOR(sta) sta->tdls_initiator





/* MAC80211 */

#define RX_ENC_HT(s) s->encoding = RX_ENC_HT
#define RX_ENC_HT_GF(s) { s->encoding = RX_ENC_HT;      \
        s->enc_flags |= RX_ENC_FLAG_HT_GF; }
#define RX_ENC_VHT(s) s->encoding = RX_ENC_VHT
#define RX_ENC_HE(s) s->encoding = RX_ENC_HE
#define RX_ENC_FLAG_SHORT_GI(s) s->enc_flags |= RX_ENC_FLAG_SHORT_GI
#define RX_ENC_FLAG_SHORT_PRE(s) s->enc_flags |= RX_ENC_FLAG_SHORTPRE
#define RX_ENC_FLAG_LDPC(s) s->enc_flags |= RX_ENC_FLAG_LDPC
#define RX_BW_40MHZ(s) s->bw = RATE_INFO_BW_40
#define RX_BW_80MHZ(s) s->bw = RATE_INFO_BW_80
#define RX_BW_160MHZ(s) s->bw = RATE_INFO_BW_160
#define RX_NSS(s) s->nss



#ifndef CONFIG_VENDOR_RWNX_AMSDUS_TX
#endif /* CONFIG_VENDOR_RWNX_AMSDUS_TX */




/* NET */
#define rwnx_select_queue(dev, skb, sb_dev) \
    rwnx_select_queue(dev, skb, sb_dev)




/* TRACE */


/* TIME */



#endif /* _RWNX_COMPAT_H_ */
