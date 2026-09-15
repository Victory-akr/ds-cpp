CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O0 -g
INC_DIR  := include
SRC_DIR  := src
TEST_DIR := tests
BIN_DIR  := bin

# 所有 .cpp 里，除了 src/main.cpp（它自带 main()）之外，都是可以复用的实现
LIB_SRCS  := $(filter-out $(SRC_DIR)/main.cpp,$(wildcard $(SRC_DIR)/*.cpp))
MAIN_SRC  := $(SRC_DIR)/main.cpp
MAIN_BIN  := $(BIN_DIR)/main
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_BINS := $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TEST_SRCS))

.PHONY: all run test check clean

all: $(MAIN_BIN)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 小程序 = main.cpp + 所有实现文件
$(MAIN_BIN): $(MAIN_SRC) $(LIB_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(MAIN_SRC) $(LIB_SRCS) -o $@

# 每个测试 = 测试文件 + 所有实现文件（但不含 main.cpp，避免两个 main 冲突）
$(BIN_DIR)/%: $(TEST_DIR)/%.cpp $(LIB_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $< $(LIB_SRCS) -o $@

run: $(MAIN_BIN)
	./$(MAIN_BIN)

test: $(TEST_BINS)
	@fail=0; for t in $(TEST_BINS); do \
		echo "=== $$t ==="; ./$$t || fail=1; done; \
	if [ $$fail -eq 0 ]; then echo "ALL TESTS PASSED"; else echo "SOME TESTS FAILED"; exit 1; fi

# 最快的反馈：只做语法检查，不产出可执行文件
check:
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -fsyntax-only $(MAIN_SRC) $(LIB_SRCS) && echo "SYNTAX OK"

clean:
	rm -rf $(BIN_DIR)
