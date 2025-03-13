# target
TARGET = prog

# optimization
OPT = #-Og

# pathes
PROJECT_ROOT_DIR = .
SRC_CODE_DIR = $(PROJECT_ROOT_DIR)/src
BUILD_DIR = $(PROJECT_ROOT_DIR)/build

# cpp defines
CPP_DEFS = 

# cpp sources
CPP_SOURCES = \
$(SRC_CODE_DIR)/main.cpp

# cpp includes '-I'
CPP_INCLUDES = 

# cpp libs
SHARED_LIBS = 

# linker flags
LFLAGS = 

# compile g++ flags
CFLAGS = -c

# sanitazers flags
SF =  AFL_USE_UBSAN=1 # AFL_USE_ASAN=1

# compiler
CXX = ../AFL/afl-g++

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
	../AFL/afl-fuzz -i in -o out $(BUILD_DIR)/$(TARGET)
