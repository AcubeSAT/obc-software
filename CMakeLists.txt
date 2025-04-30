cmake_minimum_required(VERSION 3.19.2)

project(OBC_SOFTWARE C CXX ASM)

add_definitions(-DARM_MATH_CM7 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -D__FPU_PRESENT=1)

find_package(etl CONFIG REQUIRED)
find_package(logger CONFIG REQUIRED COMPONENTS log_common)
find_package(ecss-services CONFIG REQUIRED COMPONENTS common)

include_directories(common)
file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/common/*")

set(DIRS_ONLY "")
foreach(item ${INCLUDE_DIRS})
    if(IS_DIRECTORY "${item}")
        list(APPEND DIRS_ONLY "${item}")
    endif()
endforeach()

include_directories(${DIRS_ONLY})

add_subdirectory(common/lib/cross-platform-software)

add_subdirectory(${OBC_BUILD})