################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/Board_test.cpp \
../src/Cell.cpp \
../src/Cell_test.cpp \
../src/Region.cpp \
../src/Region_test.cpp \
../src/SudokoBBD.cpp 

OBJS += \
./src/Board.o \
./src/Board_test.o \
./src/Cell.o \
./src/Cell_test.o \
./src/Region.o \
./src/Region_test.o \
./src/SudokoBBD.o 

CPP_DEPS += \
./src/Board.d \
./src/Board_test.d \
./src/Cell.d \
./src/Cell_test.d \
./src/Region.d \
./src/Region_test.d \
./src/SudokoBBD.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/stekman/git/SudokoBBD/SudokoBBD/dependencies/igloo-master" -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


