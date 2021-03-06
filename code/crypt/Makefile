# Travis example for Identifier created by Rafael Garibotti
# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../..

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -ggdb3
CFLAGS += -Wfatal-errors 

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/TestCrypt.c \
  test/test_runners/TestCrypt_Runner.c \
  test/test_runners/all_tests.c \
  src/aes.c \
  src/blowfish.c \
  src/xtea.c \
  src/crypt.c 
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=


##### Compiler options #####
CC = gcc

##### Project specific libraries #####
SRC_FILES = src/*.c





ALL = clean cppcheck addrsanitizer run clean unitytest run valgrind gcov

all: $(ALL)

##### General commands #####
main: $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o app
	#ma$(CC) *.o -o app
#	rm -rf *.o

run:
	- ./$(TARGET1) -v	


###################### TEST TOOLS#######################################
unitytest:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -fprofile-arcs -ftest-coverage -o $(TARGET1)

addrsanitizer:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -fsanitize=address -o $(TARGET1)

cppcheck:
	cppcheck --enable=all -v --suppress=missingIncludeSystem src/crypt.c src/aes.c src/xtea.c src/blowfish.c

gcov:
	gcov -b -a -f crypt aes xtea blowfish

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./all_tests.out
#########################################################################
clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov *.out

cleanunity:
	$(CLEANUP) $(TARGET1)



test: addrsanitizer clean unitytest
	

#ci: CFLAGS += -Werror





