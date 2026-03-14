savedcmd_aic8800_fdrv/rwnx_gki.o := gcc -Wp,-MMD,aic8800_fdrv/.rwnx_gki.o.d -nostdinc -I/usr/src/kernels/6.19.6-300.fc44.aarch64/arch/arm64/include -I/usr/src/kernels/6.19.6-300.fc44.aarch64/arch/arm64/include/generated -I/usr/src/kernels/6.19.6-300.fc44.aarch64/include -I/usr/src/kernels/6.19.6-300.fc44.aarch64/include -I/usr/src/kernels/6.19.6-300.fc44.aarch64/arch/arm64/include/uapi -I/usr/src/kernels/6.19.6-300.fc44.aarch64/arch/arm64/include/generated/uapi -I/usr/src/kernels/6.19.6-300.fc44.aarch64/include/uapi -I/usr/src/kernels/6.19.6-300.fc44.aarch64/include/generated/uapi -include /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler-version.h -include /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/kconfig.h -include /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler_types.h -D__KERNEL__ -mlittle-endian -DCC_USING_PATCHABLE_FUNCTION_ENTRY -DKASAN_SHADOW_SCALE_SHIFT= -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mgeneral-regs-only -DCONFIG_CC_HAS_K_CONSTRAINT=1 -Wno-psabi -mabi=lp64 -fno-asynchronous-unwind-tables -fno-unwind-tables -mbranch-protection=pac-ret -Wa,-march=armv8.5-a -DARM64_ASM_ARCH='"armv8.5-a"' -DKASAN_SHADOW_SCALE_SHIFT= -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -ftrivial-auto-var-init=zero -fzero-init-padding-bits=all -fno-stack-clash-protection -fdiagnostics-show-context=2 -fpatchable-function-entry=4,2 -fno-inline-functions-called-once -fmin-function-alignment=8 -fstrict-flex-arrays=3 -fms-extensions -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -Wall -Wextra -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=2048 -Wno-main -Wno-dangling-pointer -Wvla-larger-than=1 -Wno-pointer-sign -Wcast-function-type -Wno-unterminated-string-initialization -Wno-array-bounds -Wno-stringop-overflow -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g -mstack-protector-guard=sysreg -mstack-protector-guard-reg=sp_el0 -mstack-protector-guard-offset=2328 -DCONFIG_RWNX_DEBUGFS -DCONFIG_RWNX_UM_HELPER_DFLT=\""/dini/dini_bin/rwnx_umh.sh"\" -DNX_VIRT_DEV_MAX=4 -DNX_REMOTE_STA_MAX_FOR_OLD_IC=32 -DNX_REMOTE_STA_MAX=32 -DNX_MU_GROUP_MAX=62 -DNX_TXDESC_CNT=64 -DNX_TX_MAX_RATES=4 -DNX_CHAN_CTXT_CNT=3 -DCONFIG_START_FROM_BOOTROM -DCONFIG_VRF_DCDC_MODE -DCONFIG_COEX -DCONFIG_RWNX_FULLMAC -I/usr/src/kernels/6.19.6-300.fc44.aarch64 -I/usr/src/kernels/6.19.6-300.fc44.aarch64/./aic8800_fdrv -I/usr/src/kernels/6.19.6-300.fc44.aarch64/./aic8800_fdrv/../aic8800_bsp -DCONFIG_AIC_FW_PATH=\""/lib/firmware/aic8800"\" -DCONFIG_RWNX_RADAR -DCONFIG_RWNX_MON_DATA -DCONFIG_RWNX_DBG -DCONFIG_RFTEST -DDEFAULT_COUNTRY_CODE=""\"00""\" -DUSE_5G -DCONFIG_SUPPORT_REALTIME_CHANGE_MAC -DCONFIG_USE_FW_REQUEST -DCONFIG_FILTER_TCP_ACK -DCONFIG_ONE_TXQ -DCONFIG_CACHE_GUARD -DAICWF_PCIE_SUPPORT -DCONFIG_USER_MAX=1 -DNX_TXQ_CNT=5 -DAICWF_RX_REORDER -DAICWF_ARP_OFFLOAD -DCONFIG_DOWNLOAD_FW -DCONFIG_RX_NETIF_RECV_SKB -DAIC_TRACE_INCLUDE_PATH=./aic8800_fdrv  -fsanitize=bounds-strict -fsanitize=shift    -DMODULE  -DKBUILD_BASENAME='"rwnx_gki"' -DKBUILD_MODNAME='"aic8800D80_fdrv"' -D__KBUILD_MODNAME=aic8800D80_fdrv -c -o aic8800_fdrv/rwnx_gki.o aic8800_fdrv/rwnx_gki.c  

source_aic8800_fdrv/rwnx_gki.o := aic8800_fdrv/rwnx_gki.c

deps_aic8800_fdrv/rwnx_gki.o := \
    $(wildcard include/config/GKI_OPT_FEATURES) \
    $(wildcard include/config/ANDROID) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/CC_HAS_ASSUME) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/CC_HAS_MULTIDIMENSIONAL_NONSTRING) \
    $(wildcard include/config/UBSAN_INTEGER_WRAP) \
    $(wildcard include/config/CFI) \
    $(wildcard include/config/ARCH_USES_CFI_GENERIC_LLVM_PASS) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler_attributes.h \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/linux/compiler-gcc.h \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
    $(wildcard include/config/CC_HAS_TYPEOF_UNQUAL) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/arch/arm64/include/asm/compiler.h \
    $(wildcard include/config/ARM64_PTR_AUTH_KERNEL) \
    $(wildcard include/config/ARM64_PTR_AUTH) \
    $(wildcard include/config/BUILTIN_RETURN_ADDRESS_STRIPS_PAC) \
  /usr/src/kernels/6.19.6-300.fc44.aarch64/include/generated/uapi/linux/version.h \

aic8800_fdrv/rwnx_gki.o: $(deps_aic8800_fdrv/rwnx_gki.o)

$(deps_aic8800_fdrv/rwnx_gki.o):
