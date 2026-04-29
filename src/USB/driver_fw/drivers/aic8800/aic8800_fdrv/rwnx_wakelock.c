#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/pm_wakeirq.h>
#include "rwnx_defs.h"
#include "rwnx_wakelock.h"

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 16, 0)
struct wakeup_source *rwnx_wakeup_init(const char *name)
{
	struct wakeup_source *ws;
	ws = wakeup_source_register(NULL, name);
	return ws;
}

void rwnx_wakeup_deinit(struct wakeup_source *ws)
{
	if (ws && ws->active)
		__pm_relax(ws);
	wakeup_source_unregister(ws);
}
#endif
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
    AICWFDBG(LOGDEBUG, "%s enter \r\n", __func__);
	__pm_stay_awake(ws);
}

void rwnx_wakeup_unlock(struct wakeup_source *ws)
{
    AICWFDBG(LOGDEBUG, "%s enter \r\n", __func__);
	__pm_relax(ws);
}

void rwnx_wakeup_lock_timeout(struct wakeup_source *ws, unsigned int msec)
{
	__pm_wakeup_event(ws, msec);
}

void aicwf_wakeup_lock_init(struct rwnx_hw *rwnx_hw)
{
	#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 16, 0)
	 struct aic_usb_dev *usbdev = rwnx_hw->usbdev;
	rwnx_hw->ws_tx = rwnx_wakeup_register(usbdev->dev, "rwnx_tx_wakelock");
	rwnx_hw->ws_rx = rwnx_wakeup_register(usbdev->dev,"rwnx_rx_wakelock");
	rwnx_hw->ws_irqrx = rwnx_wakeup_register(usbdev->dev, "rwnx_irqrx_wakelock");
	rwnx_hw->ws_pwrctrl = rwnx_wakeup_register(usbdev->dev, "rwnx_pwrcrl_wakelock");
	#else
	rwnx_hw->ws_tx = rwnx_wakeup_init("rwnx_tx_wakelock");
	rwnx_hw->ws_rx = rwnx_wakeup_init("rwnx_rx_wakelock");
    rwnx_hw->ws_irqrx = rwnx_wakeup_init("rwnx_irqrx_wakelock");
	rwnx_hw->ws_pwrctrl = rwnx_wakeup_init("rwnx_pwrcrl_wakelock");
	#endif
}

void aicwf_wakeup_lock_deinit(struct rwnx_hw *rwnx_hw)
{
	#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 16, 0)
	rwnx_wakeup_unregister(rwnx_hw->ws_tx);
	rwnx_wakeup_unregister(rwnx_hw->ws_rx);
	rwnx_wakeup_unregister(rwnx_hw->ws_irqrx);
	rwnx_wakeup_unregister(rwnx_hw->ws_pwrctrl);
	#else
	rwnx_wakeup_deinit(rwnx_hw->ws_tx);
	rwnx_wakeup_deinit(rwnx_hw->ws_rx);
	rwnx_wakeup_deinit(rwnx_hw->ws_irqrx);
	rwnx_wakeup_deinit(rwnx_hw->ws_pwrctrl);
	#endif
	rwnx_hw->ws_tx = NULL;
	rwnx_hw->ws_rx = NULL;
	rwnx_hw->ws_irqrx = NULL;
	rwnx_hw->ws_pwrctrl = NULL;
}

