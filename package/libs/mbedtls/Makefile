#
# Copyright (C) 2011-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mbedtls
<<<<<<< HEAD
PKG_VERSION:=2.2.1
PKG_RELEASE:=1
=======
PKG_VERSION:=2.3.0
PKG_RELEASE:=2
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
PKG_USE_MIPS16:=0

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-gpl.tgz
PKG_SOURCE_URL:=https://tls.mbed.org/download/
<<<<<<< HEAD
PKG_MD5SUM:=b6909d94600fc5f644e9bca52e96fb27
=======
PKG_MD5SUM:=21237014f779bde70b2d71399cc1ea53365eb7f10cdd74a13ee6329a1910cb49
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600

PKG_BUILD_PARALLEL:=1
PKG_LICENSE:=GPL-2.0+

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/mbedtls/Default
  SUBMENU:=SSL
  TITLE:=Embedded SSL
  URL:=https://tls.mbed.org
endef

define Package/mbedtls/Default/description
The aim of the mbedtls project is to provide a quality, open-source
cryptographic library written in C and targeted at embedded systems.
endef

define Package/libmbedtls
$(call Package/mbedtls/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE+= (library)
  ABI_VERSION:=$(PKG_VERSION)-$(PKG_RELEASE)
endef

define Package/libmbedtls/description
$(call Package/mbedtls/Default/description)
This package contains the mbedtls library.
endef

PKG_INSTALL:=1

CMAKE_OPTIONS += \
	-DCMAKE_BUILD_TYPE:String="Release" \
	-DUSE_SHARED_MBEDTLS_LIBRARY:Bool=ON \
	-DENABLE_TESTING:Bool=OFF \
	-DENABLE_PROGRAMS:Bool=OFF \

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/mbedtls $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
<<<<<<< HEAD
	$(LN) lib$(PKG_NAME).so.9 $(1)/usr/lib/lib$(PKG_NAME).so
=======
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
endef

define Package/libmbedtls/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
<<<<<<< HEAD
	$(LN) lib$(PKG_NAME).so.09 $(1)/usr/lib/lib$(PKG_NAME).so
endef

$(eval $(call BuildPackage,libmbedtls))

=======
endef

$(eval $(call BuildPackage,libmbedtls))
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
