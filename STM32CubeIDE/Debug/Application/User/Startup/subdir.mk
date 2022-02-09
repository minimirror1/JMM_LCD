################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/User/Startup/startup_stm32f746nghx.s 

S_DEPS += \
./Application/User/Startup/startup_stm32f746nghx.d 

OBJS += \
./Application/User/Startup/startup_stm32f746nghx.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Startup/%.o: ../Application/User/Startup/%.s Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"D:/stm32_ws/board/JointManipulator_Master/JMM_LCD_V1/JMM_LCD/STM32CubeIDE/Application/User/gui" -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I"D:/stm32_ws/driver/UART_Driver/Inc" -I"D:/stm32_ws/driver/UART_Parsing/Protocol/Inc" -I"D:/stm32_ws/driver/CRC/Inc" -I"D:/stm32_ws/driver/non_stop_delay/Inc" -I"D:/stm32_ws/driver/CAN_Driver/Inc" -I"D:/stm32_ws/driver/CAN_Parsing/Inc" -I"D:/stm32_ws/board/JointManipulator_Master/JMM_LCD_V1/JMM_LCD/STM32CubeIDE/Application/User/Motion_Task/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-Startup

clean-Application-2f-User-2f-Startup:
	-$(RM) ./Application/User/Startup/startup_stm32f746nghx.d ./Application/User/Startup/startup_stm32f746nghx.o

.PHONY: clean-Application-2f-User-2f-Startup

