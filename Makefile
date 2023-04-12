CXX		  := g++
CXX_FLAGS := -Wall -Wextra -Wno-unused-parameter -std=c++17 -ggdb

BIN		:= build
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= 
EXECUTABLE	:= main

MKDIR_P = mkdir -p

.PHONY: directories

all: directories $(BIN)/$(EXECUTABLE)

directories: ${BIN}

${BIN}:
	${MKDIR_P} ${BIN}

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
