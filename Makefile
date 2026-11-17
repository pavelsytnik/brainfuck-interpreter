CC = gcc

SRC_DIR = src
BIN_DIR = bin
OBJS = $(BIN_DIR)/main.o
CFLAGS = -std=c89 -Wall -Wextra -Werror -pedantic

$(BIN_DIR)/bf : $(OBJS)
	$(CC) $(OBJS) -o $@

$(BIN_DIR) :
	mkdir -p $@

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean :
	rm -rf $(BIN_DIR)
