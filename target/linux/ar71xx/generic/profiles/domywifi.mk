#
<<<<<<< HEAD
# Copyright (C) 2009 OpenWrt.org
=======
# Copyright (C) 2011 OpenWrt.org
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/DW33D
	NAME:=DomyWifi DW33D
<<<<<<< HEAD
	PACKAGES:=kmod-usb-core kmod-usb2 kmod-ledtrig-usbdev kmod-ath10k
=======
	PACKAGES:=kmod-usb-core kmod-usb2 kmod-usb-storage kmod-ledtrig-usbdev kmod-ath10k
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
endef

define Profile/DW33D/Description
	Package set optimized for the DomyWifi DW33D.
endef

$(eval $(call Profile,DW33D))
