# the compiler: gcc for C program, define as g++ for C++
CC = gcc

ifeq ($(ARCH), WIN)
CXX = x86_64-w64-mingw32-g++
else
CXX = g++
endif

BUILD_DIR = build
IMGUI_DIR = ../libs/imgui

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall $(LINKING)
ifeq ($(ARCH), WIN)
LINKING=-static -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows -I../libs/win/freeglut/include -L../libs/win/freeglut/lib/x64
else
LINKING = -lglut -lGL -lGLU
endif

IMGUI_SOURCES_DIRTY := $(wildcard $(IMGUI_DIR)/*.cpp)
IMGUI_SOURCES_NO_PREFIX := $(subst $(IMGUI_DIR)/,,$(IMGUI_SOURCES_DIRTY))
IMGUI_SOURCES := $(IMGUI_SOURCES_NO_PREFIX:.cpp=)
IMGUI_OBJS := $(IMGUI_SOURCES:%=$(BUILD_DIR)/imgui/%.o)

all: orbit

$(BUILD_DIR)/imgui/%.o: $(IMGUI_DIR)/%.cpp | build_imgui
	$(CXX) $(CFLAGS) -o $@ -c $< 

orbit: terrasol.cpp build/imageloader.o imgui | build
	$(CXX) $(CFLAGS) -o orbit terrasol.cpp build/imageloader.o build/imgui/*.o $(LINKING)

run: orbit
	./orbit

build_imgui: build
	mkdir build/imgui -p

build:
	mkdir build -p

imgui: $(IMGUI_OBJS) build

clean:
	$(RM) $(BUILD_DIR)/*.o -rf
	$(RM) orbit

clean-full:
	$(RM) $(BUILD_DIR) -rf

$(BUILD_DIR)/imageloader.o: imageloader.cpp | build
	$(CXX) $(CFLAGS) -o $@ -c $<
