# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -fPIC -I$(SCOPE_INCLUDEDIR)
LDFLAGS = -shared

# Directories
IRP_SRCDIR = 02_irp_source
COMP_SRCDIR = 03_comp_source
ILL_SRCDIR = 01_ill_source
SEED_SRCDIR = 04_seed_source
SCOPE_SRCDIR = 05_scope_source
SCOPE_INCLUDEDIR = 05_scope_include

# Include directories
IRP_INCLUDEDIR = 02_irp_include
COMP_INCLUDEDIR = 03_comp_include
ILL_INCLUDEDIR = 01_ill_include
SEED_INCLUDEDIR = 04_seed_include

# Object directories
IRP_OBJDIR = irp_obj
COMP_OBJDIR = comp_obj
ILL_OBJDIR = ill_obj
SEED_OBJDIR = seed_obj
SCOPE_OBJDIR = $(OBJDIR)/scope

# Scope table library directories
SCOPE_SRCDIR = 05_scope_source
SCOPE_INCLUDEDIR = 05_scope_include
SCOPE_OBJDIR = $(OBJDIR)/scope
SCOPE_LIBDIR = lib

# Source files (unchanged)
IRP_SRCS = $(IRP_SRCDIR)/irp_main.c \
           $(IRP_SRCDIR)/irp_match.c \
           $(IRP_SRCDIR)/color.c \
           $(IRP_SRCDIR)/irp_lex.c \
           $(IRP_SRCDIR)/fm_processor.c \
           $(IRP_SRCDIR)/error.c 

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
IRP_OBJS = $(addprefix $(IRP_OBJDIR)/irp_, $(notdir $(IRP_SRCS:.c=.o)))
COMP_OBJS = $(addprefix $(COMP_OBJDIR)/comp_, $(notdir $(COMP_SRCS:.c=.o)))
SCOPE_OBJS = $(patsubst $(SCOPE_SRCDIR)/%.c,$(SCOPE_OBJDIR)/%.o,$(SCOPE_SRCS))
COMP_BASIC_OBJS = $(addprefix $(COMP_OBJDIR)/basic_, $(notdir $(COMP_SRCS:.c=.o)))

# Library names
SCOPE_LIB_STATIC = $(LIBDIR)/libscope_table.a
SCOPE_LIB_SHARED = $(LIBDIR)/libscope_table.so

# Output executables
IRP_TARGET = $(BINDIR)/irp
COMP_TARGET = $(BINDIR)/comp
SEED_TARGET = $(BINDIR)/seed
ILL_TARGET = $(BINDIR)/ill

# Add Seedling source files
SEED_SRCS = $(SEED_SRCDIR)/seed_main.c \
            $(SEED_SRCDIR)/seed_align.c \
            $(SEED_SRCDIR)/seed_arch.c \
            $(SEED_SRCDIR)/seed_assign.c \
			$(SEED_SRCDIR)/seed_arith.c \
            $(SEED_SRCDIR)/seed_begin_prog.c \
            $(SEED_SRCDIR)/seed_code.c \
            $(SEED_SRCDIR)/seed_compare.c \
			$(SEED_SRCDIR)/seed_common.c \
            $(SEED_SRCDIR)/seed_call.c \
			$(SEED_SRCDIR)/seed_nasm_encode.c \
            $(SEED_SRCDIR)/seed_error.c \
            $(SEED_SRCDIR)/seed_declare.c \
            $(SEED_SRCDIR)/seed_global_block.c \
            $(SEED_SRCDIR)/seed_global.c \
            $(SEED_SRCDIR)/seed_lex.c \
            $(SEED_SRCDIR)/seed_literal.c \
            $(SEED_SRCDIR)/seed_local_block.c \
            $(SEED_SRCDIR)/seed_local.c \
            $(SEED_SRCDIR)/seed_log.c \
			$(SEED_SRCDIR)/seed_file.c \
            $(SEED_SRCDIR)/seed_match.c \
			$(SEED_SRCDIR)/seed_opcode.c \
			$(SEED_SRCDIR)/seed_pad.c \
			$(SEED_SRCDIR)/seed_phrases.c \
            $(SEED_SRCDIR)/seed_parse_type.c \
			$(SEED_SRCDIR)/seed_push.c \
			$(SEED_SRCDIR)/seed_registers.c \
            $(SEED_SRCDIR)/seed_section.c \
			$(SEED_SRCDIR)/seed_system.c \
            $(SEED_SRCDIR)/seed_universal.c \
			$(SEED_SRCDIR)/seed_move.c \
			$(SEED_SRCDIR)/seed_jump.c \
			$(SEED_SRCDIR)/seed_pass_arg.c \
			$(SEED_SRCDIR)/seed_set_flag.c \
            $(SEED_SRCDIR)/color.c

