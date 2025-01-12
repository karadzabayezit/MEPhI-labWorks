SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin
C_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_FILES))
EXECUTABLE := $(BIN_DIR)/app

all: $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	gcc -g -c $< -o $@

$(EXECUTABLE): $(OBJ_FILES) | $(BIN_DIR)
	gcc -g $^ -lreadline -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

watch:
	while true; do \
		inotifywait -e modify $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h; \
		make; \
	done

.PHONY: all clean watch
