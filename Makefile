# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -fPIC -I$(SCOPE_INCLUDEDIR) -I$(COMP_INCLUDEDIR)
LDFLAGS = -shared

# Directories
COMP_SRCDIR = 03_comp_source
SCOPE_SRCDIR = 05_scope_source
SCOPE_INCLUDEDIR = 05_scope_include
COMP_INCLUDEDIR = 03_comp_include

# Object directories
COMP_OBJDIR = $(OBJDIR)/comp
SCOPE_OBJDIR = $(OBJDIR)/scope

# Library directories
SCOPE_LIBDIR = lib

# Source files
COMP_SRCS = $(COMP_SRCDIR)/assign.c \
    $(COMP_SRCDIR)/block_compound.c \
    $(COMP_SRCDIR)/begin_prog.c \
    $(COMP_SRCDIR)/call.c \
    $(COMP_SRCDIR)/check.c \
    $(COMP_SRCDIR)/color.c \
    $(COMP_SRCDIR)/compare.c \
    $(COMP_SRCDIR)/comp_main.c \
    $(COMP_SRCDIR)/comp_nasm_code_gen.c \
    $(COMP_SRCDIR)/comp_seed_code_gen.c \
    $(COMP_SRCDIR)/convert.c \
    $(COMP_SRCDIR)/data_types.c \
    $(COMP_SRCDIR)/error.c \
    $(COMP_SRCDIR)/external.c \
    $(COMP_SRCDIR)/function.c \
    $(COMP_SRCDIR)/generate.c \
    $(COMP_SRCDIR)/global_compound.c \
    $(COMP_SRCDIR)/hold.c \
    $(COMP_SRCDIR)/internal.c \
    $(COMP_SRCDIR)/lexer.c \
    $(COMP_SRCDIR)/list.c \
    $(COMP_SRCDIR)/local_compound.c \
    $(COMP_SRCDIR)/log.c \
    $(COMP_SRCDIR)/loop.c \
    $(COMP_SRCDIR)/manager.c \
    $(COMP_SRCDIR)/match.c \
    $(COMP_SRCDIR)/pare.c \
    $(COMP_SRCDIR)/parse.c \
    $(COMP_SRCDIR)/parse_expressions.c \
    $(COMP_SRCDIR)/passage.c \
    $(COMP_SRCDIR)/pass_arg.c \
    $(COMP_SRCDIR)/port_hub.c \
    $(COMP_SRCDIR)/prototype.c \
    $(COMP_SRCDIR)/retrieve.c \
    $(COMP_SRCDIR)/set_loop.c \
    $(COMP_SRCDIR)/state.c \
    $(COMP_SRCDIR)/strand.c \
    $(COMP_SRCDIR)/table.c \
    $(COMP_SRCDIR)/tripare.c \
    $(COMP_SRCDIR)/vine.c \
    $(COMP_SRCDIR)/yield.c

