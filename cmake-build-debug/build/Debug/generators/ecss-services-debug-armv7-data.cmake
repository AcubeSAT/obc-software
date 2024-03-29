########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(ecss-services_COMPONENT_NAMES "")
list(APPEND ecss-services_FIND_DEPENDENCY_NAMES logger etl)
list(REMOVE_DUPLICATES ecss-services_FIND_DEPENDENCY_NAMES)
set(logger_FIND_MODE "NO_MODULE")
set(etl_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(ecss-services_PACKAGE_FOLDER_DEBUG "/home/ktsoupos/.conan2/p/ecss-388a2fb519b10/p")
set(ecss-services_BUILD_MODULES_PATHS_DEBUG )


set(ecss-services_INCLUDE_DIRS_DEBUG "${ecss-services_PACKAGE_FOLDER_DEBUG}/inc")
set(ecss-services_RES_DIRS_DEBUG )
set(ecss-services_DEFINITIONS_DEBUG )
set(ecss-services_SHARED_LINK_FLAGS_DEBUG )
set(ecss-services_EXE_LINK_FLAGS_DEBUG )
set(ecss-services_OBJECTS_DEBUG )
set(ecss-services_COMPILE_DEFINITIONS_DEBUG )
set(ecss-services_COMPILE_OPTIONS_C_DEBUG )
set(ecss-services_COMPILE_OPTIONS_CXX_DEBUG )
set(ecss-services_LIB_DIRS_DEBUG "${ecss-services_PACKAGE_FOLDER_DEBUG}/lib")
set(ecss-services_BIN_DIRS_DEBUG )
set(ecss-services_LIBRARY_TYPE_DEBUG STATIC)
set(ecss-services_IS_HOST_WINDOWS_DEBUG 0)
set(ecss-services_LIBS_DEBUG common)
set(ecss-services_SYSTEM_LIBS_DEBUG )
set(ecss-services_FRAMEWORK_DIRS_DEBUG )
set(ecss-services_FRAMEWORKS_DEBUG )
set(ecss-services_BUILD_DIRS_DEBUG )
set(ecss-services_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(ecss-services_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${ecss-services_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${ecss-services_COMPILE_OPTIONS_C_DEBUG}>")
set(ecss-services_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${ecss-services_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${ecss-services_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${ecss-services_EXE_LINK_FLAGS_DEBUG}>")


set(ecss-services_COMPONENTS_DEBUG )