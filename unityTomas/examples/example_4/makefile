C_COMPILER=gcc

UNITY_ROOT=../..
TARGET_EXTENSION=.exe


TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)

.PHONY: all test clean

program: 
	$(C_COMPILER) -o program src/main2_refactored.c src/main2_functions.c

test: 
	$(C_COMPILER) src/main2_functions.c $(UNITY_ROOT)/src/unity.c test/test_main2_functions.c -o $(TARGET1)
	- ./$(TARGET1) -v





