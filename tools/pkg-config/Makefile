# 
<<<<<<< HEAD
# Copyright (C) 2006-2015 OpenWrt.org
=======
# Copyright (C) 2006-2016 OpenWrt.org
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=pkg-config
<<<<<<< HEAD
PKG_VERSION:=0.29

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pkgconfig.freedesktop.org/releases/
PKG_MD5SUM:=77f27dce7ef88d0634d0d6f90e03a77f
=======
PKG_VERSION:=0.29.1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pkgconfig.freedesktop.org/releases/
PKG_MD5SUM:=f739a28cae4e0ca291f82d1d41ef107d
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600

HOST_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/host-build.mk

unexport PKG_CONFIG

HOST_CONFIGURE_ARGS += --with-internal-glib

ifeq ($(HOST_OS),Darwin)
HOST_LDFLAGS += -framework CoreFoundation -framework Carbon
endif

define Host/Install
	$(MAKE) -C $(HOST_BUILD_DIR) install
	mv $(STAGING_DIR_HOST)/bin/pkg-config $(STAGING_DIR_HOST)/bin/pkg-config.real
	$(INSTALL_BIN) ./files/pkg-config $(STAGING_DIR_HOST)/bin/pkg-config
endef

define Host/Clean
	-$(MAKE) -C $(HOST_BUILD_DIR) uninstall
	$(call Host/Clean/Default)
endef

$(eval $(call HostBuild))
