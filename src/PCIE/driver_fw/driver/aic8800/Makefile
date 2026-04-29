CONFIG_AIC8800_WLAN_SUPPORT := m

obj-$(CONFIG_AIC8800_WLAN_SUPPORT) += aic8800_fdrv/

########## config option ##########
export CONFIG_USE_FW_REQUEST = y
export CONFIG_AIC_FW_PATH = "/lib/firmware/aic8800"
###################################

########## platform support list ##########
export CONFIG_PLATFORM_UBUNTU = y
###########################################

ifeq ($(CONFIG_PLATFORM_UBUNTU), y)
KDIR  = /lib/modules/$(shell uname -r)/build
PWD   = $(shell pwd)
KVER = $(shell uname -r)
MODDESTDIR = /lib/modules/$(KVER)/kernel/drivers/net/wireless/aic8800
SUBARCH = $(shell uname -m | sed -e s/i.86/i386/ -e s/armv.l/arm/ -e s/aarch64/arm64/)
ARCH ?= $(SUBARCH)
CROSS_COMPILE ?=
endif

MAKEFLAGS +=-j$(shell nproc)

all: modules
modules:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

install:
	mkdir -p $(MODDESTDIR)
	install -p -m 644 aic8800_fdrv/aic8800D80_fdrv.ko  $(MODDESTDIR)/
	/sbin/depmod -a ${KVER}

uninstall:
	rm -rfv $(MODDESTDIR)/aic8800D80_fdrv.ko
	/sbin/depmod -a ${KVER}

clean:
	cd aic8800_fdrv/;make clean;cd ..
	rm -rf modules.order Module.symvers .modules.order.cmd .Module.symvers.cmd .tmp_versions/
