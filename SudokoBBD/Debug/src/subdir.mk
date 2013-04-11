################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cell.cpp \
../src/Cell_test.cpp \
../src/Region.cpp \
../src/Region_test.cpp \
../src/SudokoBBD.cpp 

OBJS += \
./src/Cell.o \
./src/Cell_test.o \
./src/Region.o \
./src/Region_test.o \
./src/SudokoBBD.o 

CPP_DEPS += \
./src/Cell.d \
./src/Cell_test.d \
./src/Region.d \
./src/Region_test.d \
./src/SudokoBBD.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


