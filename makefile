C_COMPILER=gcc
MAIN_FILE=main.c
FILE_TO_TEST=LedDriverTest.c
UNITY_PATH_AND_FILE=unity/src/unity.c
all:
	${C_COMPILER} ${MAIN_FILE} -o main.exe
test:
	${C_COMPILER} ${FILE_TO_TEST} ${UNITY_PATH_AND_FILE} -o test.exe
