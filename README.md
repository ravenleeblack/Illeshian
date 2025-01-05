# Illeshian is a suite of programs.
```
The Illeshian Driver - ill
The Illeshian Runtime Preprocessor - irp
The Illeshian Compiler - comp
The Seedling assembler - seed
The Rootling linker - hasnt been started yet - root
```





I am still working on everything and plan to create a linker named rootling later that supports .exe, .elf, and .elm files.

The Ill driver is the main program that handles the workflow. The ill takes in a file manager file with the extention .fm. The .fm takes in 
a series of headers and sources files that need to compiled and assembled. We use the file manager so we do not have to include headers in every 
source file. The irp takes the .fm file as input and preprocesses it before outputting a .i file for headers and a .p for source files. The comp 
which is the illeshian compiler will take these in as input. When the comp is finished it should produce a .seed file for the seedling assembler.

# Main Goal Right Now:
- Getting the seedling assembler finished as a boot strap then self hosting program so that we can write the illeshian code gen in seedling. Since we are writing the program in c, the program takes in seedling as input and produces nasm as output. This means once we actually compile the c program into binary, we have an executable program, that executable program takes in seedling and produces nasm. We then have to rewrite the assembler in seedling instead of c now that we have a program that can assemble seedling to nasm. Since the first program produces nasm output, once we use that to assemble the new seedling assembler code, then we would have a self hosting seedling assembler.
- The current problem that I have right now is that other assemblers are section based and seedling is scope based with sections underneath. I had to create some nasm temp files, so that I collect all the
  seedling sections then write them into the right nasm section temp file, so that later we can bring all that information back in and have it write to the proper nasm files properly.

