include $(TOPDIR)/rules.mk

PKG_NAME:=gsoap
PKG_VERSION:=2.8
PKG_RELEASE:=36

PKG_BUILD_DIR:=$(BUILD_DIR)/$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).$(PKG_RELEASE).zip
PKG_SOURCE_URL:=https://sourceforge.net/projects/gsoap2/files/$(PKG_NAME)-$(PKG_VERSION)/
PKG_MD5SUM:=6f500965431eb253271cb087b153493e

PKG_LICENSE:=GPLv2
PKG_LICENSE_FILES:=README

PKG_INSTALL:=1

define Package/gsoap
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Toolkit for SOAP and REST Web Services and XML-Based Applications
  URL:=https://sourceforge.net/projects/gsoap2/
endef

define Package/gsoap/description
	Development toolkit for Web Services and XML data bindings for C and C++.
endef

define Build/Compile
	$(call Build/Compile/Default)
endef

define Package/gsoap/install
	$(INSTALL_DIR) $(1)/usr/bin
endef

$(eval $(call BuildPackage,gsoap))

