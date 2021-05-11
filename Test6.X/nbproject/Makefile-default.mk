#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/main.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/peripheral/clk/plib_clk.c ../src/config/default/peripheral/pio/plib_pio.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/config/default/peripheral/efc/plib_efc.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/cache/sys_cache.c ../src/app.c ../src/config/default/tasks.c ../src/config/default/system/time/src/sys_time.c ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c ../../../../Desktop/FreeRTOS/Source/timers.c ../../../../Desktop/FreeRTOS/Source/croutine.c ../../../../Desktop/FreeRTOS/Source/stream_buffer.c ../../../../Desktop/FreeRTOS/Source/list.c ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c ../../../../Desktop/FreeRTOS/Source/event_groups.c ../../../../Desktop/FreeRTOS/Source/queue.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/60165520/plib_clk.o ${OBJECTDIR}/_ext/60177924/plib_pio.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/60167248/plib_efc.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/1014039709/sys_cache.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/1151461019/timers.o ${OBJECTDIR}/_ext/1151461019/croutine.o ${OBJECTDIR}/_ext/1151461019/stream_buffer.o ${OBJECTDIR}/_ext/1151461019/list.o ${OBJECTDIR}/_ext/1137148840/heap_5.o ${OBJECTDIR}/_ext/385781579/port.o ${OBJECTDIR}/_ext/1151461019/event_groups.o ${OBJECTDIR}/_ext/1151461019/queue.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/60165520/plib_clk.o.d ${OBJECTDIR}/_ext/60177924/plib_pio.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/60167248/plib_efc.o.d ${OBJECTDIR}/_ext/1881668453/sys_int.o.d ${OBJECTDIR}/_ext/1014039709/sys_cache.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1171490990/tasks.o.d ${OBJECTDIR}/_ext/101884895/sys_time.o.d ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o.d ${OBJECTDIR}/_ext/1151461019/timers.o.d ${OBJECTDIR}/_ext/1151461019/croutine.o.d ${OBJECTDIR}/_ext/1151461019/stream_buffer.o.d ${OBJECTDIR}/_ext/1151461019/list.o.d ${OBJECTDIR}/_ext/1137148840/heap_5.o.d ${OBJECTDIR}/_ext/385781579/port.o.d ${OBJECTDIR}/_ext/1151461019/event_groups.o.d ${OBJECTDIR}/_ext/1151461019/queue.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/60165520/plib_clk.o ${OBJECTDIR}/_ext/60177924/plib_pio.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/60167248/plib_efc.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/1014039709/sys_cache.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/1151461019/timers.o ${OBJECTDIR}/_ext/1151461019/croutine.o ${OBJECTDIR}/_ext/1151461019/stream_buffer.o ${OBJECTDIR}/_ext/1151461019/list.o ${OBJECTDIR}/_ext/1137148840/heap_5.o ${OBJECTDIR}/_ext/385781579/port.o ${OBJECTDIR}/_ext/1151461019/event_groups.o ${OBJECTDIR}/_ext/1151461019/queue.o

