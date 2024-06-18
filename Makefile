#
# Example Makefile for linux build
#

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra

# Linker flags
LDFLAGS = -Llib -Wl,-rpath=\$$ORIGIN/lib -lraylib -lm -ldl -lpthread -lrt -lX11

# Source directory
SRCDIR = src

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object directory
OBJDIR = obj

# Object files
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile the source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
