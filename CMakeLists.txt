CMAKE_MINIMUM_REQUIRED( VERSION 3.0.0 )

# Configure project
PROJECT( Structura VERSION 1.0.0 )

OPTION( STRUCTURA_TESTS         "Build Structura test suite" OFF )
OPTION( STRUCTURA_STATIC        "Build Structura library as a static library" OFF )
OPTION( STRUCTURA_DOCUMENTATION "Build Structura documentation" OFF )

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
INCLUDE_DIRECTORIES( "${CMAKE_CURRENT_SOURCE_DIR}/includes" )

FILE( GLOB_RECURSE STRUCTURA_SOURCES "sources/*.cpp" "sources/**/*.cpp" )
FILE( GLOB_RECURSE STRUCTURA_HEADERS "includes/*.hpp" "includes/**/*.hpp" )
FILE( GLOB_RECURSE STRUCTURA_INLINES "includes/*.inl" "includes/**/*.inl" )

FILE(
    GLOB_RECURSE
    STRUCTURA_FILES
    ${STRUCTURA_SOURCES}
    ${STRUCTURA_HEADERS}
    ${STRUCTURA_INLINES}
)

# Configuring Doxygen target
IF( STRUCTURA_DOCUMENTATION )
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
ENDIF()

# Configuring linking
IF( STRUCTURA_STATIC )
	SET( STRUCTURA_LINKING STATIC )
ELSE()
	SET( STRUCTURA_LINKING SHARED )
ENDIF()

# Adding library
ADD_LIBRARY( "Structura" "${STRUCTURA_LINKING}" ${STRUCTURA_FILES} )

IF( STRUCTURA_TESTS )
	# Configuring Catch2
	ADD_SUBDIRECTORY( "${CMAKE_CURRENT_SOURCE_DIR}/submodules/Catch2" )

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
ENDIF()