# Source Files
SOURCEFILES=../src/main.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/peripheral/clk/plib_clk.c ../src/config/default/peripheral/pio/plib_pio.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/config/default/peripheral/efc/plib_efc.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/cache/sys_cache.c ../src/app.c ../src/config/default/tasks.c ../src/config/default/system/time/src/sys_time.c ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c ../../../../Desktop/FreeRTOS/Source/timers.c ../../../../Desktop/FreeRTOS/Source/croutine.c ../../../../Desktop/FreeRTOS/Source/stream_buffer.c ../../../../Desktop/FreeRTOS/Source/list.c ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c ../../../../Desktop/FreeRTOS/Source/event_groups.c ../../../../Desktop/FreeRTOS/Source/queue.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAMV71Q21B
MP_LINKER_FILE_OPTION=,--script="../src/config/default/ATSAMV71Q21B.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/c1b1079be376b2e900a2f04704d05419ecca2f69.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/b180f40c7236afcc451040dac88aa7c487c77285.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/faaca6c55d99d3a75be32d502f2bf317b70f581d.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/d7a7c29d54c32db7ec4159c089cffb8b6ff9444b.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/cdef06062d50c324e3e8b5f344af43cee121b332.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165520/plib_clk.o: ../src/config/default/peripheral/clk/plib_clk.c  .generated_files/6b4eed269573c60d651cb187b1b129fe00e8770c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60165520" 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165520/plib_clk.o.d" -o ${OBJECTDIR}/_ext/60165520/plib_clk.o ../src/config/default/peripheral/clk/plib_clk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60177924/plib_pio.o: ../src/config/default/peripheral/pio/plib_pio.c  .generated_files/1f049a86ce7addc97e3e5b1331a4a827220e4e1b.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60177924" 
	@${RM} ${OBJECTDIR}/_ext/60177924/plib_pio.o.d 
	@${RM} ${OBJECTDIR}/_ext/60177924/plib_pio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60177924/plib_pio.o.d" -o ${OBJECTDIR}/_ext/60177924/plib_pio.o ../src/config/default/peripheral/pio/plib_pio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/e46455ebd52d1e4b83135915c318952b0f7e3ee4.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/99a79245232d7becfa11101f9ac05b72beddffc2.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/c993c5cc1332d3bd385bbf4d4af27ec1f765c89c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/a52c006c951e8b667348803ba6b13ccb165dc6ce.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167248/plib_efc.o: ../src/config/default/peripheral/efc/plib_efc.c  .generated_files/18e60cb1cc64fcbf9f2e6ca59629dc6aeadda585.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60167248" 
	@${RM} ${OBJECTDIR}/_ext/60167248/plib_efc.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167248/plib_efc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60167248/plib_efc.o.d" -o ${OBJECTDIR}/_ext/60167248/plib_efc.o ../src/config/default/peripheral/efc/plib_efc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/4d12d66274fe9baf96d29f45073c50b31de1fd3a.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1014039709/sys_cache.o: ../src/config/default/system/cache/sys_cache.c  .generated_files/bfa216e2ac1deadecddec1d73c927d29f376e3a.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1014039709" 
	@${RM} ${OBJECTDIR}/_ext/1014039709/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1014039709/sys_cache.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1014039709/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1014039709/sys_cache.o ../src/config/default/system/cache/sys_cache.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/48b29e23953a8b83e663963aa6a1a86a8899bf0e.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/4aa87625c7f43be391b1e920893412ac6f1fe5e3.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/a3170104aeecc1221b3821d752b3689d640cb770.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o: ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c  .generated_files/119074f4b7becf4706cdc74bebf8e5adde97759e.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/timers.o: ../../../../Desktop/FreeRTOS/Source/timers.c  .generated_files/f8810ec1206af1808e505b362a2a644d8d224969.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/timers.o.d" -o ${OBJECTDIR}/_ext/1151461019/timers.o ../../../../Desktop/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/croutine.o: ../../../../Desktop/FreeRTOS/Source/croutine.c  .generated_files/273d0d412d78a9e995f295b628812979882fad01.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/croutine.o.d" -o ${OBJECTDIR}/_ext/1151461019/croutine.o ../../../../Desktop/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/stream_buffer.o: ../../../../Desktop/FreeRTOS/Source/stream_buffer.c  .generated_files/7f3f0f0d611bdd0b6c0a2ba5dcd506e9b12d0e91.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/stream_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1151461019/stream_buffer.o ../../../../Desktop/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/list.o: ../../../../Desktop/FreeRTOS/Source/list.c  .generated_files/78c362be2baac9c4fbe9ee17058c28bc4e9c531b.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/list.o.d" -o ${OBJECTDIR}/_ext/1151461019/list.o ../../../../Desktop/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1137148840/heap_5.o: ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c  .generated_files/d5f2fef4ee8acf38cfdf6bf68984793da54617a5.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1137148840" 
	@${RM} ${OBJECTDIR}/_ext/1137148840/heap_5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137148840/heap_5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1137148840/heap_5.o.d" -o ${OBJECTDIR}/_ext/1137148840/heap_5.o ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/385781579/port.o: ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c  .generated_files/68b45f9252ba30a44b7d7be1e948d02a30cdee34.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/385781579" 
	@${RM} ${OBJECTDIR}/_ext/385781579/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/385781579/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/385781579/port.o.d" -o ${OBJECTDIR}/_ext/385781579/port.o ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/event_groups.o: ../../../../Desktop/FreeRTOS/Source/event_groups.c  .generated_files/c407145e4abc18134bf95f85a7948c3834ad7a4f.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/event_groups.o.d" -o ${OBJECTDIR}/_ext/1151461019/event_groups.o ../../../../Desktop/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/queue.o: ../../../../Desktop/FreeRTOS/Source/queue.c  .generated_files/def5c6d3a8920443dafe92307c464b287700d4c0.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/queue.o.d" -o ${OBJECTDIR}/_ext/1151461019/queue.o ../../../../Desktop/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/121be03c71c3e968f9916f69c4466969513b1481.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/b0b59ae81a42e82c4bbf7f4a287c4a074bd9b2ac.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/1cbed69d709fb4aae77388d223a8af5838f288c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/c148f73fcfdf3501ed9e29c163635cb8dc3fcdec.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/b62ac89fc0f4f22e6b5beb8704b2929e85503c8c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165520/plib_clk.o: ../src/config/default/peripheral/clk/plib_clk.c  .generated_files/2a09e57bc2f2e5ac4df453db0b3e31e04cbe9e06.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60165520" 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165520/plib_clk.o.d" -o ${OBJECTDIR}/_ext/60165520/plib_clk.o ../src/config/default/peripheral/clk/plib_clk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60177924/plib_pio.o: ../src/config/default/peripheral/pio/plib_pio.c  .generated_files/96a697093a3433b4eb70bd256e07c6907fffcd3.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60177924" 
	@${RM} ${OBJECTDIR}/_ext/60177924/plib_pio.o.d 
	@${RM} ${OBJECTDIR}/_ext/60177924/plib_pio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60177924/plib_pio.o.d" -o ${OBJECTDIR}/_ext/60177924/plib_pio.o ../src/config/default/peripheral/pio/plib_pio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/c2a321ca64465218beb94a47fc2ecb0f7021e615.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/fa9b6aa2357263b714c269e9551deb2f0b4352f0.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/61b10ed5f31cef8d55afada53af1d6afd390ac1c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/6c46a8e496ccc8453e224f0ed60aeae1e32030dd.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167248/plib_efc.o: ../src/config/default/peripheral/efc/plib_efc.c  .generated_files/fda077b1ff44bce72683419c4f02b037241c432b.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/60167248" 
	@${RM} ${OBJECTDIR}/_ext/60167248/plib_efc.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167248/plib_efc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60167248/plib_efc.o.d" -o ${OBJECTDIR}/_ext/60167248/plib_efc.o ../src/config/default/peripheral/efc/plib_efc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/57b31f088fb7da89cab7384e872845da43fcbc8a.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1014039709/sys_cache.o: ../src/config/default/system/cache/sys_cache.c  .generated_files/8aa449cb0ea81729632c4cbac085eaad6817f45f.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1014039709" 
	@${RM} ${OBJECTDIR}/_ext/1014039709/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1014039709/sys_cache.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1014039709/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1014039709/sys_cache.o ../src/config/default/system/cache/sys_cache.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/8e7ecb5780264315c2e3accc9139b755e17d3a61.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/9bfea50d36f95a01a847fec764ccbcce8e5370ed.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/8b00c79d9037f6cb31bcb2ae27e2c10cee3703cc.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o: ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c  .generated_files/e944cb6ad92bb11299e7858a6c350c65ccbfd08e.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/1151461019/FreeRTOS_tasks.o ../../../../Desktop/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/timers.o: ../../../../Desktop/FreeRTOS/Source/timers.c  .generated_files/abcefea2441470d011d6196cc80c01e509cb0f0c.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/timers.o.d" -o ${OBJECTDIR}/_ext/1151461019/timers.o ../../../../Desktop/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/croutine.o: ../../../../Desktop/FreeRTOS/Source/croutine.c  .generated_files/dc717173235581be7fbfcba65cc5a79bb6480ea9.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/croutine.o.d" -o ${OBJECTDIR}/_ext/1151461019/croutine.o ../../../../Desktop/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/stream_buffer.o: ../../../../Desktop/FreeRTOS/Source/stream_buffer.c  .generated_files/8548c3677bcfb29822d2c6b045b96d74825c04a7.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/stream_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1151461019/stream_buffer.o ../../../../Desktop/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/list.o: ../../../../Desktop/FreeRTOS/Source/list.c  .generated_files/9f44dd0d6e85e916533e13c10ce121221fd9563d.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/list.o.d" -o ${OBJECTDIR}/_ext/1151461019/list.o ../../../../Desktop/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1137148840/heap_5.o: ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c  .generated_files/146d4d1e5212ff4c6481ffde5f08bc51e70aa198.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1137148840" 
	@${RM} ${OBJECTDIR}/_ext/1137148840/heap_5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137148840/heap_5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1137148840/heap_5.o.d" -o ${OBJECTDIR}/_ext/1137148840/heap_5.o ../../../../Desktop/FreeRTOS/Source/portable/MemMang/heap_5.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/385781579/port.o: ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c  .generated_files/9e02915573825ed515d62c502aee037a2888237e.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/385781579" 
	@${RM} ${OBJECTDIR}/_ext/385781579/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/385781579/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/385781579/port.o.d" -o ${OBJECTDIR}/_ext/385781579/port.o ../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/event_groups.o: ../../../../Desktop/FreeRTOS/Source/event_groups.c  .generated_files/b7c2560d24c01ce031d77b02b92a19c8ee6be036.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/event_groups.o.d" -o ${OBJECTDIR}/_ext/1151461019/event_groups.o ../../../../Desktop/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1151461019/queue.o: ../../../../Desktop/FreeRTOS/Source/queue.c  .generated_files/f5e7aee38922de94223faf6013a4cfeae14dc1.flag .generated_files/8fb3907c2a656deb20be90b37523b20d21dd48a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1151461019" 
	@${RM} ${OBJECTDIR}/_ext/1151461019/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1151461019/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../Desktop/FreeRTOS/Source/include" -I"../../../../Desktop/FreeRTOS/Source/portable/GCC/SAM/CM7" -I"../../../../Desktop" -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/config/default" -I"../src/packs/ATSAMV71Q21B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1151461019/queue.o.d" -o ${OBJECTDIR}/_ext/1151461019/queue.o ../../../../Desktop/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samv71b" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/ATSAMV71Q21B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g  -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}/samv71b"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/ATSAMV71Q21B.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}/samv71b"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Test6.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