# Scope table library source files
SCOPE_SRCS = $(wildcard $(SCOPE_SRCDIR)/*.c)
SCOPE_HEADERS = $(wildcard $(SCOPE_INCLUDEDIR)/*.h)

# Object files
COMP_OBJS = $(addprefix $(COMP_OBJDIR)/comp_, $(notdir $(COMP_SRCS:.c=.o)))
SCOPE_OBJS = $(patsubst $(SCOPE_SRCDIR)/%.c,$(SCOPE_OBJDIR)/%.o,$(SCOPE_SRCS))
COMP_BASIC_OBJS = $(addprefix $(COMP_OBJDIR)/basic_, $(notdir $(COMP_SRCS:.c=.o)))

# Library names
SCOPE_LIB_STATIC = $(LIBDIR)/libscope_table.a
SCOPE_LIB_SHARED = $(LIBDIR)/libscope_table.so

# Output executable
COMP_TARGET = $(BINDIR)/comp

# Local build directories
BINDIR = 00_bin
OBJDIR = 00_obj
LIBDIR = 00_lib

# Create directory structure
create_dirs:
	@mkdir -p $(BINDIR)
	@mkdir -p $(COMP_OBJDIR)
	@mkdir -p $(SCOPE_OBJDIR)
	@mkdir -p $(LIBDIR)

# Main targets
.PHONY: all clean clean_comp clean_scope debug install comp scope

# Default target builds everything into local bin/
all: scope comp

# Installation target
install: all
	sudo mkdir -p /usr/local/illeshian/00_bin
	sudo mkdir -p /usr/local/illeshian/00_lib
	sudo mkdir -p /usr/local/illeshian/include/illeshian
	sudo install -m 755 $(COMP_TARGET) /usr/local/illeshian/00_bin
	sudo cp -r $(SCOPE_LIBDIR)/* /usr/local/illeshian/00_lib
	sudo cp -r $(SCOPE_INCLUDEDIR)/* /usr/local/illeshian/include/illeshian

# Separate target for scope table library
scope: create_dirs $(SCOPE_LIB_STATIC) $(SCOPE_LIB_SHARED)

# Separate target for main compiler
comp: create_dirs scope $(COMP_OBJS) $(SCOPE_LIB_STATIC)
	@echo "Linking COMP with scope library..."
	@$(CC) -o $(COMP_TARGET) $(COMP_OBJS) $(SCOPE_LIB_STATIC)
	@cp $(COMP_TARGET) ./comp

# Compile Compiler source files
$(COMP_OBJDIR)/comp_%.o: $(COMP_SRCDIR)/%.c | create_dirs $(SCOPE_LIB_STATIC)
	@echo "Compiling COMP: $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Compile basic compiler files (without scope table)
$(COMP_OBJDIR)/basic_%.o: $(COMP_SRCDIR)/%.c | create_dirs
	@echo "Compiling COMP (basic): $< -> $@"
	$(CC) $(CFLAGS) -DBASIC_COMPILER -c $< -o $@

# Compile scope table source files
$(SCOPE_OBJDIR)/%.o: $(SCOPE_SRCDIR)/%.c | create_dirs
	@echo "Compiling scope table: $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(SCOPE_LIB_STATIC): $(SCOPE_OBJS)
	@echo "Creating static library: $@"
	ar rcs $@ $(SCOPE_OBJS)

# Create shared library
$(SCOPE_LIB_SHARED): $(SCOPE_OBJS)
	@echo "Creating shared library: $@"
	$(CC) $(LDFLAGS) -o $@ $(SCOPE_OBJS)

# Link basic compiler executable
$(COMP_TARGET)_basic: $(COMP_BASIC_OBJS)
	@echo "Linking basic COMP..."
	@$(CC) $(COMP_BASIC_OBJS) -o $@ 2>&1 || { echo "Error linking $(COMP_TARGET)_basic:"; $(CC) $(COMP_BASIC_OBJS) -o $@; }

# Debug target
debug:
	@echo "COMP_SRCS = $(COMP_SRCS)"
	@echo "COMP_OBJS = $(COMP_OBJS)"
	@echo "SCOPE_SRCS = $(SCOPE_SRCS)"
	@echo "SCOPE_OBJS = $(SCOPE_OBJS)"
	@echo "Current directory: $$(pwd)"
	@echo "Directory contents:"
	@ls -R

# Individual clean rules
clean_comp:
	@echo "Cleaning COMP..."
	rm -rf $(COMP_OBJDIR)
	rm -f $(COMP_TARGET)
	rm -f $(COMP_TARGET)_basic
	rm -f comp

clean_scope:
	@echo "Cleaning scope library..."
	rm -rf $(SCOPE_OBJDIR)
	rm -f $(SCOPE_LIB_STATIC)
	rm -f $(SCOPE_LIB_SHARED)
	rm -f scope_table.txt

# Main clean rule
clean: clean_comp clean_scope
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
	rm -rf $(LIBDIR)
