################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dependencies/igloo-master/tests/abstract_tests.cpp \
../dependencies/igloo-master/tests/alternative_registration.cpp \
../dependencies/igloo-master/tests/assertmacro_tests.cpp \
../dependencies/igloo-master/tests/bdd_tests.cpp \
../dependencies/igloo-master/tests/boolean_constraints.cpp \
../dependencies/igloo-master/tests/coloredconsoletestresultsoutput_tests.cpp \
../dependencies/igloo-master/tests/container_spec.cpp \
../dependencies/igloo-master/tests/context_error_handling.cpp \
../dependencies/igloo-master/tests/context_metadata.cpp \
../dependencies/igloo-master/tests/contextregistry_tests.cpp \
../dependencies/igloo-master/tests/custom_matchers_test.cpp \
../dependencies/igloo-master/tests/defaulttestresultsoutput_tests.cpp \
../dependencies/igloo-master/tests/exceptions_tests.cpp \
../dependencies/igloo-master/tests/expression_error_handling.cpp \
../dependencies/igloo-master/tests/igloo_tests.cpp \
../dependencies/igloo-master/tests/main.cpp \
../dependencies/igloo-master/tests/map_tests.cpp \
../dependencies/igloo-master/tests/nested_contexts.cpp \
../dependencies/igloo-master/tests/operator_tests.cpp \
../dependencies/igloo-master/tests/sequence_container_tests.cpp \
../dependencies/igloo-master/tests/string_line_tests.cpp \
../dependencies/igloo-master/tests/string_tests.cpp \
../dependencies/igloo-master/tests/stringize_tests.cpp \
../dependencies/igloo-master/tests/testfixtures.cpp \
../dependencies/igloo-master/tests/testlistener_tests.cpp \
../dependencies/igloo-master/tests/testresultfactory_tests.cpp \
../dependencies/igloo-master/tests/testresults_tests.cpp \
../dependencies/igloo-master/tests/visualstudiotestresultsoutput_tests.cpp \
../dependencies/igloo-master/tests/xmlwritter_tests.cpp \
../dependencies/igloo-master/tests/xunittestresultsoutput_tests.cpp 

OBJS += \
./dependencies/igloo-master/tests/abstract_tests.o \
./dependencies/igloo-master/tests/alternative_registration.o \
./dependencies/igloo-master/tests/assertmacro_tests.o \
./dependencies/igloo-master/tests/bdd_tests.o \
./dependencies/igloo-master/tests/boolean_constraints.o \
./dependencies/igloo-master/tests/coloredconsoletestresultsoutput_tests.o \
./dependencies/igloo-master/tests/container_spec.o \
./dependencies/igloo-master/tests/context_error_handling.o \
./dependencies/igloo-master/tests/context_metadata.o \
./dependencies/igloo-master/tests/contextregistry_tests.o \
./dependencies/igloo-master/tests/custom_matchers_test.o \
./dependencies/igloo-master/tests/defaulttestresultsoutput_tests.o \
./dependencies/igloo-master/tests/exceptions_tests.o \
./dependencies/igloo-master/tests/expression_error_handling.o \
./dependencies/igloo-master/tests/igloo_tests.o \
./dependencies/igloo-master/tests/main.o \
./dependencies/igloo-master/tests/map_tests.o \
./dependencies/igloo-master/tests/nested_contexts.o \
./dependencies/igloo-master/tests/operator_tests.o \
./dependencies/igloo-master/tests/sequence_container_tests.o \
./dependencies/igloo-master/tests/string_line_tests.o \
./dependencies/igloo-master/tests/string_tests.o \
./dependencies/igloo-master/tests/stringize_tests.o \
./dependencies/igloo-master/tests/testfixtures.o \
./dependencies/igloo-master/tests/testlistener_tests.o \
./dependencies/igloo-master/tests/testresultfactory_tests.o \
./dependencies/igloo-master/tests/testresults_tests.o \
./dependencies/igloo-master/tests/visualstudiotestresultsoutput_tests.o \
./dependencies/igloo-master/tests/xmlwritter_tests.o \
./dependencies/igloo-master/tests/xunittestresultsoutput_tests.o 

CPP_DEPS += \
./dependencies/igloo-master/tests/abstract_tests.d \
./dependencies/igloo-master/tests/alternative_registration.d \
./dependencies/igloo-master/tests/assertmacro_tests.d \
./dependencies/igloo-master/tests/bdd_tests.d \
./dependencies/igloo-master/tests/boolean_constraints.d \
./dependencies/igloo-master/tests/coloredconsoletestresultsoutput_tests.d \
./dependencies/igloo-master/tests/container_spec.d \
./dependencies/igloo-master/tests/context_error_handling.d \
./dependencies/igloo-master/tests/context_metadata.d \
./dependencies/igloo-master/tests/contextregistry_tests.d \
./dependencies/igloo-master/tests/custom_matchers_test.d \
./dependencies/igloo-master/tests/defaulttestresultsoutput_tests.d \
./dependencies/igloo-master/tests/exceptions_tests.d \
./dependencies/igloo-master/tests/expression_error_handling.d \
./dependencies/igloo-master/tests/igloo_tests.d \
./dependencies/igloo-master/tests/main.d \
./dependencies/igloo-master/tests/map_tests.d \
./dependencies/igloo-master/tests/nested_contexts.d \
./dependencies/igloo-master/tests/operator_tests.d \
./dependencies/igloo-master/tests/sequence_container_tests.d \
./dependencies/igloo-master/tests/string_line_tests.d \
./dependencies/igloo-master/tests/string_tests.d \
./dependencies/igloo-master/tests/stringize_tests.d \
./dependencies/igloo-master/tests/testfixtures.d \
./dependencies/igloo-master/tests/testlistener_tests.d \
./dependencies/igloo-master/tests/testresultfactory_tests.d \
./dependencies/igloo-master/tests/testresults_tests.d \
./dependencies/igloo-master/tests/visualstudiotestresultsoutput_tests.d \
./dependencies/igloo-master/tests/xmlwritter_tests.d \
./dependencies/igloo-master/tests/xunittestresultsoutput_tests.d 


# Each subdirectory must supply rules for building sources it contributes
dependencies/igloo-master/tests/%.o: ../dependencies/igloo-master/tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/stekman/git/SudokoBBD/SudokoBBD/dependencies/igloo-master" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -std=c++11
	@echo 'Finished building: $<'
	@echo ' '


