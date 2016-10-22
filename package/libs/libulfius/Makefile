include $(TOPDIR)/rules.mk

PKG_NAME:=libulfius
PKG_RELEASE:=1.0

PKG_LICENSE:=LGPL-2.1
PKG_LICENSE_FILES:=README

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

MAKE_FLAGS += PREFIX="$(PKG_INSTALL_DIR)/usr"

define Package/libulfius
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Web Framework for REST Applications in C.
  DEPENDS:=+libmicrohttpd +libcurl +jansson
  URL:=https://github.com/babelouest/ulfius
endef

define Package/libulfius/description
	Web Framework for REST Applications in C.
endef

# The Github hosted solution has two dependand repositories (orcania and yder)
# which I was not able to refrence with PKG_SOURCE_URL.
# Instead of using PKG_SOURCE_URL, I download the required files from Github
# and extracted them into a files folder located within the package, libulfius
# directory.
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./files/* $(PKG_BUILD_DIR)/
endef

define Build/InstallDev
	mkdir -p $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include

	mkdir -p $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

define Package/libulfius/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libulfius))

