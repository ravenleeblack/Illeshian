#ifndef SEED_OPCODE_H
#define SEED_OPCODE_H

struct seed_opcode               //This node is used for Hashing using Chaining
{
        char name[10];
        char code[35];
        char format[5];
        /**
        rri = reg reg imm. addr.
        rrr = reg reg reg
        ri  = reg imm.
        rr  = reg reg
        a   = add
        z   = zero
        */
        struct seed_opcode *next_opcode;
};

typedef struct seed_opcode opcode;


typedef enum 
{
    reg8_phrase,         //used where 08 bit regs are needed in phrases or operands
    reg16_phrase,        //used where 16 bit regs are needed in phrases or operands
    reg32_phrase,        //used where 32 bit regs are needed in phrases or operands
    reg64_phrase,        //used where 64 bit regs are needed in phrases or operands
    memory_phrase,       //used where memory regs are needed in phrases or operands
    immediate_phrase,    //not sure yet
    rm_gpr_phrase,       //not sure yet
    reg_al_phrase,       //assuming stack return regs for arch 08 size
    reg_ax_phrase,       //assuming stack return regs for arch 16 size
    reg_eax_phrase,      //assuming stack return regs for arch 32 size
    reg_rax_phrase,      //assuming stack return regs for arch 64 size
    signed_byte,         //used for signed data values in phrase or operands: when using dens, bays, aisles, and zones. Since they are signed based off the added s ext added to keyword.
    no_phrase,           //For unused phrase operand slots
} phrase_type;

typedef enum 
{
    arch_16 = 1,          //8086
    arch_32 = 2,          //386 or x86
    arch_64 = 4           //x64
} arch_type;

typedef struct 
{
    int seed_opcode;                   // Instruction opcode
    int phrase_count;                  // Number of phrases or operands
    phrase_type phrases[4];            // phrase or operand types (up to 4)
    arch_type arch_flags;              // supported architectures
    const char *encoding_strand;       // encoding_strand
} instruction;


/*keep track of the ident used for labels, so that we can collect them, get addresses.
not sure how I am going to use this yet but I know we need it.                        */
typedef struct label 
{
    char label_name[50];                 // Label name
    unsigned int label_address;          // Address of the label
    int scope_level;                     // maybe? flag what scope its in since we have universal, global, local, global block, and local block.
    struct label *next_label;            // Pointer to the next label
};

// when handling labels since all the  work is done in global scope mainly. Then we create libraries from the global and child local labels. This
// should make it possible for the liker to relocate libraries fast because it can just add them on as if they are just another global label in 
// the program.

//struct label * scope_table = NULL;            
// need to figure out how to make scope table tell the difference the normal idents we insert and search and flag as label which shouldnt be hard
// seeing as we already have tool and data types then use that flag somehow. Also need to be able to add the actual value of labels, and literals and
// we need to be able to identify which kind of literal we have. THe scope table does take string literals in right now but if we have a hex or num literal
// we will need to add in the real value?? maybe.

//So we already introduces num_ptr[index], fetch[index], and address[index] into the seedling assembler so we need to also add in mana_ptr[label_name] and
//func_ptr[label_name] that away there will already be native support in seedling before we build Illeshian backend. Also need to add in the support for
//log_ptr[log_name] and list_ptr[list_name]






#endif // SEED_OPCODE_H