CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -O2
INCLUDES=-Isrc
SRCS := $(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
TARGET=library_manager

# Test configuration
TEST_DIR=tests
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS=$(TEST_SRCS:.c=.o)
# Source files needed for tests (exclude main.c)
TEST_SRC_FILES := $(filter-out src/main.c, $(SRCS))
TEST_SRC_OBJS := $(TEST_SRC_FILES:.c=.o)
TEST_TARGET=test_runner

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "🗑️  Removing old executable if exists..."
	@rm -f $(TARGET)
	@echo "🔨 Linking executable..."
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "✅ Build complete!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(TEST_OBJS) $(TEST_TARGET)

# Run the program
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)

# Build and run in one command
build-run: clean all
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)

# Test targets
$(TEST_TARGET): $(TEST_SRC_OBJS) $(TEST_OBJS)
	@echo "🔨 Building test executable..."
	$(CC) $(CFLAGS) -o $@ $(TEST_SRC_OBJS) $(TEST_OBJS)
	@echo "✅ Test build complete!"

test: $(TEST_TARGET)
	@echo "🧪 Running tests..."
	./$(TEST_TARGET)

test-clean:
	rm -f $(TEST_OBJS) $(TEST_TARGET)

.PHONY: all clean run build-run test test-clean
