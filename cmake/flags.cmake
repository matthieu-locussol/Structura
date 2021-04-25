# Common compilation flags (depending on build configurations)
SET( UNIX_DEFAULT_CXX_FLAGS         "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -std=c++11" )
SET( UNIX_DEFAULT_CXX_FLAGS_DEBUG   "-g3 -ggdb" )
SET( UNIX_DEFAULT_CXX_FLAGS_RELEASE "-DNDEBUG -O3" )

SET( MSVC_DEFAULT_CXX_FLAGS_DEBUG   "/D_DEBUG /DCORE_DEBUG /Od /Zi" )
SET( MSVC_DEFAULT_CXX_FLAGS_RELEASE "/DNDEBUG /Ox" )

SET( CMAKE_CXX_STANDARD 11 )

# Platform-specific compilation flags
IF( APPLE )
    MESSAGE( STATUS "${PROJECT_NAME}: Compiling on Apple with compiler " ${CMAKE_CXX_COMPILER_ID} )

    SET( CMAKE_CXX_FLAGS         "${UNIX_DEFAULT_CXX_FLAGS}                 ${CMAKE_CXX_FLAGS}" )
    SET( CMAKE_CXX_FLAGS_DEBUG   "${UNIX_DEFAULT_CXX_FLAGS_DEBUG}     ${CMAKE_CXX_FLAGS_DEBUG}" )
    SET( CMAKE_CXX_FLAGS_RELEASE "${UNIX_DEFAULT_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_RELEASE}" )
ELSEIF( UNIX OR MINGW )
    MESSAGE( STATUS "${PROJECT_NAME}: Compiling on Unix/MinGW with compiler " ${CMAKE_CXX_COMPILER} )

    SET( CMAKE_CXX_FLAGS         "${UNIX_DEFAULT_CXX_FLAGS}                 ${CMAKE_CXX_FLAGS}" )
    SET( CMAKE_CXX_FLAGS_DEBUG   "${UNIX_DEFAULT_CXX_FLAGS_DEBUG}     ${CMAKE_CXX_FLAGS_DEBUG}" )
    SET( CMAKE_CXX_FLAGS_RELEASE "${UNIX_DEFAULT_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_RELEASE}" )
ELSEIF( MSVC )
    MESSAGE( STATUS "${PROJECT_NAME}: Compiling on MSVC with compiler " ${CMAKE_CXX_COMPILER} )

    ADD_DEFINITIONS( -D_CRT_SECURE_NO_WARNINGS )
    ADD_DEFINITIONS( -D_SCL_SECURE_NO_WARNINGS )

    SET( CMAKE_CXX_FLAGS_DEBUG   "${MSVC_DEFAULT_CXX_FLAGS_DEBUG}     ${CMAKE_CXX_FLAGS_DEBUG}" )
    SET( CMAKE_CXX_FLAGS_RELEASE "${MSVC_DEFAULT_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_RELEASE}" )
ENDIF()

# Additional flags depending on build options
IF( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
    ADD_DEFINITIONS( -DNO_DEBUG_INFO )
ENDIF()

# Additional flags depending on platform
IF( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    MESSAGE( STATUS "${PROJECT_NAME}: 64 bits build" )
ELSE()
    MESSAGE( STATUS "${PROJECT_NAME}: 32 bits build" )
ENDIF()