/**
 ******************************************************************************
 *
 * @file rwnx_compat.h
 *
 * Compatibility macros for cfg80211/mac80211/net APIs.
 * Targeting kernel 6.1+; all pre-6.1 compat shims have been removed.
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
#define IEEE80211_MAX_AMPDU_BUF                             IEEE80211_MAX_AMPDU_BUF_HE
#define IEEE80211_HE_PHY_CAP6_TRIG_MU_BEAMFORMER_FB        IEEE80211_HE_PHY_CAP6_TRIG_MU_BEAMFORMING_PARTIAL_BW_FB
#define IEEE80211_HE_PHY_CAP6_TRIG_SU_BEAMFORMER_FB        IEEE80211_HE_PHY_CAP6_TRIG_SU_BEAMFORMING_FB
#define IEEE80211_HE_PHY_CAP3_RX_HE_MU_PPDU_FROM_NON_AP_STA IEEE80211_HE_PHY_CAP3_RX_PARTIAL_BW_SU_IN_20MHZ_MU

#define CCFS0(vht) vht->center_freq_seg0_idx
#define CCFS1(vht) vht->center_freq_seg1_idx

#define STA_TDLS_INITIATOR(sta) sta->tdls_initiator

#define SURVEY_TIME(s) s->time
#define SURVEY_TIME_BUSY(s) s->time_busy

/* MAC80211 */
#define RX_ENC_HT(s) (s->encoding = RX_ENC_HT)
#define RX_ENC_HT_GF(s) { s->encoding = RX_ENC_HT;      \
		s->enc_flags |= RX_ENC_FLAG_HT_GF; }
#define RX_ENC_VHT(s) (s->encoding = RX_ENC_VHT)
#define RX_ENC_HE(s) (s->encoding = RX_ENC_HE)
#define RX_ENC_FLAG_SHORT_GI(s) (s->enc_flags |= RX_ENC_FLAG_SHORT_GI)
#define RX_ENC_FLAG_SHORT_PRE(s) (s->enc_flags |= RX_ENC_FLAG_SHORTPRE)
#define RX_ENC_FLAG_LDPC(s) (s->enc_flags |= RX_ENC_FLAG_LDPC)
#define RX_BW_40MHZ(s) (s->bw = RATE_INFO_BW_40)
#define RX_BW_80MHZ(s) (s->bw = RATE_INFO_BW_80)
#define RX_BW_160MHZ(s) (s->bw = RATE_INFO_BW_160)
#define RX_NSS(s) s->nss

#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 11, 0)
#define ieee80211_cqm_rssi_notify(vif, event, level, gfp) \
    ieee80211_cqm_rssi_notify(vif, event, gfp)
#endif

#ifndef CONFIG_VENDOR_RWNX_AMSDUS_TX
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0))
#define rwnx_ops_ampdu_action(hw, vif, params) \
    rwnx_ops_ampdu_action(hw, vif, enum ieee80211_ampdu_mlme_action action, \
                          struct ieee80211_sta *sta, u16 tid, u16 *ssn, u8 buf_size)
#elif  (LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0))
#define rwnx_ops_ampdu_action(hw, vif, params) \
    rwnx_ops_ampdu_action(hw, vif, enum ieee80211_ampdu_mlme_action action, \
                          struct ieee80211_sta *sta, u16 tid, u16 *ssn, u8 buf_size, \
                          bool amsdu)
#endif
#endif /* CONFIG_VENDOR_RWNX_AMSDUS_TX */

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 2, 0)
#define IEEE80211_HW_SUPPORT_FAST_XMIT 0
#define ieee80211_hw_check(hw, feat) (hw->flags & IEEE80211_HW_##feat)
#define ieee80211_hw_set(hw, feat) {hw->flags |= IEEE80211_HW_##feat;}
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
#define rwnx_ops_sw_scan_start(hw, vif, mac_addr) \
    rwnx_ops_sw_scan_start(hw)
#define rwnx_ops_sw_scan_complete(hw, vif) \
    rwnx_ops_sw_scan_complete(hw)
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 17, 0)
#define rwnx_ops_hw_scan(hw, vif, hw_req) \
    rwnx_ops_hw_scan(hw, vif, struct cfg80211_scan_request *req)
#endif

u16 rwnx_select_txq(struct rwnx_vif *rwnx_vif, struct sk_buff *skb);
/* NET */
#define rwnx_select_queue(dev, skb, sb_dev) \
	rwnx_select_queue(dev, skb, sb_dev)

#endif /* _RWNX_COMPAT_H_ */
