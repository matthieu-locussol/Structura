CMAKE_MINIMUM_REQUIRED( VERSION 3.0.0 )

# Configure project
PROJECT( Structura )

# Configuration CMake Module Path
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )

# Choose default build type (if none specified)
IF( NOT CMAKE_BUILD_TYPE )
    SET( CMAKE_BUILD_TYPE Debug )
ENDIF()

# Disable in-source builds
IF( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    MESSAGE( FATAL_ERROR "In-source builds are not allowed. Please create a new directory (i.e. a build/ directory)." )
ENDIF()

# Compilation flags
INCLUDE( flags )

# Set prefix path if none specified
IF( NOT CMAKE_PREFIX_PATH )
    SET( CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR} )
ENDIF()

# Configure Structura sources
INCLUDE_DIRECTORIES( "${CMAKE_CURRENT_SOURCE_DIR}/src" )

FILE( GLOB_RECURSE STRUCTURA_SOURCES "src/**/*.cpp" )
FILE( GLOB_RECURSE STRUCTURA_HEADERS "src/**/*.hpp" )
FILE( GLOB_RECURSE STRUCTURA_INLINES "src/**/*.inl" )

FILE(
    GLOB_RECURSE
    STRUCTURA_FILES
    ${STRUCTURA_SOURCES}
    ${STRUCTURA_HEADERS}
    ${STRUCTURA_INLINES}
)

# Configuring Catch2
ADD_SUBDIRECTORY( "${CMAKE_CURRENT_SOURCE_DIR}/submodules/Catch2" )

# Configuring Doxygen target
FIND_PACKAGE( Doxygen )

IF( DOXYGEN_FOUND )
    SET( DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in )
    SET( DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile )

    CONFIGURE_FILE( ${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY )

    ADD_CUSTOM_TARGET(
      Documentation ALL
   	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
      COMMENT "Generating documentation using Doxygen."
      VERBATIM
    )
ELSE()
    MESSAGE( STATUS "${PROJECT_NAME}: Doxygen needs to be installed to generate documentation." )
ENDIF()

# Configuring linking
IF( STRUCTURA_STATIC )
	SET( STRUCTURA_LINKING STATIC )
ELSE()
	SET( STRUCTURA_LINKING SHARED )
ENDIF()

# Adding library
ADD_LIBRARY( "Structura" "${STRUCTURA_LINKING}" ${STRUCTURA_FILES} )

# Adding tests
FILE( GLOB_RECURSE STRUCTURA_TESTS_SOURCES "tests/**/*.cpp" )

FILE(
    GLOB_RECURSE
    STRUCTURA_TESTS_FILES
    ${STRUCTURA_TESTS_SOURCES}
)

ADD_EXECUTABLE( "StructuraTests" ${STRUCTURA_TESTS_FILES} )
TARGET_LINK_LIBRARIES( "StructuraTests" PRIVATE "Structura" )
TARGET_LINK_LIBRARIES( "StructuraTests" PRIVATE Catch2::Catch2WithMain )