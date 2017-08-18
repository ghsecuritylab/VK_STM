################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ethernetif.c \
../Src/freertos.c \
../Src/keyboard.c \
../Src/lcdUpdate.c \
../Src/lwip.c \
../Src/main.c \
../Src/mouse.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_hal_timebase_TIM.c \
../Src/stm32f7xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f7xx.c \
../Src/tm_stm32_delay.c \
../Src/tm_stm32_disco.c \
../Src/tm_stm32_dma.c \
../Src/tm_stm32_dma2d_graphic.c \
../Src/tm_stm32_fonts.c \
../Src/tm_stm32_gpio.c \
../Src/tm_stm32_lcd.c \
../Src/tm_stm32_rcc.c \
../Src/tm_stm32_sdram.c \
../Src/usb_device.c \
../Src/usbd_conf.c \
../Src/usbd_desc.c 

OBJS += \
./Src/ethernetif.o \
./Src/freertos.o \
./Src/keyboard.o \
./Src/lcdUpdate.o \
./Src/lwip.o \
./Src/main.o \
./Src/mouse.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_hal_timebase_TIM.o \
./Src/stm32f7xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f7xx.o \
./Src/tm_stm32_delay.o \
./Src/tm_stm32_disco.o \
./Src/tm_stm32_dma.o \
./Src/tm_stm32_dma2d_graphic.o \
./Src/tm_stm32_fonts.o \
./Src/tm_stm32_gpio.o \
./Src/tm_stm32_lcd.o \
./Src/tm_stm32_rcc.o \
./Src/tm_stm32_sdram.o \
./Src/usb_device.o \
./Src/usbd_conf.o \
./Src/usbd_desc.o 

C_DEPS += \
./Src/ethernetif.d \
./Src/freertos.d \
./Src/keyboard.d \
./Src/lcdUpdate.d \
./Src/lwip.d \
./Src/main.d \
./Src/mouse.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_hal_timebase_TIM.d \
./Src/stm32f7xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f7xx.d \
./Src/tm_stm32_delay.d \
./Src/tm_stm32_disco.d \
./Src/tm_stm32_dma.d \
./Src/tm_stm32_dma2d_graphic.d \
./Src/tm_stm32_fonts.d \
./Src/tm_stm32_gpio.d \
./Src/tm_stm32_lcd.d \
./Src/tm_stm32_rcc.d \
./Src/tm_stm32_sdram.d \
./Src/usb_device.d \
./Src/usbd_conf.d \
./Src/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D_TIMEVAL_DEFINED -D_SYS_TIME_H_ '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -DSTM32F7xx -DSTM32F7_DISCOVERY -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Inc" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/system" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/lwip" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/netif" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/posix" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Middlewares/Third_Party/LwIP/system/arch" -I"C:/Users/PR6/workspace/AB/STM/Cube/lan3_wlcd/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


