########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(ecss-services_FIND_QUIETLY)
    set(ecss-services_MESSAGE_MODE VERBOSE)
else()
    set(ecss-services_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/ecss-servicesTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${ecss-services_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(ecss-services_VERSION_STRING "1.1")
set(ecss-services_INCLUDE_DIRS ${ecss-services_INCLUDE_DIRS_DEBUG} )
set(ecss-services_INCLUDE_DIR ${ecss-services_INCLUDE_DIRS_DEBUG} )
set(ecss-services_LIBRARIES ${ecss-services_LIBRARIES_DEBUG} )
set(ecss-services_DEFINITIONS ${ecss-services_DEFINITIONS_DEBUG} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${ecss-services_BUILD_MODULES_PATHS_DEBUG} )
    message(${ecss-services_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


