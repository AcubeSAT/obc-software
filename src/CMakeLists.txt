
cmake_minimum_required(VERSION 3.19)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
# project settings
project( TEST_INTEGRATION C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# specify cross compilers and tools
set(CMAKE_C_COMPILER xc32-gcc)
set(CMAKE_CXX_COMPILER xc32-g++)
set(CMAKE_ASM_COMPILER xc32-gcc)
set(CMAKE_AR xc32-ar)
set(CMAKE_OBJCOPY xc32-objcopy)
set(CMAKE_OBJDUMP xc32-objdump)
set(SIZE xc32-size)


#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
#set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/src/config/default/ATSAMV71Q21B.ld)
#set(C_INCLUDE_PATH /opt/microchip/xc32/v2.50/pic32mx/include)
#set(XC32_LIBRARY_PATH /opt/microchip/xc32/v2.50/pic32mx/lib ; /opt/microchip/xc32/v2.50/lib)
#set(CMAKE_VERBOSE_MAKEFILE ON)

#Uncomment for hardware floating point
#add_compile_definitions(ARM_MATH_CM7;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
#add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
#add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
#add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

#add_compile_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
#add_compile_options(-mcpu=cortex-m7 -mthumb -mthumb-interwork)
#add_link_options(-T ${LINKER_SCRIPT})
#add_link_options(--verbose)


include_directories(.)
include_directories(src)
include_directories(src/config)
include_directories(src/config/default)
include_directories(src/config/default/osal)
include_directories(src/config/default/peripheral/clk)
include_directories(src/config/default/peripheral/efc)
include_directories(src/config/default/peripheral/nvic)
include_directories(src/config/default/peripheral/pio)
include_directories(src/config/default/peripheral/systick)
include_directories(src/config/default/system)
include_directories(src/config/default/system/cache)
include_directories(src/config/default/system/debug)
include_directories(src/config/default/system/int)
include_directories(src/config/default/system/time)
include_directories(src/config/default/system/time/src)
include_directories(src/FreeRTOS)
include_directories(src/FreeRTOS/Source)
include_directories(src/FreeRTOS/Source/include)
include_directories(src/FreeRTOS/Source/portable)
include_directories(src/FreeRTOS/Source/portable/GCC)
include_directories(src/FreeRTOS/Source/portable/GCC/SAM)
include_directories(src/FreeRTOS/Source/portable/GCC/SAM/CM7)
include_directories(src/FreeRTOS/Source/portable/MemMang)
include_directories(src/packs)
include_directories(src/packs/ATSAMV71Q21B_DFP)
include_directories(src/packs/ATSAMV71Q21B_DFP/component)
include_directories(src/packs/ATSAMV71Q21B_DFP/instance)
include_directories(src/packs/ATSAMV71Q21B_DFP/pio)
include_directories(src/packs/CMSIS)
include_directories(src/packs/CMSIS/CMSIS)
include_directories(src/packs/CMSIS/CMSIS/Core)
include_directories(src/packs/CMSIS/CMSIS/Core/Include)
include_directories(Test6.X)
include_directories(Test6.X/dist)
include_directories(Test6.X/dist/default)
include_directories(Test6.X/dist/default/production)
include_directories(Test6.X/nbproject)
include_directories(Test6.X/nbproject/private)


#generic include from mplab

file(GLOB_RECURSE SOURCE "src/*.c")
add_executable(TEST_INTEGRATION ${SOURCE})

target_include_directories(
        TEST_INTEGRATION
        PRIVATE
        src/
        src/config/default/
        src/packs/ATSAMV71Q21B_DFP/
        src/packs/CMSIS/
        src/packs/CMSIS/Core/Include
        /opt/microchip/mplabx/v5.45/packs/arm/CMSIS/5.4.0/CMSIS/Core/Include/
)

target_compile_definitions(
        TEST_INTEGRATION
        PRIVATE
        -DXPRJ_default=default
)
target_compile_options(
        TEST_INTEGRATION
        PRIVATE
        -x c -c -mprocessor=ATSAMV71Q21B -mdfp=/opt/microchip/mplabx/v5.45/packs/Microchip/SAMV71_DFP/4.4.78/samv71b/
)

target_link_options(
        TEST_INTEGRATION
        PRIVATE
        SHELL:-mprocessor=ATSAMV71Q21B -mno-device-startup-code
        LINKER:--defsym=_min_heap_size=512,--defsym=__MPLAB_BUILD=1,--script=${CMAKE_SOURCE_DIR}/src/config/default/ATSAMV71Q21B.ld,
        --gc-sections,-Map=${CMAKE_BINARY_DIR}/${CMAKE_TARGET_NAME}-${CMAKE_CONFIG_NAME}.map,
        --memorysummary,${CMAKE_BINARY_DIR}/${CMAKE_TARGET_NAME}-${CMAKE_CONFIG_NAME}-memoryfile.xml
)

set_target_properties(
        TEST_INTEGRATION
        PROPERTIES
        OUTPUT_NAME xc32-template.elf
)

