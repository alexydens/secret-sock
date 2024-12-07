SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

#CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c11 -I$(INC_DIR)
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -I$(INC_DIR)
LDFLAGS = -lm

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BIN_DIR)/secret_sock: $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR):
	mkdir -p $@
$(BIN_DIR):
	mkdir -p $@

.PHONY: clean build test

build: $(BIN_DIR)/secret_sock

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

test: build
	./$(BIN_DIR)/secret_sock
