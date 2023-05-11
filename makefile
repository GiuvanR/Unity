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
CFLAGS += -fprofile-arcs -ftest-coverage

TARGET_BASE1=testes

TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)

SRC_FILES1=\
  src/unity.c \
  extras/fixture/src/unity_fixture.c \
  examples/t1/src/bubble_sort.c \
  examples/t1/src/counting_sort.c \
  examples/t1/src/heap_sort.c \
  examples/t1/src/insertion_sort.c \
  examples/t1/src/merge_sort.c \
  examples/t1/src/quick_sort.c \
  examples/t1/src/radix_sort.c \
  examples/t1/src/selection_sort.c \
  examples/t1/src/sort.c \
  examples/t1/test/TestSort.c \
  examples/t1/test/test_runners/TestSort_Runner.c \
  examples/t1/test/test_runners/all_tests.c

INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

SYMBOLS=

all: 
	clean compile run

compile:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $(INC_DIRS) $(SRC_FILES1)

valgrind:
	$(GCC_COMPILER) -g -Wall -Wfatal-errors $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET1) -v

sanitizer:
	$(CLANG_COMPILER) -g -Wall -Wfatal-errors -fsanitize=address $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1) -v

cov:
	$(GCC_COMPILER) $(CFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1) -v
	gcov -b sort.c bubble_sort.c counting_sort.c heap_sort.c insertion_sort.c merge_sort.c quick_sort.c radix_sort.c selection_sort.c

run:
	./$(TARGET1) -v

clean:
	rm -fr $(TARGET1) *.gcno *.gcda *.gcov *.dSYM

ci: CFLAGS += -Werror
ci: compile