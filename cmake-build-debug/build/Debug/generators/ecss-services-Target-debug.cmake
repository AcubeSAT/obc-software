# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(ecss-services_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(ecss-services_FRAMEWORKS_FOUND_DEBUG "${ecss-services_FRAMEWORKS_DEBUG}" "${ecss-services_FRAMEWORK_DIRS_DEBUG}")

set(ecss-services_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET ecss-services_DEPS_TARGET)
    add_library(ecss-services_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET ecss-services_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${ecss-services_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${ecss-services_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:logger::logger;etl::etl>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### ecss-services_DEPS_TARGET to all of them
conan_package_library_targets("${ecss-services_LIBS_DEBUG}"    # libraries
                              "${ecss-services_LIB_DIRS_DEBUG}" # package_libdir
                              "${ecss-services_BIN_DIRS_DEBUG}" # package_bindir
                              "${ecss-services_LIBRARY_TYPE_DEBUG}"
                              "${ecss-services_IS_HOST_WINDOWS_DEBUG}"
                              ecss-services_DEPS_TARGET
                              ecss-services_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "ecss-services"    # package_name
                              "${ecss-services_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${ecss-services_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET common
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${ecss-services_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${ecss-services_LIBRARIES_TARGETS}>
                 APPEND)

    if("${ecss-services_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET common
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     ecss-services_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET common
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${ecss-services_LINKER_FLAGS_DEBUG}> APPEND)
    set_property(TARGET common
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${ecss-services_INCLUDE_DIRS_DEBUG}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET common
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${ecss-services_LIB_DIRS_DEBUG}> APPEND)
    set_property(TARGET common
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${ecss-services_COMPILE_DEFINITIONS_DEBUG}> APPEND)
    set_property(TARGET common
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${ecss-services_COMPILE_OPTIONS_DEBUG}> APPEND)

########## For the modules (FindXXX)
set(ecss-services_LIBRARIES_DEBUG common)
