# ————————————————————
# Main Makefile
# Index of Modifiable paths
# GAME_BASE_DIR
# |
# |__ SRC_DIR				(Main Directory Definitions)
# |__ RESOURCE_DIR			(Main Directory Definitions)
# |  |__ MAIN_INCLUDE_DIR	(Main Directory Definitions)
# |  |__ MAIN_LIB_DIR		(Main Directory Definitions)
# |__ INCLUDE_DIRS			(Compiler Config)
# |__ LIBRARY_DIRS			(Linker Config)
# ————————————————————
# Compiler
# ————————————————————
CC = g++

OPT= -O0
# ————————————————————
# Main Directory Definitions (Sent to sub-makes as well)
# ————————————————————
GAME_BASE_DIR = .

SRC_DIR = $(GAME_BASE_DIR)/src

RESOURCE_DIR = $(GAME_BASE_DIR)/src/resources

MAIN_INCLUDE_DIR = $(RESOURCE_DIR)/include

MAIN_LIB_DIR = $(RESOURCE_DIR)/lib

BUILD_DIR = $(GAME_BASE_DIR)/builds
# ————————————————————
# Compiler Config
# ————————————————————
INCLUDE_DIRS = $(MAIN_INCLUDE_DIR) $(wildcard $(MAIN_INCLUDE_DIR/*/))

DEP_FLAGS = -MP -MD

COMPILER_FLAGS = -Wall -Wextra -W1,-subsystem,windows -g $(foreach D, $(INCLUDE_DIRS), -I$(D)) $(OPT) $(DEP_FLAGS)
# ————————————————————
# Linker Config
# ————————————————————
LIBRARY_DIRS = $(wildcard $(MAIN_LIB_DIR/*/))

LINKER_FLAGS = -lmingw32 -lSDL.lib -lSDLmain.lib $(foreach D, $(LIBRARY_DIRS), -L$(D))
# ————————————————————
# Build Config
# ————————————————————
CFILES = $(foreach, D, $(SRC_DIR), $(wildcard $(D)/*.cpp))

OBS = $(patsubst %.cpp, %.o, $(CFILES))

DEP_FILES = $(patsubst %.cpp, %.d, $(CFILES))

TARGET_NAME = $(BUILD_DIR)/custom_build_game
# ————————————————————
# Build Rules
# ————————————————————
all: $(TARGET_NAME)

$(TARGET_NAME): $(OBS)
	$(CC) $(OBS) $(LINKER_FLAGS) -o $(TARGET_NAME)

%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGET_NAME) $(OBS) $(DEP_FILES)

# Leaves the target binary
cleanlite:
	rm -rf $(TARGET_NAME) $(OBS) $(DEP_FILES)

distribute: clean
	tar zcvf dist.tgz *

-include $(DEP_FILES)

.PHONY: all clean distribute
# ————————————————————
# End Main Makefile
# ————————————————————
