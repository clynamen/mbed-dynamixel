# This file was automagically generated by mbed.org. For more information, 
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded

# cross-platform directory manipulation
ifeq ($(shell echo $$OS),$$OS)
    MAKEDIR = if not exist "$(1)" mkdir "$(1)"
    RM = rmdir /S /Q "$(1)"
else
    MAKEDIR = $(SHELL) -c "mkdir -p \"$(1)\""
    RM = $(SHELL) -c "rm -rf \"$(1)\""
endif

ifeq (,$(filter .build,$(notdir $(CURDIR))))
.SUFFIXES:
OBJDIR := .build
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKETARGET = $(MAKE) --no-print-directory -C $(OBJDIR) -f $(mkfile_path) \
		SRCDIR=$(CURDIR) $(MAKECMDGOALS)
.PHONY: $(OBJDIR) clean
all:
	+@$(call MAKEDIR,$(OBJDIR))
	+@$(MAKETARGET)
$(OBJDIR): all
Makefile : ;
% :: $(OBJDIR) ; :
clean :
	$(call RM,$(OBJDIR))

else

VPATH = ../../.. 

GCC_BIN = 
PROJECT = mbed_dynamixel
OBJECTS = mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/TOOLCHAIN_GCC_ARM/startup_stm32f401xe.o mbed-dev/hal/mbed_pinmap_common.o mbed-dev/hal/mbed_ticker_api.o mbed-dev/hal/mbed_us_ticker_api.o mbed-dev/hal/mbed_lp_ticker_api.o mbed-dev/hal/mbed_gpio.o mbed-dev/platform/mbed_assert.o mbed-dev/platform/mbed_critical.o mbed-dev/platform/mbed_wait_api_no_rtos.o mbed-dev/platform/mbed_interface.o mbed-dev/platform/mbed_mem_trace.o mbed-dev/platform/mbed_semihost_api.o mbed-dev/platform/mbed_error.o mbed-dev/platform/mbed_board.o mbed-dev/targets/TARGET_STM/trng_api.o mbed-dev/targets/TARGET_STM/stm_spi_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/lp_ticker.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/serial_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/rtc_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/mbed_overrides.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/port_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/sleep.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/pinmap.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/pwmout_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/gpio_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/can_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/us_ticker.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/i2c_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/spi_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/analogin_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/gpio_irq_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/analogout_api.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/PeripheralPins.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/system_stm32f4xx.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/cmsis_nvic.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/hal_tick.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_flash_ramfunc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_sd.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_adc_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_can.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_ll_fmc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_lptim.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_nand.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_iwdg.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_tim.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dfsdm.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dma2d.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dcmi_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_sdram.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_cryp.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_fmpi2c.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_cec.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_cryp_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_gpio.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_flash.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_uart.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_eth.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_rtc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_hcd.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dma.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_wwdg.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_ltdc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_sai.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_rng.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_crc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_msp_template.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_tim_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_ll_sdmmc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_i2c_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_nor.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_pccard.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_qspi.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_pwr_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_rtc_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_irda.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_ll_fsmc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_rcc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_spi.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dma_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_usart.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dsi.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_rcc_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_ltdc_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_pcd.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dcmi.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_ll_usb.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_i2s.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_sai_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_pwr.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_fmpi2c_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dac_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_smartcard.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_i2s_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_dac.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_spdifrx.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_hash.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_i2c.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_sram.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_adc.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_flash_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_pcd_ex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_cortex.o mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device/stm32f4xx_hal_hash_ex.o SerialHalfDuplex.o MX.o main.o communication_1/communication_1.o mbed-dev/platform/mbed_rtc_time.o mbed-dev/platform/retarget.o mbed-dev/platform/mbed_alloc_wrappers.o mbed-dev/platform/mbed_wait_api_rtos.o mbed-dev/platform/CallChain.o mbed-dev/drivers/FileLike.o mbed-dev/drivers/SerialBase.o mbed-dev/drivers/BusIn.o mbed-dev/drivers/InterruptIn.o mbed-dev/drivers/I2CSlave.o mbed-dev/drivers/Timer.o mbed-dev/drivers/Stream.o mbed-dev/drivers/TimerEvent.o mbed-dev/drivers/LocalFileSystem.o mbed-dev/drivers/CAN.o mbed-dev/drivers/SPISlave.o mbed-dev/drivers/FileSystemLike.o mbed-dev/drivers/Timeout.o mbed-dev/drivers/AnalogIn.o mbed-dev/drivers/Ethernet.o mbed-dev/drivers/Serial.o mbed-dev/drivers/InterruptManager.o mbed-dev/drivers/SPI.o mbed-dev/drivers/BusOut.o mbed-dev/drivers/BusInOut.o mbed-dev/drivers/Ticker.o mbed-dev/drivers/FileBase.o mbed-dev/drivers/I2C.o mbed-dev/drivers/RawSerial.o mbed-dev/drivers/FilePath.o MX106/MX106.o MX64/MX64.o AX12/AX12.o 
SYS_OBJECTS = 
INCLUDE_PATHS = -I../../../. -I../../../communication_1 -I../../../mbed-dev -I../../../mbed-dev/hal -I../../../mbed-dev/hal/hal -I../../../mbed-dev/hal/storage_abstraction -I../../../mbed-dev/platform -I../../../mbed-dev/drivers -I../../../mbed-dev/cmsis -I../../../mbed-dev/cmsis/TOOLCHAIN_GCC -I../../../mbed-dev/targets -I../../../mbed-dev/targets/TARGET_STM -I../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4 -I../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE -I../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device -I../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/TOOLCHAIN_GCC_ARM -I../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4/device -I../../../projectfiles -I../../../projectfiles/gcc_arm_NUCLEO_F401RE -I../../../MX106 -I../../../MX64 -I../../../AX12 -I../../../. -I../. 
LIBRARY_PATHS = 
LIBRARIES = 
LINKER_SCRIPT = ../../../mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE/device/TOOLCHAIN_GCC_ARM/STM32F401XE.ld

