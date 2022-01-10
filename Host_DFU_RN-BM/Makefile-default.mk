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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../../Source/ble_api.c ../../../Source/ble_manager.c ../../../Source/bm_application_mode.c ../../../Source/bm_program_mode.c ../../../Source/bm_utils.c ../../../Source/dfu_api.c ../../../Source/dfu_manager.c ../../../Source/event_mem.c ../../../Source/fifo.c ../../../Source/interface.c ../../../Source/memory.c ../../../Source/platform_pic.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c ../../../Common/time.c ../../../Common/uart_app.c ../../../Common/uart_drv.c ../main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/449926602/ble_api.o ${OBJECTDIR}/_ext/449926602/ble_manager.o ${OBJECTDIR}/_ext/449926602/bm_application_mode.o ${OBJECTDIR}/_ext/449926602/bm_program_mode.o ${OBJECTDIR}/_ext/449926602/bm_utils.o ${OBJECTDIR}/_ext/449926602/dfu_api.o ${OBJECTDIR}/_ext/449926602/dfu_manager.o ${OBJECTDIR}/_ext/449926602/event_mem.o ${OBJECTDIR}/_ext/449926602/fifo.o ${OBJECTDIR}/_ext/449926602/interface.o ${OBJECTDIR}/_ext/449926602/memory.o ${OBJECTDIR}/_ext/449926602/platform_pic.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o ${OBJECTDIR}/_ext/1986190483/pcache.o ${OBJECTDIR}/_ext/2046243727/uart_lib.o ${OBJECTDIR}/_ext/8382566/time.o ${OBJECTDIR}/_ext/8382566/uart_app.o ${OBJECTDIR}/_ext/8382566/uart_drv.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/449926602/ble_api.o.d ${OBJECTDIR}/_ext/449926602/ble_manager.o.d ${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d ${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d ${OBJECTDIR}/_ext/449926602/bm_utils.o.d ${OBJECTDIR}/_ext/449926602/dfu_api.o.d ${OBJECTDIR}/_ext/449926602/dfu_manager.o.d ${OBJECTDIR}/_ext/449926602/event_mem.o.d ${OBJECTDIR}/_ext/449926602/fifo.o.d ${OBJECTDIR}/_ext/449926602/interface.o.d ${OBJECTDIR}/_ext/449926602/memory.o.d ${OBJECTDIR}/_ext/449926602/platform_pic.o.d ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d ${OBJECTDIR}/_ext/1986190483/pcache.o.d ${OBJECTDIR}/_ext/2046243727/uart_lib.o.d ${OBJECTDIR}/_ext/8382566/time.o.d ${OBJECTDIR}/_ext/8382566/uart_app.o.d ${OBJECTDIR}/_ext/8382566/uart_drv.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/449926602/ble_api.o ${OBJECTDIR}/_ext/449926602/ble_manager.o ${OBJECTDIR}/_ext/449926602/bm_application_mode.o ${OBJECTDIR}/_ext/449926602/bm_program_mode.o ${OBJECTDIR}/_ext/449926602/bm_utils.o ${OBJECTDIR}/_ext/449926602/dfu_api.o ${OBJECTDIR}/_ext/449926602/dfu_manager.o ${OBJECTDIR}/_ext/449926602/event_mem.o ${OBJECTDIR}/_ext/449926602/fifo.o ${OBJECTDIR}/_ext/449926602/interface.o ${OBJECTDIR}/_ext/449926602/memory.o ${OBJECTDIR}/_ext/449926602/platform_pic.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o ${OBJECTDIR}/_ext/1986190483/pcache.o ${OBJECTDIR}/_ext/2046243727/uart_lib.o ${OBJECTDIR}/_ext/8382566/time.o ${OBJECTDIR}/_ext/8382566/uart_app.o ${OBJECTDIR}/_ext/8382566/uart_drv.o ${OBJECTDIR}/_ext/1472/main.o

# Source Files
SOURCEFILES=../../../Source/ble_api.c ../../../Source/ble_manager.c ../../../Source/bm_application_mode.c ../../../Source/bm_program_mode.c ../../../Source/bm_utils.c ../../../Source/dfu_api.c ../../../Source/dfu_manager.c ../../../Source/event_mem.c ../../../Source/fifo.c ../../../Source/interface.c ../../../Source/memory.c ../../../Source/platform_pic.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c ../../../Common/time.c ../../../Common/uart_app.c ../../../Common/uart_drv.c ../main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
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
${OBJECTDIR}/_ext/449926602/ble_api.o: ../../../Source/ble_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/ble_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/ble_api.o.d" -o ${OBJECTDIR}/_ext/449926602/ble_api.o ../../../Source/ble_api.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/ble_manager.o: ../../../Source/ble_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/ble_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/ble_manager.o.d" -o ${OBJECTDIR}/_ext/449926602/ble_manager.o ../../../Source/ble_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_application_mode.o: ../../../Source/bm_application_mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_application_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_application_mode.o ../../../Source/bm_application_mode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_program_mode.o: ../../../Source/bm_program_mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_program_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_program_mode.o ../../../Source/bm_program_mode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_utils.o: ../../../Source/bm_utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_utils.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_utils.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_utils.o ../../../Source/bm_utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/dfu_api.o: ../../../Source/dfu_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/dfu_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/dfu_api.o.d" -o ${OBJECTDIR}/_ext/449926602/dfu_api.o ../../../Source/dfu_api.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/dfu_manager.o: ../../../Source/dfu_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/dfu_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/dfu_manager.o.d" -o ${OBJECTDIR}/_ext/449926602/dfu_manager.o ../../../Source/dfu_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/event_mem.o: ../../../Source/event_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/event_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/event_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/event_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/event_mem.o.d" -o ${OBJECTDIR}/_ext/449926602/event_mem.o ../../../Source/event_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/fifo.o: ../../../Source/fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/fifo.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/fifo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/fifo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/fifo.o.d" -o ${OBJECTDIR}/_ext/449926602/fifo.o ../../../Source/fifo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/interface.o: ../../../Source/interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/interface.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/interface.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/interface.o.d" -o ${OBJECTDIR}/_ext/449926602/interface.o ../../../Source/interface.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/memory.o: ../../../Source/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/memory.o.d" -o ${OBJECTDIR}/_ext/449926602/memory.o ../../../Source/memory.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/platform_pic.o: ../../../Source/platform_pic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/platform_pic.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/platform_pic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/platform_pic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/platform_pic.o.d" -o ${OBJECTDIR}/_ext/449926602/platform_pic.o ../../../Source/platform_pic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1986190483/pcache.o: ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1986190483" 
	@${RM} ${OBJECTDIR}/_ext/1986190483/pcache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986190483/pcache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1986190483/pcache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1986190483/pcache.o.d" -o ${OBJECTDIR}/_ext/1986190483/pcache.o ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2046243727/uart_lib.o: ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2046243727" 
	@${RM} ${OBJECTDIR}/_ext/2046243727/uart_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/2046243727/uart_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2046243727/uart_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/2046243727/uart_lib.o.d" -o ${OBJECTDIR}/_ext/2046243727/uart_lib.o ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/time.o: ../../../Common/time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/time.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/time.o.d" -o ${OBJECTDIR}/_ext/8382566/time.o ../../../Common/time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/uart_app.o: ../../../Common/uart_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/uart_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/uart_app.o.d" -o ${OBJECTDIR}/_ext/8382566/uart_app.o ../../../Common/uart_app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/uart_drv.o: ../../../Common/uart_drv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_drv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/uart_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/uart_drv.o.d" -o ${OBJECTDIR}/_ext/8382566/uart_drv.o ../../../Common/uart_drv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/449926602/ble_api.o: ../../../Source/ble_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/ble_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/ble_api.o.d" -o ${OBJECTDIR}/_ext/449926602/ble_api.o ../../../Source/ble_api.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/ble_manager.o: ../../../Source/ble_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/ble_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/ble_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/ble_manager.o.d" -o ${OBJECTDIR}/_ext/449926602/ble_manager.o ../../../Source/ble_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_application_mode.o: ../../../Source/bm_application_mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_application_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_application_mode.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_application_mode.o ../../../Source/bm_application_mode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_program_mode.o: ../../../Source/bm_program_mode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_program_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_program_mode.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_program_mode.o ../../../Source/bm_program_mode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/bm_utils.o: ../../../Source/bm_utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/bm_utils.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/bm_utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/bm_utils.o.d" -o ${OBJECTDIR}/_ext/449926602/bm_utils.o ../../../Source/bm_utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/dfu_api.o: ../../../Source/dfu_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/dfu_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/dfu_api.o.d" -o ${OBJECTDIR}/_ext/449926602/dfu_api.o ../../../Source/dfu_api.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/dfu_manager.o: ../../../Source/dfu_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/dfu_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/dfu_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/dfu_manager.o.d" -o ${OBJECTDIR}/_ext/449926602/dfu_manager.o ../../../Source/dfu_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/event_mem.o: ../../../Source/event_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/event_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/event_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/event_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/event_mem.o.d" -o ${OBJECTDIR}/_ext/449926602/event_mem.o ../../../Source/event_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/fifo.o: ../../../Source/fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/fifo.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/fifo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/fifo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/fifo.o.d" -o ${OBJECTDIR}/_ext/449926602/fifo.o ../../../Source/fifo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/interface.o: ../../../Source/interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/interface.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/interface.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/interface.o.d" -o ${OBJECTDIR}/_ext/449926602/interface.o ../../../Source/interface.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/memory.o: ../../../Source/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/memory.o.d" -o ${OBJECTDIR}/_ext/449926602/memory.o ../../../Source/memory.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/449926602/platform_pic.o: ../../../Source/platform_pic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/449926602" 
	@${RM} ${OBJECTDIR}/_ext/449926602/platform_pic.o.d 
	@${RM} ${OBJECTDIR}/_ext/449926602/platform_pic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/449926602/platform_pic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/449926602/platform_pic.o.d" -o ${OBJECTDIR}/_ext/449926602/platform_pic.o ../../../Source/platform_pic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw0_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw0_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o: ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/clear_core_sw1_lib.o ../../../Common/pic32-libs/peripheral/int/source/clear_core_sw1_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_configure_system_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_configure_system_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_disable_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_disable_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_mv_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_mv_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_enable_sv_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_enable_sv_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_get_pending_int_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_get_pending_int_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_restore_interrupts_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_restore_interrupts_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_ebase_vs_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_ebase_vs_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_set_vector_spacing_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_set_vector_spacing_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_5xx_6xx_7xx_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_5xx_6xx_7xx_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_legacy_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_legacy_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o: ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o.d" -o ${OBJECTDIR}/_ext/1819808422/int_tbl_lib_obs.o ../../../Common/pic32-libs/peripheral/int/source/int_tbl_lib_obs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw0_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw0_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_leg_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_leg_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o: ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1819808422" 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o.d" -o ${OBJECTDIR}/_ext/1819808422/set_core_sw1_lib.o ../../../Common/pic32-libs/peripheral/int/source/set_core_sw1_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1986190483/pcache.o: ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1986190483" 
	@${RM} ${OBJECTDIR}/_ext/1986190483/pcache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986190483/pcache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1986190483/pcache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1986190483/pcache.o.d" -o ${OBJECTDIR}/_ext/1986190483/pcache.o ../../../Common/pic32-libs/peripheral/pcache/source/pcache.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2046243727/uart_lib.o: ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2046243727" 
	@${RM} ${OBJECTDIR}/_ext/2046243727/uart_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/2046243727/uart_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2046243727/uart_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/2046243727/uart_lib.o.d" -o ${OBJECTDIR}/_ext/2046243727/uart_lib.o ../../../Common/pic32-libs/peripheral/uart/source/uart_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/time.o: ../../../Common/time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/time.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/time.o.d" -o ${OBJECTDIR}/_ext/8382566/time.o ../../../Common/time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/uart_app.o: ../../../Common/uart_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/uart_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/uart_app.o.d" -o ${OBJECTDIR}/_ext/8382566/uart_app.o ../../../Common/uart_app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/8382566/uart_drv.o: ../../../Common/uart_drv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/8382566" 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/8382566/uart_drv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/8382566/uart_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/8382566/uart_drv.o.d" -o ${OBJECTDIR}/_ext/8382566/uart_drv.o ../../../Common/uart_drv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../../../Source" -I"../../../Common" -I"../../../Common/pic32-libs/include" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/DFU_Demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
