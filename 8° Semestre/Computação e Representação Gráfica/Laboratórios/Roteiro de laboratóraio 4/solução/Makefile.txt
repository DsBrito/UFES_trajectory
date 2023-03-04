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

all: soldier

$(BUILD_DIR)/imgui/%.o: $(IMGUI_DIR)/%.cpp | build_imgui
	$(CXX) $(CFLAGS) -o $@ -c $< 

soldier: soldado.cpp build/objloader.o imgui | build
	$(CXX) $(CFLAGS) -o soldier soldado.cpp build/objloader.o build/imgui/*.o $(LINKING)

run: soldier
	./soldier

build_imgui: build
	mkdir build/imgui -p

build:
	mkdir build -p

imgui: $(IMGUI_OBJS) build

clean:
	$(RM) $(BUILD_DIR)/*.o -rf
	$(RM) soldier

clean-full:
	$(RM) $(BUILD_DIR) -rf

$(BUILD_DIR)/objloader.o: objloader.cpp | build
	$(CXX) $(CFLAGS) -o $@ -c $<
