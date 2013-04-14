################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dependencies/hippomocks/injector/injector.cpp \
../dependencies/hippomocks/injector/injectorTest.cpp 

OBJS += \
./dependencies/hippomocks/injector/injector.o \
./dependencies/hippomocks/injector/injectorTest.o 

CPP_DEPS += \
./dependencies/hippomocks/injector/injector.d \
./dependencies/hippomocks/injector/injectorTest.d 


# Each subdirectory must supply rules for building sources it contributes
dependencies/hippomocks/injector/%.o: ../dependencies/hippomocks/injector/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/stekman/git/SudokoBBD/SudokoBBD/dependencies/igloo-master" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -std=c++11
	@echo 'Finished building: $<'
	@echo ' '


