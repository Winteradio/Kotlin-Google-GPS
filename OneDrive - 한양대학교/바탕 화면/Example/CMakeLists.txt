#############################################################
## ----- Setting for Build
MESSAGE( STATUS "Setting for Build")

SET( PROJECT_NAME "Example" )
	## Set the Variable of "PROJECT_NAME" to "Example"
SET( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
SET( CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" )
SET( CMAKE_BUILD_TYPE Debug )
SET( CMAKE_CXX_STANDARD 17 )
	## Set the C++ version for 17

CMAKE_MINIMUM_REQUIRED( VERSION 3.11 )
	## Required minimum version for CMAKE
PROJECT( ${PROJECT_NAME} )

MESSAGE( STATUS "Done")
## ----- Setting
#############################################################


#############################################################
###################################################
### If you make new Source or Header file, ########
### Rewrite Under the Code                 ########
### Just SET Directory for New files       ########
###################################################

## ----- Source Directory
MESSAGE( STATUS "Setting for Source Files" )

SET( SRC_DIR ${CMAKE_SOURCE_DIR}/src )

## ----- Sources

SET( SRCS
	${SRC_DIR}/main.cpp
	)
MESSAGE( STATUS "Done" )
## ----- Sources
#############################################################


#############################################################
## ----- Header Files
MESSAGE( STATUS "Setting for Header Files" )

SET( INCS
	)

MESSAGE( STATUS "Done" )
## ----- Header Files
#############################################################


#############################################################
## ----- Linking files for Project in Local
ADD_EXECUTABLE( ${PROJECT_NAME} ${SRCS} )
## ----- Linking files for Project in Local
#############################################################


#############################################################
## ----- Dependency.cmake
INCLUDE( Dependency.cmake )
## ----- Dependency.cmake


## ----- Adding Option for include & library
MESSAGE( STATUS "Setting Options for Target Files")

TARGET_INCLUDE_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR} ${INCS} )
TARGET_LINK_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} PUBLIC ${DEP_LIBS} )

IF ( DEP_LIST )
	ADD_DEPENDENCIES( ${PROJECT_NAME} ${DEP_LIST} )
ENDIF()

MESSAGE( STATUS "Setting Done ")
## ----- Adding Option for include & library
#############################################################
