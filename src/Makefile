CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
SRC=s21_sscanf.c sscanf_driver.c
EXE=s21_sscanf

.PHONY: all clean

all: clean
	$(CC) $(CFLAGS) $(SRC) -o $(EXE) -lm

clean:
	rm -rf $(EXE)
