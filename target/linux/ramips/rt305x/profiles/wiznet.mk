#
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/WIZFI630A
	NAME:=WIZnet WizFi630A
	PACKAGES:=\
<<<<<<< HEAD
		kmod-usb2
=======
		kmod-usb2 
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
endef

define Profile/WIZFI630A/Description
	Package set for WIZnet WizFi630A board
endef
$(eval $(call Profile,WIZFI630A))