# Add Seedling object files
SEED_OBJS = $(addprefix $(SEED_OBJDIR)/seed_, $(notdir $(SEED_SRCS:.c=.o)))

# Add Illeshian driver source files
ILL_SRCS = $(ILL_SRCDIR)/ill_main.c \
           $(ILL_SRCDIR)/process_irp.c \
           $(ILL_SRCDIR)/process_comp.c \
           $(ILL_SRCDIR)/process_seed.c \
           $(ILL_SRCDIR)/process_root.c \
           $(ILL_SRCDIR)/ill_error.c \
           $(ILL_SRCDIR)/color.c

# Add Illeshian driver object files
ILL_OBJS = $(patsubst $(ILL_SRCDIR)/%.c,$(ILL_OBJDIR)/%.o,$(ILL_SRCS))

# Local build directories
BINDIR = 00_bin
OBJDIR = 00_obj
LIBDIR = 00_lib

# Object subdirectories
IRP_OBJDIR = $(OBJDIR)/irp
COMP_OBJDIR = $(OBJDIR)/comp
ILL_OBJDIR = $(OBJDIR)/ill
SEED_OBJDIR = $(OBJDIR)/seed
SCOPE_OBJDIR = $(OBJDIR)/scope

# Library directory
SCOPE_LIBDIR = $(LIBDIR)

# Executable targets in bin
IRP_TARGET = $(BINDIR)/irp
COMP_TARGET = $(BINDIR)/comp
SEED_TARGET = $(BINDIR)/seed
ILL_TARGET = $(BINDIR)/ill

# Create directory structure
create_dirs:
	@mkdir -p $(BINDIR)
	@mkdir -p $(IRP_OBJDIR)
	@mkdir -p $(COMP_OBJDIR)
	@mkdir -p $(ILL_OBJDIR)
	@mkdir -p $(SEED_OBJDIR)
	@mkdir -p $(SCOPE_OBJDIR)
	@mkdir -p $(LIBDIR)

# Main targets
.PHONY: all clean clean_irp clean_comp clean_seed clean_ill clean_scope debug install irp comp scope illeshian seed

# Default target builds everything into local bin/
all: scope irp comp seed ill

