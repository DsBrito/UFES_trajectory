# the compiler: gcc for C program, define as g++ for C++
CC = gcc
CXX = g++

BUILD_DIR = build
IMGUI_DIR = ../../libs/imgui

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
LINKING = -lglut -lGL -lGLU

IMGUI_SOURCES_DIRTY := $(wildcard $(IMGUI_DIR)/*.cpp)
IMGUI_SOURCES_NO_PREFIX := $(subst $(IMGUI_DIR)/,,$(IMGUI_SOURCES_DIRTY))
IMGUI_SOURCES := $(IMGUI_SOURCES_NO_PREFIX:.cpp=)
IMGUI_OBJS := $(IMGUI_SOURCES:%=$(BUILD_DIR)/imgui/%.o)

all: lightToroide

$(BUILD_DIR)/imgui/%.o: $(IMGUI_DIR)/%.cpp | build_imgui
	$(CXX) $(CFLAGS) -o $@ -c $< 

lightToroide: imgui lightToroide.cpp build
	$(CXX) $(CFLAGS) -o lightToroide lightToroide.cpp build/imgui/*.o $(LINKING)

run: lightToroide build
	./lightToroide

build_imgui: build
	mkdir build/imgui -p

build:
	mkdir build -p

imgui: $(IMGUI_OBJS) build

clean:
	$(RM) $(BUILD_DIR)/*.o -rf

clean-full:
	$(RM) $(BUILD_DIR) -rf