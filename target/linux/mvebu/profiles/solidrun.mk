#
# Copyright (C) 2016 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/Solidrun-Clearfog-A1
  NAME:=SolidRun ClearFog A1 board
<<<<<<< HEAD
  PACKAGES:= \
	kmod-usb3 kmod-usb2 kmod-usb-storage \
	kmod-of-i2c kmod-i2c-core kmod-i2c-mv64xxx \
	kmod-ata-core kmod-ata-marvell-sata \
	kmod-thermal-armada kmod-rtc-marvell
=======
  PACKAGES:=
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
endef

define Profile/Solidrun-Clearfog-A1/Description
 Package set compatible with the SolidRun ClearFog A1 board
endef

$(eval $(call Profile,Solidrun-Clearfog-A1))
