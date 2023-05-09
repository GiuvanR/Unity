all: 
	clean compile run
	gcc -o app src/quick_sort.c src/merge_sort.c src/heap_sort.c src/selection_sort.c src/insertion_sort.c src/bubble_sort.c src/radix_sort.c src/counting_sort.c src/sort.c main.c

compile:
	$(GCC_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o $(TARGET)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $(INC_DIRS) src/foo.c

valgrind:
	$(GCC_COMPILER) -g -Wall -Wfatal-errors $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) -v

sanitizer:
	$(CLANG_COMPILER) -g -Wall -Wfatal-errors -fsanitize=address $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET) -v

cov:
	$(GCC_COMPILER) $(CFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET) -v
	gcov -b foo.c

run:
	./$(TARGET) -v

clean:
	rm -fr $(TARGET) *.gcno *.gcda *.gcov *.dSYM
	rm -f app
