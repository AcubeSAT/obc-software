########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

list(APPEND logger_COMPONENT_NAMES log_common)
list(REMOVE_DUPLICATES logger_COMPONENT_NAMES)
list(APPEND logger_FIND_DEPENDENCY_NAMES etl)
list(REMOVE_DUPLICATES logger_FIND_DEPENDENCY_NAMES)
set(etl_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(logger_PACKAGE_FOLDER_DEBUG "/home/evangelia/.conan2/p/b/loggee09719fc9d37d/p")
set(logger_BUILD_MODULES_PATHS_DEBUG )


set(logger_INCLUDE_DIRS_DEBUG "${logger_PACKAGE_FOLDER_DEBUG}/inc")
set(logger_RES_DIRS_DEBUG )
set(logger_DEFINITIONS_DEBUG )
set(logger_SHARED_LINK_FLAGS_DEBUG )
set(logger_EXE_LINK_FLAGS_DEBUG )
set(logger_OBJECTS_DEBUG )
set(logger_COMPILE_DEFINITIONS_DEBUG )
set(logger_COMPILE_OPTIONS_C_DEBUG )
set(logger_COMPILE_OPTIONS_CXX_DEBUG )
set(logger_LIB_DIRS_DEBUG "${logger_PACKAGE_FOLDER_DEBUG}/lib")
set(logger_BIN_DIRS_DEBUG )
set(logger_LIBRARY_TYPE_DEBUG STATIC)
set(logger_IS_HOST_WINDOWS_DEBUG 0)
set(logger_LIBS_DEBUG log_common)
set(logger_SYSTEM_LIBS_DEBUG )
set(logger_FRAMEWORK_DIRS_DEBUG )
set(logger_FRAMEWORKS_DEBUG )
set(logger_BUILD_DIRS_DEBUG )
set(logger_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(logger_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${logger_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${logger_COMPILE_OPTIONS_C_DEBUG}>")
set(logger_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${logger_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${logger_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${logger_EXE_LINK_FLAGS_DEBUG}>")


set(logger_COMPONENTS_DEBUG log_common)
########### COMPONENT log_common VARIABLES ############################################

set(logger_log_common_INCLUDE_DIRS_DEBUG "${logger_PACKAGE_FOLDER_DEBUG}/inc")
set(logger_log_common_LIB_DIRS_DEBUG "${logger_PACKAGE_FOLDER_DEBUG}/lib")
set(logger_log_common_BIN_DIRS_DEBUG )
set(logger_log_common_LIBRARY_TYPE_DEBUG STATIC)
set(logger_log_common_IS_HOST_WINDOWS_DEBUG 0)
set(logger_log_common_RES_DIRS_DEBUG )
set(logger_log_common_DEFINITIONS_DEBUG )
set(logger_log_common_OBJECTS_DEBUG )
set(logger_log_common_COMPILE_DEFINITIONS_DEBUG )
set(logger_log_common_COMPILE_OPTIONS_C_DEBUG "")
set(logger_log_common_COMPILE_OPTIONS_CXX_DEBUG "")
set(logger_log_common_LIBS_DEBUG log_common)
set(logger_log_common_SYSTEM_LIBS_DEBUG )
set(logger_log_common_FRAMEWORK_DIRS_DEBUG )
set(logger_log_common_FRAMEWORKS_DEBUG )
set(logger_log_common_DEPENDENCIES_DEBUG )
set(logger_log_common_SHARED_LINK_FLAGS_DEBUG )
set(logger_log_common_EXE_LINK_FLAGS_DEBUG )
set(logger_log_common_NO_SONAME_MODE_DEBUG FALSE)

# COMPOUND VARIABLES
set(logger_log_common_LINKER_FLAGS_DEBUG
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${logger_log_common_SHARED_LINK_FLAGS_DEBUG}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${logger_log_common_SHARED_LINK_FLAGS_DEBUG}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${logger_log_common_EXE_LINK_FLAGS_DEBUG}>
)
set(logger_log_common_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${logger_log_common_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${logger_log_common_COMPILE_OPTIONS_C_DEBUG}>")