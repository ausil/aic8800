#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/pm_wakeirq.h>
#include "rwnx_defs.h"
#include "rwnx_wakelock.h"

struct wakeup_source *rwnx_wakeup_init(const char *name)
{
	return wakeup_source_register(NULL, name);
}

void rwnx_wakeup_deinit(struct wakeup_source *ws)
{
	if (ws && ws->active)
		__pm_relax(ws);
	wakeup_source_unregister(ws);
}

struct wakeup_source *rwnx_wakeup_register(struct device *dev, const char *name)
{

	return wakeup_source_register(dev, name);
}

void rwnx_wakeup_unregister(struct wakeup_source *ws)
{
	if (ws && ws->active)
		__pm_relax(ws);
	wakeup_source_unregister(ws);
}

void rwnx_wakeup_lock(struct wakeup_source *ws)
{
	__pm_stay_awake(ws);
}

void rwnx_wakeup_unlock(struct wakeup_source *ws)
{
	__pm_relax(ws);
}

void rwnx_wakeup_lock_timeout(struct wakeup_source *ws, unsigned int msec)
{
	__pm_wakeup_event(ws, msec);
}

void aicwf_wakeup_lock_init(struct rwnx_hw *rwnx_hw)
{
	rwnx_hw->ws_tx = rwnx_wakeup_init("rwnx_tx_wakelock");
	rwnx_hw->ws_rx = rwnx_wakeup_init("rwnx_rx_wakelock");
    rwnx_hw->ws_irqrx = rwnx_wakeup_init("rwnx_irqrx_wakelock");
	rwnx_hw->ws_pwrctrl = rwnx_wakeup_init("rwnx_pwrcrl_wakelock");
}

void aicwf_wakeup_lock_deinit(struct rwnx_hw *rwnx_hw)
{
	rwnx_wakeup_deinit(rwnx_hw->ws_tx);
	rwnx_wakeup_deinit(rwnx_hw->ws_rx);
	rwnx_wakeup_deinit(rwnx_hw->ws_irqrx);
	rwnx_wakeup_deinit(rwnx_hw->ws_pwrctrl);
	rwnx_hw->ws_tx = NULL;
	rwnx_hw->ws_rx = NULL;
	rwnx_hw->ws_irqrx = NULL;
	rwnx_hw->ws_pwrctrl = NULL;
}

