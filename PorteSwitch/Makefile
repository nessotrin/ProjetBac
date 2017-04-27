SRC_DIR = .

AUTO_CPPS = $(shell find $(SRC_DIR) -type f -name "*.cpp")

AUTO_FOLDER = $(shell find $(SRC_DIR) -type d)

AUTO_INCLUDE = $(shell find $(SRC_DIR) -type d | sed 's;$(SRC_DIR);-I $(SRC_DIR);')

CXX = g++
CXX_FLAGS = -g -fstack-protector-all -std=c++11 -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g 
BUILD_FLAGS = $(AUTO_INCLUDE) -I ../ClientLib/ -I ../BBBio_lib/ -D BBB
LINK_FLAGS = ../ClientLib/ClientLib.a /home/debian/Downloads/BBBIOlib-master/BBBio_lib/libBBBio.a

# Final binary
BIN = PorteSwitch
# Put all auto generated stuff to this build dir.
BUILD_DIR = ./build



# List of all .cpp source files.
CPPS =  $(AUTO_CPPS)

# All .o files go to build dir.
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o,$(CPPS))
# $(CPPS:$(PROJECT_FOLDER)/%.cpp=$(BUILD_DIR)/%.o)
# Gcc/Clang will create these .d files containing dependencies.
DEP = $(OBJ:%.o=%.d)



# Actual target of the binary - depends on all .o files.
$(BIN) : $(OBJ)
	@# Create build directories - same structure as sources.
	@mkdir -p $(@D)
	@# Just link all the object files.
	$(CXX) $^ -o $@ $(CXX_FLAGS) $(LINK_FLAGS)

# Include all .d files
-include $(DEP)

# Build target for every single object file.
# The potential dependency on header files is covered
# by calling `-include $(DEP)`.
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@# The -MMD flags additionaly creates a .d file with
	@# the same name as the .o file.
	$(CXX) -c $< -o $@ $(CXX_FLAGS) -MMD $(BUILD_FLAGS)

.PHONY : clean
clean :
	# This should remove all generated files.
	-@rm $(BUILD_DIR)/$(BIN) $(OBJ) $(DEP)
