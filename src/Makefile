LIB = s21_string.a
TEST_LIB = $(addprefix test_, $(LIB))

CC = gcc
GCOV = gcov

ifeq ($(shell uname -p), arm)
		CC = gcc-12
		GCOV = gcov-12
endif

FLAGS = -Wall -Werror -Wextra -std=c11 -g
GFLAGS = -fprofile-arcs -ftest-coverage
IN_FLAGS = $(shell pkg-config --cflags check)
CHFLAGS = $(shell pkg-config --cflags --libs check)
GOFLAGS = -lgcov
TEST_DIR = tests
BUILD_DIR = build
BUILD_TEST_DIR = build_tests
TEST_BUILD_DIR = test_build
GCOV_DIR = gcov_report

S21_SOURCES = $(wildcard s21_*.c)
TESTS = $(wildcard $(TEST_DIR)/test_*.c)
S21_OBJECTS=$(addprefix $(BUILD_DIR)/, $(S21_SOURCES:.c=.o))
TEST_S21_OBJECTS=$(addprefix $(TEST_BUILD_DIR)/, $(S21_SOURCES:.c=.o))
TEST_OBJECTS=$(addprefix $(BUILD_TEST_DIR)/, $(notdir $(TESTS:.c=.o)))

.PHONY : all clean gcov_report \
				style style-fix check  \
				rebuild docker gcov    \
				valgrind run external

all : $(LIB) test #gcov_report

test: $(TEST_OBJECTS) $(TEST_LIB)
	$(CC) $(FLAGS) $^ -o $@ $(CHFLAGS) $(GOFLAGS)

$(TEST_OBJECTS) : $(BUILD_TEST_DIR)/%.o : $(TEST_DIR)/%.c $(TEST_DIR)/test_string.h
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(IN_FLAGS) -c $< -o $@ $(WNO)


$(TEST_LIB): $(TEST_S21_OBJECTS)
	ar -rcs $@ $^

$(TEST_S21_OBJECTS): $(TEST_BUILD_DIR)/%.o : %.c $(LIB:.a=.h)
	@mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) $(GFLAGS) -c $< -o $@

$(LIB): $(S21_OBJECTS)
	ar -rcs $@ $^

$(S21_OBJECTS): $(BUILD_DIR)/%.o : %.c $(LIB:.a=.h)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

gcov: gcov_report
	@open ./$(GCOV_DIR)/gcov_report.html

gcov_report : $(LIB) test run $(GCOV_DIR)/gcov_report.html

$(GCOV_DIR)/gcov_report.html : $(LIB) test
	@mkdir -p gcov_report
	gcovr -r . --gcov-executable $(GCOV) --html --html-details -o $(GCOV_DIR)/gcov_report.html

style:
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -n *.c *.h
	@clang-format -n tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

style-fix:
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -style=Google -i *.c *.h
	@clang-format -style=Google -i tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

clean:
	@echo ==Cleaning...==
	@rm -rf $(GCOV_DIR) $(BUILD_DIR) $(BUILD_TEST_DIR) $(TEST_BUILD_DIR)
	@rm -rf *.html
	@rm -rf a.out test
	@rm -rf *.a
	@rm -rf *.css
	@rm -rf *.gch $(TEST_DIR)/*.gch
	@rm -rf ./external/external
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild : 
	$(MAKE) clean
	$(MAKE) all

<<<<<<< HEAD
SRC=s21_strlen.c s21_strcpy.c s21_strncpy.c s21_sscanf.c sscanf_driver.c
EXE=s21_sscanf

sscanf : 
	$(CC) $(FLAGS) $(SRC) -o $(EXE) -lm
=======
>>>>>>> origin/vlad
