CC = g++
OPT = -O0

GAME_BASE_DIR = .
SOURCE_DIR = $(GAME_BASE_DIR)/src
RESOURCES_DIR = $(SOURCE_DIR)/resources
MAIN_INCLUDE_DIR = $(RESOURCES_DIR)/include
MAIN_LIBRARY_DIR = $(RESOURCES_DIR)/lib

# ONLY NEED TO CHANGE THESE
CODE_DIRS = $(SOURCE_DIR) $(MAIN_LIBRARY_DIR)
INCLUDE_DIRS = $(MAIN_INCLUDE_DIR) $(MAIN_INCLUDE_DIR)/SDL2
EXTERNAL_LIBRARY_DIRS = $(MAIN_LIBRARY_DIR)/SDL2
BUILD_DIR = $(GAME_BASE_DIR)/bin

DEP_FLAGS = -MP -MD
COMPILER_FLAGS = -Wall -Wextra $(foreach D, $(INCLUDE_DIRS), -I$(D)) $(OPT) $(DEP_FLAGS)
LINKER_FLAGS = $(foreach D, $(EXTERNAL_LIBRARY_DIRS), -L$(D)) -lmingw32 -lSDL2 -lSDL2main

CFILES = $(foreach D, $(CODE_DIRS), $(wildcard $(D)/*.cpp))
OFILES = $(patsubst %.cpp, %.o, $(CFILES))
DFILES = $(patsubst %.cpp, %.d, $(CFILES))
TARGET_BINARY = $(BUILD_DIR)/snake_game

all: $(TARGET_BINARY)

$(TARGET_BINARY): $(OFILES)
	$(CC) $(OFILES) $(LINKER_FLAGS) -o $(TARGET_BINARY)

%.o: %.cpp
	$(CC) $< $(COMPILER_FLAGS) -c -o $@

clean:
	rm -rf $(TARGET_BINARY) $(OFILES) $(DFILES)

-include $(DFILES)