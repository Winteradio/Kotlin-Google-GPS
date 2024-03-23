## ----- External Project
MESSAGE( STATUS "Setting for ExternalProject")

INCLUDE( ExternalProject )

MESSAGE( STATUS "Done")
## ----- External Project


## ----- Setting for Dependency
MESSAGE( STATUS "Setting Variables for Dependency")

SET( DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install )
SET( DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include )
SET( DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib )

SET( DEP_LIST ${DEP_LIST} )
SET( DEP_LIBS ${DEP_LIBS} )

MESSAGE( STATUS "Done")
## ----- Setting for Dependency


## ----- WIN API
IF ( WIN32 OR WIN64 OR MSVC )
MESSAGE( STATUS "Window - Linking")

SET( WINDOWSDK_INCLUDE_DIR
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\shared"
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\um"
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\winrt
	")

SET( WINDOWSDK_LIB_DIR
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\um"
	)

SET( WINDOWSDK_LIBS winMM.lib Pdh.lib)

TARGET_INCLUDE_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${WINDOWSDK_INCLUDE_DIR} )
TARGET_LINK_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${WINDOWSDK_LIB_DIR} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} PUBLIC ${WINDOWSDK_LIBS})

MESSAGE( STATUS "WindowSDK - Done")
endif()
## ----- WIN API