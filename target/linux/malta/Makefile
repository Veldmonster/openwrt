#
# Copyright (C) 2010-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

BOARD:=malta
BOARDNAME:=MIPS Malta CoreLV board (qemu)
<<<<<<< HEAD
SUBTARGETS:=le be
=======
CPU_TYPE:=24kc
SUBTARGETS:=le be #le64 be64
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
INITRAMFS_EXTRA_FILES:=
MAINTAINER:=Florian Fainelli <florian@openwrt.org>

KERNEL_PATCHVER:=4.4

include $(INCLUDE_DIR)/target.mk

DEFAULT_PACKAGES += wpad-mini kmod-mac80211-hwsim kmod-pcnet32

$(eval $(call BuildTarget))
