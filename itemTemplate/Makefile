SRC_DIR := ./
OBJ_DIR := ./build/
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := 
CPPFLAGS := 
CXXFLAGS := -std=c++11

MKDIR = mkdir
RM = rm -f
ECHO = echo

all: app

app: $(OBJ_FILES)
	@$(ECHO) Building $< to $@
	@$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(ECHO) Compiling $< to $@
	@$(MKDIR) -p $(OBJ_DIR)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	@$(RM) app	
	@$(RM) -r $(OBJ_DIR)