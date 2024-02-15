################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.cpp \
../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.cpp \
../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.cpp 

OBJS += \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.o \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.o \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.o 

CPP_DEPS += \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.d \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.d \
./MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.o: ../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"D:/MY Courses/Embedded C++/STM32F103C8/C++ Drivers/MCAL_Stm32F103C8T6_cpp/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.o: ../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"D:/MY Courses/Embedded C++/STM32F103C8/C++ Drivers/MCAL_Stm32F103C8T6_cpp/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PIN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.o: ../MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"D:/MY Courses/Embedded C++/STM32F103C8/C++ Drivers/MCAL_Stm32F103C8T6_cpp/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"MCAL_Stm32F103C8T6_cpp/GPIO_Stm32F103C8T6_cpp/MCAL_GPIO_PORT.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