# Installation target (depends on all being built first)
install: all
	sudo mkdir -p /usr/local/illeshian/00_bin
	sudo mkdir -p /usr/local/illeshian/00_lib
	sudo mkdir -p /usr/local/illeshian/include/illeshian
	sudo install -m 755 $(BINDIR)/* /usr/local/illeshian/bin
	sudo cp -r $(SCOPE_LIBDIR)/* /usr/local/illeshian/lib
	sudo cp -r ill_include/* /usr/local/illeshian/include/illeshian

# Basic compiler without scope table
illeshian: create_dirs $(IRP_TARGET) $(COMP_TARGET)_basic

# Separate target for scope table library
scope: create_dirs $(SCOPE_LIB_STATIC) $(SCOPE_LIB_SHARED)

# Separate target for IRP compiler
irp: $(IRP_OBJS) | create_dirs
	@echo "Linking IRP..."
	@$(CC) $(IRP_OBJS) -o $(IRP_TARGET)

# Separate target for main compiler
comp: create_dirs scope $(COMP_OBJS) $(SCOPE_LIB_STATIC)
	@echo "Linking COMP with scope library..."
	@$(CC) -o $(COMP_TARGET) $(COMP_OBJS) $(SCOPE_LIB_STATIC)

# Compile IRP source files
$(IRP_OBJDIR)/irp_%.o: $(IRP_SRCDIR)/%.c | create_dirs
	@echo "Compiling IRP: $< -> $@"
	$(CC) $(CFLAGS) -I$(IRP_INCLUDEDIR) -c $< -o $@

# Compile Compiler source files
$(COMP_OBJDIR)/comp_%.o: $(COMP_SRCDIR)/%.c | create_dirs $(SCOPE_LIB_STATIC)
	@echo "Compiling COMP: $< -> $@"
	$(CC) $(CFLAGS) -I$(COMP_INCLUDEDIR) -I$(SCOPE_INCLUDEDIR) -c $< -o $@

# Compile basic compiler files (without scope table)
$(COMP_OBJDIR)/basic_%.o: $(COMP_SRCDIR)/%.c | create_dirs
	@echo "Compiling COMP (basic): $< -> $@"
	$(CC) $(CFLAGS) -I$(COMP_INCLUDEDIR) -DBASIC_COMPILER -c $< -o $@

# Compile scope table source files
$(SCOPE_OBJDIR)/%.o: $(SCOPE_SRCDIR)/%.c | create_dirs
	@echo "Compiling scope table: $< -> $@"
	$(CC) $(CFLAGS) -I$(SCOPE_INCLUDEDIR) -I$(COMP_INCLUDEDIR) -c $< -o $@

# Create static library
$(SCOPE_LIB_STATIC): $(SCOPE_OBJS)
	@echo "Creating static library: $@"
	ar rcs $@ $(SCOPE_OBJS)

# Create shared library
$(SCOPE_LIB_SHARED): $(SCOPE_OBJS)
	@echo "Creating shared library: $@"
	$(CC) $(LDFLAGS) -o $@ $(SCOPE_OBJS)

# Link basic compiler executable - Modified to be quiet
$(COMP_TARGET)_basic: $(COMP_BASIC_OBJS)
	@echo "Linking basic COMP..."
	@$(CC) $(COMP_BASIC_OBJS) -o $@ 2>&1 || { echo "Error linking $(COMP_TARGET)_basic:"; $(CC) $(COMP_BASIC_OBJS) -o $@; }

# Debug target
debug:
	@echo "IRP_SRCS = $(IRP_SRCS)"
	@echo "IRP_OBJS = $(IRP_OBJS)"
	@echo "COMP_SRCS = $(COMP_SRCS)"
	@echo "COMP_OBJS = $(COMP_OBJS)"
	@echo "SCOPE_SRCS = $(SCOPE_SRCS)"
	@echo "SCOPE_OBJS = $(SCOPE_OBJS)"
	@echo "Current directory: $$(pwd)"
	@echo "Directory contents:"
	@ls -R

# Individual clean rules
clean_irp:
	@echo "Cleaning IRP..."
	rm -rf $(IRP_OBJDIR)
	rm -f $(IRP_TARGET)
	rm -f irp

clean_comp:
	@echo "Cleaning COMP..."
	rm -rf $(COMP_OBJDIR)
	rm -f $(COMP_TARGET)
	rm -f $(COMP_TARGET)_basic
	rm -f comp

clean_seed:
	@echo "Cleaning SEED..."
	rm -rf $(SEED_OBJDIR)
	rm -f $(SEED_TARGET)
	rm -f seed
	rm -f main.asm
	rm -f write.asm
	rm -f yield.asm
	rm -f temp_bss.asm
	rm -f temp_text.asm
	rm -f temp_data.asm
	rm -f temp_rodata.asm
	rm -f write_neli.asm

clean_ill:
	@echo "Cleaning ILL..."
	rm -rf $(ILL_OBJDIR)
	rm -f $(ILL_TARGET)
	rm -f ill

clean_scope:
	@echo "Cleaning scope library..."
	rm -rf $(SCOPE_OBJDIR)
	rm -f $(SCOPE_LIB_STATIC)
	rm -f $(SCOPE_LIB_SHARED)
	rm -f scope_table.txt

# Update main clean to use individual cleans
clean: clean_irp clean_comp clean_seed clean_ill clean_scope
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
	rm -rf $(LIBDIR)

# Add Seedling compilation rule
$(SEED_OBJDIR)/seed_%.o: $(SEED_SRCDIR)/%.c | create_dirs $(SCOPE_LIB_STATIC)
	@echo "Compiling SEED: $< -> $@"
	$(CC) $(CFLAGS) -I$(SEED_INCLUDEDIR) -I$(SCOPE_INCLUDEDIR) -c $< -o $@

# Add Seedling target
seed: create_dirs scope $(SEED_OBJS) $(SCOPE_LIB_STATIC)
	@echo "Linking SEED with scope library..."
	@$(CC) -o $(SEED_TARGET) $(SEED_OBJS) $(SCOPE_LIB_STATIC)
	@ln -sf $(SEED_TARGET) ./seed

# Add Illeshian compilation rule
$(ILL_OBJDIR)/%.o: $(ILL_SRCDIR)/%.c | create_dirs
	@echo "Compiling ILL: $< -> $@"
	$(CC) $(CFLAGS) -I$(ILL_INCLUDEDIR) -I$(SCOPE_INCLUDEDIR) -c $< -o $@

# Add Illeshian driver target
ill: create_dirs scope $(ILL_OBJS) $(SCOPE_LIB_STATIC)
	@echo "Linking ILL driver..."
	@$(CC) -o $(ILL_TARGET) $(ILL_OBJS) $(SCOPE_LIB_STATIC)

# Add symlinks to current directory for testing
links: all
	@ln -sf $(BINDIR)/ill ./ill
	@ln -sf $(BINDIR)/irp ./irp
	@ln -sf $(BINDIR)/comp ./comp
	@ln -sf $(BINDIR)/seed ./seed