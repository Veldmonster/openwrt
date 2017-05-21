#
# Copyright (C) 2015 OpenWrt.org
#

SUBTARGET:=mt7688
BOARDNAME:=MT7688 based boards
<<<<<<< HEAD
ARCH_PACKAGES:=ramips_24kec
=======
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
FEATURES+=usb
CPU_TYPE:=24kec
CPU_SUBTYPE:=dsp

<<<<<<< HEAD
=======
DEFAULT_PACKAGES += kmod-mt76

>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
define Target/Description
	Build firmware images for Ralink MT7688 based boards.
endef

