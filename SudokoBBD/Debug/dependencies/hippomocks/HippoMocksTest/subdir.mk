################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dependencies/hippomocks/HippoMocksTest/is_virtual.cpp \
../dependencies/hippomocks/HippoMocksTest/test.cpp \
../dependencies/hippomocks/HippoMocksTest/test_args.cpp \
../dependencies/hippomocks/HippoMocksTest/test_class_args.cpp \
../dependencies/hippomocks/HippoMocksTest/test_class_mock.cpp \
../dependencies/hippomocks/HippoMocksTest/test_constref_params.cpp \
../dependencies/hippomocks/HippoMocksTest/test_cv_funcs.cpp \
../dependencies/hippomocks/HippoMocksTest/test_except.cpp \
../dependencies/hippomocks/HippoMocksTest/test_exception_quality.cpp \
../dependencies/hippomocks/HippoMocksTest/test_functors.cpp \
../dependencies/hippomocks/HippoMocksTest/test_nevercall.cpp \
../dependencies/hippomocks/HippoMocksTest/test_optional.cpp \
../dependencies/hippomocks/HippoMocksTest/test_overload.cpp \
../dependencies/hippomocks/HippoMocksTest/test_ref_args.cpp \
../dependencies/hippomocks/HippoMocksTest/test_regression_arg_count.cpp \
../dependencies/hippomocks/HippoMocksTest/test_retval.cpp \
../dependencies/hippomocks/HippoMocksTest/test_transaction.cpp \
../dependencies/hippomocks/HippoMocksTest/yaffut.cpp 

OBJS += \
./dependencies/hippomocks/HippoMocksTest/is_virtual.o \
./dependencies/hippomocks/HippoMocksTest/test.o \
./dependencies/hippomocks/HippoMocksTest/test_args.o \
./dependencies/hippomocks/HippoMocksTest/test_class_args.o \
./dependencies/hippomocks/HippoMocksTest/test_class_mock.o \
./dependencies/hippomocks/HippoMocksTest/test_constref_params.o \
./dependencies/hippomocks/HippoMocksTest/test_cv_funcs.o \
./dependencies/hippomocks/HippoMocksTest/test_except.o \
./dependencies/hippomocks/HippoMocksTest/test_exception_quality.o \
./dependencies/hippomocks/HippoMocksTest/test_functors.o \
./dependencies/hippomocks/HippoMocksTest/test_nevercall.o \
./dependencies/hippomocks/HippoMocksTest/test_optional.o \
./dependencies/hippomocks/HippoMocksTest/test_overload.o \
./dependencies/hippomocks/HippoMocksTest/test_ref_args.o \
./dependencies/hippomocks/HippoMocksTest/test_regression_arg_count.o \
./dependencies/hippomocks/HippoMocksTest/test_retval.o \
./dependencies/hippomocks/HippoMocksTest/test_transaction.o \
./dependencies/hippomocks/HippoMocksTest/yaffut.o 

CPP_DEPS += \
./dependencies/hippomocks/HippoMocksTest/is_virtual.d \
./dependencies/hippomocks/HippoMocksTest/test.d \
./dependencies/hippomocks/HippoMocksTest/test_args.d \
./dependencies/hippomocks/HippoMocksTest/test_class_args.d \
./dependencies/hippomocks/HippoMocksTest/test_class_mock.d \
./dependencies/hippomocks/HippoMocksTest/test_constref_params.d \
./dependencies/hippomocks/HippoMocksTest/test_cv_funcs.d \
./dependencies/hippomocks/HippoMocksTest/test_except.d \
./dependencies/hippomocks/HippoMocksTest/test_exception_quality.d \
./dependencies/hippomocks/HippoMocksTest/test_functors.d \
./dependencies/hippomocks/HippoMocksTest/test_nevercall.d \
./dependencies/hippomocks/HippoMocksTest/test_optional.d \
./dependencies/hippomocks/HippoMocksTest/test_overload.d \
./dependencies/hippomocks/HippoMocksTest/test_ref_args.d \
./dependencies/hippomocks/HippoMocksTest/test_regression_arg_count.d \
./dependencies/hippomocks/HippoMocksTest/test_retval.d \
./dependencies/hippomocks/HippoMocksTest/test_transaction.d \
./dependencies/hippomocks/HippoMocksTest/yaffut.d 


# Each subdirectory must supply rules for building sources it contributes
dependencies/hippomocks/HippoMocksTest/%.o: ../dependencies/hippomocks/HippoMocksTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/stekman/git/SudokoBBD/SudokoBBD/dependencies/igloo-master" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -std=c++11
	@echo 'Finished building: $<'
	@echo ' '


