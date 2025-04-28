cmake_minimum_required(VERSION 3.19.2)

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/src/config/default/ATSAMV71Q21B.ld)

SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--gc-sections,--print-memory-usage -T ${LINKER_SCRIPT}")

include_directories(.)
include_directories(inc)
include_directories(inc/Platform)
include_directories(inc/FreeRTOSTasks)
include_directories(inc/Platform/Parameters)
include_directories(src)
include_directories(src/config)
include_directories(src/config/default)
include_directories(src/config/default/osal)
include_directories(src/config/default/peripheral/clk)
include_directories(src/config/default/peripheral/efc)
include_directories(src/config/default/peripheral/nvic)
include_directories(src/config/default/peripheral/pio)
include_directories(src/config/default/peripheral/rtc)
include_directories(src/config/default/peripheral/systick)
include_directories(src/config/default/peripheral/twihs/master)
include_directories(src/config/default/system)
include_directories(src/config/default/system/cache)
include_directories(src/config/default/system/debug)
include_directories(src/config/default/system/int)
include_directories(src/config/default/system/time)
include_directories(src/config/default/system/time/src)
include_directories(src/packs)
include_directories(src/packs/ATSAMV71Q21B_DFP)
include_directories(src/packs/ATSAMV71Q21B_DFP/component)
include_directories(src/packs/ATSAMV71Q21B_DFP/instance)
include_directories(src/packs/ATSAMV71Q21B_DFP/pio)
include_directories(src/packs/CMSIS)
include_directories(src/packs/CMSIS/CMSIS)
include_directories(src/packs/CMSIS/CMSIS/Core)
include_directories(src/packs/CMSIS/CMSIS/Core/Include)
include_directories(/opt/microchip/mplabx/v5.45/packs/arm/CMSIS/5.4.0/CMSIS/Core/Include/)

file(GLOB_RECURSE DRIVER_SOURCES "../common/lib/atsam-component-drivers/MCP9808/*.cpp" "../common/lib/atsam-component-drivers/InternalFlash/*.cpp")
file(GLOB_RECURSE SOURCES "../common/src/*.cpp" "../common/src/*.c" "src/*.c" "src/*.cpp" "../common/lib/SEGGER/RTT/*.c")
file(GLOB_RECURSE FREERTOS_SOURCES "../common/lib/FreeRTOS/*.c")

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT} ${FREERTOS_SOURCES} ${DRIVER_SOURCES})

target_include_directories(${PROJECT_NAME}.elf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${PROJECT_NAME}.elf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/Platform)
target_include_directories(${PROJECT_NAME}.elf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE TAR_INCLUDES LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}")

set(DIRS_ONLY2 "")
foreach(item ${TAR_INCLUDES})
    if(IS_DIRECTORY "${item}")
        list(APPEND DIRS_ONLY2 "${item}")
    endif()
endforeach()

target_include_directories(common_cross PRIVATE ${DIRS_ONLY2})

target_link_libraries(${PROJECT_NAME}.elf PRIVATE common common_cross etl log_common)

set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS_INIT} -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

add_compile_definitions(LOGLEVEL_TRACE)
target_compile_options(${PROJECT_NAME}.elf PRIVATE -Wno-psabi)
target_compile_definitions(${PROJECT_NAME}.elf PRIVATE OBC_DEV)