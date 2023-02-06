#############################################################
## ----- Setting for Build
MESSAGE( STATUS "Setting Variables")

## Make Project Name
SET( PROJECT_NAME "Example" )
## Set Compiler
SET( CMAKE_CXX_COMPILER g++ )
SET( CMAKE_C_COMPILER gcc )
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
SET( CMAKE_BUILD_TYPE Debug )
## Set CXX Compiler Version
IF(MSVC)
MESSAGE( STATUS "Setting C++17")
ENDIF(MSVC)

## CMake minimun version required
CMAKE_MINIMUM_REQUIRED( VERSION 3.11 )
## Project name
PROJECT( ${PROJECT_NAME} )
## Set compile options

MESSAGE( STATUS "Setting Done")
## ----- Setting
#############################################################


#############################################################
## ----- Source
MESSAGE( STATUS "Setting for Source Files" )

SET( SRC_DIR ${CMAKE_SOURCE_DIR}/src )
SET( IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui )
SET( LOG_DIR ${SRC_DIR}/LOG )

###################################################
### If you make new Source or Header file, ########
### Rewrite Under the Code                 ########
### Just SET Directory for New files       ########
###################################################


## Source Files
SET( SRCS
	${SRC_DIR}/main.cpp

	${LOG_DIR}/Log.h ${LOG_DIR}/Log.cpp
	)

SET( IMGUI
	${IMGUI_DIR}/imgui_demo.cpp
	${IMGUI_DIR}/imgui.cpp
	${IMGUI_DIR}/imgui_draw.cpp
	${IMGUI_DIR}/imgui_tables.cpp
	${IMGUI_DIR}/imgui_widgets.cpp
	)

MESSAGE( STATUS "Done" )
## ----- Source
#############################################################


#############################################################
## ----- Header Files
MESSAGE( STATUS "Setting for Header Files" )

## Header Files
SET( INCS
	${IMGUI_DIR}

	${LOG_DIR}
	)
MESSAGE( STATUS "Done" )
## ----- Header Files
#############################################################


#############################################################
## ----- Linking files for Project in Local
ADD_EXECUTABLE( ${PROJECT_NAME} WIN32 ${SRCS} ${IMGUIS})
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

MESSAGE( STATUS "Setting Done ")
## ----- Adding Option for include & library
#############################################################