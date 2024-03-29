# Load the debug and release variables
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB DATA_FILES "${_DIR}/etl-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${etl_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${etl_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET etl::etl)
    add_library(etl::etl INTERFACE IMPORTED)
    message(${etl_MESSAGE_MODE} "Conan: Target declared 'etl::etl'")
endif()
if(NOT TARGET etl)
    add_library(etl INTERFACE IMPORTED)
    set_property(TARGET etl PROPERTY INTERFACE_LINK_LIBRARIES etl::etl)
else()
    message(WARNING "Target name 'etl' already exists.")
endif()
# Load the debug and release library finders
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/etl-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()