############################################################################### 
AS      = $(GCC_BIN)arm-none-eabi-as
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
LD      = $(GCC_BIN)arm-none-eabi-gcc
OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE    = $(GCC_BIN)arm-none-eabi-size 

ifeq ($(HARDFP),1)
	FLOAT_ABI = hard
else
	FLOAT_ABI = softfp
endif


CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=$(FLOAT_ABI) 
CC_FLAGS = -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os -std=gnu99 -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -D__FPU_PRESENT=1 -DTARGET_FF_ARDUINO -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DMBED_BUILD_TIMESTAMP=1481838173.37 -DDEVICE_PORTINOUT=1 -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DARM_MATH_CM4 -include mbed_config.h -MMD -MP
CPPC_FLAGS = -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os -std=gnu++98 -fno-rtti -Wvla -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -D__FPU_PRESENT=1 -DTARGET_FF_ARDUINO -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DMBED_BUILD_TIMESTAMP=1481838173.37 -DDEVICE_PORTINOUT=1 -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DARM_MATH_CM4 -include mbed_config.h -MMD -MP
ASM_FLAGS = -x assembler-with-cpp -D__CMSIS_RTOS -D__FPU_PRESENT=1 -DARM_MATH_CM4 -D__CORTEX_M4 -D__MBED_CMSIS_RTOS_CM -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os
CC_SYMBOLS = 

LD_FLAGS =-Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp 
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys


ifeq ($(DEBUG), 1)
  CC_FLAGS += -DDEBUG -O0
else
  CC_FLAGS += -DNDEBUG -Os
endif


.PHONY: all lst size

all: $(PROJECT).bin $(PROJECT).hex size



.asm.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<
.s.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<
.S.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<

.c.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC)  $(CC_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<

.cpp.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CPP) $(CPPC_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<



$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS) $(LINKER_SCRIPT)
	$(LD) $(LD_FLAGS) -T$(filter %.ld, $^) $(LIBRARY_PATHS) -o $@ $(filter %.o, $^) -Wl,--start-group $(LIBRARIES) $(LD_SYS_LIBS) -Wl,--end-group


$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

$(PROJECT).hex: $(PROJECT).elf
	@$(OBJCOPY) -O ihex $< $@

$(PROJECT).lst: $(PROJECT).elf
	@$(OBJDUMP) -Sdh $< > $@

lst: $(PROJECT).lst

size: $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)


endif
