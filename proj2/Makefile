# target
TARGET = prog

# optimization
OPT = #-Og

# pathes
PROJECT_ROOT_DIR = ../
EXT_DIR = $(PROJECT_ROOT_DIR)/ext
AFL_DIR = $(EXT_DIR)/AFL
BUILD_DIR = $(PROJECT_ROOT_DIR)/build

# cpp defines
CPP_DEFS = 

# cpp sources
CPP_SOURCES = \
$(PROJECT_ROOT_DIR)/main.cpp

# cpp includes '-I'
CPP_INCLUDES = 

# cpp libs
SHARED_LIBS = 

# linker flags
LFLAGS = 

# compile g++ flags
CFLAGS = -c

# sanitazers flags
SF =  AFL_USE_UBSAN=1 AFL_USE_ASAN=1

# compiler
CXX = $(AFL_DIR)/afl-g++

all: $(BUILD_DIR)/$(TARGET)
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(SF) $(CXX) $(OBJECTS) -o $@ $(LFLAGS) $(SHARED_LIBS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(SF) $(CXX) $(CFLAGS) $< -o $@ $(CPP_DEFS) $(CPP_INCLUDES)

$(BUILD_DIR):
	mkdir $@

clean:
	rm -rf $(BUILD_DIR)

clean-test:
	rm -rf ./out

clean-all:
	rm -rf $(BUILD_DIR)
	rm -rf ./out

test:
	$(AFL_DIR)/afl-fuzz -i in -o out $(BUILD_DIR)/$(TARGET)
